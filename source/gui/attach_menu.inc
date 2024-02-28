#if defined _gui_attach_menu_inc
	#endinput
#endif
#define _gui_attach_menu_inc

static Text: gui_AttachMenu[71];
static bool: gui_AttachMenuPlayerShow[MAX_PLAYERS];
static bool: gui_AttachMenuActivePanel[MAX_PLAYERS];
static bool: gui_AttachMenuBannedPanel[MAX_PLAYERS];


enum
{
	GUI_ATTACH_MENU_MANAGE,
	GUI_ATTACH_MENU_EXPORT,
	GUI_ATTACH_MENU_NEW,
	GUI_ATTACH_MENU_DELETE,
	GUI_ATTACH_MENU_DUBLICATE,
	GUI_ATTACH_MENU_OBJECT,
	GUI_ATTACH_MENU_BONE,
	GUI_ATTACH_MENU_SYMMETRY,
	GUI_ATTACH_MENU_EDIT,
	GUI_ATTACH_MENU_COLOR_1,
	GUI_ATTACH_MENU_COLOR_2,
	GUI_ATTACH_MENU_ANIMATIONS,
	GUI_ATTACH_MENU_ANIMATION_CLEAR,
	GUI_ATTACH_MENU_PREV_SKIN,
	GUI_ATTACH_MENU_SKIN,
	GUI_ATTACH_MENU_NEXT_SKIN,
	GUI_ATTACH_MENU_CAMERA_MOVE
}


