#if defined _gui_logo_inc
	#endinput
#endif
#define _gui_logo_inc


static Text:gui_Logo;


public OnGameModeInit()
{
	static const
		fmt_str[] =
			"PAEditor:_v%.1f"
	;
	new string[sizeof(fmt_str) + (- 2 + 11)];

	format(string, sizeof(string),
		fmt_str,
		CURRENT_PAEDITOR_VERSION
	);
	gui_Logo = TextDrawCreate(628.9333, 2.7481, string);
	TextDrawLetterSize(gui_Logo, 0.3073, 1.4174);
	TextDrawAlignment(gui_Logo, 3);
	TextDrawColor(gui_Logo, 950371583);
	TextDrawSetOutline(gui_Logo, -1);
	TextDrawBackgroundColor(gui_Logo, 255);
	TextDrawFont(gui_Logo, 1);
	TextDrawSetProportional(gui_Logo, 1);
	TextDrawSetShadow(gui_Logo, 0);


#if defined guilogoOnGameModeInit
	return guilogoOnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit guilogoOnGameModeInit
#if defined    guilogoOnGameModeInit
	forward guilogoOnGameModeInit();
#endif

public OnPlayerDisconnect(playerid, reason)
{
	gui_logo_HideTD(playerid);
#if defined guilogoOnPlayerDisconnect
	return guilogoOnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guilogoOnPlayerDisconnect
#if defined    guilogoOnPlayerDisconnect
	forward guilogoOnPlayerDisconnect(playerid, reason);
#endif


stock gui_logo_ShowTD(playerid)
{
	TextDrawShowForPlayer(playerid, gui_Logo);
	return 1;
}

stock gui_logo_HideTD(playerid)
{
	TextDrawHideForPlayer(playerid, gui_Logo);
	return 1;
}