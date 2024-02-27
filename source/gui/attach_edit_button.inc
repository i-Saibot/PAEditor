#if defined _gui_attach_edit_button_inc
	#endinput
#endif
#define _gui_attach_edit_button_inc


static PlayerText:gui_AttachEditButton[MAX_PLAYERS][22];
static bool: gui_AttachEditPlayerCreate[MAX_PLAYERS];


public OnPlayerDisconnect(playerid, reason)
{
	gui_ath_edit_DestroyTextdraws(playerid);
#if defined guiaedt_OnPlayerDisconnect
	return guiaedt_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guiaedt_OnPlayerDisconnect
#if defined    guiaedt_OnPlayerDisconnect
	forward guiaedt_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerSpawn(playerid)
{
	gui_ath_edit_DestroyTextdraws(playerid);
#if defined guiaedt_OnPlayerSpawn
	return guiaedt_OnPlayerSpawn(playerid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn guiaedt_OnPlayerSpawn
#if defined    guiaedt_OnPlayerSpawn
	forward guiaedt_OnPlayerSpawn(playerid);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (gui_ath_edit_IsPlayerCreateTD(playerid))
	{
		if (clickedid == Text: INVALID_TEXT_DRAW)
		{
			gui_ath_edit_DestroyTextdraws(playerid);
			attacheditbtn_PressCancel(playerid);
			gui_atatch_menu_ShowCursor(playerid);
		}
	}
#if defined guiaedt_OnClickTextDraw
	return guiaedt_OnClickTextDraw(playerid, Text:clickedid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw guiaedt_OnClickTextDraw
#if defined    guiaedt_OnClickTextDraw
	forward guiaedt_OnClickTextDraw(playerid, Text:clickedid);
#endif


public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (gui_ath_edit_IsPlayerCreateTD(playerid))
	{
		if (Dialog_IsOpen(playerid))
		{
			return 0;
		}
		new PlayerText: textdraw_save	= gui_AttachEditButton[playerid][7];
		new PlayerText: textdraw_cancel	= gui_AttachEditButton[playerid][8];
		
		if (playertextid == textdraw_save)
		{
			attacheditbtn_PressSave(playerid);
			return 1;
		}
		else if (playertextid == textdraw_cancel)
		{
			attacheditbtn_PressCancel(playerid);
			return 1;
		}
		return 1;
	}
#if defined guiaedt_OnPlayerClickPTD
	return guiaedt_OnPlayerClickPTD(playerid, playertextid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif
#define OnPlayerClickPlayerTextDraw guiaedt_OnPlayerClickPTD
#if defined    guiaedt_OnPlayerClickPTD
	forward guiaedt_OnPlayerClickPTD(playerid, PlayerText:playertextid);
#endif


stock gui_ath_edit_CreateTextdraws(playerid)
{
	if (gui_ath_edit_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	gui_AttachEditButton[playerid][0] = CreatePlayerTextDraw(playerid, 549.1328, 299.2843, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][0], 63.0000, 11.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][0], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][0], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][0], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][0], 0);

	gui_AttachEditButton[playerid][1] = CreatePlayerTextDraw(playerid, 553.2321, 245.7324, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][1], 53.6500, 11.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][1], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][1], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][1], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][1], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][1], 0);

	gui_AttachEditButton[playerid][2] = CreatePlayerTextDraw(playerid, 581.2017, 246.1885, "Press_Button");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][2], 0.1450, 0.8572);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][2], 2);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][2], 950371583);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][2], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][2], 2);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][2], 0);

	gui_AttachEditButton[playerid][3] = CreatePlayerTextDraw(playerid, 546.8317, 243.2442, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][3], 12.0000, 16.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][3], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][3], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][3], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][3], 0);

	gui_AttachEditButton[playerid][4] = CreatePlayerTextDraw(playerid, 543.6657, 296.6961, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][4], 12.0000, 16.4500);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][4], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][4], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][4], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][4], 0);

	gui_AttachEditButton[playerid][5] = CreatePlayerTextDraw(playerid, 605.8322, 296.6961, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][5], 12.0000, 16.4500);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][5], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][5], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][5], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][5], 0);

	gui_AttachEditButton[playerid][6] = CreatePlayerTextDraw(playerid, 578.3331, 296.2072, "/");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][6], 0.4000, 1.7099);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][6], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][6], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][6], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][6], 0);

	gui_AttachEditButton[playerid][7] = CreatePlayerTextDraw(playerid, 564.1978, 300.0963, "SAVE");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][7], 0.1613, 0.8450);
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][7], 7.0000, 24.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][7], 2);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][7], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][7], 2);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][7], 0);
	PlayerTextDrawSetSelectable(playerid, gui_AttachEditButton[playerid][7], true);

	gui_AttachEditButton[playerid][8] = CreatePlayerTextDraw(playerid, 599.1300, 300.2962, "CANCEL");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][8], 0.1613, 0.8450);
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][8], 7.0000, 30.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][8], 2);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][8], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][8], 2);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][8], 0);
	PlayerTextDrawSetSelectable(playerid, gui_AttachEditButton[playerid][8], true);

	gui_AttachEditButton[playerid][9] = CreatePlayerTextDraw(playerid, 601.4334, 243.1439, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][9], 12.0000, 15.9898);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][9], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][9], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][9], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][9], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][9], 0);

	gui_AttachEditButton[playerid][10] = CreatePlayerTextDraw(playerid, 572.7661, 278.5397, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][10], 16.0000, 18.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][10], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][10], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][10], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][10], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][10], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][10], 0);

	gui_AttachEditButton[playerid][11] = CreatePlayerTextDraw(playerid, 572.8330, 259.9580, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][11], 16.0000, 18.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][11], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][11], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][11], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][11], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][11], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][11], 0);

	gui_AttachEditButton[playerid][12] = CreatePlayerTextDraw(playerid, 556.4326, 278.5544, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][12], 16.0000, 18.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][12], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][12], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][12], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][12], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][12], 0);

	gui_AttachEditButton[playerid][13] = CreatePlayerTextDraw(playerid, 589.1986, 278.5544, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][13], 16.0000, 18.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][13], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][13], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][13], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][13], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][13], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][13], 0);

	gui_AttachEditButton[playerid][14] = CreatePlayerTextDraw(playerid, 556.6336, 259.7434, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][14], 16.0000, 18.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][14], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][14], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][14], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][14], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][14], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][14], 0);

	gui_AttachEditButton[playerid][15] = CreatePlayerTextDraw(playerid, 589.0291, 259.9580, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachEditButton[playerid][15], 16.0000, 18.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][15], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][15], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][15], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][15], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][15], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][15], 0);

	gui_AttachEditButton[playerid][16] = CreatePlayerTextDraw(playerid, 576.6032, 262.6705, "W");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][16], 0.2921, 1.2100);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][16], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][16], COLOR_GREY);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][16], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][16], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][16], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][16], 0);

	gui_AttachEditButton[playerid][17] = CreatePlayerTextDraw(playerid, 578.7025, 281.1076, "S");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][17], 0.2921, 1.2100);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][17], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][17], COLOR_GREY);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][17], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][17], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][17], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][17], 0);

	gui_AttachEditButton[playerid][18] = CreatePlayerTextDraw(playerid, 561.5368, 281.0223, "A");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][18], 0.2921, 1.2100);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][18], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][18], COLOR_GREY);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][18], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][18], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][18], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][18], 0);

	gui_AttachEditButton[playerid][19] = CreatePlayerTextDraw(playerid, 594.3988, 281.1076, "D");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][19], 0.2921, 1.2100);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][19], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][19], COLOR_GREY);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][19], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][19], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][19], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][19], 0);

	gui_AttachEditButton[playerid][20] = CreatePlayerTextDraw(playerid, 561.0324, 262.5262, "Q");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][20], 0.2921, 1.2100);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][20], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][20], COLOR_GREY);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][20], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][20], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][20], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][20], 0);

	gui_AttachEditButton[playerid][21] = CreatePlayerTextDraw(playerid, 594.9652, 262.5262, "E");
	PlayerTextDrawLetterSize(playerid, gui_AttachEditButton[playerid][21], 0.2921, 1.2100);
	PlayerTextDrawAlignment(playerid, gui_AttachEditButton[playerid][21], 1);
	PlayerTextDrawColor(playerid, gui_AttachEditButton[playerid][21], COLOR_GREY);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachEditButton[playerid][21], 255);
	PlayerTextDrawFont(playerid, gui_AttachEditButton[playerid][21], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachEditButton[playerid][21], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachEditButton[playerid][21], 0);

	gui_AttachEditPlayerCreate[playerid] = true;
	return 1;
}

