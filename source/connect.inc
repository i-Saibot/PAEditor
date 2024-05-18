#if defined _connect_inc
	#endinput
#endif
#define _connect_inc


const CONNECT_CLEAR_CHAT = 100;


public OnPlayerConnect(playerid)
{
	for (new i; i < MAX_PLAYER_ATTACHED_OBJECTS; i++)
	{
		RemovePlayerAttachedObject(playerid, i);
	}
	PreloadAllAnimLibs(playerid);
	TogglePlayerSpectating(playerid, true);

	SetTimerEx(
		"@_OnPlayerConnect",
		1_000,
		false,
		"d",
		playerid
	);
#if defined connect_OnPlayerConnect
	return connect_OnPlayerConnect(playerid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect connect_OnPlayerConnect
#if defined    connect_OnPlayerConnect
	forward connect_OnPlayerConnect(playerid);
#endif

@_OnPlayerConnect(playerid);
@_OnPlayerConnect(playerid)
{
	for (new i; i < CONNECT_CLEAR_CHAT;i++)
	{
		SendClientMessage(playerid, COLOR_WHITE, "");
	}
	SetSpawnInfo(playerid, 255, 0, 0, 0, 0, 1.0, -1, -1, -1, -1, -1, -1);
	TogglePlayerSpectating(playerid, false);

	GameTextForPlayer(playerid, "~y~PAEditor", 3000, 4);

	Dialog_Show(playerid, "dLanguageChoose");

	gui_logo_ShowTD(playerid);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	SetPlayerPos(
		playerid,
		CORE_PLAYER_SPAWN_X,
		CORE_PLAYER_SPAWN_Y,
		CORE_PLAYER_SPAWN_Z
	);
	SetPlayerFacingAngle(playerid, CORE_PLAYER_SPAWN_A);

	SetCameraBehindPlayer(playerid);
	SetPlayerSkin(playerid, CORE_PLAYER_DEFAULT_SKIN_ID);

	SetPlayerHealth(playerid, 999);
#if defined connect_OnPlayerSpawn
	return connect_OnPlayerSpawn(playerid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn connect_OnPlayerSpawn
#if defined    connect_OnPlayerSpawn
	forward connect_OnPlayerSpawn(playerid);
#endif

stock PreloadAllAnimLibs(playerid)
{
	PreloadAnimLib(playerid,"AIRPORT");
	PreloadAnimLib(playerid,"Attractors");
	PreloadAnimLib(playerid,"BAR");
	PreloadAnimLib(playerid,"BASEBALL");
	PreloadAnimLib(playerid,"BD_FIRE");
	PreloadAnimLib(playerid,"BEACH");
	PreloadAnimLib(playerid,"benchpress");
	PreloadAnimLib(playerid,"BF_injection");
	PreloadAnimLib(playerid,"BIKED");
	PreloadAnimLib(playerid,"BIKEH");
	PreloadAnimLib(playerid,"BIKELEAP");
	PreloadAnimLib(playerid,"BIKES");
	PreloadAnimLib(playerid,"BIKEV");
	PreloadAnimLib(playerid,"BIKE_DBZ");
	PreloadAnimLib(playerid,"BLOWJOBZ");
	PreloadAnimLib(playerid,"BMX");
	PreloadAnimLib(playerid,"BOMBER");
	PreloadAnimLib(playerid,"BOX");
	PreloadAnimLib(playerid,"BSKTBALL");
	PreloadAnimLib(playerid,"BUDDY");
	PreloadAnimLib(playerid,"BUS");
	PreloadAnimLib(playerid,"CAMERA");
	PreloadAnimLib(playerid,"CAR");
	PreloadAnimLib(playerid,"CARRY");
	PreloadAnimLib(playerid,"CAR_CHAT");
	PreloadAnimLib(playerid,"CASINO");
	PreloadAnimLib(playerid,"CHAINSAW");
	PreloadAnimLib(playerid,"CHOPPA");
	PreloadAnimLib(playerid,"CLOTHES");
	PreloadAnimLib(playerid,"COACH");
	PreloadAnimLib(playerid,"COLT45");
	PreloadAnimLib(playerid,"COP_AMBIENT");
	PreloadAnimLib(playerid,"COP_DVBYZ");
	PreloadAnimLib(playerid,"CRACK");
	PreloadAnimLib(playerid,"CRIB");
	PreloadAnimLib(playerid,"DAM_JUMP");
	PreloadAnimLib(playerid,"DANCING");
	PreloadAnimLib(playerid,"DEALER");
	PreloadAnimLib(playerid,"DILDO");
	PreloadAnimLib(playerid,"DODGE");
	PreloadAnimLib(playerid,"DOZER");
	PreloadAnimLib(playerid,"DRIVEBYS");
	PreloadAnimLib(playerid,"FAT");
	PreloadAnimLib(playerid,"FIGHT_B");
	PreloadAnimLib(playerid,"FIGHT_C");
	PreloadAnimLib(playerid,"FIGHT_D");
	PreloadAnimLib(playerid,"FIGHT_E");
	PreloadAnimLib(playerid,"FINALE");
	PreloadAnimLib(playerid,"FINALE2");
	PreloadAnimLib(playerid,"FLAME");
	PreloadAnimLib(playerid,"Flowers");
	PreloadAnimLib(playerid,"FOOD");
	PreloadAnimLib(playerid,"Freeweights");
	PreloadAnimLib(playerid,"GANGS");
	PreloadAnimLib(playerid,"GHANDS");
	PreloadAnimLib(playerid,"GHETTO_DB");
	PreloadAnimLib(playerid,"goggles");
	PreloadAnimLib(playerid,"GRAFFITI");
	PreloadAnimLib(playerid,"GRAVEYARD");
	PreloadAnimLib(playerid,"GRENADE");
	PreloadAnimLib(playerid,"GYMNASIUM");
	PreloadAnimLib(playerid,"HAIRCUTS");
	PreloadAnimLib(playerid,"HEIST9");
	PreloadAnimLib(playerid,"INT_HOUSE");
	PreloadAnimLib(playerid,"INT_OFFICE");
	PreloadAnimLib(playerid,"INT_SHOP");
	PreloadAnimLib(playerid,"JST_BUISNESS");
	PreloadAnimLib(playerid,"KART");
	PreloadAnimLib(playerid,"KISSING");
	PreloadAnimLib(playerid,"KNIFE");
	PreloadAnimLib(playerid,"LAPDAN1");
	PreloadAnimLib(playerid,"LAPDAN2");
	PreloadAnimLib(playerid,"LAPDAN3");
	PreloadAnimLib(playerid,"LOWRIDER");
	PreloadAnimLib(playerid,"MD_CHASE");
	PreloadAnimLib(playerid,"MD_END");
	PreloadAnimLib(playerid,"MEDIC");
	PreloadAnimLib(playerid,"MISC");
	PreloadAnimLib(playerid,"MTB");
	PreloadAnimLib(playerid,"MUSCULAR");
	PreloadAnimLib(playerid,"NEVADA");
	PreloadAnimLib(playerid,"ON_LOOKERS");
	PreloadAnimLib(playerid,"OTB");
	PreloadAnimLib(playerid,"PARACHUTE");
	PreloadAnimLib(playerid,"PARK");
	PreloadAnimLib(playerid,"PAULNMAC");
	PreloadAnimLib(playerid,"ped");
	PreloadAnimLib(playerid,"PLAYER_DVBYS");
	PreloadAnimLib(playerid,"PLAYIDLES");
	PreloadAnimLib(playerid,"POLICE");
	PreloadAnimLib(playerid,"POOL");
	PreloadAnimLib(playerid,"POOR");
	PreloadAnimLib(playerid,"PYTHON");
	PreloadAnimLib(playerid,"QUAD");
	PreloadAnimLib(playerid,"QUAD_DBZ");
	PreloadAnimLib(playerid,"RAPPING");
	PreloadAnimLib(playerid,"RIFLE");
	PreloadAnimLib(playerid,"RIOT");
	PreloadAnimLib(playerid,"ROB_BANK");
	PreloadAnimLib(playerid,"ROCKET");
	PreloadAnimLib(playerid,"RUSTLER");
	PreloadAnimLib(playerid,"RYDER");
	PreloadAnimLib(playerid,"SCRATCHING");
	PreloadAnimLib(playerid,"SHAMAL");
	PreloadAnimLib(playerid,"SHOP");
	PreloadAnimLib(playerid,"SHOTGUN");
	PreloadAnimLib(playerid,"SILENCED");
	PreloadAnimLib(playerid,"SKATE");
	PreloadAnimLib(playerid,"SMOKING");
	PreloadAnimLib(playerid,"SNIPER");
	PreloadAnimLib(playerid,"SPRAYCAN");
	PreloadAnimLib(playerid,"STRIP");
	PreloadAnimLib(playerid,"SUNBATHE");
	PreloadAnimLib(playerid,"SWAT");
	PreloadAnimLib(playerid,"SWEET");
	PreloadAnimLib(playerid,"SWIM");
	PreloadAnimLib(playerid,"SWORD");
	PreloadAnimLib(playerid,"TANK");
	PreloadAnimLib(playerid,"TATTOOS");
	PreloadAnimLib(playerid,"TEC");
	PreloadAnimLib(playerid,"TRAIN");
	PreloadAnimLib(playerid,"TRUCK");
	PreloadAnimLib(playerid,"UZI");
	PreloadAnimLib(playerid,"VAN");
	PreloadAnimLib(playerid,"VENDING");
	PreloadAnimLib(playerid,"VORTEX");
	PreloadAnimLib(playerid,"WAYFARER");
	PreloadAnimLib(playerid,"WEAPONS");
	PreloadAnimLib(playerid,"WUZI");
	return 1;
}

static PreloadAnimLib(playerid, const animlib[])
{
	ApplyAnimation(playerid,animlib,"null",0.0,0,0,0,0,0);
	return 1;
}