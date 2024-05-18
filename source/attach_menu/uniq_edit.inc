#if defined _attach_uniq_button_inc
	#endinput
#endif
#define _attach_uniq_button_inc

const ATTACH_UNIQEDIT_TIMER_UPDATE					= 8;

static enum e_attach_uniq_edit_struct
{
	Float:attachuniqedit_MinX,
	Float:attachuniqedit_MaxX,
	Float:attachuniqedit_MinY,
	Float:attachuniqedit_MaxY
}
static const Float:gAttachUniqEditCoordButtons[][e_attach_uniq_edit_struct] =
{
	{
		0.6536,	//min x
		0.6781,	//max x

		0.3944,	//min y
		0.4203	//max y
	},
	{
		0.7124,	//min x
		0.7354,	//max x

		0.4666,	//min y
		0.5805	//max y
	},
	{
		0.6536,	//min x
		0.6781,	//max x

		0.5537,	//min y
		0.5805	//max y
	},
	{
		0.3156,	//min x
		0.3380,	//max x

		0.3888,	//min y
		0.4194	//max y
	},
	{
		0.2526,	//min x
		0.2729,	//max x

		0.4694,	//min y
		0.5055	//max y
	},
	{
		0.3119,	//min x
		0.3369,	//max x

		0.5546,	//min y
		0.5842	//max y
	},
	{
		0.4406,	//min x
		0.4614,	//max x

		0.2490,	//min y
		0.2851	//max y
	},
	{
		0.5395,	//min x
		0.5593,	//max x

		0.2481,	//min y
		0.2833	//max y
	},
	{
		0.4890,	//min x
		0.5088,	//max x

		0.3055,	//min y
		0.3314	//max y
	}
};

static enum
{
	UNIQ_EDIT_BUTTON_OFFSET_X,
	UNIQ_EDIT_BUTTON_OFFSET_Y,
	UNIQ_EDIT_BUTTON_OFFSET_Z,

	UNIQ_EDIT_BUTTON_ROT_X,
	UNIQ_EDIT_BUTTON_ROT_Y,
	UNIQ_EDIT_BUTTON_ROT_Z,

	UNIQ_EDIT_BUTTON_SCALE_X,
	UNIQ_EDIT_BUTTON_SCALE_Y,
	UNIQ_EDIT_BUTTON_SCALE_Z,
}

static enum e_edit_uniq_temp_struct
{
	uniqedit_ObjectId,
	uniqedit_BoneId,
	Float:uniqedit_fOffsetX,
	Float:uniqedit_fOffsetY,
	Float:uniqedit_fOffsetZ,
	Float:uniqedit_fRotX,
	Float:uniqedit_fRotY,
	Float:uniqedit_fRotZ,
	Float:uniqedit_fScaleX,
	Float:uniqedit_fScaleY,
	Float:uniqedit_fScaleZ,
	uniqedit_materialcolor1,
	uniqedit_materialcolor2
}
static
	uniqedit_TempStructure[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][e_edit_uniq_temp_struct],
	bool:gAttachUniqStartEdit[MAX_PLAYERS],
	Iterator:UniqEditAttachs<MAX_PLAYER_ATTACHED_OBJECTS>,
	gAttachUniqEditTimerMove[MAX_PLAYERS],
	gAttachUniqEditInputType[MAX_PLAYERS];