public OnGameModeInit()
{
	gui_AttachMenu[0] = TextDrawCreate(139.1990, 413.3002, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[0], 393.0400, 34.0000);
	TextDrawAlignment(gui_AttachMenu[0], 1);
	TextDrawColor(gui_AttachMenu[0], 255);
	TextDrawBackgroundColor(gui_AttachMenu[0], 255);
	TextDrawFont(gui_AttachMenu[0], 4);
	TextDrawSetProportional(gui_AttachMenu[0], 0);
	TextDrawSetShadow(gui_AttachMenu[0], 0);

	gui_AttachMenu[1] = TextDrawCreate(140.1990, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[1], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[1], 1);
	TextDrawColor(gui_AttachMenu[1], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[1], 255);
	TextDrawFont(gui_AttachMenu[1], 4);
	TextDrawSetProportional(gui_AttachMenu[1], 0);
	TextDrawSetShadow(gui_AttachMenu[1], 0);
	TextDrawSetSelectable(gui_AttachMenu[1], true);

	gui_AttachMenu[2] = TextDrawCreate(142.6325, 421.5111, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[2], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[2], 1);
	TextDrawColor(gui_AttachMenu[2], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[2], 255);
	TextDrawFont(gui_AttachMenu[2], 4);
	TextDrawSetProportional(gui_AttachMenu[2], 0);
	TextDrawSetShadow(gui_AttachMenu[2], 0);

	gui_AttachMenu[3] = TextDrawCreate(142.5325, 425.9111, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[3], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[3], 1);
	TextDrawColor(gui_AttachMenu[3], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[3], 255);
	TextDrawFont(gui_AttachMenu[3], 4);
	TextDrawSetProportional(gui_AttachMenu[3], 0);
	TextDrawSetShadow(gui_AttachMenu[3], 0);

	gui_AttachMenu[4] = TextDrawCreate(142.5325, 429.8114, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[4], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[4], 1);
	TextDrawColor(gui_AttachMenu[4], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[4], 255);
	TextDrawFont(gui_AttachMenu[4], 4);
	TextDrawSetProportional(gui_AttachMenu[4], 0);
	TextDrawSetShadow(gui_AttachMenu[4], 0);

	gui_AttachMenu[5] = TextDrawCreate(143.7993, 437.2296, "Manage");
	TextDrawLetterSize(gui_AttachMenu[5], 0.1720, 0.8116);
	TextDrawTextSize(gui_AttachMenu[5], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[5], 1);
	TextDrawColor(gui_AttachMenu[5], -1);
	TextDrawBackgroundColor(gui_AttachMenu[5], 255);
	TextDrawFont(gui_AttachMenu[5], 1);
	TextDrawSetProportional(gui_AttachMenu[5], 1);
	TextDrawSetShadow(gui_AttachMenu[5], 0);

	gui_AttachMenu[6] = TextDrawCreate(168.1304, 414.6480, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[6], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[6], 1);
	TextDrawColor(gui_AttachMenu[6], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[6], 255);
	TextDrawFont(gui_AttachMenu[6], 4);
	TextDrawSetProportional(gui_AttachMenu[6], 0);
	TextDrawSetShadow(gui_AttachMenu[6], 0);
	TextDrawSetSelectable(gui_AttachMenu[6], true);

	gui_AttachMenu[7] = TextDrawCreate(174.5307, 416.8330, "....");
	TextDrawLetterSize(gui_AttachMenu[7], 0.3916, 1.5377);
	TextDrawAlignment(gui_AttachMenu[7], 1);
	TextDrawColor(gui_AttachMenu[7], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[7], 255);
	TextDrawFont(gui_AttachMenu[7], 1);
	TextDrawSetProportional(gui_AttachMenu[7], 1);
	TextDrawSetShadow(gui_AttachMenu[7], 0);

	gui_AttachMenu[8] = TextDrawCreate(173.0675, 437.2296, "Export");
	TextDrawLetterSize(gui_AttachMenu[8], 0.1843, 0.8198);
	TextDrawTextSize(gui_AttachMenu[8], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[8], 1);
	TextDrawColor(gui_AttachMenu[8], -1);
	TextDrawBackgroundColor(gui_AttachMenu[8], 255);
	TextDrawFont(gui_AttachMenu[8], 1);
	TextDrawSetProportional(gui_AttachMenu[8], 1);
	TextDrawSetShadow(gui_AttachMenu[8], 0);

	gui_AttachMenu[9] = TextDrawCreate(196.1022, 414.6036, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[9], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[9], 1);
	TextDrawColor(gui_AttachMenu[9], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[9], 255);
	TextDrawFont(gui_AttachMenu[9], 4);
	TextDrawSetProportional(gui_AttachMenu[9], 0);
	TextDrawSetShadow(gui_AttachMenu[9], 0);
	TextDrawSetSelectable(gui_AttachMenu[9], true);

	gui_AttachMenu[10] = TextDrawCreate(204.0036, 414.6408, "+");
	TextDrawLetterSize(gui_AttachMenu[10], 0.5015, 2.3046);
	TextDrawTextSize(gui_AttachMenu[10], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[10], 1);
	TextDrawColor(gui_AttachMenu[10], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[10], 255);
	TextDrawFont(gui_AttachMenu[10], 2);
	TextDrawSetProportional(gui_AttachMenu[10], 1);
	TextDrawSetShadow(gui_AttachMenu[10], 0);

	gui_AttachMenu[11] = TextDrawCreate(204.0028, 437.2296, "New");
	TextDrawLetterSize(gui_AttachMenu[11], 0.1949, 0.8197);
	TextDrawTextSize(gui_AttachMenu[11], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[11], 1);
	TextDrawColor(gui_AttachMenu[11], -1);
	TextDrawBackgroundColor(gui_AttachMenu[11], 255);
	TextDrawFont(gui_AttachMenu[11], 1);
	TextDrawSetProportional(gui_AttachMenu[11], 1);
	TextDrawSetShadow(gui_AttachMenu[11], 0);

	gui_AttachMenu[12] = TextDrawCreate(224.1040, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[12], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[12], 1);
	TextDrawColor(gui_AttachMenu[12], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[12], 255);
	TextDrawFont(gui_AttachMenu[12], 4);
	TextDrawSetProportional(gui_AttachMenu[12], 0);
	TextDrawSetShadow(gui_AttachMenu[12], 0);
	TextDrawSetSelectable(gui_AttachMenu[12], true);

	gui_AttachMenu[13] = TextDrawCreate(233.7718, 415.4407, "X");
	TextDrawLetterSize(gui_AttachMenu[13], 0.3113, 2.1222);
	TextDrawTextSize(gui_AttachMenu[13], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[13], 1);
	TextDrawColor(gui_AttachMenu[13], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[13], 255);
	TextDrawFont(gui_AttachMenu[13], 2);
	TextDrawSetProportional(gui_AttachMenu[13], 1);
	TextDrawSetShadow(gui_AttachMenu[13], 0);

	gui_AttachMenu[14] = TextDrawCreate(229.4046, 437.2296, "Delete");
	TextDrawLetterSize(gui_AttachMenu[14], 0.1782, 0.8155);
	TextDrawTextSize(gui_AttachMenu[14], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[14], 1);
	TextDrawColor(gui_AttachMenu[14], -1);
	TextDrawBackgroundColor(gui_AttachMenu[14], 255);
	TextDrawFont(gui_AttachMenu[14], 1);
	TextDrawSetProportional(gui_AttachMenu[14], 1);
	TextDrawSetShadow(gui_AttachMenu[14], 0);

	gui_AttachMenu[15] = TextDrawCreate(252.2061, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[15], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[15], 1);
	TextDrawColor(gui_AttachMenu[15], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[15], 255);
	TextDrawFont(gui_AttachMenu[15], 4);
	TextDrawSetProportional(gui_AttachMenu[15], 0);
	TextDrawSetShadow(gui_AttachMenu[15], 0);
	TextDrawSetSelectable(gui_AttachMenu[15], true);

	gui_AttachMenu[16] = TextDrawCreate(258.9407, 420.3630, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[16], 9.0000, 9.0000);
	TextDrawAlignment(gui_AttachMenu[16], 1);
	TextDrawColor(gui_AttachMenu[16], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[16], 255);
	TextDrawFont(gui_AttachMenu[16], 4);
	TextDrawSetProportional(gui_AttachMenu[16], 0);
	TextDrawSetShadow(gui_AttachMenu[16], 0);

	gui_AttachMenu[17] = TextDrawCreate(263.1744, 424.5111, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[17], 9.0000, 9.0000);
	TextDrawAlignment(gui_AttachMenu[17], 1);
	TextDrawColor(gui_AttachMenu[17], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[17], 255);
	TextDrawFont(gui_AttachMenu[17], 4);
	TextDrawSetProportional(gui_AttachMenu[17], 0);
	TextDrawSetShadow(gui_AttachMenu[17], 0);

	gui_AttachMenu[18] = TextDrawCreate(253.6060, 437.2296, "Dublicate");
	TextDrawLetterSize(gui_AttachMenu[18], 0.1736, 0.8327);
	TextDrawTextSize(gui_AttachMenu[18], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[18], 1);
	TextDrawColor(gui_AttachMenu[18], -1);
	TextDrawBackgroundColor(gui_AttachMenu[18], 255);
	TextDrawFont(gui_AttachMenu[18], 1);
	TextDrawSetProportional(gui_AttachMenu[18], 1);
	TextDrawSetShadow(gui_AttachMenu[18], 0);

	gui_AttachMenu[19] = TextDrawCreate(280.0075, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[19], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[19], 1);
	TextDrawColor(gui_AttachMenu[19], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[19], 255);
	TextDrawFont(gui_AttachMenu[19], 4);
	TextDrawSetProportional(gui_AttachMenu[19], 0);
	TextDrawSetShadow(gui_AttachMenu[19], 0);
	TextDrawSetSelectable(gui_AttachMenu[19], true);

	gui_AttachMenu[20] = TextDrawCreate(287.1412, 419.6369, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[20], 12.0000, 13.0000);
	TextDrawAlignment(gui_AttachMenu[20], 1);
	TextDrawColor(gui_AttachMenu[20], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[20], 255);
	TextDrawFont(gui_AttachMenu[20], 4);
	TextDrawSetProportional(gui_AttachMenu[20], 0);
	TextDrawSetShadow(gui_AttachMenu[20], 0);

	gui_AttachMenu[21] = TextDrawCreate(290.5071, 419.6221, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[21], 1.0000, 12.9299);
	TextDrawAlignment(gui_AttachMenu[21], 1);
	TextDrawColor(gui_AttachMenu[21], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[21], 255);
	TextDrawFont(gui_AttachMenu[21], 4);
	TextDrawSetProportional(gui_AttachMenu[21], 0);
	TextDrawSetShadow(gui_AttachMenu[21], 0);

	gui_AttachMenu[22] = TextDrawCreate(287.2408, 426.2626, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[22], 12.0000, 1.0000);
	TextDrawAlignment(gui_AttachMenu[22], 1);
	TextDrawColor(gui_AttachMenu[22], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[22], 255);
	TextDrawFont(gui_AttachMenu[22], 4);
	TextDrawSetProportional(gui_AttachMenu[22], 0);
	TextDrawSetShadow(gui_AttachMenu[22], 0);

	gui_AttachMenu[23] = TextDrawCreate(284.2076, 437.2296, "Objects");
	TextDrawLetterSize(gui_AttachMenu[23], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[23], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[23], 1);
	TextDrawColor(gui_AttachMenu[23], -1);
	TextDrawBackgroundColor(gui_AttachMenu[23], 255);
	TextDrawFont(gui_AttachMenu[23], 1);
	TextDrawSetProportional(gui_AttachMenu[23], 1);
	TextDrawSetShadow(gui_AttachMenu[23], 0);

	gui_AttachMenu[24] = TextDrawCreate(544.8579, 413.4147, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[24], 84.9001, 34.0000);
	TextDrawAlignment(gui_AttachMenu[24], 1);
	TextDrawColor(gui_AttachMenu[24], 255);
	TextDrawBackgroundColor(gui_AttachMenu[24], 255);
	TextDrawFont(gui_AttachMenu[24], 4);
	TextDrawSetProportional(gui_AttachMenu[24], 0);
	TextDrawSetShadow(gui_AttachMenu[24], 0);

	gui_AttachMenu[25] = TextDrawCreate(364.0126, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[25], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[25], 1);
	TextDrawColor(gui_AttachMenu[25], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[25], 255);
	TextDrawFont(gui_AttachMenu[25], 4);
	TextDrawSetProportional(gui_AttachMenu[25], 0);
	TextDrawSetShadow(gui_AttachMenu[25], 0);
	TextDrawSetSelectable(gui_AttachMenu[25], true);

	gui_AttachMenu[26] = TextDrawCreate(373.3132, 437.2296, "Edit");
	TextDrawLetterSize(gui_AttachMenu[26], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[26], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[26], 1);
	TextDrawColor(gui_AttachMenu[26], -1);
	TextDrawBackgroundColor(gui_AttachMenu[26], 255);
	TextDrawFont(gui_AttachMenu[26], 1);
	TextDrawSetProportional(gui_AttachMenu[26], 1);
	TextDrawSetShadow(gui_AttachMenu[26], 0);

	gui_AttachMenu[27] = TextDrawCreate(545.9135, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[27], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[27], 1);
	TextDrawColor(gui_AttachMenu[27], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[27], 255);
	TextDrawFont(gui_AttachMenu[27], 4);
	TextDrawSetProportional(gui_AttachMenu[27], 0);
	TextDrawSetShadow(gui_AttachMenu[27], 0);
	TextDrawSetSelectable(gui_AttachMenu[27], true);

	gui_AttachMenu[28] = TextDrawCreate(476.0194, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[28], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[28], 1);
	TextDrawColor(gui_AttachMenu[28], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[28], 255);
	TextDrawFont(gui_AttachMenu[28], 4);
	TextDrawSetProportional(gui_AttachMenu[28], 0);
	TextDrawSetShadow(gui_AttachMenu[28], 0);
	TextDrawSetSelectable(gui_AttachMenu[28], true);

	gui_AttachMenu[29] = TextDrawCreate(484.9479, 414.5591, "A");
	TextDrawLetterSize(gui_AttachMenu[29], 0.3366, 2.2097);
	TextDrawAlignment(gui_AttachMenu[29], 1);
	TextDrawColor(gui_AttachMenu[29], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[29], 255);
	TextDrawFont(gui_AttachMenu[29], 2);
	TextDrawSetProportional(gui_AttachMenu[29], 1);
	TextDrawSetShadow(gui_AttachMenu[29], 0);

	gui_AttachMenu[30] = TextDrawCreate(477.6531, 437.2296, "Animation");
	TextDrawLetterSize(gui_AttachMenu[30], 0.1570, 0.8284);
	TextDrawTextSize(gui_AttachMenu[30], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[30], 1);
	TextDrawColor(gui_AttachMenu[30], -1);
	TextDrawBackgroundColor(gui_AttachMenu[30], 255);
	TextDrawFont(gui_AttachMenu[30], 1);
	TextDrawSetProportional(gui_AttachMenu[30], 1);
	TextDrawSetShadow(gui_AttachMenu[30], 0);

	gui_AttachMenu[31] = TextDrawCreate(504.1213, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[31], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[31], 1);
	TextDrawColor(gui_AttachMenu[31], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[31], 255);
	TextDrawFont(gui_AttachMenu[31], 4);
	TextDrawSetProportional(gui_AttachMenu[31], 0);
	TextDrawSetShadow(gui_AttachMenu[31], 0);
	TextDrawSetSelectable(gui_AttachMenu[31], true);

	gui_AttachMenu[32] = TextDrawCreate(509.1162, 414.5296, "CA");
	TextDrawLetterSize(gui_AttachMenu[32], 0.3366, 2.2097);
	TextDrawAlignment(gui_AttachMenu[32], 1);
	TextDrawColor(gui_AttachMenu[32], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[32], 255);
	TextDrawFont(gui_AttachMenu[32], 2);
	TextDrawSetProportional(gui_AttachMenu[32], 1);
	TextDrawSetShadow(gui_AttachMenu[32], 0);

	gui_AttachMenu[33] = TextDrawCreate(505.5548, 437.2296, "Clear_Anim");
	TextDrawLetterSize(gui_AttachMenu[33], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[33], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[33], 1);
	TextDrawColor(gui_AttachMenu[33], -1);
	TextDrawBackgroundColor(gui_AttachMenu[33], 255);
	TextDrawFont(gui_AttachMenu[33], 1);
	TextDrawSetProportional(gui_AttachMenu[33], 1);
	TextDrawSetShadow(gui_AttachMenu[33], 0);

	gui_AttachMenu[34] = TextDrawCreate(496.2703, 401.9859, "Hide_cursor_-");
	TextDrawLetterSize(gui_AttachMenu[34], 0.1251, 0.9168);
	TextDrawTextSize(gui_AttachMenu[34], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[34], 2);
	TextDrawColor(gui_AttachMenu[34], -1);
	TextDrawBackgroundColor(gui_AttachMenu[34], 255);
	TextDrawFont(gui_AttachMenu[34], 2);
	TextDrawSetProportional(gui_AttachMenu[34], 1);
	TextDrawSetShadow(gui_AttachMenu[34], 0);

	gui_AttachMenu[35] = TextDrawCreate(473.7385, 401.4151, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[35], 58.3899, 11.0000);
	TextDrawAlignment(gui_AttachMenu[35], 1);
	TextDrawColor(gui_AttachMenu[35], 255);
	TextDrawBackgroundColor(gui_AttachMenu[35], 255);
	TextDrawFont(gui_AttachMenu[35], 4);
	TextDrawSetProportional(gui_AttachMenu[35], 0);
	TextDrawSetShadow(gui_AttachMenu[35], 0);

	gui_AttachMenu[36] = TextDrawCreate(474.3053, 402.3327, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[36], 56.7495, 9.2398);
	TextDrawAlignment(gui_AttachMenu[36], 1);
	TextDrawColor(gui_AttachMenu[36], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[36], 255);
	TextDrawFont(gui_AttachMenu[36], 4);
	TextDrawSetProportional(gui_AttachMenu[36], 0);
	TextDrawSetShadow(gui_AttachMenu[36], 0);

	gui_AttachMenu[37] = TextDrawCreate(522.2006, 401.8005, "ESC");
	TextDrawLetterSize(gui_AttachMenu[37], 0.1551, 1.0166);
	TextDrawTextSize(gui_AttachMenu[37], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[37], 2);
	TextDrawColor(gui_AttachMenu[37], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[37], 255);
	TextDrawFont(gui_AttachMenu[37], 2);
	TextDrawSetProportional(gui_AttachMenu[37], 1);
	TextDrawSetShadow(gui_AttachMenu[37], 0);

	gui_AttachMenu[38] = TextDrawCreate(164.4640, 401.9858, "Show_cursor_-");
	TextDrawLetterSize(gui_AttachMenu[38], 0.1211, 0.9268);
	TextDrawTextSize(gui_AttachMenu[38], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[38], 2);
	TextDrawColor(gui_AttachMenu[38], -1);
	TextDrawBackgroundColor(gui_AttachMenu[38], 255);
	TextDrawFont(gui_AttachMenu[38], 2);
	TextDrawSetProportional(gui_AttachMenu[38], 1);
	TextDrawSetShadow(gui_AttachMenu[38], 0);

	gui_AttachMenu[39] = TextDrawCreate(139.2321, 401.4151, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[39], 58.3899, 11.0000);
	TextDrawAlignment(gui_AttachMenu[39], 1);
	TextDrawColor(gui_AttachMenu[39], 255);
	TextDrawBackgroundColor(gui_AttachMenu[39], 255);
	TextDrawFont(gui_AttachMenu[39], 4);
	TextDrawSetProportional(gui_AttachMenu[39], 0);
	TextDrawSetShadow(gui_AttachMenu[39], 0);

	gui_AttachMenu[40] = TextDrawCreate(139.8986, 402.4179, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[40], 56.4496, 8.9799);
	TextDrawAlignment(gui_AttachMenu[40], 1);
	TextDrawColor(gui_AttachMenu[40], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[40], 255);
	TextDrawFont(gui_AttachMenu[40], 4);
	TextDrawSetProportional(gui_AttachMenu[40], 0);
	TextDrawSetShadow(gui_AttachMenu[40], 0);

	gui_AttachMenu[41] = TextDrawCreate(189.0973, 401.2005, "N");
	TextDrawLetterSize(gui_AttachMenu[41], 0.1764, 1.0607);
	TextDrawTextSize(gui_AttachMenu[41], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[41], 2);
	TextDrawColor(gui_AttachMenu[41], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[41], 255);
	TextDrawFont(gui_AttachMenu[41], 2);
	TextDrawSetProportional(gui_AttachMenu[41], 1);
	TextDrawSetShadow(gui_AttachMenu[41], 0);

	gui_AttachMenu[42] = TextDrawCreate(392.1875, 414.7182, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[42], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[42], 1);
	TextDrawColor(gui_AttachMenu[42], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[42], 255);
	TextDrawFont(gui_AttachMenu[42], 4);
	TextDrawSetProportional(gui_AttachMenu[42], 0);
	TextDrawSetShadow(gui_AttachMenu[42], 0);
	TextDrawSetSelectable(gui_AttachMenu[42], true);

	gui_AttachMenu[43] = TextDrawCreate(398.7546, 437.2296, "Color_1");
	TextDrawLetterSize(gui_AttachMenu[43], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[43], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[43], 1);
	TextDrawColor(gui_AttachMenu[43], -1);
	TextDrawBackgroundColor(gui_AttachMenu[43], 255);
	TextDrawFont(gui_AttachMenu[43], 1);
	TextDrawSetProportional(gui_AttachMenu[43], 1);
	TextDrawSetShadow(gui_AttachMenu[43], 0);

	gui_AttachMenu[44] = TextDrawCreate(420.2893, 414.7182, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[44], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[44], 1);
	TextDrawColor(gui_AttachMenu[44], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[44], 255);
	TextDrawFont(gui_AttachMenu[44], 4);
	TextDrawSetProportional(gui_AttachMenu[44], 0);
	TextDrawSetShadow(gui_AttachMenu[44], 0);
	TextDrawSetSelectable(gui_AttachMenu[44], true);

	gui_AttachMenu[45] = TextDrawCreate(397.0006, 420.6075, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[45], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[45], 1);
	TextDrawColor(gui_AttachMenu[45], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[45], 255);
	TextDrawFont(gui_AttachMenu[45], 4);
	TextDrawSetProportional(gui_AttachMenu[45], 0);
	TextDrawSetShadow(gui_AttachMenu[45], 0);

	gui_AttachMenu[46] = TextDrawCreate(403.0675, 419.4074, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[46], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[46], 1);
	TextDrawColor(gui_AttachMenu[46], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[46], 255);
	TextDrawFont(gui_AttachMenu[46], 4);
	TextDrawSetProportional(gui_AttachMenu[46], 0);
	TextDrawSetShadow(gui_AttachMenu[46], 0);

	gui_AttachMenu[47] = TextDrawCreate(429.3345, 419.4222, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[47], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[47], 1);
	TextDrawColor(gui_AttachMenu[47], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[47], 255);
	TextDrawFont(gui_AttachMenu[47], 4);
	TextDrawSetProportional(gui_AttachMenu[47], 0);
	TextDrawSetShadow(gui_AttachMenu[47], 0);

	gui_AttachMenu[48] = TextDrawCreate(423.8020, 421.1075, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[48], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[48], 1);
	TextDrawColor(gui_AttachMenu[48], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[48], 255);
	TextDrawFont(gui_AttachMenu[48], 4);
	TextDrawSetProportional(gui_AttachMenu[48], 0);
	TextDrawSetShadow(gui_AttachMenu[48], 0);

	gui_AttachMenu[49] = TextDrawCreate(426.0898, 437.2296, "Color_2");
	TextDrawLetterSize(gui_AttachMenu[49], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[49], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[49], 1);
	TextDrawColor(gui_AttachMenu[49], -1);
	TextDrawBackgroundColor(gui_AttachMenu[49], 255);
	TextDrawFont(gui_AttachMenu[49], 1);
	TextDrawSetProportional(gui_AttachMenu[49], 1);
	TextDrawSetShadow(gui_AttachMenu[49], 0);

	gui_AttachMenu[50] = TextDrawCreate(370.2025, 418.0335, "<__>");
	TextDrawLetterSize(gui_AttachMenu[50], 0.2806, 1.7632);
	TextDrawAlignment(gui_AttachMenu[50], 1);
	TextDrawColor(gui_AttachMenu[50], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[50], 255);
	TextDrawFont(gui_AttachMenu[50], 1);
	TextDrawSetProportional(gui_AttachMenu[50], 1);
	TextDrawSetShadow(gui_AttachMenu[50], 0);

	gui_AttachMenu[51] = TextDrawCreate(308.2654, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[51], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[51], 1);
	TextDrawColor(gui_AttachMenu[51], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[51], 255);
	TextDrawFont(gui_AttachMenu[51], 4);
	TextDrawSetProportional(gui_AttachMenu[51], 0);
	TextDrawSetShadow(gui_AttachMenu[51], 0);
	TextDrawSetSelectable(gui_AttachMenu[51], true);

	gui_AttachMenu[52] = TextDrawCreate(317.5143, 418.4515, "#");
	TextDrawLetterSize(gui_AttachMenu[52], 0.4611, 1.9076);
	TextDrawAlignment(gui_AttachMenu[52], 1);
	TextDrawColor(gui_AttachMenu[52], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[52], 255);
	TextDrawFont(gui_AttachMenu[52], 1);
	TextDrawSetProportional(gui_AttachMenu[52], 1);
	TextDrawSetShadow(gui_AttachMenu[52], 0);

	gui_AttachMenu[53] = TextDrawCreate(315.4218, 437.2296, "Bone");
	TextDrawLetterSize(gui_AttachMenu[53], 0.1685, 0.8284);
	TextDrawTextSize(gui_AttachMenu[53], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[53], 1);
	TextDrawColor(gui_AttachMenu[53], -1);
	TextDrawBackgroundColor(gui_AttachMenu[53], 255);
	TextDrawFont(gui_AttachMenu[53], 1);
	TextDrawSetProportional(gui_AttachMenu[53], 1);
	TextDrawSetShadow(gui_AttachMenu[53], 0);

	gui_AttachMenu[54] = TextDrawCreate(336.0321, 414.5479, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[54], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[54], 1);
	TextDrawColor(gui_AttachMenu[54], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[54], 255);
	TextDrawFont(gui_AttachMenu[54], 4);
	TextDrawSetProportional(gui_AttachMenu[54], 0);
	TextDrawSetShadow(gui_AttachMenu[54], 0);
	TextDrawSetSelectable(gui_AttachMenu[54], true);

	gui_AttachMenu[55] = TextDrawCreate(343.3341, 416.6036, "/");
	TextDrawLetterSize(gui_AttachMenu[55], 0.4458, 2.0225);
	TextDrawAlignment(gui_AttachMenu[55], 1);
	TextDrawColor(gui_AttachMenu[55], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[55], 255);
	TextDrawFont(gui_AttachMenu[55], 2);
	TextDrawSetProportional(gui_AttachMenu[55], 1);
	TextDrawSetShadow(gui_AttachMenu[55], 0);

	gui_AttachMenu[56] = TextDrawCreate(356.6347, 416.6184, "/");
	TextDrawLetterSize(gui_AttachMenu[56], -0.4810, 2.0834);
	TextDrawAlignment(gui_AttachMenu[56], 1);
	TextDrawColor(gui_AttachMenu[56], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[56], 255);
	TextDrawFont(gui_AttachMenu[56], 2);
	TextDrawSetProportional(gui_AttachMenu[56], 1);
	TextDrawSetShadow(gui_AttachMenu[56], 0);

	gui_AttachMenu[57] = TextDrawCreate(338.4230, 437.2296, "Symmetry");
	TextDrawLetterSize(gui_AttachMenu[57], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[57], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[57], 1);
	TextDrawColor(gui_AttachMenu[57], -1);
	TextDrawBackgroundColor(gui_AttachMenu[57], 255);
	TextDrawFont(gui_AttachMenu[57], 1);
	TextDrawSetProportional(gui_AttachMenu[57], 1);
	TextDrawSetShadow(gui_AttachMenu[57], 0);

	gui_AttachMenu[58] = TextDrawCreate(573.6815, 414.1181, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[58], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[58], 1);
	TextDrawColor(gui_AttachMenu[58], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[58], 255);
	TextDrawFont(gui_AttachMenu[58], 4);
	TextDrawSetProportional(gui_AttachMenu[58], 0);
	TextDrawSetShadow(gui_AttachMenu[58], 0);
	TextDrawSetSelectable(gui_AttachMenu[58], true);

	gui_AttachMenu[59] = TextDrawCreate(601.8468, 414.5331, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[59], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[59], 1);
	TextDrawColor(gui_AttachMenu[59], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[59], 255);
	TextDrawFont(gui_AttachMenu[59], 4);
	TextDrawSetProportional(gui_AttachMenu[59], 0);
	TextDrawSetShadow(gui_AttachMenu[59], 0);
	TextDrawSetSelectable(gui_AttachMenu[59], true);

	gui_AttachMenu[60] = TextDrawCreate(582.1055, 415.5295, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[60], 10.5200, 12.7199);
	TextDrawAlignment(gui_AttachMenu[60], 1);
	TextDrawColor(gui_AttachMenu[60], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[60], 255);
	TextDrawFont(gui_AttachMenu[60], 4);
	TextDrawSetProportional(gui_AttachMenu[60], 0);
	TextDrawSetShadow(gui_AttachMenu[60], 0);

	gui_AttachMenu[61] = TextDrawCreate(577.4735, 425.4851, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[61], 20.1200, 7.0000);
	TextDrawAlignment(gui_AttachMenu[61], 1);
	TextDrawColor(gui_AttachMenu[61], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[61], 255);
	TextDrawFont(gui_AttachMenu[61], 4);
	TextDrawSetProportional(gui_AttachMenu[61], 0);
	TextDrawSetShadow(gui_AttachMenu[61], 0);

	gui_AttachMenu[62] = TextDrawCreate(582.7097, 437.2296, "Skin");
	TextDrawLetterSize(gui_AttachMenu[62], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[62], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[62], 1);
	TextDrawColor(gui_AttachMenu[62], -1);
	TextDrawBackgroundColor(gui_AttachMenu[62], 255);
	TextDrawFont(gui_AttachMenu[62], 1);
	TextDrawSetProportional(gui_AttachMenu[62], 1);
	TextDrawSetShadow(gui_AttachMenu[62], 0);

	gui_AttachMenu[63] = TextDrawCreate(555.6605, 418.5108, "<");
	TextDrawLetterSize(gui_AttachMenu[63], 0.3445, 1.7036);
	TextDrawAlignment(gui_AttachMenu[63], 1);
	TextDrawColor(gui_AttachMenu[63], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[63], 255);
	TextDrawFont(gui_AttachMenu[63], 3);
	TextDrawSetProportional(gui_AttachMenu[63], 1);
	TextDrawSetShadow(gui_AttachMenu[63], 0);

	gui_AttachMenu[64] = TextDrawCreate(612.5604, 418.8255, ">");
	TextDrawLetterSize(gui_AttachMenu[64], 0.3445, 1.7036);
	TextDrawAlignment(gui_AttachMenu[64], 1);
	TextDrawColor(gui_AttachMenu[64], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[64], 255);
	TextDrawFont(gui_AttachMenu[64], 3);
	TextDrawSetProportional(gui_AttachMenu[64], 1);
	TextDrawSetShadow(gui_AttachMenu[64], 0);

	gui_AttachMenu[65] = TextDrawCreate(547.8184, 437.2296, "Prev_skin");
	TextDrawLetterSize(gui_AttachMenu[65], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[65], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[65], 1);
	TextDrawColor(gui_AttachMenu[65], -1);
	TextDrawBackgroundColor(gui_AttachMenu[65], 255);
	TextDrawFont(gui_AttachMenu[65], 1);
	TextDrawSetProportional(gui_AttachMenu[65], 1);
	TextDrawSetShadow(gui_AttachMenu[65], 0);

	gui_AttachMenu[66] = TextDrawCreate(604.3046, 437.2296, "Next_skin");
	TextDrawLetterSize(gui_AttachMenu[66], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[66], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[66], 1);
	TextDrawColor(gui_AttachMenu[66], -1);
	TextDrawBackgroundColor(gui_AttachMenu[66], 255);
	TextDrawFont(gui_AttachMenu[66], 1);
	TextDrawSetProportional(gui_AttachMenu[66], 1);
	TextDrawSetShadow(gui_AttachMenu[66], 0);

	gui_AttachMenu[67] = TextDrawCreate(448.1661, 414.7628, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[67], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[67], 1);
	TextDrawColor(gui_AttachMenu[67], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[67], 255);
	TextDrawFont(gui_AttachMenu[67], 4);
	TextDrawSetProportional(gui_AttachMenu[67], 0);
	TextDrawSetShadow(gui_AttachMenu[67], 0);
	TextDrawSetSelectable(gui_AttachMenu[67], true);

	gui_AttachMenu[68] = TextDrawCreate(454.6667, 418.6484, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[68], 14.0000, 16.0000);
	TextDrawAlignment(gui_AttachMenu[68], 1);
	TextDrawColor(gui_AttachMenu[68], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[68], 255);
	TextDrawFont(gui_AttachMenu[68], 4);
	TextDrawSetProportional(gui_AttachMenu[68], 0);
	TextDrawSetShadow(gui_AttachMenu[68], 0);

	gui_AttachMenu[69] = TextDrawCreate(450.0999, 420.8927, "<____>");
	TextDrawLetterSize(gui_AttachMenu[69], 0.3123, 1.2764);
	TextDrawAlignment(gui_AttachMenu[69], 1);
	TextDrawColor(gui_AttachMenu[69], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[69], 255);
	TextDrawFont(gui_AttachMenu[69], 1);
	TextDrawSetProportional(gui_AttachMenu[69], 1);
	TextDrawSetShadow(gui_AttachMenu[69], 0);

	gui_AttachMenu[70] = TextDrawCreate(449.2512, 437.2296, "Camera_Move");
	TextDrawLetterSize(gui_AttachMenu[70], 0.1202, 0.7901);
	TextDrawTextSize(gui_AttachMenu[70], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[70], 1);
	TextDrawColor(gui_AttachMenu[70], -1);
	TextDrawBackgroundColor(gui_AttachMenu[70], 255);
	TextDrawFont(gui_AttachMenu[70], 1);
	TextDrawSetProportional(gui_AttachMenu[70], 1);
	TextDrawSetShadow(gui_AttachMenu[70], 0);

#if defined guiatachmenu_OnGameModeInit
	return guiatachmenu_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit guiatachmenu_OnGameModeInit
#if defined    guiatachmenu_OnGameModeInit
	forward guiatachmenu_OnGameModeInit();
#endif

public OnPlayerDisconnect(playerid, reason)
{
	gui_atatch_menu_HideMenu(playerid);
	gui_AttachMenuActivePanel[playerid] = false;
#if defined guiatachmenu_OnPlayerDisconnect
	return guiatachmenu_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guiatachmenu_OnPlayerDisconnect
#if defined    guiatachmenu_OnPlayerDisconnect
	forward guiatachmenu_OnPlayerDisconnect(playerid, reason);
#endif


public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (gui_atatch_menu_IsShow(playerid))
	{
		if (clickedid == Text: INVALID_TEXT_DRAW)
		{
			gui_atatch_menu_HideCursor(playerid);
			SetCameraBehindPlayer(playerid);
			gui_camera_rot_HideInfo(playerid);
		}
		if (!Dialog_IsOpen(playerid)
			&& !gui_ath_obj_IsPlayerCreateTD(playerid)
			&& !gui_atatch_menu_IsBannedPanel(playerid))
		{
			const INDEX_TD_ID = 0;
			const INDEX_TYPE_ID = 1;

			static const index[][] =
			{
				{1, 	GUI_ATTACH_MENU_MANAGE},
				{6, 	GUI_ATTACH_MENU_EXPORT},
				{9,		GUI_ATTACH_MENU_NEW},
				{12,	GUI_ATTACH_MENU_DELETE},
				{15,	GUI_ATTACH_MENU_DUBLICATE},
				{19,	GUI_ATTACH_MENU_OBJECT},
				{51,	GUI_ATTACH_MENU_BONE},
				{54,	GUI_ATTACH_MENU_SYMMETRY},
				{25,	GUI_ATTACH_MENU_EDIT},
				{42,	GUI_ATTACH_MENU_COLOR_1},
				{44,	GUI_ATTACH_MENU_COLOR_2},
				{28,	GUI_ATTACH_MENU_ANIMATIONS},
				{31,	GUI_ATTACH_MENU_ANIMATION_CLEAR},
				{27,	GUI_ATTACH_MENU_PREV_SKIN},
				{58,	GUI_ATTACH_MENU_SKIN},
				{59,	GUI_ATTACH_MENU_NEXT_SKIN},
				{67,	GUI_ATTACH_MENU_CAMERA_MOVE}
			};
			new typeid;

			for (new i, cellid; i < sizeof(index); i++)
			{
				cellid = index[i][INDEX_TD_ID];

				if (clickedid == gui_AttachMenu[cellid])
				{
					typeid = index[i][INDEX_TYPE_ID];

					if (attachmain_IsUseMultiObject(playerid))
					{
						if (typeid != GUI_ATTACH_MENU_MANAGE
							&& typeid != GUI_ATTACH_MENU_EXPORT
							&& typeid != GUI_ATTACH_MENU_EDIT
							&& typeid != GUI_ATTACH_MENU_DELETE
							&& typeid != GUI_ATTACH_MENU_PREV_SKIN
							&& typeid != GUI_ATTACH_MENU_SKIN
							&& typeid != GUI_ATTACH_MENU_NEXT_SKIN)
						{

							language_MessageError(playerid, MSG_NO_AVAILABLE_MULTIPLE_OBJ);
							return 0;
						}
					}
					CallRemoteFunction(
						"OnGuiAttachMenuClicked",
						"dd",
						playerid,
						typeid
					);
					return 1;
				}
			}
			return 1;
		}
	}
#if defined guiatachmenu_OnClickTextDraw
	return guiatachmenu_OnClickTextDraw(playerid, Text:clickedid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw guiatachmenu_OnClickTextDraw
#if defined    guiatachmenu_OnClickTextDraw
	forward guiatachmenu_OnClickTextDraw(playerid, Text:clickedid);
#endif


stock gui_atatch_menu_ShowMenu(playerid)
{
	if (gui_atatch_menu_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachMenu); i++)
	{
		TextDrawShowForPlayer(playerid, gui_AttachMenu[i]);
	}
	gui_AttachMenuPlayerShow[playerid] = true;
	return 1;
}

stock gui_atatch_menu_HideMenu(playerid)
{
	if (!gui_atatch_menu_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachMenu); i++)
	{
		TextDrawHideForPlayer(playerid, gui_AttachMenu[i]);
	}
	gui_AttachMenuPlayerShow[playerid] = false;
	return 1;
}

stock gui_atatch_menu_IsShow(playerid)
{
	return gui_AttachMenuPlayerShow[playerid];
}

stock gui_atatch_menu_ShowCursor(playerid)
{
	SelectTextDraw(playerid, COLOR_TD_CLICK);
	gui_AttachMenuActivePanel[playerid] = true;
	return 1;
}

stock gui_atatch_menu_HideCursor(playerid)
{
	gui_AttachMenuActivePanel[playerid] = false;
	return 1;
}

stock gui_atatch_menu_IsActivePanel(playerid)
{
	return gui_AttachMenuActivePanel[playerid];
}

stock gui_atatch_menu_IsBannedPanel(playerid)
{
	return gui_AttachMenuBannedPanel[playerid];
}

stock gui_atatch_menu_SetBannedPanel(playerid, bool: value)
{
	gui_AttachMenuBannedPanel[playerid] = value;
	return 1;
}
