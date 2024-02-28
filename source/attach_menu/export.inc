#if defined _attach_export_inc
	#endinput
#endif
#define _attach_export_inc

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_EXPORT)
	{
		if (Iter_Count(AttachObjectSlots[playerid]) == 0)
		{
			language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
			return 0;
		}
		new bool: is_valid_export;
		foreach (AttachObjectSlots[playerid], i)
		{
			if (attachmain_GetObjectSlotId(playerid, i) != CORE_INVALID_OBJECT_MODEL)
			{
				is_valid_export = true;
				break;
			}
		}
		if (!is_valid_export)
		{
			language_MessageError(playerid, MSG_TO_SET_OBJECT_PRESS_OBJECTS);
			return 0;
		}
		if (attacheditbtn_IsStartEdit(playerid))
		{
			return 0;
		}
		attachexport_Export(playerid);
		return 1;
	}
#if defined attachexport_OnGuiAttachMenu
	return attachexport_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attachexport_OnGuiAttachMenu
#if defined attachexport_OnGuiAttachMenu
	forward attachexport_OnGuiAttachMenu(playerid, typeid);
#endif

stock attachexport_Export(playerid, bool: is_show_dialog_info = true)
{
	new
		index,
		boneid,
		modelid,
		Float:offset_x,
		Float:offset_y,
		Float:offset_z,
		Float:rot_x,
		Float:rot_y,
		Float:rot_z,
		Float:scale_x,
		Float:scale_y,
		Float:scale_z,
		material_color_1,
		material_color_2;

	new
		name[CORE_MAX_LENGHT_FOLDER_PROJECT + 1],
		note[CORE_MAX_LENGHT_NAME_NOTE + 1],
		str_note[4 + CORE_MAX_LENGHT_NAME_NOTE + 1],
		string[333 + 70 + 36 + 10 + 4 + MAX_PLAYER_NAME + ((120 + 3 + 4+ CORE_MAX_LENGHT_NAME_NOTE) + 14 * 11) * MAX_PLAYER_ATTACHED_OBJECTS];

	project_GetFileName(playerid, name);

	new
		day,
		month,
		year,
		hour,
		minuite,
		second,
		player_name[MAX_PLAYER_NAME + 1];

	GetPlayerName(playerid, player_name, sizeof(player_name));

	getdate(year, month, day);
	gettime(hour, minuite, second);

	if (!fexist(name))
	{
		string =	"/////////////////////////////////////////////////////////////////////////\n\
					/////////////////////////////PAEditor////////////////////////////////////\n\
					/////////////////////////////////////////////author: Saibot//////////////\n\
					/////////////////////////////////////////////////////////////////////////\n"
				
		;
	}
	format(string, sizeof(string),
		"%s\n\nDateTime: [%02d.%02d.%d %02d:%02d:%02d] | SkinId: %d | By %s\n",
		string,
		day,
		month,
		year,
		hour,
		minuite,
		second,
		GetPlayerSkin(playerid),
		player_name
	);
	new File:handle = fopen(name, io_append);

	foreach (AttachObjectSlots[playerid], i)
	{
		attachmain_GetMainAttachData(
			playerid,
			i,
			modelid,
			boneid,
			offset_x,
			offset_y,
			offset_z,
			rot_x,
			rot_y,
			rot_z,
			scale_x,
			scale_y,
			scale_z,
			material_color_1,
			material_color_2
		);
		if (modelid == CORE_INVALID_OBJECT_MODEL)
		{
			continue;
		}
		attachmain_GetObjectSlotNote(playerid, i, note);

		str_note = "";

		if (strcmp(note, "-", false))
		{
			strcat(str_note, " //");
			strcat(str_note, note);
		}
		format(string, sizeof(string),
			"%sSetPlayerAttachedObject(playerid, %d, %d, %d, %f, %f, %f, %f, %f, %f, %f, %f, %f, 0x%x, 0x%x);%s\n",
			string,
			index++,
			modelid,
			boneid,
			offset_x,
			offset_y,
			offset_z,
			rot_x,
			rot_y,
			rot_z,
			scale_x,
			scale_y,
			scale_z,
			material_color_1,
			material_color_2,
			str_note
		);
	}
	for(new i; i < strlen(string); i++)
	{
		fputchar(handle, string[i], false);
	}
	fclose(handle);

	if (is_show_dialog_info)
	{
		new str_dialog[LANGUAGE_MAX_LENGHT_STRING_DL + 1];

		language_GetDialogString(
			playerid,
			DG_DATA_EXPORT_SUCCESS,
			str_dialog
		);
		Dialog_Open(
			playerid,
			Dialog:dNone,
			DIALOG_STYLE_MSGBOX,
			name_dialog_header,
			str_dialog,
			"X",
			""
		);
	}
	return 1;
}