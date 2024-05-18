#if defined _cmd_settime_inc
	#endinput
#endif
#define _cmd_settime_inc


CMD:settime(playerid, params[])
{
	new hour;
	new minute;

	if (sscanf(params, "dD(0)", hour, minute))
	{
		SendClientMessage(playerid, COLOR_SERVER_MAIN, "» "cWhite"/settime [hour] [minute]");
		return 0;
	}
	const
		HOUR_MIN = 0,
		HOUR_MAX = 23;

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
	const
		MINUTE_MIN = 0,
		MINUTE_MAX = 59;

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