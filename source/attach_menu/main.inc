#if defined _attach_main_inc
	#endinput
#endif
#define _attach_main_inc


static const gAttachMainBoneId[CORE_MAX_COUNT_BONE] =
{
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18
};

static const gAttachMainBoneName[LANGUAGE_MAX_COUNT][CORE_MAX_COUNT_BONE][CORE_MAX_LENGHT_NAME_BONE + 1];


static enum e_attach_data_struct
{
	abone_SlotId,
	abone_ObjectId,
	abone_BoneId,
	Float:abone_fOffsetX,
	Float:abone_fOffsetY,
	Float:abone_fOffsetZ,
	Float:abone_fRotX,
	Float:abone_fRotY,
	Float:abone_fRotZ,
	Float:abone_fScaleX,
	Float:abone_fScaleY,
	Float:abone_fScaleZ,
	abone_materialcolor1,
	abone_materialcolor2
}
static abone_Structure[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][e_attach_data_struct];
static gAttachMainUseCurrentSloteId[MAX_PLAYERS];
static gAttachMainNoteBone[MAX_PLAYERS][MAX_PLAYER_ATTACHED_OBJECTS][CORE_MAX_LENGHT_NAME_NOTE + 1];
new IteratorArray: AttachObjectSlots[MAX_PLAYERS]<MAX_PLAYER_ATTACHED_OBJECTS>;