stock gui_ath_edit_IsPlayerCreateTD(playerid)
{
	return gui_AttachEditPlayerCreate[playerid];
}

stock gui_ath_edit_ShowTextdraws(playerid)
{
	if (!gui_ath_edit_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachEditButton[]); i++)
	{
		PlayerTextDrawShow(
			playerid,
			gui_AttachEditButton[playerid][i]
		);
	}
	SelectTextDraw(playerid, COLOR_TD_CLICK);
	return 1;
}

stock gui_ath_edit_SetClorPressBtn(playerid, color, key_vk)
{
	if (!gui_ath_edit_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	const
		TD_BUTTON_W			= 16,
		TD_BUTTON_S			= 17,
		TD_BUTTON_A			= 18,
		TD_BUTTON_D			= 19,
		TD_BUTTON_Q			= 20,
		TD_BUTTON_E			= 21;

	new index;

	switch (key_vk)
	{
		case VK_KEY_W: index = TD_BUTTON_W;
		case VK_KEY_S: index = TD_BUTTON_S;
		case VK_KEY_A: index = TD_BUTTON_A;
		case VK_KEY_D: index = TD_BUTTON_D;
		case VK_KEY_Q: index = TD_BUTTON_Q;
		case VK_KEY_E: index = TD_BUTTON_E;
	}
	PlayerTextDrawColor(
		playerid,
		gui_AttachEditButton[playerid][index],
		color
	);
	PlayerTextDrawShow(
		playerid,
		gui_AttachEditButton[playerid][index]
	);
	return 1;
}


stock gui_ath_edit_DestroyTextdraws(playerid)
{
	if (!gui_ath_edit_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachEditButton[]); i++)
	{
		PlayerTextDrawDestroy(
			playerid,
			gui_AttachEditButton[playerid][i]
		);
	}
	gui_AttachEditPlayerCreate[playerid] = false;
	return 1;
}