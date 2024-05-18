#if defined _cmd_setweather_inc
	#endinput
#endif
#define _cmd_setweather_inc


CMD:setweather(playerid, params[])
{
	new weatherid;

	if (sscanf(params, "d", weatherid))
	{
		SendClientMessage(playerid, COLOR_SERVER_MAIN, "» "cWhite"/setweather [id]");
		return 0;
	}
	const
		WEATHER_ID_MIN = 0,
		WEATHER_ID_MAX = 20;

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