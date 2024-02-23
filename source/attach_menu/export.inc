#if defined _attach_export_inc
	#endinput
#endif
#define _attach_export_inc

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_EXPORT)
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		if (slotid == ITER_NONE)
		{
			language_MessageError(playerid, MSG_PROCESS_START_PRESS_NEW);
			return 0;
		}
		new modelid = attachmain_GetObjectSlotId(playerid, slotid);

		if (modelid == CORE_INVALID_OBJECT_MODEL)
		{
			language_MessageError(playerid, MSG_START_SELECT_OBJ_PRESS_OBJ);
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

static attachexport_Export(playerid)
{
	new index;
	new boneid;
	new modelid;
	new Float:fOffsetX;
	new Float:fOffsetY;
	new Float:fOffsetZ;
	new Float:fRotX;
	new Float:fRotY;
	new Float:fRotZ;
	new Float:fScaleX;
	new Float:fScaleY;
	new Float:fScaleZ;
	new materialcolor1;
	new materialcolor2;

	new name[CORE_MAX_LENGHT_FOLDER_PROJECT];
	new note[CORE_MAX_LENGHT_NAME_NOTE];
	new str_note[4 + CORE_MAX_LENGHT_NAME_NOTE];
	new string[333 + 70 + 36 + 10 + 4 + MAX_PLAYER_NAME + ((120 + 3 + 4+ CORE_MAX_LENGHT_NAME_NOTE) + 14 * 11) * MAX_PLAYER_ATTACHED_OBJECTS];

	project_GetFileName(playerid, name);

	new day;
	new month;
	new year;
	new hour;
	new minuite;
	new second;
	new player_name[MAX_PLAYER_NAME + 1];

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
		attachmain_GetAttachInfo(
			playerid,
			i,
			modelid,
			boneid,
			fOffsetX,
			fOffsetY,
			fOffsetZ,
			fRotX,
			fRotY,
			fRotZ,
			fScaleX,
			fScaleY,
			fScaleZ,
			materialcolor1,
			materialcolor2
		);
		attachmain_GetObjectSlotNote(playerid, i, note);

		if (!strcmp(note, "-", false))
		{
			str_note = "";
		}
		else
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
			fOffsetX,
			fOffsetY,
			fOffsetZ,
			fRotX,
			fRotY,
			fRotZ,
			fScaleX,
			fScaleY,
			fScaleZ,
			materialcolor1,
			materialcolor2,
			str_note
		);
	}
	for(new i; i < strlen(string); i++)
	{
		fputchar(handle, string[i], false);
	}
	fclose(handle);

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
		!""cMain"PAEditor",
		str_dialog,
		!"X",
		!""
	);
	return 1;
}