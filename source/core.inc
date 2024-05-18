#if defined _core_inc
	#endinput
#endif
#define _core_inc

#define COLOR_WHITE								0xFFFFFFFF
#define COLOR_RED								0xcb2323FF
#define COLOR_GREY								0x565656FF

#define COLOR_TD_CLICK							0x767676FF
#define COLOR_SERVER_MAIN						0x38A584FF

#define cWhite									"{FFFFFF}"
#define cMain									"{38A584}"
#define cGrey									"{8e8e8e}"
#define cRed									"{cb2323}"
#define cGreen									"{51734c}"

#define CORE_EMPTY_NOTE							"-"


const
	Float:CORE_PLAYER_SPAWN_X					= 1909.4329,
	Float:CORE_PLAYER_SPAWN_Y					= 1273.1715,
	Float:CORE_PLAYER_SPAWN_Z					= 10.6719,
	Float:CORE_PLAYER_SPAWN_A					= 269.7423,

	CORE_PLAYER_DEFAULT_SKIN_ID					= 60,
	CORE_MAX_LENGHT_NAME_PROJECT				= 32,
	CORE_MAX_LENGHT_FOLDER_PROJECT				= CORE_MAX_LENGHT_NAME_PROJECT + 1 + 36 + 6,

	CORE_MAX_LENGHT_NAME_NOTE					= 31,
	CORE_MAX_LENGHT_NAME_BONE					= 32,
	CORE_MAX_COUNT_BONE							= 18,

	CORE_MIN_VALID_OBJECT_MODEL					= 320,
	CORE_MAX_VALID_OBJECT_MODEL					= 19999,

	CORE_INVALID_OBJECT_MODEL					= -1;

////////////////////////////////////////////////////////////////////////////////

forward OnGuiAttachMenuClicked(playerid, typeid);
forward OnGuiAttachObjectsClicked(playerid, typeid, index);
forward OnVirtualKeyPressed(playerid, key_vk);
forward OnVirtualKeyReleased(playerid, key_vk);

////////////////////////////////////////////////////////////////////////////////

new
	json_file_name_colors[]						= "resources/colors.json",
	json_file_name_objects[]					= "resources/objects.json",
	json_file_name_animations[]					= "resources/animations.json",
	json_file_name_import[]						= "scriptfiles/project/import/",
	json_file_name_export[]						= "project/export/",
	json_file_name_list[]						= "scriptfiles/project/import/.list.json";

////////////////////////////////////////////////////////////////////////////////

new name_dialog_header[]						= ""cMain"PAEditor";

////////////////////////////////////////////////////////////////////////////////

enum
{
	ATTACH_BONE_SPINE = 1,
	ATTACH_BONE_HEAD,
	ATTACH_BONE_LEFT_SHOULDER,
	ATTACH_BONE_RIGHT_SHOULDER,
	ATTACH_BONE_LEFT_ARM,
	ATTACH_BONE_RIGHT_ARM,
	ATTACH_BONE_LEFT_THIGH,
	ATTACH_BONE_RIGHT_THIGH,
	ATTACH_BONE_LEFT_LEG,
	ATTACH_BONE_RIGHT_LEG,
	ATTACH_BONE_RIGHT_SHIN,
	ATTACH_BONE_LEFT_SHIN,
	ATTACH_BONE_LEFT_FOREARM,
	ATTACH_BONE_RIGHT_FOREARM,
	ATTACH_BONE_LEFT_CLAVICLE,
	ATTACH_BONE_RIGHT_CLAVICLE,
	ATTACH_BONE_NECK,
	ATTACH_BONE_JAW
}

////////////////////////////////////////////////////////////////////////////////

public OnPlayerCommandText(playerid, cmdtext[])
{
	return 0;
}


public OnPlayerCommandPerformed(playerid, cmd[], params[], result, flags)
{
	if (result == -1)
	{
		return 0;
	}
	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	SetPlayerPos(playerid, fX, fY, fZ);
	SetPlayerHealth(playerid, 100.0);
	return 1;
}