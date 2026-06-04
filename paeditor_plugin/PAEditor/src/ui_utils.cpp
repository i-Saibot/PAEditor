#include "ui_utils.h"
#include "native.h"

#include <process.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>

namespace ui_utils
{
	void drawModernRect(HDC hdc, RECT r, COLORREF color)
	{
		HBRUSH hBr = CreateSolidBrush(color);
		FillRect(hdc, &r, hBr);
		DeleteObject(hBr);
	}

	COLORREF GetFullSpectrumColor(float H)
	{
		float r, g, b;
		int i = static_cast<int>(floor(H * 6));
		float f = H * 6 - i;
		float p = 0;
		float q = (1 - f);
		float t = f;

		switch (i % 6)
		{
			case 0: r = 1, g = t, b = p; break;
			case 1: r = q, g = 1, b = p; break;
			case 2: r = p, g = 1, b = t; break;
			case 3: r = p, g = q, b = 1; break;
			case 4: r = t, g = p, b = 1; break;
			case 5: r = 1, g = p, b = q; break;
			default: r = 0; g = 0; b = 0; break;
		}
		return RGB((BYTE)(r * 255), (BYTE)(g * 255), (BYTE)(b * 255));
	}

	void drawMarker(HDC hdc, int x, int y, int radius, int thickness)
	{
		HPEN hWhite = CreatePen(PS_SOLID, thickness, RGB(255, 255, 255));
		HGDIOBJ hOldPen = SelectObject(hdc, hWhite);
		HGDIOBJ hOldBr = SelectObject(hdc, GetStockObject(NULL_BRUSH));

		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
		SelectObject(hdc, hOldPen);
		SelectObject(hdc, hOldBr);
		DeleteObject(hWhite);
	}

	void drawHorizontalMarker(HDC hdc, RECT r, int y, int thickness)
	{
		HPEN hWhite = CreatePen(PS_SOLID, thickness, RGB(255, 255, 255));
		HGDIOBJ hOldPen = SelectObject(hdc, hWhite);

		MoveToEx(hdc, r.left - 2, y, NULL);
		LineTo(hdc, r.right + 2, y);
		SelectObject(hdc, hOldPen);
		DeleteObject(hWhite);
	}

