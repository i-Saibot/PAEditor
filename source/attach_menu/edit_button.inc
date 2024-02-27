#if defined _attach_edit_button_inc
	#endinput
#endif
#define _attach_edit_button_inc


static enum e_edit_btn_temp_struct
{
	aeditbutton_SlotId,
	aeditbutton_ObjectId,
	aeditbutton_BoneId,
	Float:aeditbutton_fOffsetX,
	Float:aeditbutton_fOffsetY,
	Float:aeditbutton_fOffsetZ,
	Float:aeditbutton_fRotX,
	Float:aeditbutton_fRotY,
	Float:aeditbutton_fRotZ,
	Float:aeditbutton_fScaleX,
	Float:aeditbutton_fScaleY,
	Float:aeditbutton_fScaleZ,
	aeditbutton_materialcolor1,
	aeditbutton_materialcolor2
}
static aeditbutton_TempStructure[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][e_edit_btn_temp_struct];

static bool: gAttachEditButtonStart[MAX_PLAYERS];


public OnVirtualKeyPressed(playerid, key_vk)
{
	if (attacheditbtn_IsStartEdit(playerid))
	{
		new
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
			material_color_2,
			bool: is_was_change;

		foreach (AttachMultiObjectSlots[playerid], i)
		{
			attacheditbtn_GetTempAttach(
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
			if (key_vk == VK_KEY_W || key_vk == VK_KEY_S || key_vk == VK_KEY_A || key_vk == VK_KEY_D || key_vk == VK_KEY_Q || key_vk == VK_KEY_E)
			{
				offset_x += (key_vk == VK_KEY_A) ? 0.01 : ((key_vk == VK_KEY_D) ? -0.01 : 0.0);
				offset_y += (key_vk == VK_KEY_W) ? 0.01 : ((key_vk == VK_KEY_S) ? -0.01 : 0.0);
				offset_z += (key_vk == VK_KEY_Q) ? 0.01 : ((key_vk == VK_KEY_E) ? -0.01 : 0.0);

				gui_ath_edit_SetClorPressBtn(playerid, COLOR_WHITE, key_vk);
				is_was_change = true;
			}
			if (is_was_change)
			{
				attacheditbtn_SetTempAttach(
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
				aeditbutton_SetTempAttachObject(playerid, i);
			}
		}
	}
#if defined attchdtbtn_OnVirtualKeyPressed
	return attchdtbtn_OnVirtualKeyPressed(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyPressed
	#undef OnVirtualKeyPressed
#else
	#define _ALS_OnVirtualKeyPressed
#endif
#define OnVirtualKeyPressed attchdtbtn_OnVirtualKeyPressed
#if defined    attchdtbtn_OnVirtualKeyPressed
	forward attchdtbtn_OnVirtualKeyPressed(playerid, key_vk);
#endif

public OnVirtualKeyReleased(playerid, key_vk)
{
	if (attacheditbtn_IsStartEdit(playerid))
	{
		if (key_vk == VK_KEY_W
			|| key_vk == VK_KEY_S
			|| key_vk == VK_KEY_A
			|| key_vk == VK_KEY_D
			|| key_vk == VK_KEY_Q
			|| key_vk == VK_KEY_E)
		{
			gui_ath_edit_SetClorPressBtn(playerid, COLOR_GREY, key_vk);
		}
	}
#if defined attchdtbtn_OnVirtualKeyReleased
	return attchdtbtn_OnVirtualKeyReleased(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased attchdtbtn_OnVirtualKeyReleased
#if defined    attchdtbtn_OnVirtualKeyReleased
	forward attchdtbtn_OnVirtualKeyReleased(playerid, key_vk);
#endif

public OnGuiAttachMenuClicked(playerid, typeid)
{
	if (typeid == GUI_ATTACH_MENU_EDIT)
	{
		if (attachmain_IsUseMultiObject(playerid))
		{
			new
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

			foreach (AttachMultiObjectSlots[playerid], i)
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
				attacheditbtn_SetTempAttach(
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
			}
			gui_ath_edit_CreateTextdraws(playerid);
			gui_ath_edit_ShowTextdraws(playerid);

			attacheditbtn_SetStartEdit(playerid, true);
			gui_atatch_menu_SetBannedPanel(playerid, true);
			return 1;
		}
	}
#if defined attchdtbtn_OnGuiAttachMenu
	return attchdtbtn_OnGuiAttachMenu(playerid, typeid);
#else
	return 1;
#endif
}
#if defined _ALS_OnGuiAttachMenu
	#undef OnGuiAttachMenuClicked
#else
	#define _ALS_OnGuiAttachMenu
#endif
#define OnGuiAttachMenuClicked attchdtbtn_OnGuiAttachMenu
#if defined attchdtbtn_OnGuiAttachMenu
	forward attchdtbtn_OnGuiAttachMenu(playerid, typeid);
#endif

static attacheditbtn_GetTempAttach(
	playerid,
	slotid,
	&objectid,
	&boneid,
	&Float:offset_x,
	&Float:offset_y,
	&Float:offset_z,
	&Float:rot_x,
	&Float:rot_y,
	&Float:rot_z,
	&Float:scale_x,
	&Float:scale_y,
	&Float:scale_z,
	&material_color_1,
	&material_color_2)
{
	objectid		=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_ObjectId];
	boneid			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_BoneId];
	offset_x		=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fOffsetX];
	offset_y		=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fOffsetY];
	offset_z		=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fOffsetZ];
	rot_x			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fRotX];
	rot_y			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fRotY];
	rot_z			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fRotZ];
	scale_x			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fScaleX];
	scale_y			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fScaleY];
	scale_z			=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fScaleZ];
	material_color_1	=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_materialcolor1];
	material_color_2	=	aeditbutton_TempStructure[playerid][slotid][aeditbutton_materialcolor2];
	return 1;
}

