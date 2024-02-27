#if defined _gui_attach_symmetry_inc
	#endinput
#endif
#define _gui_attach_symmetry_inc


enum
{
	GUI_ATTACH_SYMMETRY_TYPE_X,
	GUI_ATTACH_SYMMETRY_TYPE_Y,
	GUI_ATTACH_SYMMETRY_TYPE_Z,
	GUI_ATTACH_SYMMETRY_TYPE_R,
	GUI_ATTACH_SYMMETRY_TYPE_XY,
	GUI_ATTACH_SYMMETRY_TYPE_YZ,
	GUI_ATTACH_SYMMETRY_TYPE_ZX
}


static Text: gui_AttachSymmetry[17];
static bool: gui_AttachSymmetryShowTD[MAX_PLAYERS];

public OnGameModeInit()
{
	gui_AttachSymmetry[0] = TextDrawCreate(424.9344, 237.7224, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachSymmetry[0], 100.8301, 28.8300);
	TextDrawAlignment(gui_AttachSymmetry[0], 1);
	TextDrawColor(gui_AttachSymmetry[0], 370480895);
	TextDrawBackgroundColor(gui_AttachSymmetry[0], 255);
	TextDrawFont(gui_AttachSymmetry[0], 4);
	TextDrawSetProportional(gui_AttachSymmetry[0], 0);
	TextDrawSetShadow(gui_AttachSymmetry[0], 0);

	gui_AttachSymmetry[1] = TextDrawCreate(425.5010, 239.2962, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachSymmetry[1], 99.5501, 26.0000);
	TextDrawAlignment(gui_AttachSymmetry[1], 1);
	TextDrawColor(gui_AttachSymmetry[1], 606151167);
	TextDrawBackgroundColor(gui_AttachSymmetry[1], 255);
	TextDrawFont(gui_AttachSymmetry[1], 4);
	TextDrawSetProportional(gui_AttachSymmetry[1], 0);
	TextDrawSetShadow(gui_AttachSymmetry[1], 0);

	gui_AttachSymmetry[2] = TextDrawCreate(432.3006, 248.8773, "X");
	TextDrawLetterSize(gui_AttachSymmetry[2], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[2], 11.0000, 6.0000);
	TextDrawAlignment(gui_AttachSymmetry[2], 2);
	TextDrawColor(gui_AttachSymmetry[2], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[2], 255);
	TextDrawFont(gui_AttachSymmetry[2], 2);
	TextDrawSetProportional(gui_AttachSymmetry[2], 1);
	TextDrawSetShadow(gui_AttachSymmetry[2], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[2], true);

	gui_AttachSymmetry[3] = TextDrawCreate(443.8013, 248.8773, "Y");
	TextDrawLetterSize(gui_AttachSymmetry[3], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[3], 11.0000, 6.0000);
	TextDrawAlignment(gui_AttachSymmetry[3], 2);
	TextDrawColor(gui_AttachSymmetry[3], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[3], 255);
	TextDrawFont(gui_AttachSymmetry[3], 2);
	TextDrawSetProportional(gui_AttachSymmetry[3], 1);
	TextDrawSetShadow(gui_AttachSymmetry[3], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[3], true);

	gui_AttachSymmetry[4] = TextDrawCreate(455.3687, 248.8773, "Z");
	TextDrawLetterSize(gui_AttachSymmetry[4], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[4], 11.0000, 6.0000);
	TextDrawAlignment(gui_AttachSymmetry[4], 2);
	TextDrawColor(gui_AttachSymmetry[4], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[4], 255);
	TextDrawFont(gui_AttachSymmetry[4], 2);
	TextDrawSetProportional(gui_AttachSymmetry[4], 1);
	TextDrawSetShadow(gui_AttachSymmetry[4], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[4], true);

	gui_AttachSymmetry[5] = TextDrawCreate(466.9694, 248.8773, "R");
	TextDrawLetterSize(gui_AttachSymmetry[5], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[5], 11.0000, 6.0000);
	TextDrawAlignment(gui_AttachSymmetry[5], 2);
	TextDrawColor(gui_AttachSymmetry[5], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[5], 255);
	TextDrawFont(gui_AttachSymmetry[5], 2);
	TextDrawSetProportional(gui_AttachSymmetry[5], 1);
	TextDrawSetShadow(gui_AttachSymmetry[5], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[5], true);

	gui_AttachSymmetry[6] = TextDrawCreate(481.2703, 248.8773, "XY");
	TextDrawLetterSize(gui_AttachSymmetry[6], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[6], 11.0000, 11.0000);
	TextDrawAlignment(gui_AttachSymmetry[6], 2);
	TextDrawColor(gui_AttachSymmetry[6], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[6], 255);
	TextDrawFont(gui_AttachSymmetry[6], 2);
	TextDrawSetProportional(gui_AttachSymmetry[6], 1);
	TextDrawSetShadow(gui_AttachSymmetry[6], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[6], true);

	gui_AttachSymmetry[7] = TextDrawCreate(499.2714, 248.8773, "YZ");
	TextDrawLetterSize(gui_AttachSymmetry[7], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[7], 11.0000, 11.0000);
	TextDrawAlignment(gui_AttachSymmetry[7], 2);
	TextDrawColor(gui_AttachSymmetry[7], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[7], 255);
	TextDrawFont(gui_AttachSymmetry[7], 2);
	TextDrawSetProportional(gui_AttachSymmetry[7], 1);
	TextDrawSetShadow(gui_AttachSymmetry[7], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[7], true);

	gui_AttachSymmetry[8] = TextDrawCreate(516.2719, 248.8773, "ZX");
	TextDrawLetterSize(gui_AttachSymmetry[8], 0.2442, 1.5003);
	TextDrawTextSize(gui_AttachSymmetry[8], 11.0000, 11.0000);
	TextDrawAlignment(gui_AttachSymmetry[8], 2);
	TextDrawColor(gui_AttachSymmetry[8], COLOR_WHITE);
	TextDrawBackgroundColor(gui_AttachSymmetry[8], 255);
	TextDrawFont(gui_AttachSymmetry[8], 2);
	TextDrawSetProportional(gui_AttachSymmetry[8], 1);
	TextDrawSetShadow(gui_AttachSymmetry[8], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[8], true);

	gui_AttachSymmetry[9] = TextDrawCreate(451.2669, 237.4369, "Select_Type");
	TextDrawLetterSize(gui_AttachSymmetry[9], 0.1746, 1.0026);
	TextDrawAlignment(gui_AttachSymmetry[9], 1);
	TextDrawColor(gui_AttachSymmetry[9], 950371583);
	TextDrawBackgroundColor(gui_AttachSymmetry[9], 255);
	TextDrawFont(gui_AttachSymmetry[9], 2);
	TextDrawSetProportional(gui_AttachSymmetry[9], 1);
	TextDrawSetShadow(gui_AttachSymmetry[9], 0);

	gui_AttachSymmetry[10] = TextDrawCreate(418.9668, 249.2992, "particle:lamp_shad_64");
	TextDrawTextSize(gui_AttachSymmetry[10], 120.0000, -11.0000);
	TextDrawAlignment(gui_AttachSymmetry[10], 1);
	TextDrawColor(gui_AttachSymmetry[10], 950371365);
	TextDrawBackgroundColor(gui_AttachSymmetry[10], 255);
	TextDrawFont(gui_AttachSymmetry[10], 4);
	TextDrawSetProportional(gui_AttachSymmetry[10], 0);
	TextDrawSetShadow(gui_AttachSymmetry[10], 0);

	gui_AttachSymmetry[11] = TextDrawCreate(448.0332, 267.8294, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachSymmetry[11], 53.0000, 12.0000);
	TextDrawAlignment(gui_AttachSymmetry[11], 1);
	TextDrawColor(gui_AttachSymmetry[11], 370480895);
	TextDrawBackgroundColor(gui_AttachSymmetry[11], 255);
	TextDrawFont(gui_AttachSymmetry[11], 4);
	TextDrawSetProportional(gui_AttachSymmetry[11], 0);
	TextDrawSetShadow(gui_AttachSymmetry[11], 0);

	gui_AttachSymmetry[12] = TextDrawCreate(441.7668, 265.0407, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachSymmetry[12], 13.0000, 17.5699);
	TextDrawAlignment(gui_AttachSymmetry[12], 1);
	TextDrawColor(gui_AttachSymmetry[12], 370480895);
	TextDrawBackgroundColor(gui_AttachSymmetry[12], 255);
	TextDrawFont(gui_AttachSymmetry[12], 4);
	TextDrawSetProportional(gui_AttachSymmetry[12], 0);
	TextDrawSetShadow(gui_AttachSymmetry[12], 0);

	gui_AttachSymmetry[13] = TextDrawCreate(495.1668, 265.0260, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachSymmetry[13], 13.0000, 17.5699);
	TextDrawAlignment(gui_AttachSymmetry[13], 1);
	TextDrawColor(gui_AttachSymmetry[13], 370480895);
	TextDrawBackgroundColor(gui_AttachSymmetry[13], 255);
	TextDrawFont(gui_AttachSymmetry[13], 4);
	TextDrawSetProportional(gui_AttachSymmetry[13], 0);
	TextDrawSetShadow(gui_AttachSymmetry[13], 0);

	gui_AttachSymmetry[14] = TextDrawCreate(459.1340, 268.9148, "Save");
	TextDrawLetterSize(gui_AttachSymmetry[14], 0.1486, 0.8325);
	TextDrawTextSize(gui_AttachSymmetry[14], 7.0000, 24.0000);
	TextDrawAlignment(gui_AttachSymmetry[14], 2);
	TextDrawColor(gui_AttachSymmetry[14], -1);
	TextDrawBackgroundColor(gui_AttachSymmetry[14], 255);
	TextDrawFont(gui_AttachSymmetry[14], 2);
	TextDrawSetProportional(gui_AttachSymmetry[14], 1);
	TextDrawSetShadow(gui_AttachSymmetry[14], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[14], true);

	gui_AttachSymmetry[15] = TextDrawCreate(490.0358, 269.1148, "Cancel");
	TextDrawLetterSize(gui_AttachSymmetry[15], 0.1486, 0.8325);
	TextDrawTextSize(gui_AttachSymmetry[15], 7.0000, 28.0000);
	TextDrawAlignment(gui_AttachSymmetry[15], 2);
	TextDrawColor(gui_AttachSymmetry[15], -1);
	TextDrawBackgroundColor(gui_AttachSymmetry[15], 255);
	TextDrawFont(gui_AttachSymmetry[15], 2);
	TextDrawSetProportional(gui_AttachSymmetry[15], 1);
	TextDrawSetShadow(gui_AttachSymmetry[15], 0);
	TextDrawSetSelectable(gui_AttachSymmetry[15], true);

	gui_AttachSymmetry[16] = TextDrawCreate(471.7999, 264.3666, "/");
	TextDrawLetterSize(gui_AttachSymmetry[16], 0.3926, 1.8157);
	TextDrawAlignment(gui_AttachSymmetry[16], 1);
	TextDrawColor(gui_AttachSymmetry[16], 606151167);
	TextDrawBackgroundColor(gui_AttachSymmetry[16], 255);
	TextDrawFont(gui_AttachSymmetry[16], 1);
	TextDrawSetProportional(gui_AttachSymmetry[16], 1);
	TextDrawSetShadow(gui_AttachSymmetry[16], 0);
#if defined guiatachstmm_OnGameModeInit
	return guiatachstmm_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit guiatachstmm_OnGameModeInit
#if defined    guiatachstmm_OnGameModeInit
	forward guiatachstmm_OnGameModeInit();
#endif


public OnPlayerDisconnect(playerid, reason)
{
	gui_atatch_symm_HideMenu(playerid);
#if defined guiatachstmm_OnPlayerDisconnect
	return guiatachstmm_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guiatachstmm_OnPlayerDisconnect
#if defined    guiatachstmm_OnPlayerDisconnect
	forward guiatachstmm_OnPlayerDisconnect(playerid, reason);
#endif


public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (gui_atatch_symm_IsShow(playerid))
	{
		if (clickedid == Text: INVALID_TEXT_DRAW)
		{
			gui_atatch_symm_HideMenu(playerid);
		}
		else
		{
			new Text: textdraw_save = gui_AttachSymmetry[14];
			new Text: textdraw_cancel = gui_AttachSymmetry[15];
			
			if (clickedid == textdraw_save)
			{
				Dialog_Show(playerid, "dAttachSymmetrySaveNote");
				return 1;
			}
			else if (clickedid == textdraw_cancel)
			{
				asymmetry_PressCancel(playerid);
				return 1;
			}
			const INDEX_TD_ID = 0;
			const INDEX_TYPE_ID = 1;

			static const index[][] =
			{
				{2, 	GUI_ATTACH_SYMMETRY_TYPE_X},
				{3, 	GUI_ATTACH_SYMMETRY_TYPE_Y},
				{4,		GUI_ATTACH_SYMMETRY_TYPE_Z},
				{5,		GUI_ATTACH_SYMMETRY_TYPE_R},
				{6,		GUI_ATTACH_SYMMETRY_TYPE_XY},
				{7,		GUI_ATTACH_SYMMETRY_TYPE_YZ},
				{8,		GUI_ATTACH_SYMMETRY_TYPE_ZX}
			};
			new typeid;

			for (new i, cellid; i < sizeof(index); i++)
			{
				cellid = index[i][INDEX_TD_ID];

				if (clickedid == gui_AttachSymmetry[cellid])
				{
					typeid = index[i][INDEX_TYPE_ID];

					asymmetry_SetSymmetryType(playerid, typeid);
					return 1;
				}
			}
		}
	}
#if defined guiatachstmm_OnClickTextDraw
	return guiatachstmm_OnClickTextDraw(playerid, Text:clickedid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw guiatachstmm_OnClickTextDraw
#if defined    guiatachstmm_OnClickTextDraw
	forward guiatachstmm_OnClickTextDraw(playerid, Text:clickedid);
#endif


stock gui_atatch_symm_ShowMenu(playerid)
{
	if (gui_atatch_symm_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachSymmetry); i++)
	{
		TextDrawShowForPlayer(playerid, gui_AttachSymmetry[i]);
	}
	gui_AttachSymmetryShowTD[playerid] = true;
	
	SelectTextDraw(playerid, COLOR_TD_CLICK);
	gui_atatch_menu_SetBannedPanel(playerid, true);
	return 1;
}

stock gui_atatch_symm_HideMenu(playerid)
{
	if (!gui_atatch_symm_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachSymmetry); i++)
	{
		TextDrawHideForPlayer(playerid, gui_AttachSymmetry[i]);
	}
	gui_AttachSymmetryShowTD[playerid] = false;
	gui_atatch_menu_SetBannedPanel(playerid, false);
	return 1;
}

stock gui_atatch_symm_IsShow(playerid)
{
	return gui_AttachSymmetryShowTD[playerid];
}