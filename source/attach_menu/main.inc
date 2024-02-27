#if defined _attach_main_inc
	#endinput
#endif
#define _attach_main_inc

static const gAttachMainBoneId[CORE_MAX_COUNT_BONE] = {1, 2, ...};
static const gAttachMainBoneName[LANGUAGE_MAX_COUNT][CORE_MAX_COUNT_BONE][CORE_MAX_LENGHT_NAME_BONE + 1];


static const gAttachMainOppositeBoneIds[][] =
{
	{ATTACH_BONE_SPINE, ATTACH_BONE_SPINE},
	{ATTACH_BONE_HEAD, ATTACH_BONE_HEAD},
	{ATTACH_BONE_LEFT_SHOULDER, ATTACH_BONE_RIGHT_SHOULDER},
	{ATTACH_BONE_LEFT_ARM, ATTACH_BONE_RIGHT_ARM},
	{ATTACH_BONE_LEFT_THIGH, ATTACH_BONE_RIGHT_THIGH},
	{ATTACH_BONE_LEFT_LEG, ATTACH_BONE_RIGHT_LEG},
	{ATTACH_BONE_RIGHT_SHIN, ATTACH_BONE_LEFT_SHIN},
	{ATTACH_BONE_LEFT_FOREARM, ATTACH_BONE_RIGHT_FOREARM},
	{ATTACH_BONE_LEFT_CLAVICLE, ATTACH_BONE_RIGHT_CLAVICLE},
	{ATTACH_BONE_NECK, ATTACH_BONE_NECK},
	{ATTACH_BONE_JAW, ATTACH_BONE_JAW}
};


static enum e_attach_data_struct
{
	attachmain_SlotId,
	attachmain_ObjectId,
	attachmain_BoneId,
	Float:attachmain_fOffsetX,
	Float:attachmain_fOffsetY,
	Float:attachmain_fOffsetZ,
	Float:attachmain_fRotX,
	Float:attachmain_fRotY,
	Float:attachmain_fRotZ,
	Float:attachmain_fScaleX,
	Float:attachmain_fScaleY,
	Float:attachmain_fScaleZ,
	attachmain_materialcolor1,
	attachmain_materialcolor2
}
static attachmain_Structure[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][e_attach_data_struct];
static gAttachMainUseCurrentSloteId[MAX_PLAYERS];
static gAttachMainNoteBone[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][CORE_MAX_LENGHT_NAME_NOTE + 1];
static gAttachMenuMultiObject[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS];
new IteratorArray: AttachObjectSlots[MAX_PLAYERS]<MAX_PLAYER_ATTACHED_OBJECTS>;
new IteratorArray: AttachMultiObjectSlots[MAX_PLAYERS]<MAX_PLAYER_ATTACHED_OBJECTS>;