public OnGameModeInit()
{
	Iter_Init(AttachObjectSlots);
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

/*
	functions
*/


stock attachmain_GetBoneId(index)
{
	return gAttachMainBoneId[index];
}

stock attachmain_GetBoneName(language, boneid, name[], const size = sizeof(name))
{
	name[0] = EOS;
	strcat(name, gAttachMainBoneName[language][boneid], size);
	return 1;
}

stock attachmain_SetBoneName(language, boneid, const name[])
{
	strcat(gAttachMainBoneName[language][boneid], name);
	return 1;
}

stock attachmain_GetBoneSlotId(playerid, slotid)
{
	return abone_Structure[playerid][slotid][abone_BoneId];
}

stock attachmain_SetBoneSlotId(playerid, index, value)
{
	abone_Structure[playerid][index][abone_BoneId] = value;
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
	return abone_Structure[playerid][index][abone_ObjectId];
}

stock attachmain_SetObjectSlotId(playerid, index, value)
{
	abone_Structure[playerid][index][abone_ObjectId] = value;
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
	return abone_Structure[playerid][index][abone_SlotId];
}

stock attachmain_SetSlotId(playerid, index, value)
{
	abone_Structure[playerid][index][abone_SlotId] = value;

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
	abone_Structure[playerid][index][abone_materialcolor1] = value;
	return 1;
}

stock attachmain_SetMaterialColor2(playerid, index, value)
{
	abone_Structure[playerid][index][abone_materialcolor2] = value;
	return 1;
}

stock attachmain_GetAttachInfo(
	playerid,
	slotid,
	&objectid,
	&boneid,
	&Float:fOffsetX,
	&Float:fOffsetY,
	&Float:fOffsetZ,
	&Float:fRotX,
	&Float:fRotY,
	&Float:fRotZ,
	&Float:fScaleX,
	&Float:fScaleY,
	&Float:fScaleZ,
	&materialcolor1,
	&materialcolor2)
{
	objectid		=	abone_Structure[playerid][slotid][abone_ObjectId];
	boneid			=	abone_Structure[playerid][slotid][abone_BoneId];
	fOffsetX		=	abone_Structure[playerid][slotid][abone_fOffsetX];
	fOffsetY		=	abone_Structure[playerid][slotid][abone_fOffsetY];
	fOffsetZ		=	abone_Structure[playerid][slotid][abone_fOffsetZ];
	fRotX			=	abone_Structure[playerid][slotid][abone_fRotX];
	fRotY			=	abone_Structure[playerid][slotid][abone_fRotY];
	fRotZ			=	abone_Structure[playerid][slotid][abone_fRotZ];
	fScaleX			=	abone_Structure[playerid][slotid][abone_fScaleX];
	fScaleY			=	abone_Structure[playerid][slotid][abone_fScaleY];
	fScaleZ			=	abone_Structure[playerid][slotid][abone_fScaleZ];
	materialcolor1	=	abone_Structure[playerid][slotid][abone_materialcolor1];
	materialcolor2	=	abone_Structure[playerid][slotid][abone_materialcolor2];
	return 1;
}


stock attachmain_SetAttachInfo(
	playerid,
	slotid,
	objectid,
	boneid,
	Float:fOffsetX,
	Float:fOffsetY,
	Float:fOffsetZ,
	Float:fRotX,
	Float:fRotY,
	Float:fRotZ,
	Float:fScaleX,
	Float:fScaleY,
	Float:fScaleZ,
	materialcolor1,
	materialcolor2)
{
	abone_Structure[playerid][slotid][abone_SlotId]				= slotid;
	abone_Structure[playerid][slotid][abone_ObjectId]			= objectid;
	abone_Structure[playerid][slotid][abone_BoneId]				= boneid;
	abone_Structure[playerid][slotid][abone_fOffsetX]			= fOffsetX;
	abone_Structure[playerid][slotid][abone_fOffsetY]			= fOffsetY;
	abone_Structure[playerid][slotid][abone_fOffsetZ]			= fOffsetZ;
	abone_Structure[playerid][slotid][abone_fRotX]				= fRotX;
	abone_Structure[playerid][slotid][abone_fRotY]				= fRotY;
	abone_Structure[playerid][slotid][abone_fRotZ]				= fRotZ;
	abone_Structure[playerid][slotid][abone_fScaleX]			= fScaleX;
	abone_Structure[playerid][slotid][abone_fScaleY]			= fScaleY;
	abone_Structure[playerid][slotid][abone_fScaleZ]			= fScaleZ;
	abone_Structure[playerid][slotid][abone_materialcolor1]		= materialcolor1;
	abone_Structure[playerid][slotid][abone_materialcolor2]		= materialcolor2;
	return 1;
}

stock attachmain_SetAttachCoord(
	playerid,
	slotid,
	Float:fOffsetX,
	Float:fOffsetY,
	Float:fOffsetZ,
	Float:fRotX,
	Float:fRotY,
	Float:fRotZ,
	Float:fScaleX,
	Float:fScaleY,
	Float:fScaleZ)
{
	abone_Structure[playerid][slotid][abone_fOffsetX] = fOffsetX;
	abone_Structure[playerid][slotid][abone_fOffsetY] = fOffsetY;
	abone_Structure[playerid][slotid][abone_fOffsetZ] = fOffsetZ;
	abone_Structure[playerid][slotid][abone_fRotX] = fRotX;
	abone_Structure[playerid][slotid][abone_fRotY] = fRotY;
	abone_Structure[playerid][slotid][abone_fRotZ] = fRotZ;
	abone_Structure[playerid][slotid][abone_fScaleX] = fScaleX;
	abone_Structure[playerid][slotid][abone_fScaleY] = fScaleY;
	abone_Structure[playerid][slotid][abone_fScaleZ] = fScaleZ;
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
	abone_Structure[playerid][slotid][abone_SlotId] = ITER_NONE;
	abone_Structure[playerid][slotid][abone_ObjectId] = CORE_INVALID_OBJECT_MODEL;
	abone_Structure[playerid][slotid][abone_BoneId] = 0;
	abone_Structure[playerid][slotid][abone_fOffsetX] = 0.0;
	abone_Structure[playerid][slotid][abone_fOffsetY] = 0.0;
	abone_Structure[playerid][slotid][abone_fOffsetZ] = 0.0;
	abone_Structure[playerid][slotid][abone_fRotX] = 0.0;
	abone_Structure[playerid][slotid][abone_fRotY] = 0.0;
	abone_Structure[playerid][slotid][abone_fRotZ] = 0.0;
	abone_Structure[playerid][slotid][abone_fScaleX] = 1.0;
	abone_Structure[playerid][slotid][abone_fScaleY] = 1.0;
	abone_Structure[playerid][slotid][abone_fScaleZ] = 1.0;
	abone_Structure[playerid][slotid][abone_materialcolor1] = 0;
	abone_Structure[playerid][slotid][abone_materialcolor2] = 0;
	gAttachMainNoteBone[playerid][slotid] = CORE_EMPTY_NOTE;

	RemovePlayerAttachedObject(playerid, slotid);
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

	new JsonNode:node;
	new JsonNode:item;
	new JsonNode:obj;
	new JsonCallResult:result = JSON_ParseFile(name_project, node);

	if (result == JSON_CALL_NO_ERR)
	{
		new note[CORE_MAX_LENGHT_NAME_NOTE + 1];

		new objectid;
		new boneid;
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

		attachmain_GetObjectSlotNote(playerid, slotid, note);

		attachmain_GetAttachInfo(
			playerid,
			slotid,
			objectid,
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
			"fOffsetX", JSON_Float(fOffsetX),
			"fOffsetY", JSON_Float(fOffsetY),
			"fOffsetZ", JSON_Float(fOffsetZ),
			"fRotX", JSON_Float(fRotX),
			"fRotY", JSON_Float(fRotY),
			"fRotZ", JSON_Float(fRotZ),
			"fScaleX", JSON_Float(fScaleX),
			"fScaleY", JSON_Float(fScaleY),
			"fScaleZ", JSON_Float(fScaleZ),
			"materialcolor1", JSON_Int(materialcolor1),
			"materialcolor2", JSON_Int(materialcolor2),
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
	
	new JsonNode:node;
	new JsonNode:item;
	new JsonNode:attachArray;
	new JsonCallResult:result = JSON_ParseFile(name_project, node);

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