public OnPlayerDisconnect(playerid, reason)
{
	new timerid = gAttachUniqEditTimerMove[playerid];

	if (timerid != 0)
	{
		KillTimer(timerid);
	}
	gAttachUniqStartEdit[playerid] = false;
	gAttachUniqEditTimerMove[playerid] = false;
#if defined attchdtunq_OnPlayerDisconnect
	return attchdtunq_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect attchdtunq_OnPlayerDisconnect
#if defined    attchdtunq_OnPlayerDisconnect
	forward attchdtunq_OnPlayerDisconnect(playerid, reason);
#endif

public OnVirtualKeyPressed(playerid, key_vk)
{
	if (key_vk == VK_LBUTTON)
	{
		if (gui_ath_uniqedit_IsShowTD(playerid))
		{
			new
				Float:x,
				Float:y,
				
				Float:button_min_x,
				Float:button_max_x,
				Float:button_min_y,
				Float:button_max_y;

			GetMousePos(x, y);

			for (new i; i < sizeof(gAttachUniqEditCoordButtons); i++)
			{
				button_min_x = gAttachUniqEditCoordButtons[i][attachuniqedit_MinX];
				button_max_x = gAttachUniqEditCoordButtons[i][attachuniqedit_MaxX];

				button_min_y = gAttachUniqEditCoordButtons[i][attachuniqedit_MinY];
				button_max_y = gAttachUniqEditCoordButtons[i][attachuniqedit_MaxY];

				if ((button_min_x <= x <= button_max_x)	&& (button_min_y <= y <= button_max_y))
				{
					if (gAttachUniqEditTimerMove[playerid] != 0)
					{
						return 0;
					}
					gAttachUniqEditTimerMove[playerid] = SetTimerEx(
						"@_OnTimerUniqEditMove",
						ATTACH_UNIQEDIT_TIMER_UPDATE,
						false,
						"dd",
						playerid,
						i
					);
					gAttachUniqStartEdit[playerid] = true;
					return 1;
				}
			}
		}
	}
#if defined attchdtunq_OnVirtualKeyPressed
	return attchdtunq_OnVirtualKeyPressed(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyPressed
	#undef OnVirtualKeyPressed
#else
	#define _ALS_OnVirtualKeyPressed
#endif
#define OnVirtualKeyPressed attchdtunq_OnVirtualKeyPressed
#if defined    attchdtunq_OnVirtualKeyPressed
	forward attchdtunq_OnVirtualKeyPressed(playerid, key_vk);
#endif

public OnVirtualKeyReleased(playerid, key_vk)
{
	if (key_vk == VK_LBUTTON)
	{
		new timerid = gAttachUniqEditTimerMove[playerid];

		if (timerid != 0)
		{
			KillTimer(timerid);
			gAttachUniqEditTimerMove[playerid] = 0;
			gAttachUniqStartEdit[playerid] = false;
		}
	}
	else if (key_vk == VK_RBUTTON)
	{
		new
			Float:x,
			Float:y,
			
			Float:button_min_x,
			Float:button_max_x,
			Float:button_min_y,
			Float:button_max_y;

		GetMousePos(x, y);

		for (new i; i < sizeof(gAttachUniqEditCoordButtons); i++)
		{
			button_min_x = gAttachUniqEditCoordButtons[i][attachuniqedit_MinX];
			button_max_x = gAttachUniqEditCoordButtons[i][attachuniqedit_MaxX];

			button_min_y = gAttachUniqEditCoordButtons[i][attachuniqedit_MinY];
			button_max_y = gAttachUniqEditCoordButtons[i][attachuniqedit_MaxY];

			if ((button_min_x <= x <= button_max_x)	&& (button_min_y <= y <= button_max_y))
			{
				gAttachUniqEditInputType[playerid] = i;

				Dialog_Show(playerid, "dAttachMenuUniqEditInput");
				return 1;
			}
		}
	}
#if defined attchdtunq_OnVirtualKeyRlsd
	return attchdtunq_OnVirtualKeyRlsd(playerid, key_vk);
#else
	return 1;
#endif
}
#if defined _ALS_OnVirtualKeyReleased
	#undef OnVirtualKeyReleased
#else
	#define _ALS_OnVirtualKeyReleased
#endif
#define OnVirtualKeyReleased attchdtunq_OnVirtualKeyRlsd
#if defined    attchdtunq_OnVirtualKeyRlsd
	forward attchdtunq_OnVirtualKeyRlsd(playerid, key_vk);
#endif

@_OnTimerUniqEditMove(playerid, button);
@_OnTimerUniqEditMove(playerid, button)
{
	const
		Float:DELIMITER			= 0.005,
		Float:DELIMITER_ROT		= 1.2;

	new
		Float:edit_offset_x,
		Float:edit_offset_y,
		Float:edit_offset_z,
		Float:edit_rot_x,
		Float:edit_rot_y,
		Float:edit_rot_z,
		Float:edit_scale_x,
		Float:edit_scale_y,
		Float:edit_scale_z,
		
		direction = GetMouseDirection();

	switch (button)
	{
		case UNIQ_EDIT_BUTTON_OFFSET_X:
		{
			if (direction == PAE_MOUSE_MOVE_UP)
				edit_offset_x = DELIMITER;

			else if (direction == PAE_MOUSE_MOVE_DOWN)
				edit_offset_x = -DELIMITER;
		}
		case UNIQ_EDIT_BUTTON_OFFSET_Y:
		{
			if (direction == PAE_MOUSE_MOVE_LEFT)
				edit_offset_y = DELIMITER;

			else if (direction == PAE_MOUSE_MOVE_RIGHT)
				edit_offset_y = -DELIMITER;
		}
		case UNIQ_EDIT_BUTTON_OFFSET_Z:
		{
			if (direction == PAE_MOUSE_MOVE_UP)
				edit_offset_z = DELIMITER;

			else if (direction == PAE_MOUSE_MOVE_DOWN)
				edit_offset_z = -DELIMITER;
		}
		case UNIQ_EDIT_BUTTON_ROT_X:
		{
			if (direction == PAE_MOUSE_MOVE_UP)
				edit_rot_x = DELIMITER_ROT;
	
			else if (direction == PAE_MOUSE_MOVE_DOWN)
				edit_rot_x = -DELIMITER_ROT;
		}
		case UNIQ_EDIT_BUTTON_ROT_Y:
		{
			if (direction == PAE_MOUSE_MOVE_LEFT)
				edit_rot_y = DELIMITER_ROT;

			else if (direction == PAE_MOUSE_MOVE_RIGHT)
				edit_rot_y = -DELIMITER_ROT;
		}
		case UNIQ_EDIT_BUTTON_ROT_Z:
		{
			if (direction == PAE_MOUSE_MOVE_UP)
				edit_rot_z = DELIMITER_ROT;

			else if (direction == PAE_MOUSE_MOVE_DOWN)
				edit_rot_z = -DELIMITER_ROT;
		}
		case UNIQ_EDIT_BUTTON_SCALE_X:
		{
			if (direction == PAE_MOUSE_MOVE_LEFT)
				edit_scale_x = DELIMITER;

			else if (direction == PAE_MOUSE_MOVE_RIGHT)
				edit_scale_x = -DELIMITER;
		}
		case UNIQ_EDIT_BUTTON_SCALE_Y:
		{
			if (direction == PAE_MOUSE_MOVE_LEFT)
				edit_scale_y = DELIMITER;

			else if (direction == PAE_MOUSE_MOVE_RIGHT)
				edit_scale_y = -DELIMITER;
		}
		case UNIQ_EDIT_BUTTON_SCALE_Z:
		{
			if (direction == PAE_MOUSE_MOVE_UP)
				edit_scale_z = DELIMITER;

			else if (direction == PAE_MOUSE_MOVE_DOWN)
				edit_scale_z = -DELIMITER;
		}
	}
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
	
	foreach (UniqEditAttachs, i)
	{
		attach_unqedit_GetTempAttach(
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
		offset_x += edit_offset_x;
		offset_y += edit_offset_y;
		offset_z += edit_offset_z;

		rot_x += edit_rot_x;
		rot_y += edit_rot_y;
		rot_z += edit_rot_z;

		scale_x += edit_scale_x;
		scale_y += edit_scale_y;
		scale_z += edit_scale_z;

		attach_unqedit_SetTempAttach(
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
		if (!attachmain_IsUseMultiObject(playerid))
		{
			gui_ath_uniqedit_UpdateCoord(
				offset_x,
				offset_y,
				offset_z,
				rot_x,
				rot_y,
				rot_z,
				scale_x,
				scale_y,
				scale_z
			);
		}
		attach_unqedit_ApplyTempAttach(playerid, i);
	}
	gAttachUniqEditTimerMove[playerid] = SetTimerEx(
		"@_OnTimerUniqEditMove",
		ATTACH_UNIQEDIT_TIMER_UPDATE,
		false,
		"dd",
		playerid,
		button
	);
	return 1;
}

stock attach_unqedit_StartEdit(playerid)
{
	Iter_Clear(UniqEditAttachs);

	gui_ath_uniqedit_ShowTextdraws(playerid);

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

	if (attachmain_IsUseMultiObject(playerid))
	{
		gui_ath_uniqedit_HideCoord(playerid);

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
			attach_unqedit_SetTempAttach(
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
			Iter_Add(UniqEditAttachs, i);
		}
	}
	else
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		attachmain_GetMainAttachData(
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
		attach_unqedit_SetTempAttach(
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
		gui_ath_uniqedit_UpdateCoord(
			offset_x,
			offset_y,
			offset_z,
			rot_x,
			rot_y,
			rot_z,
			scale_x,
			scale_y,
			scale_z
		);
		Iter_Add(UniqEditAttachs, slotid);
	}
	gAttachUniqStartEdit[playerid] = true;
	return 1;
}

static attach_unqedit_GetTempAttach(
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
	objectid			=	uniqedit_TempStructure[playerid][slotid][uniqedit_ObjectId];
	boneid				=	uniqedit_TempStructure[playerid][slotid][uniqedit_BoneId];
	offset_x			=	uniqedit_TempStructure[playerid][slotid][uniqedit_fOffsetX];
	offset_y			=	uniqedit_TempStructure[playerid][slotid][uniqedit_fOffsetY];
	offset_z			=	uniqedit_TempStructure[playerid][slotid][uniqedit_fOffsetZ];
	rot_x				=	uniqedit_TempStructure[playerid][slotid][uniqedit_fRotX];
	rot_y				=	uniqedit_TempStructure[playerid][slotid][uniqedit_fRotY];
	rot_z				=	uniqedit_TempStructure[playerid][slotid][uniqedit_fRotZ];
	scale_x				=	uniqedit_TempStructure[playerid][slotid][uniqedit_fScaleX];
	scale_y				=	uniqedit_TempStructure[playerid][slotid][uniqedit_fScaleY];
	scale_z				=	uniqedit_TempStructure[playerid][slotid][uniqedit_fScaleZ];
	material_color_1	=	uniqedit_TempStructure[playerid][slotid][uniqedit_materialcolor1];
	material_color_2	=	uniqedit_TempStructure[playerid][slotid][uniqedit_materialcolor2];
	return 1;
}

static attach_unqedit_SetTempAttach(
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
	uniqedit_TempStructure[playerid][slotid][uniqedit_ObjectId]			= objectid;
	uniqedit_TempStructure[playerid][slotid][uniqedit_BoneId]			= boneid;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fOffsetX]			= offset_x;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fOffsetY]			= offset_y;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fOffsetZ]			= offset_z;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fRotX]			= rot_x;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fRotY]			= rot_y;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fRotZ]			= rot_z;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fScaleX]			= scale_x;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fScaleY]			= scale_y;
	uniqedit_TempStructure[playerid][slotid][uniqedit_fScaleZ]			= scale_z;
	uniqedit_TempStructure[playerid][slotid][uniqedit_materialcolor1]	= material_color_1;
	uniqedit_TempStructure[playerid][slotid][uniqedit_materialcolor2]	= material_color_2;
	return 1;
}

