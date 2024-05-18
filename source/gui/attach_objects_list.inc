#if defined _gui_attach_objects_list_inc
	#endinput
#endif
#define _gui_attach_objects_list_inc


const
	ATTACH_OBJ_EMPTY_MODEL							= 1_649,
	ATTACH_OBJ_MAX_ITEM_IN_PAGE						= 20;

enum
{
	GUI_ATTACH_OBJECT_CLOSE,
	GUI_ATTACH_OBJECT_PREVIOUS,
	GUI_ATTACH_OBJECT_NEXT,
	GUI_ATTACH_OBJECT_ITEM
}


static
	PlayerText: gui_AttachObjectTextdrawsBases[MAX_PLAYERS][15],
	PlayerText: gui_AttachObjectTextdrawsItems[MAX_PLAYERS][ATTACH_OBJ_MAX_ITEM_IN_PAGE],
	PlayerText: gui_AttachObjectTextdrawsText[MAX_PLAYERS][ATTACH_OBJ_MAX_ITEM_IN_PAGE],
	bool:gui_AttachObjectPlayerCreate[MAX_PLAYERS];

public OnPlayerDisconnect(playerid, reason)
{
	gui_ath_obj_DestroyTextdraws(playerid);
#if defined guiaobj_OnPlayerDisconnect
	return guiaobj_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guiaobj_OnPlayerDisconnect
#if defined    guiaobj_OnPlayerDisconnect
	forward guiaobj_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerSpawn(playerid)
{
	gui_ath_obj_DestroyTextdraws(playerid);
#if defined guiaobj_OnPlayerSpawn
	return guiaobj_OnPlayerSpawn(playerid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn guiaobj_OnPlayerSpawn
#if defined    guiaobj_OnPlayerSpawn
	forward guiaobj_OnPlayerSpawn(playerid);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		if (clickedid == Text: INVALID_TEXT_DRAW)
		{
			CallRemoteFunction(
				"OnGuiAttachObjectsClicked",
				"ddd",
				playerid,
				GUI_ATTACH_OBJECT_CLOSE,
				-1
			);
			gui_ath_obj_DestroyTextdraws(playerid);
		}
	}
#if defined guiaobj_OnClickTextDraw
	return guiaobj_OnClickTextDraw(playerid, Text:clickedid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw guiaobj_OnClickTextDraw
#if defined    guiaobj_OnClickTextDraw
	forward guiaobj_OnClickTextDraw(playerid, Text:clickedid);
#endif


public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if (gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		if (Dialog_IsOpen(playerid))
		{
			return 0;
		}
		const
			INDEX_TD_ID = 0,
			INDEX_TYPE_ID = 0;

		static const index[][] =
		{
			{9,		GUI_ATTACH_OBJECT_CLOSE},
			{11,	GUI_ATTACH_OBJECT_PREVIOUS},
			{13,	GUI_ATTACH_OBJECT_NEXT}
		};
		for (new i, cellid; i < sizeof(index); i++)
		{
			cellid = index[i][INDEX_TD_ID];

			if (playertextid == gui_AttachObjectTextdrawsBases[playerid][cellid])
			{
				if (i == GUI_ATTACH_OBJECT_CLOSE)
				{
					gui_ath_obj_DestroyTextdraws(playerid);
				}
				CallRemoteFunction(
					"OnGuiAttachObjectsClicked",
					"ddd",
					playerid,
					index[i][INDEX_TYPE_ID],
					-1
				);
				return 1;
			}
		}
		for (new i; i < ATTACH_OBJ_MAX_ITEM_IN_PAGE; i++)
		{
			if (playertextid == gui_AttachObjectTextdrawsItems[playerid][i])
			{
				CallRemoteFunction(
					"OnGuiAttachObjectsClicked",
					"ddd",
					playerid,
					GUI_ATTACH_OBJECT_ITEM,
					i
				);
				return 1;
			}
		}
		return 1;
	}
#if defined guiaobj_OnPlayerClickPTD
	return guiaobj_OnPlayerClickPTD(playerid, playertextid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTD
#endif
#define OnPlayerClickPlayerTextDraw guiaobj_OnPlayerClickPTD
#if defined    guiaobj_OnPlayerClickPTD
	forward guiaobj_OnPlayerClickPTD(playerid, PlayerText:playertextid);
#endif

stock gui_ath_obj_CreateTextdraws(playerid)
{
	if (gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	gui_AttachObjectTextdrawsBases[playerid][0] = CreatePlayerTextDraw(playerid, 210.8999, 121.8180, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 211.0000, 225.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][0], 0);

	gui_AttachObjectTextdrawsBases[playerid][1] = CreatePlayerTextDraw(playerid, 300.2333, 123.2592, "Objects");
	PlayerTextDrawLetterSize(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 0.2097, 1.1600);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 950371583);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][1], 0);

	gui_AttachObjectTextdrawsBases[playerid][2] = CreatePlayerTextDraw(playerid, 205.3332, 119.4552, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 13.0000, 15.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][2], 0);

	gui_AttachObjectTextdrawsBases[playerid][3] = CreatePlayerTextDraw(playerid, 414.6665, 119.4552, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 13.0000, 15.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][3], 0);

	gui_AttachObjectTextdrawsBases[playerid][4] = CreatePlayerTextDraw(playerid, 205.4996, 334.6296, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 13.0000, 15.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][4], 0);

	gui_AttachObjectTextdrawsBases[playerid][5] = CreatePlayerTextDraw(playerid, 414.6329, 334.5000, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 13.0000, 15.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][5], 0);

	gui_AttachObjectTextdrawsBases[playerid][6] = CreatePlayerTextDraw(playerid, 207.3997, 124.9184, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 218.0000, 218.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 370480895);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][6], 0);

	gui_AttachObjectTextdrawsBases[playerid][7] = CreatePlayerTextDraw(playerid, 212.6665, 137.9777, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 207.5590, 179.2709);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][7], 0);

	gui_AttachObjectTextdrawsBases[playerid][8] = CreatePlayerTextDraw(playerid, 310.0382, 322.4703, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 17.0000, 20.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][8], 0);

	gui_AttachObjectTextdrawsBases[playerid][9] = CreatePlayerTextDraw(playerid, 318.7691, 326.8594, "X");
	PlayerTextDrawLetterSize(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 0.2311, 1.1726);
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 9.0000, 11.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 2);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][9], -1523963137);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][9], 0);
	PlayerTextDrawSetSelectable(playerid, gui_AttachObjectTextdrawsBases[playerid][9], true);

	gui_AttachObjectTextdrawsBases[playerid][10] = CreatePlayerTextDraw(playerid, 290.2691, 322.4703, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 17.0000, 20.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][10], 0);

	gui_AttachObjectTextdrawsBases[playerid][11] = CreatePlayerTextDraw(playerid, 298.7001, 324.8146, "<");
	PlayerTextDrawLetterSize(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 0.2599, 1.5542);
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 9.0000, 12.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 2);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][11], -1378294017);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][11], 0);
	PlayerTextDrawSetSelectable(playerid, gui_AttachObjectTextdrawsBases[playerid][11], true);

	gui_AttachObjectTextdrawsBases[playerid][12] = CreatePlayerTextDraw(playerid, 330.4710, 322.4703, "LD_BEAT:chit");
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 17.0000, 20.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 1);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 606151167);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 4);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 0);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][12], 0);

	gui_AttachObjectTextdrawsBases[playerid][13] = CreatePlayerTextDraw(playerid, 340.0021, 324.8146, ">");
	PlayerTextDrawLetterSize(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 0.2599, 1.5542);
	PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 9.0000, 12.0000);
	PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 2);
	PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsBases[playerid][13], -1378294017);
	PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 255);
	PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 1);
	PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 1);
	PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsBases[playerid][13], 0);
	PlayerTextDrawSetSelectable(playerid, gui_AttachObjectTextdrawsBases[playerid][13], true);

	const
		MAX_ROWS						= 5,

		Float:X_BASE_ITEM			= 214.2666,
		Float:Y_BASE_ITEM			= 139.4812,

		Float:DX_ITEM				= 41.1,
		Float:DY_ITEM				= 44.4;
	
	new
		Float:x_cell_pos_item,
		Float:y_cell_pos_item;

	for (new i; i < ATTACH_OBJ_MAX_ITEM_IN_PAGE; i++)
	{
		x_cell_pos_item = X_BASE_ITEM + DX_ITEM * (i % MAX_ROWS);
		y_cell_pos_item = Y_BASE_ITEM + DY_ITEM * (i / MAX_ROWS);

		gui_AttachObjectTextdrawsItems[playerid][i] = CreatePlayerTextDraw(playerid, x_cell_pos_item, y_cell_pos_item, "_");
		PlayerTextDrawTextSize(playerid, gui_AttachObjectTextdrawsItems[playerid][i], 40.0000, 43.0000);
		PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsItems[playerid][i], 1);
		PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsItems[playerid][i], -1);
		PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsItems[playerid][i], 791621631);
		PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsItems[playerid][i], 5);
		PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsItems[playerid][14], 0);
		PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsItems[playerid][i], 0);
		PlayerTextDrawSetSelectable(playerid, gui_AttachObjectTextdrawsItems[playerid][i], true);
		PlayerTextDrawSetPreviewModel(playerid, gui_AttachObjectTextdrawsItems[playerid][i], ATTACH_OBJ_EMPTY_MODEL);
		PlayerTextDrawSetPreviewRot(playerid, gui_AttachObjectTextdrawsItems[playerid][i], 0.0000, 0.0000, 90.0000, 2.0000);

	}
	const
		Float:X_BASE_AMOUNT			= 253.6666,
		Float:Y_BASE_AMOUNT			= 139.0,

		Float:DX_AMOUNT				= 41.0,
		Float:DY_AMOUNT				= 45.2;

	new
		Float:x_cell_pos_amount,
		Float:y_cell_pos_amount;

	for (new i; i < ATTACH_OBJ_MAX_ITEM_IN_PAGE; i++)
	{
		x_cell_pos_amount = X_BASE_AMOUNT + DX_AMOUNT * (i % MAX_ROWS);
		y_cell_pos_amount = Y_BASE_AMOUNT + DY_AMOUNT * (i / MAX_ROWS);

		gui_AttachObjectTextdrawsText[playerid][i] = CreatePlayerTextDraw(playerid, x_cell_pos_amount, y_cell_pos_amount, "M:0");
		PlayerTextDrawLetterSize(playerid, gui_AttachObjectTextdrawsText[playerid][i], 0.15, 0.7);
		PlayerTextDrawAlignment(playerid, gui_AttachObjectTextdrawsText[playerid][i], 3);
		PlayerTextDrawColor(playerid, gui_AttachObjectTextdrawsText[playerid][i], 0xc8c7c7FF);
		PlayerTextDrawBackgroundColor(playerid, gui_AttachObjectTextdrawsText[playerid][i], 255);
		PlayerTextDrawFont(playerid, gui_AttachObjectTextdrawsText[playerid][i], 2);
		PlayerTextDrawSetProportional(playerid, gui_AttachObjectTextdrawsText[playerid][i], 1);
		PlayerTextDrawSetShadow(playerid, gui_AttachObjectTextdrawsText[playerid][i], 0);
	}
	gui_AttachObjectPlayerCreate[playerid] = true;
	gui_atatch_menu_SetBannedPanel(playerid, true);
	return 1;
}

