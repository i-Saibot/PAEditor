#if defined _gui_virtual_key_inc
	#endinput
#endif
#define _gui_virtual_key_inc

const V_KEY_UPDATE_TIMER				= 25;

static const gVirtualKeysId[] =
{
	VK_KEY_W,
	VK_KEY_S,
	VK_KEY_A,
	VK_KEY_D,
	VK_KEY_Q,
	VK_KEY_E,
	VK_RBUTTON,
	VK_UP,
	VK_DOWN,
	VK_LEFT,
	VK_RIGHT,
	VK_LSHIFT,
	VK_LMENU
};

static gVirtualKeyTimer[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
	gVirtualKeyTimer[playerid] = SetTimerEx(
		"@_OnTimerUpdateVkey",
		V_KEY_UPDATE_TIMER,
		false,
		"d",
		playerid
	);
#if defined vkey_OnPlayerConnect
	return vkey_OnPlayerConnect(playerid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect vkey_OnPlayerConnect
#if defined    vkey_OnPlayerConnect
	forward vkey_OnPlayerConnect(playerid);
#endif

public OnPlayerDisconnect(playerid, reason)
{
	new timerid = gVirtualKeyTimer[playerid];

	KillTimer(timerid);
#if defined vkey_OnPlayerDisconnect
	return vkey_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect vkey_OnPlayerDisconnect
#if defined    vkey_OnPlayerDisconnect
	forward vkey_OnPlayerDisconnect(playerid, reason);
#endif


@_OnTimerUpdateVkey(playerid);
@_OnTimerUpdateVkey(playerid)
{
	new keyid;

	for (new i; i < sizeof(gVirtualKeysId); i++)
	{
		keyid = gVirtualKeysId[i];

		if (GetKeyPressed(keyid))
		{
			CallRemoteFunction(
				"OnVirtualKeyPressed",
				"dd",
				playerid,
				keyid
			);
		}
		if (GetKeyReleased(keyid))
		{
			CallRemoteFunction(
				"OnVirtualKeyReleased",
				"dd",
				playerid,
				keyid
			);
		}
	}
	gVirtualKeyTimer[playerid] = SetTimerEx(
		"@_OnTimerUpdateVkey",
		V_KEY_UPDATE_TIMER,
		false,
		"d",
		playerid
	);
	return 1;
}