static attach_unqedit_ApplyTempAttach(playerid, slotid)
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

	attach_unqedit_GetTempAttach(
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

stock attach_unqedit_PressSave(playerid)
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

	foreach (UniqEditAttachs, i)
	{
		attach_unqedit_GetTempAttach(
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
		attachmain_ApplyMainAttach(playerid, i);
		project_JsonSaveAttach(playerid, i);
	}
	gui_atatch_menu_SetBannedPanel(playerid, false);

	gAttachUniqStartEdit[playerid] = false;
	return 1;
}

stock attach_unqedit_PressCancel(playerid)
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

	if (attachmain_IsUseMultiObject(playerid))
	{
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
			attachmain_ApplyMainAttach(playerid, i);
		}
	}
	else
	{
		new slotid = attachmain_GetCurrentSlotId(playerid);

		attachmain_GetMainAttachData(
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
		attachmain_SetMainAttachData(
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
		attachmain_ApplyMainAttach(playerid, slotid);
	}
	gui_atatch_menu_SetBannedPanel(playerid, false);

	gAttachUniqStartEdit[playerid] = false;
	return 1;
}

DialogCreate:dAttachMenuUniqEditInput(playerid)
{
	Dialog_Open(
		playerid,
		Dialog:dAttachMenuUniqEditInput,
		DIALOG_STYLE_INPUT,
		name_dialog_header,
		"DG_ANEW_INPUT_DATA",
		"»",
		"X"
	);
	return 1;
}

DialogResponse:dAttachMenuUniqEditInput(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		return 0;
	}
	new Float:value;

	if (sscanf(inputtext, "f", value))
	{
		Dialog_Show(playerid, "dAttachMenuUniqEditInput");
		return 0;
	}
	new button = gAttachUniqEditInputType[playerid];

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
	
	foreach (UniqEditAttachs, i)
	{
		attach_unqedit_GetTempAttach(
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
		switch (button)
		{
			case UNIQ_EDIT_BUTTON_OFFSET_X:		offset_x = value;
			case UNIQ_EDIT_BUTTON_OFFSET_Y:		offset_y = value;
			case UNIQ_EDIT_BUTTON_OFFSET_Z:		offset_z = value;
			case UNIQ_EDIT_BUTTON_ROT_X:		rot_x = value;
			case UNIQ_EDIT_BUTTON_ROT_Y:		rot_y = value;
			case UNIQ_EDIT_BUTTON_ROT_Z:		rot_z = value;
			case UNIQ_EDIT_BUTTON_SCALE_X:		scale_x = value;
			case UNIQ_EDIT_BUTTON_SCALE_Y:		scale_y = value;
			case UNIQ_EDIT_BUTTON_SCALE_Z:		scale_z = value;
		}
		attach_unqedit_SetTempAttach(
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
		if (!attachmain_IsUseMultiObject(playerid))
		{
			gui_ath_uniqedit_UpdateCoord(
				offset_x,
				offset_y,
				offset_z,
				rot_x,
				rot_y,
				rot_z,
				scale_x,
				scale_y,
				scale_z
			);
		}
		attach_unqedit_ApplyTempAttach(playerid, i);
	}
	return 1;
}

stock attach_unqedit_IsStartEdit(playerid)
{
	return gAttachUniqStartEdit[playerid];
}