stock gui_ath_obj_ShowTextdraws(playerid)
{
	if (!gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachObjectTextdrawsBases[]); i++)
	{
		PlayerTextDrawShow(
			playerid,
			gui_AttachObjectTextdrawsBases[playerid][i]
		);
	}
	for (new i; i < ATTACH_OBJ_MAX_ITEM_IN_PAGE; i++)
	{
		PlayerTextDrawShow(
			playerid,
			gui_AttachObjectTextdrawsItems[playerid][i]
		);
	}
	SelectTextDraw(playerid, COLOR_TD_CLICK);
	return 1;
}

stock gui_ath_obj_SetModelObjecInCell(playerid, cellid, modelid)
{
	if (!gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	PlayerTextDrawSetPreviewModel(
		playerid,
		gui_AttachObjectTextdrawsItems[playerid][cellid],
		(modelid == CORE_INVALID_OBJECT_MODEL) ? ATTACH_OBJ_EMPTY_MODEL : modelid
	);
	PlayerTextDrawSetPreviewRot(
		playerid,
		gui_AttachObjectTextdrawsItems[playerid][cellid],
		0.0000,
		0.0000,
		(modelid == CORE_INVALID_OBJECT_MODEL) ? 90.0000 : 0.0000,
		(modelid == CORE_INVALID_OBJECT_MODEL) ? 2.0000 : 1.0000
	);
	PlayerTextDrawShow(
		playerid,
		gui_AttachObjectTextdrawsItems[playerid][cellid]
	);
	return 1;
}

stock gui_ath_obj_SetModelTextInCell(playerid, cellid, modelid)
{
	if (!gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	if (modelid == CORE_INVALID_OBJECT_MODEL)
	{
		PlayerTextDrawHide(
			playerid,
			gui_AttachObjectTextdrawsText[playerid][cellid]
		);
		return 0;
	}
	static const
		fmt_str[] =
			"M:%d"
	;
	new string[sizeof(fmt_str) + (- 2 + 11)];

	format(string, sizeof(string),
		fmt_str,
		modelid
	);
	PlayerTextDrawSetString(
		playerid,
		gui_AttachObjectTextdrawsText[playerid][cellid],
		string
	);
	PlayerTextDrawShow(
		playerid,
		gui_AttachObjectTextdrawsText[playerid][cellid]
	);
	return 1;
}

stock gui_ath_obj_IsPlayerCreateTD(playerid)
{
	return gui_AttachObjectPlayerCreate[playerid];
}

stock gui_ath_obj_DestroyTextdraws(playerid)
{
	if (!gui_ath_obj_IsPlayerCreateTD(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachObjectTextdrawsBases[]); i++)
	{
		PlayerTextDrawDestroy(
			playerid,
			gui_AttachObjectTextdrawsBases[playerid][i]
		);
	}
	for (new i; i < ATTACH_OBJ_MAX_ITEM_IN_PAGE; i++)
	{
		PlayerTextDrawDestroy(
			playerid,
			gui_AttachObjectTextdrawsItems[playerid][i]
		);
		PlayerTextDrawDestroy(
			playerid,
			gui_AttachObjectTextdrawsText[playerid][i]
		);
	}
	gui_atatch_menu_SetBannedPanel(playerid, false);
	gui_AttachObjectPlayerCreate[playerid] = false;
	return 1;
}