public OnGameModeInit()
{
	Iter_Init(AttachObjectSlots);
	Iter_Init(AttachMultiObjectSlots);
#if defined attachjmain_OnGameModeInit
	return attachjmain_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit attachjmain_OnGameModeInit
#if defined    attachjmain_OnGameModeInit
	forward attachjmain_OnGameModeInit();
#endif

public OnPlayerConnect(playerid)
{
	attachmain_ClearArray(playerid);
#if defined attachjmain_OnPlayerConnect
	return attachjmain_OnPlayerConnect(playerid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect attachjmain_OnPlayerConnect
#if defined    attachjmain_OnPlayerConnect
	forward attachjmain_OnPlayerConnect(playerid);
#endif


public OnPlayerDisconnect(playerid, reason)
{
	attachmain_ClearArray(playerid);
#if defined attachjmain_OnPlayerDisconnect
	return attachjmain_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect attachjmain_OnPlayerDisconnect
#if defined    attachjmain_OnPlayerDisconnect
	forward attachjmain_OnPlayerDisconnect(playerid, reason);
#endif


stock attachmain_GetBoneId(index)
{
	return gAttachMainBoneId[index];
}

stock attachmain_GetBoneName(language, index, name[], const size = sizeof(name))
{
	name[0] = EOS;
	strcat(name, gAttachMainBoneName[language][index], size);
	return 1;
}

stock attachmain_SetBoneName(language, boneid, const name[])
{
	strcat(gAttachMainBoneName[language][boneid], name);
	return 1;
}

stock attachmain_GetBoneSlotId(playerid, slotid)
{
	return attachmain_Structure[playerid][slotid][attachmain_BoneId];
}

stock attachmain_SetBoneSlotId(playerid, index, value)
{
	attachmain_Structure[playerid][index][attachmain_BoneId] = value;
	return 1;
}

stock attachmain_GetCurrentSlotId(playerid)
{
	return gAttachMainUseCurrentSloteId[playerid];
}

stock attachmain_SetCurrentSlotId(playerid, value)
{
	gAttachMainUseCurrentSloteId[playerid] = value;
	return 1;
}

stock attachmain_GetObjectSlotId(playerid, index)
{
	return attachmain_Structure[playerid][index][attachmain_ObjectId];
}

stock attachmain_SetObjectSlotId(playerid, index, value)
{
	attachmain_Structure[playerid][index][attachmain_ObjectId] = value;
	return 1;
}

stock attachmain_SetObjectSlotNote(playerid, index, const note[])
{
	gAttachMainNoteBone[playerid][index][0] = EOS;
	strcat(gAttachMainNoteBone[playerid][index], note);
	return 1;
}

stock attachmain_GetObjectSlotNote(playerid, index, note[], const size = sizeof(note))
{
	note[0] = EOS;
	strcat(note, gAttachMainNoteBone[playerid][index], size);
	return 1;
}

stock attachmain_GetSlotId(playerid, index)
{
	return attachmain_Structure[playerid][index][attachmain_SlotId];
}

stock attachmain_SetSlotId(playerid, index, value)
{
	attachmain_Structure[playerid][index][attachmain_SlotId] = value;

	if (value == ITER_NONE)
	{
		Iter_Remove(AttachObjectSlots[playerid], value);
	}
	else
	{
		Iter_Add(AttachObjectSlots[playerid], value);
	}
	return 1;
}

stock attachmain_SetMaterialColor1(playerid, index, value)
{
	attachmain_Structure[playerid][index][attachmain_materialcolor1] = value;
	return 1;
}

stock attachmain_SetMaterialColor2(playerid, index, value)
{
	attachmain_Structure[playerid][index][attachmain_materialcolor2] = value;
	return 1;
}

stock attachmain_GetMainAttachData(
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
	objectid			=	attachmain_Structure[playerid][slotid][attachmain_ObjectId];
	boneid				=	attachmain_Structure[playerid][slotid][attachmain_BoneId];
	offset_x			=	attachmain_Structure[playerid][slotid][attachmain_fOffsetX];
	offset_y			=	attachmain_Structure[playerid][slotid][attachmain_fOffsetY];
	offset_z			=	attachmain_Structure[playerid][slotid][attachmain_fOffsetZ];
	rot_x				=	attachmain_Structure[playerid][slotid][attachmain_fRotX];
	rot_y				=	attachmain_Structure[playerid][slotid][attachmain_fRotY];
	rot_z				=	attachmain_Structure[playerid][slotid][attachmain_fRotZ];
	scale_x				=	attachmain_Structure[playerid][slotid][attachmain_fScaleX];
	scale_y				=	attachmain_Structure[playerid][slotid][attachmain_fScaleY];
	scale_z				=	attachmain_Structure[playerid][slotid][attachmain_fScaleZ];
	material_color_1	=	attachmain_Structure[playerid][slotid][attachmain_materialcolor1];
	material_color_2	=	attachmain_Structure[playerid][slotid][attachmain_materialcolor2];
	return 1;
}


stock attachmain_SetMainAttachData(
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
	attachmain_Structure[playerid][slotid][attachmain_SlotId]			= slotid;
	attachmain_Structure[playerid][slotid][attachmain_ObjectId]			= objectid;
	attachmain_Structure[playerid][slotid][attachmain_BoneId]			= boneid;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetX]			= offset_x;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetY]			= offset_y;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetZ]			= offset_z;
	attachmain_Structure[playerid][slotid][attachmain_fRotX]			= rot_x;
	attachmain_Structure[playerid][slotid][attachmain_fRotY]			= rot_y;
	attachmain_Structure[playerid][slotid][attachmain_fRotZ]			= rot_z;
	attachmain_Structure[playerid][slotid][attachmain_fScaleX]			= scale_x;
	attachmain_Structure[playerid][slotid][attachmain_fScaleY]			= scale_y;
	attachmain_Structure[playerid][slotid][attachmain_fScaleZ]			= scale_z;
	attachmain_Structure[playerid][slotid][attachmain_materialcolor1]	= material_color_1;
	attachmain_Structure[playerid][slotid][attachmain_materialcolor2]	= material_color_2;
	return 1;
}

stock attachmain_SetAttachCoord(
	playerid,
	slotid,
	Float:offset_x,
	Float:offset_y,
	Float:offset_z,
	Float:rot_x,
	Float:rot_y,
	Float:rot_z,
	Float:scale_x,
	Float:scale_y,
	Float:scale_z)
{
	attachmain_Structure[playerid][slotid][attachmain_fOffsetX] = offset_x;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetY] = offset_y;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetZ] = offset_z;
	attachmain_Structure[playerid][slotid][attachmain_fRotX] = rot_x;
	attachmain_Structure[playerid][slotid][attachmain_fRotY] = rot_y;
	attachmain_Structure[playerid][slotid][attachmain_fRotZ] = rot_z;
	attachmain_Structure[playerid][slotid][attachmain_fScaleX] = scale_x;
	attachmain_Structure[playerid][slotid][attachmain_fScaleY] = scale_y;
	attachmain_Structure[playerid][slotid][attachmain_fScaleZ] = scale_z;
	return 1;
}

