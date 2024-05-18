#if defined _language_inc
	#endinput
#endif
#define _language_inc

static
	gLanguages[MAX_LANGS],
	gLanguagesName[MAX_LANGS][MAX_LANG_NAME],
	Iterator:Languages<MAX_LANGS>;


new gLangArrayBone[MAX_LANGS][CORE_MAX_COUNT_BONE][CORE_MAX_LENGHT_NAME_BONE + 1];


public OnGameModeInit()
{
	new name_file[MAX_LANGS][20 + MAX_LANG_NAME];

	if (fexist("languages/.list.ini"))
	{
		new File:file = fopen("languages/.list.ini", io_read);

		if (file)
		{
			new
				string[126],
				index;

			while (fread(file, string, sizeof(string)))
			{
				sscanf(string, "p<=>s[*]s[*]", MAX_LANG_NAME, gLanguagesName[index], MAX_LANG_NAME, name_file[index]);

				new lenght = strlen(name_file[index]);

				if (name_file[index][lenght - 1] != 'i')
				{
					strdel(name_file[index], lenght - 2, lenght);
				}
				Iter_Add(Languages, index++);
			}
			fclose(file);

			new
				file_lang[11 + MAX_LANG_NAME],
				str_bone[256];

			foreach (Languages, langid)
			{
				file_lang[0] = EOS;

				strcat(file_lang, "languages/");
				strcat(file_lang, name_file[langid]);

				gLanguages[langid] = _:Lang_Add(name_file[langid], gLanguagesName[langid]);
				Lang_LoadFile(Lang:gLanguages[langid], file_lang);

				Lang_GetText(Lang:gLanguages[langid], "AR_NAME_BONE", str_bone);
				sscanf(str_bone, "p<,>a<s[256]>[18]", gLangArrayBone[langid]);
			}
		}
	}
#if defined core_OnGameModeInit
	return core_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit core_OnGameModeInit
#if defined    core_OnGameModeInit
	forward core_OnGameModeInit();
#endif

DialogCreate:dLanguageChoose(playerid)
{
	new string[(4 + MAX_LANG_NAME) * MAX_LANGS];

	foreach (Languages, langid)
	{
		format(string, sizeof(string),
			"%s%s\n",
			string,
			gLanguagesName[langid]
		);
	}
	Dialog_Open(
		playerid,
		Dialog:dLanguageChoose,
		DIALOG_STYLE_LIST,
		name_dialog_header,
		string,
		"»",
		""
	);
	return 1;
}

DialogResponse:dLanguageChoose(playerid, response, listitem, inputtext[])
{
	Lang_SetPlayerLang(playerid, Lang:gLanguages[listitem]);
	language_MessageInfo(playerid, "MSG_START_ROBOT_PRESS_MAIN_END");
	SendClientMessage(playerid, COLOR_WHITE, "");
	return 1;
}

stock language_MessageInfo(playerid, const code[])
{
	new
		string[MAX_CHATBUBBLE_LENGTH + 1],
		str_text[MAX_CHATBUBBLE_LENGTH + 1],
		Lang:lang = Lang_GetPlayerLang(playerid);

	Lang_GetText(Lang:gLanguages[_:lang], code, str_text);

	strcat(string, "[!] "cWhite"");
	strcat(string, str_text);

	SendClientMessage(playerid, COLOR_SERVER_MAIN, string);
	return 1;
}

stock language_MessageError(playerid, const code[])
{
	new
		string[MAX_CHATBUBBLE_LENGTH + 1],
		str_text[MAX_CHATBUBBLE_LENGTH + 1],
		Lang:lang = Lang_GetPlayerLang(playerid);

	Lang_GetText(Lang:gLanguages[_:lang], code, str_text);

	strcat(string, "[x] "cWhite"");
	strcat(string, str_text);

	SendClientMessage(playerid, COLOR_RED, string);
	return 1;
}