	static void CALLBACK WinEventProc(HWINEVENTHOOK, DWORD event, HWND hwnd, LONG, LONG, DWORD, DWORD)
	{
		if (!g_paletteWnd || !g_bIsRunning)
		{
			return;
		}
		switch (event)
		{
			case EVENT_SYSTEM_MINIMIZESTART:
			{
				if (hwnd == g_gameWnd)
				{
					ShowWindow(g_paletteWnd, SW_HIDE);
				}
				break;
			}
			case EVENT_SYSTEM_MINIMIZEEND:
			{
				if (hwnd == g_gameWnd)
				{
					if (g_bVisible)
					{
						ShowWindow(g_paletteWnd, SW_SHOWNOACTIVATE);
						SetWindowPos(g_paletteWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
					}
				}
				break;
			}
			case EVENT_SYSTEM_FOREGROUND:
			{
				if (hwnd == g_gameWnd && IsWindowVisible(g_paletteWnd))
				{
					SetWindowPos(g_paletteWnd, HWND_TOPMOST, 0, 0, 0, 0,
						SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
				}
				break;
			}
		}
	}

	void drawUI(HDC hdc, HWND hwnd)
	{
		RECT client; GetClientRect(hwnd, &client);

		drawModernRect(hdc, client, RGB(30, 30, 35));

		RECT header = { 0, 0, client.right, 35 };
		drawModernRect(hdc, header, RGB(45, 45, 50));
		if (g_hFontUI) SelectObject(hdc, g_hFontUI);

		SetTextColor(hdc, RGB(220, 220, 220));
		SetBkMode(hdc, TRANSPARENT);

		int x = client.right - 25;
		int y = 12;

		HPEN hPenClose = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HGDIOBJ hOldPen = SelectObject(hdc, hPenClose);

		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x + 10, y + 10);
		MoveToEx(hdc, x + 10, y, NULL);
		LineTo(hdc, x, y + 10);
		SelectObject(hdc, hOldPen);
		DeleteObject(hPenClose);

		int specW = rSpec.right - rSpec.left;
		for (int i = 0; i < specW; i++)
		{
			RECT line = { rSpec.left + i, rSpec.top, rSpec.left + i + 1, rSpec.bottom };
			drawModernRect(hdc, line, GetFullSpectrumColor((float)i / specW));
		}

		int brightH = rBright.bottom - rBright.top;
		for (int i = 0; i < brightH; i++)
		{
			float b = 1.0f - ((float)i / brightH);
			COLORREF c = RGB(
				(BYTE)(GetRValue(g_baseColor) * b),
				(BYTE)(GetGValue(g_baseColor) * b),
				(BYTE)(GetBValue(g_baseColor) * b)
			);
			RECT line = { rBright.left, rBright.top + i, rBright.right, rBright.top + i + 1 };
			drawModernRect(hdc, line, c);
		}

		COLORREF final = RGB(
			(BYTE)(GetRValue(g_baseColor) * g_brightness),
			(BYTE)(GetGValue(g_baseColor) * g_brightness),
			(BYTE)(GetBValue(g_baseColor) * g_brightness)
		);

		RECT rPreview = { 15, 125, 75, 155 };
		drawModernRect(hdc, rPreview, final);

		wchar_t info[64];
		swprintf(info, 64, L"HEX: #%02X%02X%02X",
			GetRValue(final), GetGValue(final), GetBValue(final));

		if (g_bCopied && (GetTickCount() - g_dwCopiedAt) < 1000)
		{
			SetTextColor(hdc, RGB(100, 220, 100));
			TextOut(hdc, 85, 132, L"Copied!", 7);
		}
		else
		{
			g_bCopied = false;
			SetTextColor(hdc, RGB(180, 180, 180));
			TextOut(hdc, 85, 132, info, (int)wcslen(info));
		}

		int specX = rSpec.left + (int)(g_ratSpec * (rSpec.right - rSpec.left));
		int specY = rSpec.top + (int)((1.0f - g_brightness) * (rSpec.bottom - rSpec.top));
		drawMarker(hdc, specX, specY, 6, 3);

		int brightY = rBright.top + (int)((1.0f - g_brightness) * (rBright.bottom - rBright.top));
		drawHorizontalMarker(hdc, rBright, brightY, 3);
	}

	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		static HDC hdcMem = NULL;
		static HBITMAP hbmMem = NULL;

		switch (uMsg)
		{
		case WM_MOUSEACTIVATE:
		{
			return MA_NOACTIVATE;
		}
		case WM_LBUTTONDOWN:
		{
			int x = LOWORD(lParam);
			int y = HIWORD(lParam);

			RECT rCopy = { 15, 125, 370, 155 };
			if (x >= rCopy.left && x <= rCopy.right && y >= rCopy.top && y <= rCopy.bottom)
			{
				BYTE finalR = (BYTE)(GetRValue(g_baseColor) * g_brightness);
				BYTE finalG = (BYTE)(GetGValue(g_baseColor) * g_brightness);
				BYTE finalB = (BYTE)(GetBValue(g_baseColor) * g_brightness);

				wchar_t hex[16];
				swprintf(hex, 16, L"%02X%02X%02X", finalR, finalG, finalB);

				if (OpenClipboard(hwnd))
				{
					EmptyClipboard();
					HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, sizeof(hex));
					if (hMem)
					{
						memcpy(GlobalLock(hMem), hex, sizeof(hex));
						GlobalUnlock(hMem);
						SetClipboardData(CF_UNICODETEXT, hMem);
					}
					CloseClipboard();

					g_bCopied = true;
					g_dwCopiedAt = GetTickCount();
					InvalidateRect(hwnd, NULL, FALSE);
				}
				return 0;
			}
			if (x >= rClose.left && x <= rClose.right && y >= rClose.top && y <= rClose.bottom)
			{
				g_bVisible = false;
				g_currentMode = DragMode::NONE;
				ReleaseCapture();
				ShowWindow(hwnd, SW_HIDE);
				native::closePalette();
				return 0;
			}
			if (x >= rSpec.left && x <= rSpec.right && y >= rSpec.top && y <= rSpec.bottom)
			{
				g_currentMode = DragMode::SPECTRUM;
			}
			else if (x >= rBright.left && x <= rBright.right && y >= rBright.top && y <= rBright.bottom)
			{
				g_currentMode = DragMode::BRIGHTNESS;
			}
			else
			{
				if (y <= 35)
				{
					ReleaseCapture();
					SendMessage(hwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
				}
				return 0;
			}
			SetCapture(hwnd);
			return 0;
		}
		case WM_MOUSEMOVE:
		{
			if (g_currentMode == DragMode::NONE) return 0;

			int x = LOWORD(lParam);
			int y = HIWORD(lParam);

			if (g_currentMode == DragMode::SPECTRUM)
			{
				float width = static_cast<float>(rSpec.right - rSpec.left);
				float height = static_cast<float>(rSpec.bottom - rSpec.top);

				g_ratSpec = std::clamp(static_cast<float>(x - rSpec.left) / width, 0.0f, 1.0f);
				g_baseColor = GetFullSpectrumColor(g_ratSpec);

				float ratY = std::clamp(static_cast<float>(y - rSpec.top) / height, 0.0f, 1.0f);
				g_brightness = 1.0f - ratY;
			}
			if (g_currentMode == DragMode::BRIGHTNESS)
			{
				float height = static_cast<float>(rBright.bottom - rBright.top);
				float rat = std::clamp(static_cast<float>(y - rBright.top) / height, 0.0f, 1.0f);
				g_brightness = 1.0f - rat;
			}
			BYTE finalR = (BYTE)(GetRValue(g_baseColor) * g_brightness);
			BYTE finalG = (BYTE)(GetGValue(g_baseColor) * g_brightness);
			BYTE finalB = (BYTE)(GetBValue(g_baseColor) * g_brightness);
			native::setPalette(finalR, finalG, finalB);

			InvalidateRect(hwnd, NULL, FALSE);
			return 0;
		}
		case WM_LBUTTONUP:
		{
			g_currentMode = DragMode::NONE;
			ReleaseCapture();
			InvalidateRect(hwnd, NULL, FALSE);
			return 0;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps; HDC hdc = BeginPaint(hwnd, &ps);
			RECT rc; GetClientRect(hwnd, &rc);

			if (!hdcMem)
			{
				hdcMem = CreateCompatibleDC(hdc);
				hbmMem = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
				SelectObject(hdcMem, hbmMem);
			}
			drawUI(hdcMem, hwnd);
			BitBlt(hdc, 0, 0, rc.right, rc.bottom, hdcMem, 0, 0, SRCCOPY);
			EndPaint(hwnd, &ps);
			return 0;
		}
		case WM_ACTIVATE:
		{
			SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0,
				SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
			return 0;
		}
		case WM_DESTROY:
		{
			if (g_hMinHook) { UnhookWinEvent(g_hMinHook); g_hMinHook = NULL; }
			if (g_hFgHook) { UnhookWinEvent(g_hFgHook);  g_hFgHook = NULL; }

			if (hdcMem)
			{
				DeleteObject(hbmMem);
				DeleteDC(hdcMem);
				hdcMem = NULL;
			}
			if (g_hFontUI)
			{
				DeleteObject(g_hFontUI);
				g_hFontUI = NULL;
			}
			g_bIsRunning = false;
			PostQuitMessage(0);
			return 0;
		}
		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	void showPalette()
	{
		g_bVisible = true;

		if (g_bIsRunning && g_paletteWnd)
		{
			ShowWindow(g_paletteWnd, SW_SHOWNOACTIVATE);
			SetWindowPos(g_paletteWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
			return;
		}
		g_bIsRunning = true;
		g_gameWnd = GetForegroundWindow();

		_beginthread([](void* h)
			{
				HINSTANCE hInst = (HINSTANCE)h;

				int winW = 380, winH = 175;
				int posX = (GetSystemMetrics(SM_CXSCREEN) - winW) / 2;
				int posY = (GetSystemMetrics(SM_CYSCREEN) - winH) / 2;

				g_paletteWnd = CreateWindowEx(
					WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_LAYERED | WS_EX_NOACTIVATE,
					L"ModernPal", L"",
					WS_POPUP | WS_VISIBLE,
					posX, posY, winW, winH,
					NULL,
					NULL,
					hInst,
					NULL
				);

				if (!g_paletteWnd)
				{
					g_bIsRunning = false;
					return;
				}

				SetLayeredWindowAttributes(g_paletteWnd, 0, 255, LWA_ALPHA);
				ShowWindow(g_paletteWnd, SW_SHOWNOACTIVATE);
				UpdateWindow(g_paletteWnd);
				SetWindowPos(g_paletteWnd, HWND_TOPMOST, 0, 0, 0, 0,
					SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

				if (g_gameWnd)
				{
					DWORD pid = 0;
					GetWindowThreadProcessId(g_gameWnd, &pid);

					g_hMinHook = SetWinEventHook(
						EVENT_SYSTEM_MINIMIZESTART, EVENT_SYSTEM_MINIMIZEEND,
						NULL, WinEventProc,
						pid, 0,
						WINEVENT_OUTOFCONTEXT);

					g_hFgHook = SetWinEventHook(
						EVENT_SYSTEM_FOREGROUND, EVENT_SYSTEM_FOREGROUND,
						NULL, WinEventProc,
						0, 0,
						WINEVENT_OUTOFCONTEXT);
				}
				MSG msg;
				while (g_bIsRunning && GetMessage(&msg, NULL, 0, 0))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				if (g_hMinHook) { UnhookWinEvent(g_hMinHook); g_hMinHook = NULL; }
				if (g_hFgHook) { UnhookWinEvent(g_hFgHook);  g_hFgHook = NULL; }

				if (g_paletteWnd)
				{
					DestroyWindow(g_paletteWnd);
					g_paletteWnd = NULL;
				}
				g_bIsRunning = false;

			}, 0, GetModuleHandle(NULL));
	}

	void hidePalette()
	{
		if (!g_bIsRunning || !g_paletteWnd)
		{
			return;
		}
		ShowWindow(g_paletteWnd, SW_HIDE);
	}

	void destroyPalette()
	{
		if (!g_bIsRunning)
		{
			return;
		}
		g_bIsRunning = false;

		if (g_paletteWnd)
		{
			PostMessage(g_paletteWnd, WM_QUIT, 0, 0);
			g_paletteWnd = NULL;
		}
	}

	void initPaletteClass()
	{
		WNDCLASS wc = { 0 };
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = L"ModernPal";
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		RegisterClass(&wc);

		if (g_hFontUI == NULL)
		{
			g_hFontUI = CreateFont(
				16, 0, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE,
				DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				CLEARTYPE_QUALITY, VARIABLE_PITCH, L"Segoe UI"
			);
		}
	}

}