stock attachmain_ClearArray(playerid)
{
	for (new i; i < MAX_PLAYER_ATTACHED_OBJECTS; i++)
	{
		attachmain_ClearSlotId(playerid, i);
	}
	Iter_Clear(AttachObjectSlots[playerid]);
	gAttachMainUseCurrentSloteId[playerid] = ITER_NONE;
	return 1;
}

stock attachmain_ClearSlotId(playerid, slotid)
{
	attachmain_Structure[playerid][slotid][attachmain_SlotId] = ITER_NONE;
	attachmain_Structure[playerid][slotid][attachmain_ObjectId] = CORE_INVALID_OBJECT_MODEL;
	attachmain_Structure[playerid][slotid][attachmain_BoneId] = 0;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetX] = 0.0;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetY] = 0.0;
	attachmain_Structure[playerid][slotid][attachmain_fOffsetZ] = 0.0;
	attachmain_Structure[playerid][slotid][attachmain_fRotX] = 0.0;
	attachmain_Structure[playerid][slotid][attachmain_fRotY] = 0.0;
	attachmain_Structure[playerid][slotid][attachmain_fRotZ] = 0.0;
	attachmain_Structure[playerid][slotid][attachmain_fScaleX] = 1.0;
	attachmain_Structure[playerid][slotid][attachmain_fScaleY] = 1.0;
	attachmain_Structure[playerid][slotid][attachmain_fScaleZ] = 1.0;
	attachmain_Structure[playerid][slotid][attachmain_materialcolor1] = 0;
	attachmain_Structure[playerid][slotid][attachmain_materialcolor2] = 0;
	gAttachMainNoteBone[playerid][slotid] = CORE_EMPTY_NOTE;
	gAttachMenuMultiObject[playerid][slotid] = ITER_NONE;

	RemovePlayerAttachedObject(playerid, slotid);
	return 1;
}

stock attachmain_SetMainAttachObject(playerid, slotid)
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

stock attachmain_GetFreeSlotId(playerid)
{
	return Iter_Free(AttachObjectSlots[playerid]);
}

stock attachmain_IterRemoveSlotId(playerid, slotid)
{
	Iter_Remove(AttachObjectSlots[playerid], slotid);
	return 1;
}

stock attachmain_GetFirstSlotId(playerid)
{
	if (Iter_Count(AttachObjectSlots[playerid]) == 0)
	{
		return ITER_NONE;
	}
	return Iter_First(AttachObjectSlots[playerid]);
}

stock attachmain_AddIterSlotId(playerid, slotid)
{
	Iter_Add(AttachObjectSlots[playerid], slotid);
	return 1;
}

stock attachmain_IsUseMultiObject(playerid)
{
	return Iter_Count(AttachMultiObjectSlots[playerid]) != 0;
}

stock attachmain_IsUseMultiObjSlotId(playerid, slotid)
{
	return gAttachMenuMultiObject[playerid][slotid] == slotid;
}

stock attachmain_AddMultiObjSlot(playerid, slotid)
{
	Iter_Add(AttachMultiObjectSlots[playerid], slotid);
	gAttachMenuMultiObject[playerid][slotid] = slotid;
	return 1;
}

stock attachmain_ClearMultiObjSlots(playerid)
{
	foreach (AttachObjectSlots[playerid], i)
	{
		gAttachMenuMultiObject[playerid][i] = ITER_NONE;
	}
	Iter_Clear(AttachMultiObjectSlots[playerid]);
	return 1;
}

stock attachmain_RemoveMultiObjSlot(playerid, slotid)
{
	gAttachMenuMultiObject[playerid][slotid] = ITER_NONE;
	Iter_Remove(AttachMultiObjectSlots[playerid], slotid);
	return 1;
}

