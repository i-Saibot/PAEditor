#if defined _cmd_object_inc
	#endinput
#endif
#define _cmd_object_inc

static gCreateObject[MAX_PLAYERS];

public OnPlayerDisconnect(playerid, reason)
{
	if (gCreateObject[playerid] != 0)
	{
		DestroyObject(gCreateObject[playerid]);
	}
#if defined cmd_obj_OnPlayerDisconnect
	return cmd_obj_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect cmd_obj_OnPlayerDisconnect
#if defined    cmd_obj_OnPlayerDisconnect
	forward cmd_obj_OnPlayerDisconnect(playerid, reason);
#endif

alias:object("obj")
CMD:object(playerid, params[])
{
	new modelid;

	if (sscanf(params, "d", modelid))
	{
		SendClientMessage(playerid, COLOR_SERVER_MAIN, "» "cWhite"/objectid [modelid]");
		return 0;
	}
	if (!(CORE_MIN_VALID_OBJECT_MODEL <= modelid <= CORE_MAX_VALID_OBJECT_MODEL))
	{
		language_MessageError(playerid, "MSG_INVALID_OBJECT_MODEL");
		return 0;
	}
	new
		Float:x,
		Float:y,
		Float:z,
		Float:a;
	
	GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, a);

	x -= (3.0 * floatsin(a, degrees));
	y += (3.0 * floatcos(a, degrees));

	if (gCreateObject[playerid] != 0)
	{
		DestroyObject(gCreateObject[playerid]);
	}
	gCreateObject[playerid] = CreateObject(
		modelid,
		x,
		y,
		z + 0.2,
		0.0,
		0.0,
		0.0
	);
	return 1;
}

alias:dellobject("dellobj")
CMD:dellobject(playerid, params[])
{
	if (gCreateObject[playerid] != 0)
	{
		DestroyObject(gCreateObject[playerid]);
	}
	return 1;
}