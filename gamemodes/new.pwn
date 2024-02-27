#include <a_samp>
#include <Pawn.CMD>
#include <sscanf2>
#include <mdialog>
#include <YAPJ>
#include <foreach>
#include <crashdetect>
#include <requests>
#include <dcc>
#include <PAE>

#pragma dynamic											7_000

#include "..\language\dialogs.inc"
#include "..\language\messages.inc"
#include "..\language\array.inc"

#include "..\source\core.inc"
#include "..\source\language.inc"
#include "..\source\connect.inc"
#include "..\source\virtual_key.inc"
#include "..\source\gui\attach_menu.inc"
#include "..\source\gui\attach_objects_list.inc"
#include "..\source\gui\attach_edit_button.inc"
#include "..\source\gui\camera_rotation.inc"
#include "..\source\gui\attach_symmetry.inc"

#include "..\source\project\main.inc"
#include "..\source\project\create.inc"
#include "..\source\project\loading.inc"
#include "..\source\project\help.inc"

#include "..\source\attach_menu\main.inc"
#include "..\source\attach_menu\manage.inc"
#include "..\source\attach_menu\new.inc"
#include "..\source\attach_menu\skins.inc"
#include "..\source\attach_menu\animations.inc"
#include "..\source\attach_menu\objects.inc"
#include "..\source\attach_menu\edit.inc"
#include "..\source\attach_menu\edit_button.inc"
#include "..\source\attach_menu\colors.inc"
#include "..\source\attach_menu\delete.inc"
#include "..\source\attach_menu\dublicate.inc"
#include "..\source\attach_menu\export.inc"
#include "..\source\attach_menu\move_camera.inc"
#include "..\source\attach_menu\bone.inc"
#include "..\source\attach_menu\symmetry.inc"

main(){}

static http_address_available_version[]				= "https://pastebin.com/raw/xebukdmH";

const Float:CURRENT_PAEDITOR_VERSION				= 1.1;


public OnGameModeInit()
{
	static const
		fmt_str[] =
			"Version: %.1f"
	;
	new string[sizeof(fmt_str) + (- 2 + 3)];

	format(string, sizeof(string),
		fmt_str,
		CURRENT_PAEDITOR_VERSION
	);
	SetGameModeText(string);

	for (new i; i < 20; i++)
	{
		print("\n");
	}
	new backup_color = GetConsoleColors();

	SetConsoleColors(TXT_AQUA, COLOR_TYPE_TXT);

	printf(
		"\n\
		    __      __            \n\
		|__) /\\ |_  _|.|_ _  _ \n\
		|   /--\\|__(_|||_(_)|  \n\
							"
	);
	print("\nAuthor: Saibot");
	printf("Version %.1f\n", CURRENT_PAEDITOR_VERSION);

	SetConsoleColors(backup_color, COLOR_TYPE_TXT);

	AddPlayerClass(
		0,
		CORE_PLAYER_SPAWN_X,
		CORE_PLAYER_SPAWN_Y,
		CORE_PLAYER_SPAWN_Z,
		CORE_PLAYER_SPAWN_A,
		0,
		0,
		0,
		0,
		0,
		0
	);
	new RequestsClient:https = RequestsClient(http_address_available_version);
	
	Request(
		https,
		"",
		HTTP_METHOD_GET,
		"@_OnCheckAvailableVersion"
	);
	return 1;
}

@_OnCheckAvailableVersion(Request:id, E_HTTP_STATUS:status, data[], dataLen);
@_OnCheckAvailableVersion(Request:id, E_HTTP_STATUS:status, data[], dataLen)
{
	new Float: version;
	sscanf(data, "f", version);

	if (CURRENT_PAEDITOR_VERSION != version)
	{
		new backup_color = GetConsoleColors();
		SetConsoleColors(TXT_LIGHTGREEN, COLOR_TYPE_TXT);

		printf("\n\n");
		printf("New version PAEditor available | https://github.com/i-Saibot/PAEditor/releases");

		SetConsoleColors(backup_color, COLOR_TYPE_TXT);
	}
	return 1;
}