stock attachmain_SetMultiObjSlot(playerid, slotid, value)
{
	return gAttachMenuMultiObject[playerid][slotid] = value;
}


stock attachmain_GetMultiObjSlot(playerid, slotid)
{
	return gAttachMenuMultiObject[playerid][slotid];
}


stock attachmain_JsonSaveSkin(playerid)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];
	project_GetJsonName(playerid, name_project);

	new JsonNode:node;
	new JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_SetInt(node, "skinid", GetPlayerSkin(playerid));
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(node);
	return 1;
}

stock attachmain_JsonSaveAnimation(playerid, index_anim)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	project_GetJsonName(playerid, name_project);

	new JsonNode:node;
	new JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		JSON_SetInt(node, "animation", index_anim);
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(node);
	return 1;
}

stock attachmain_JsonSaveAttach(playerid, slotid)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	project_GetJsonName(playerid, name_project);

	new
		JsonNode:node,
		JsonNode:item,
		JsonNode:obj,
		JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new note[CORE_MAX_LENGHT_NAME_NOTE + 1];

		new
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
			material_color_2;

		attachmain_GetObjectSlotNote(playerid, slotid, note);

		attachmain_GetMainAttachData(
			playerid,
			slotid,
			objectid,
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
		new length;
		new json_slotid;

		JSON_GetObject(node, "attach", obj);
		JSON_ArrayLength(obj, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(obj, i, item);

			JSON_GetInt(item, "slotid", json_slotid);

			if (json_slotid == slotid)
			{
				JSON_ArrayRemoveIndex(node, "attach", i);
				break;
			}
		}
		JSON_ArrayAppend(node, "attach", JSON_Object(
			"slotid", JSON_Int(slotid),
			"boneid", JSON_Int(boneid),
			"objectid", JSON_Int(objectid),
			"offset_x", JSON_Float(offset_x),
			"offset_y", JSON_Float(offset_y),
			"offset_z", JSON_Float(offset_z),
			"rot_x", JSON_Float(rot_x),
			"rot_y", JSON_Float(rot_y),
			"rot_z", JSON_Float(rot_z),
			"scale_x", JSON_Float(scale_x),
			"scale_y", JSON_Float(scale_y),
			"scale_z", JSON_Float(scale_z),
			"material_color_1", JSON_Int(material_color_1),
			"material_color_2", JSON_Int(material_color_2),
			"note", JSON_String(note))
		);
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(obj);
	JSON_Cleanup(item);
	JSON_Cleanup(node);
	return 1;
}


stock attachmain_JsonDeleteAttach(playerid, slotid)
{
	new name_project[CORE_MAX_LENGHT_FOLDER_PROJECT];

	project_GetJsonName(playerid, name_project);
	
	new
		JsonNode:node,
		JsonNode:item,
		JsonNode:attachArray,
		JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new length;
		new json_slotid;

		JSON_GetObject(node, "attach", attachArray);
		JSON_ArrayLength(attachArray, length);

		for (new i; i < length; i++)
		{
			JSON_ArrayObject(attachArray, i, item);

			JSON_GetInt(item, "slotid", json_slotid);

			if (json_slotid == slotid)
			{
				JSON_ArrayRemoveIndex(node, "attach", i);
				break;
			}
		}
		JSON_SaveFile(name_project, node, 4);
	}
	JSON_Cleanup(attachArray);
	JSON_Cleanup(item);
	JSON_Cleanup(node);
	return 1;
}

stock attachmain_IsCreateProcess(playerid)
{
	new slotid = attachmain_GetCurrentSlotId(playerid);
	return slotid != ITER_NONE;
}

stock attachmain_IsValidObject(playerid)
{
	new slotid = attachmain_GetCurrentSlotId(playerid);
	new modelid = attachmain_GetObjectSlotId(playerid, slotid);
	return modelid != CORE_INVALID_OBJECT_MODEL;
}

stock attachmain_GetOppositeBoneIds(boneid)
{
	for (new i; i < sizeof(gAttachMainOppositeBoneIds); i++)
	{
		if (boneid == gAttachMainOppositeBoneIds[i][0])
		{
			return gAttachMainOppositeBoneIds[i][1];
		}
	}
	for (new i; i < sizeof(gAttachMainOppositeBoneIds); i++)
	{
		if (boneid == gAttachMainOppositeBoneIds[i][1])
		{
			return gAttachMainOppositeBoneIds[i][0];
		}
	}
	return 1;
}