static attacheditbtn_SetTempAttach(
	playerid,
	slotid,
	objectid,
	boneid,
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
	material_color_2)
{
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_SlotId]			= slotid;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_ObjectId]		= objectid;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_BoneId]			= boneid;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fOffsetX]		= offset_x;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fOffsetY]		= offset_y;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fOffsetZ]		= offset_z;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fRotX]			= rot_x;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fRotY]			= rot_y;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fRotZ]			= rot_z;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fScaleX]		= scale_x;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fScaleY]		= scale_y;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_fScaleZ]		= scale_z;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_materialcolor1]	= material_color_1;
	aeditbutton_TempStructure[playerid][slotid][aeditbutton_materialcolor2]	= material_color_2;
	return 1;
}

static aeditbutton_SetTempAttachObject(playerid, slotid)
{
	new
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

	attacheditbtn_GetTempAttach(
		playerid,
		slotid,
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
	SetPlayerAttachedObject(
		playerid,
		slotid,
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
	return 1;
}

stock attacheditbtn_PressSave(playerid)
{
	new
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

	foreach (AttachMultiObjectSlots[playerid], i)
	{
		attacheditbtn_GetTempAttach(
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
		attachmain_SetMainAttachData(
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
		attachmain_SetMainAttachObject(playerid, i);
		attachmain_JsonSaveAttach(playerid, i);
	}
	gui_ath_edit_DestroyTextdraws(playerid);
	attacheditbtn_SetStartEdit(playerid, false);
	gui_atatch_menu_SetBannedPanel(playerid, false);
	return 1;
}

stock attacheditbtn_PressCancel(playerid)
{
	new
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

	foreach (AttachMultiObjectSlots[playerid], i)
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
		attachmain_SetMainAttachData(
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
		attachmain_SetMainAttachObject(playerid, i);
	}
	gui_ath_edit_DestroyTextdraws(playerid);
	gui_atatch_menu_SetBannedPanel(playerid, false);
	attacheditbtn_SetStartEdit(playerid, false);
	return 1;
}

stock attacheditbtn_IsStartEdit(playerid)
{
	return gAttachEditButtonStart[playerid];
}

stock attacheditbtn_SetStartEdit(playerid, bool: value)
{
	gAttachEditButtonStart[playerid] = value;
	return 1;
}