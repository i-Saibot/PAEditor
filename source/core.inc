#if defined _core_inc
	#endinput
#endif
#define _core_inc

#define COLOR_WHITE								0xFFFFFFFF
#define COLOR_RED								0xcb2323FF


#define COLOR_TD_CLICK							0x767676FF
#define COLOR_SERVER_MAIN						0x38A584FF

#define cWhite									"{FFFFFF}"
#define cMain									"{38A584}"
#define cGrey									"{8e8e8e}"
#define cRed									"{cb2323}"
#define cGreen									"{51734c}"

#define CORE_EMPTY_NOTE							"-"

const Float: CORE_PLAYER_SPAWN_X				= 836.6276;
const Float: CORE_PLAYER_SPAWN_Y				= -1982.3131;
const Float: CORE_PLAYER_SPAWN_Z				= 12.8672;
const Float: CORE_PLAYER_SPAWN_A				= 178.5383;

const CORE_PLAYER_DEFAULT_SKIN_ID				= 60;
const CORE_MAX_LENGHT_NAME_PROJECT				= 32;
const CORE_MAX_LENGHT_FOLDER_PROJECT			= CORE_MAX_LENGHT_NAME_PROJECT + 1 + 36 + 6;

const CORE_MAX_LENGHT_NAME_NOTE					= 20;
const CORE_MAX_LENGHT_NAME_BONE					= 18;
const CORE_MAX_COUNT_BONE						= 18;

const CORE_MIN_VALID_OBJECT_MODEL				= 615;
const CORE_MAX_VALID_OBJECT_MODEL				= 19999;

const CORE_INVALID_OBJECT_MODEL					= -1;

////////////////////////////////////////////////////////////////////////////////

forward OnGuiAttachMenuClicked(playerid, typeid);
forward OnGuiAttachObjectsClicked(playerid, typeid, index);

////////////////////////////////////////////////////////////////////////////////

new json_file_name_colors[]						= "resources/colors.json";
new json_file_name_objects[]					= "resources/objects.json";
new json_file_name_animations[]					= "resources/animations.json";

new json_file_name_import[]						= "scriptfiles/project/import/";
new json_file_name_export[]						= "project/export/";

new json_file_name_list[]						= "scriptfiles/project/import/.list.json";

new json_file_name_language_msg[]				= "language/messages.json";
new json_file_name_language_dialog[]			= "language/dialogs.json";
new json_file_name_language_array[]				= "language/array.json";

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


CMD:setweather(playerid, params[])
{
	new weatherid;

	if (sscanf(params, "d", weatherid))
	{
		SendClientMessage(playerid, COLOR_SERVER_MAIN, "» "cWhite"/setweather [id]");
		return 0;
	}
	const WEATHER_ID_MIN = 0;
	const WEATHER_ID_MAX = 20;

	if (!(WEATHER_ID_MIN <= weatherid <= WEATHER_ID_MAX))
	{
		static const
			fmt_str[] =
				"» "cWhite"%d - %d"
		;
		new string[sizeof(fmt_str) + (- 2 + 2) * 2];

		format(string, sizeof(string),
			fmt_str,
			WEATHER_ID_MIN,
			WEATHER_ID_MAX
		);
		SendClientMessage(playerid, COLOR_RED, string);
		return 0;
	}
	SetPlayerWeather(playerid, weatherid);
	return 1;
}

CMD:settime(playerid, params[])
{
	new hour;
	new minute;

	if (sscanf(params, "dD(0)", hour, minute))
	{
		SendClientMessage(playerid, COLOR_SERVER_MAIN, "» "cWhite"/settime [hour] [minute]");
		return 0;
	}
	const HOUR_MIN = 0;
	const HOUR_MAX = 23;

	if (!(HOUR_MIN <= hour <= HOUR_MAX))
	{
		static const
			fmt_str[] =
				"» "cWhite"hour %d - %d"
		;
		new string[sizeof(fmt_str) + (- 2 + 2) * 2];

		format(string, sizeof(string),
			fmt_str,
			HOUR_MIN,
			HOUR_MAX
		);
		SendClientMessage(playerid, COLOR_RED, string);
		return 0;
	}
	const MINUTE_MIN = 0;
	const MINUTE_MAX = 59;

	if (!(MINUTE_MIN <= minute <= MINUTE_MAX))
	{
		static const
			fmt_str[] =
				"» "cWhite"minute %d - %d"
		;
		new string[sizeof(fmt_str) + (- 2 + 2) * 2];

		format(string, sizeof(string),
			fmt_str,
			MINUTE_MIN,
			MINUTE_MAX
		);
		SendClientMessage(playerid, COLOR_RED, string);
		return 0;
	}
	SetPlayerTime(playerid, hour, minute);
	return 1;
}