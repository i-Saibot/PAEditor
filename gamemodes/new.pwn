#include <a_samp>
#include <Pawn.CMD>
#include <sscanf2>
#include <mdialog>
#include <YAPJ>
#include <foreach>
#include <crashdetect>
#include <requests>

#pragma dynamic											5_000

#include "..\source\core.inc"
#include "..\source\language.inc"
#include "..\source\connect.inc"
#include "..\source\gui\attach_menu.inc"
#include "..\source\gui\attach_objects_list.inc"

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
#include "..\source\attach_menu\colors.inc"
#include "..\source\attach_menu\delete.inc"
#include "..\source\attach_menu\dublicate.inc"
#include "..\source\attach_menu\export.inc"

main(){}


static http_address_available_version[]				= "https://pastebin.com/raw/xebukdmH";

const Float:CURRENT_PAEDITOR_VERSION				= 1.0;


public OnGameModeInit()
{
	print("*****************************************************");
	print("Player Attach Editor");
	printf("version %.1f\n", CURRENT_PAEDITOR_VERSION);
	print("by: Saibot");
	print("*****************************************************");

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
		print("\n\n\n");
		print("NEW PAEditor VERSION AVAILABLE | https://github.com/i-Saibot/Player-Attach-Editor");
		print("\n\n\n");
	}
	return 1;
}