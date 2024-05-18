#if defined _gui_attach_uniq_edit_inc
	#endinput
#endif
#define _gui_attach_uniq_edit_inc

static
	Text:gui_AtchMnuUniqEdit[42],
	bool:gui_AtchMnuUniqEditPlayerShow[MAX_PLAYERS];


enum
{
	GUI_ATTACH_EDIT_POS_X,
	GUI_ATTACH_EDIT_POS_Y,
	GUI_ATTACH_EDIT_POS_Z,
	GUI_ATTACH_EDIT_ROT_X,
	GUI_ATTACH_EDIT_ROT_Y,
	GUI_ATTACH_EDIT_ROT_Z,
	GUI_ATTACH_EDIT_SCALE_X,
	GUI_ATTACH_EDIT_SCALE_Y,
	GUI_ATTACH_EDIT_SCALE_Z
}

public OnGameModeInit()
{
	gui_AtchMnuUniqEdit[0] = TextDrawCreate(319.7001, 119.2775, "LD_SPAC:white"); // Size
	TextDrawTextSize(gui_AtchMnuUniqEdit[0], 1.0000, 22.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[0], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[0], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[0], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[0], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[0], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[0], 0);

	gui_AtchMnuUniqEdit[1] = TextDrawCreate(292.7001, 119.4108, "LD_SPAC:white"); // Size
	TextDrawTextSize(gui_AtchMnuUniqEdit[1], 56.0000, 1.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[1], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[1], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[1], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[1], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[1], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[1], 0);

	gui_AtchMnuUniqEdit[2] = TextDrawCreate(343.0667, 109.9999, ""); // Size
	TextDrawTextSize(gui_AtchMnuUniqEdit[2], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[2], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[2], 950371583);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[2], 0x00000000);
	TextDrawFont(gui_AtchMnuUniqEdit[2], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[2], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[2], 0);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[2], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[2], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[2], 0.0000, -90.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[3] = TextDrawCreate(311.2668, 133.3739, ""); // Size
	TextDrawTextSize(gui_AtchMnuUniqEdit[3], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[3], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[3], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[3], 5);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[3], 0x00000000);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[3], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[3], 0);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[3], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[3], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[3], 0.0000, 180.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[4] = TextDrawCreate(280.8334, 110.0442, ""); // Size
	TextDrawTextSize(gui_AtchMnuUniqEdit[4], 17.9799, 20.0300);
	TextDrawAlignment(gui_AtchMnuUniqEdit[4], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[4], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[4], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[4], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[4], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[4], 0x00000000);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[4], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[4], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[4], 0.0000, 90.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[5] = TextDrawCreate(289.3001, 115.2332, "x"); // Size
	TextDrawLetterSize(gui_AtchMnuUniqEdit[5], 0.1679, 0.8118);
	TextDrawAlignment(gui_AtchMnuUniqEdit[5], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[5], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[5], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[5], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[5], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[5], 0);

	gui_AtchMnuUniqEdit[6] = TextDrawCreate(318.9667, 138.4369, "z"); // Size
	TextDrawLetterSize(gui_AtchMnuUniqEdit[6], 0.1679, 0.8118);
	TextDrawAlignment(gui_AtchMnuUniqEdit[6], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[6], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[6], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[6], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[6], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[6], 0);

	gui_AtchMnuUniqEdit[7] = TextDrawCreate(349.5665, 116.0331, "y"); // Size
	TextDrawLetterSize(gui_AtchMnuUniqEdit[7], 0.1679, 0.6518);
	TextDrawAlignment(gui_AtchMnuUniqEdit[7], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[7], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[7], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[7], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[7], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[7], 0);

	gui_AtchMnuUniqEdit[8] = TextDrawCreate(320.8001, 110.6814, "Scale"); // Size
	TextDrawLetterSize(gui_AtchMnuUniqEdit[8], 0.1249, 0.7920);
	TextDrawAlignment(gui_AtchMnuUniqEdit[8], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[8], 950371583);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[8], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[8], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[8], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[8], 0);

	gui_AtchMnuUniqEdit[9] = TextDrawCreate(426.3334, 182.7924, "LD_SPAC:white"); // position
	TextDrawTextSize(gui_AtchMnuUniqEdit[9], 1.0000, 73.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[9], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[9], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[9], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[9], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[9], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[9], 0);

	gui_AtchMnuUniqEdit[10] = TextDrawCreate(426.6667, 218.4665, "LD_SPAC:white"); // position
	TextDrawTextSize(gui_AtchMnuUniqEdit[10], 37.0000, 1.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[10], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[10], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[10], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[10], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[10], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[10], 0);

	gui_AtchMnuUniqEdit[11] = TextDrawCreate(417.5333, 172.3369, ""); // position
	TextDrawTextSize(gui_AtchMnuUniqEdit[11], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[11], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[11], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[11], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[11], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[11], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[11], 0x00000000);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[11], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[11], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[11], 0.0000, 0.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[12] = TextDrawCreate(417.5667, 246.1740, ""); // position
	TextDrawTextSize(gui_AtchMnuUniqEdit[12], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[12], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[12], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[12], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[12], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[12], 0x00000000);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[12], 0);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[12], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[12], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[12], 0.0000, 180.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[13] = TextDrawCreate(455.1666, 208.8406, ""); // position
	TextDrawTextSize(gui_AtchMnuUniqEdit[13], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[13], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[13], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[13], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[13], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[13], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[13], 0x00000000);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[13], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[13], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[13], 0.0000, -90.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[14] = TextDrawCreate(425.1000, 178.3999, "x"); // position
	TextDrawLetterSize(gui_AtchMnuUniqEdit[14], 0.1679, 0.8118);
	TextDrawAlignment(gui_AtchMnuUniqEdit[14], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[14], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[14], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[14], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[14], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[14], 0);

	gui_AtchMnuUniqEdit[15] = TextDrawCreate(425.3666, 251.3221, "z"); // position
	TextDrawLetterSize(gui_AtchMnuUniqEdit[15], 0.1679, 0.8118);
	TextDrawAlignment(gui_AtchMnuUniqEdit[15], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[15], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[15], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[15], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[15], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[15], 0);

	gui_AtchMnuUniqEdit[16] = TextDrawCreate(461.5999, 215.4036, "y"); // position
	TextDrawLetterSize(gui_AtchMnuUniqEdit[16], 0.1679, 0.6518);
	TextDrawAlignment(gui_AtchMnuUniqEdit[16], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[16], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[16], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[16], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[16], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[16], 0);

	gui_AtchMnuUniqEdit[17] = TextDrawCreate(443.0000, 209.9223, "Position"); // position
	TextDrawLetterSize(gui_AtchMnuUniqEdit[17], 0.1249, 0.7620);
	TextDrawAlignment(gui_AtchMnuUniqEdit[17], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[17], 950371583);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[17], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[17], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[17], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[17], 0);

	gui_AtchMnuUniqEdit[18] = TextDrawCreate(208.7001, 182.7924, "LD_SPAC:white"); // rotattion
	TextDrawTextSize(gui_AtchMnuUniqEdit[18], 1.0000, 73.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[18], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[18], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[18], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[18], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[18], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[18], 0);

	gui_AtchMnuUniqEdit[19] = TextDrawCreate(171.7001, 218.0516, "LD_SPAC:white"); // rotattion
	TextDrawTextSize(gui_AtchMnuUniqEdit[19], 37.0000, 1.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[19], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[19], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[19], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[19], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[19], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[19], 0);

	gui_AtchMnuUniqEdit[20] = TextDrawCreate(199.9001, 172.3369, ""); // rotattion
	TextDrawTextSize(gui_AtchMnuUniqEdit[20], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[20], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[20], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[20], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[20], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[20], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[20], 0x00000000);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[20], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[20], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[20], 0.0000, 0.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[21] = TextDrawCreate(199.9335, 246.1739, ""); // rotattion
	TextDrawTextSize(gui_AtchMnuUniqEdit[21], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[21], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[21], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[21], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[21], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[21], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[21], 0x00000000);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[21], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[21], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[21], 0.0000, 180.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[22] = TextDrawCreate(159.1333, 208.4257, ""); // rotattion
	TextDrawTextSize(gui_AtchMnuUniqEdit[22], 18.0000, 20.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[22], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[22], 950371583);
	TextDrawFont(gui_AtchMnuUniqEdit[22], 5);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[22], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[22], 0);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[22], 0x00000000);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[22], true);
	TextDrawSetPreviewModel(gui_AtchMnuUniqEdit[22], 19134);
	TextDrawSetPreviewRot(gui_AtchMnuUniqEdit[22], 0.0000, 90.0000, 90.0000, 1.0000);

	gui_AtchMnuUniqEdit[23] = TextDrawCreate(207.4668, 178.3999, "x"); // rotattion
	TextDrawLetterSize(gui_AtchMnuUniqEdit[23], 0.1679, 0.8118);
	TextDrawAlignment(gui_AtchMnuUniqEdit[23], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[23], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[23], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[23], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[23], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[23], 0);

	gui_AtchMnuUniqEdit[24] = TextDrawCreate(207.7334, 251.3220, "z"); // rotattion
	TextDrawLetterSize(gui_AtchMnuUniqEdit[24], 0.1679, 0.8118);
	TextDrawAlignment(gui_AtchMnuUniqEdit[24], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[24], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[24], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[24], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[24], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[24], 0);

	gui_AtchMnuUniqEdit[25] = TextDrawCreate(167.7666, 214.2591, "y"); // rotattion
	TextDrawLetterSize(gui_AtchMnuUniqEdit[25], 0.1679, 0.6518);
	TextDrawAlignment(gui_AtchMnuUniqEdit[25], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[25], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[25], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[25], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[25], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[25], 0);

	gui_AtchMnuUniqEdit[26] = TextDrawCreate(191.7998, 209.5074, "Rotattion"); // rotattion
	TextDrawLetterSize(gui_AtchMnuUniqEdit[26], 0.1249, 0.7620);
	TextDrawAlignment(gui_AtchMnuUniqEdit[26], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[26], 950371583);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[26], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[26], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[26], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[26], 0);

	gui_AtchMnuUniqEdit[27] = TextDrawCreate(426.6666, 165.8407, "0.0000"); // pos x
	TextDrawLetterSize(gui_AtchMnuUniqEdit[27], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[27], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[27], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[27], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[27], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[27], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[27], 0);

	gui_AtchMnuUniqEdit[28] = TextDrawCreate(481.1333, 213.2296, "0.0000"); // pos y
	TextDrawLetterSize(gui_AtchMnuUniqEdit[28], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[28], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[28], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[28], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[28], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[28], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[28], 0);

	gui_AtchMnuUniqEdit[29] = TextDrawCreate(427.6666, 263.3075, "0.0000"); // pos z
	TextDrawLetterSize(gui_AtchMnuUniqEdit[29], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[29], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[29], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[29], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[29], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[29], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[29], 0);

	gui_AtchMnuUniqEdit[30] = TextDrawCreate(209.3332, 164.5816, "0.0000"); // rot x
	TextDrawLetterSize(gui_AtchMnuUniqEdit[30], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[30], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[30], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[30], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[30], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[30], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[30], 0);

	gui_AtchMnuUniqEdit[31] = TextDrawCreate(151.7333, 213.5297, "0.0000"); // rot y
	TextDrawLetterSize(gui_AtchMnuUniqEdit[31], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[31], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[31], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[31], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[31], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[31], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[31], 0);

	gui_AtchMnuUniqEdit[32] = TextDrawCreate(208.4000, 263.0632, "0.0000"); // rot z
	TextDrawLetterSize(gui_AtchMnuUniqEdit[32], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[32], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[32], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[32], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[32], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[32], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[32], 0);

	gui_AtchMnuUniqEdit[33] = TextDrawCreate(272.7333, 115.3891, "0.0000"); // size x
	TextDrawLetterSize(gui_AtchMnuUniqEdit[33], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[33], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[33], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[33], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[33], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[33], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[33], 0);

	gui_AtchMnuUniqEdit[34] = TextDrawCreate(368.3999, 114.5595, "0.0000"); // size y
	TextDrawLetterSize(gui_AtchMnuUniqEdit[34], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[34], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[34], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[34], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[34], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[34], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[34], 0);

	gui_AtchMnuUniqEdit[35] = TextDrawCreate(320.7332, 149.5891, "0.0000"); // size z
	TextDrawLetterSize(gui_AtchMnuUniqEdit[35], 0.1266, 0.9653);
	TextDrawAlignment(gui_AtchMnuUniqEdit[35], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[35], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[35], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[35], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[35], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[35], 0);

	gui_AtchMnuUniqEdit[36] = TextDrawCreate(450.7663, 330.8100, "LD_SPAC:white");
	TextDrawTextSize(gui_AtchMnuUniqEdit[36], 63.0000, 11.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[36], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[36], 370480895);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[36], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[36], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[36], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[36], 0);

	gui_AtchMnuUniqEdit[37] = TextDrawCreate(444.1999, 328.2217, "LD_BEAT:chit");
	TextDrawTextSize(gui_AtchMnuUniqEdit[37], 12.0000, 16.4500);
	TextDrawAlignment(gui_AtchMnuUniqEdit[37], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[37], 370480895);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[37], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[37], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[37], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[37], 0);

	gui_AtchMnuUniqEdit[38] = TextDrawCreate(508.2665, 328.2218, "LD_BEAT:chit");
	TextDrawTextSize(gui_AtchMnuUniqEdit[38], 12.0000, 16.4500);
	TextDrawAlignment(gui_AtchMnuUniqEdit[38], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[38], 370480895);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[38], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[38], 4);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[38], 0);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[38], 0);

	gui_AtchMnuUniqEdit[39] = TextDrawCreate(479.7670, 327.7330, "/");
	TextDrawLetterSize(gui_AtchMnuUniqEdit[39], 0.4000, 1.7099);
	TextDrawAlignment(gui_AtchMnuUniqEdit[39], 1);
	TextDrawColor(gui_AtchMnuUniqEdit[39], 606151167);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[39], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[39], 1);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[39], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[39], 0);

	gui_AtchMnuUniqEdit[40] = TextDrawCreate(465.6317, 331.6221, "SAVE");
	TextDrawLetterSize(gui_AtchMnuUniqEdit[40], 0.1613, 0.8450);
	TextDrawTextSize(gui_AtchMnuUniqEdit[40], 7.0000, 24.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[40], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[40], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[40], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[40], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[40], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[40], 0);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[40], true);

	gui_AtchMnuUniqEdit[41] = TextDrawCreate(500.5641, 331.8219, "CANCEL");
	TextDrawLetterSize(gui_AtchMnuUniqEdit[41], 0.1613, 0.8450);
	TextDrawTextSize(gui_AtchMnuUniqEdit[41], 7.0000, 30.0000);
	TextDrawAlignment(gui_AtchMnuUniqEdit[41], 2);
	TextDrawColor(gui_AtchMnuUniqEdit[41], -1);
	TextDrawBackgroundColor(gui_AtchMnuUniqEdit[41], 255);
	TextDrawFont(gui_AtchMnuUniqEdit[41], 2);
	TextDrawSetProportional(gui_AtchMnuUniqEdit[41], 1);
	TextDrawSetShadow(gui_AtchMnuUniqEdit[41], 0);
	TextDrawSetSelectable(gui_AtchMnuUniqEdit[41], true);
#if defined guiatachedit_OnGameModeInit
	return guiatachedit_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit guiatachedit_OnGameModeInit
#if defined    guiatachedit_OnGameModeInit
	forward guiatachedit_OnGameModeInit();
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (gui_ath_uniqedit_IsShowTD(playerid))
	{
		if (clickedid == Text:INVALID_TEXT_DRAW)
		{
			gui_ath_uniqedit_HideTextdraws(playerid);
			attach_unqedit_PressCancel(playerid);
			gui_atatch_menu_ShowCursor(playerid);
		}
		new
			Text:textdraw_save = gui_AtchMnuUniqEdit[40],
			Text:textdraw_cancel = gui_AtchMnuUniqEdit[41];

		if (clickedid == textdraw_save)
		{
			attach_unqedit_PressSave(playerid);
			
			gui_ath_uniqedit_HideTextdraws(playerid);
			attach_unqedit_PressCancel(playerid);
			gui_atatch_menu_ShowCursor(playerid);
		}
		else if (clickedid == textdraw_cancel)
		{
			gui_ath_uniqedit_HideTextdraws(playerid);
			attach_unqedit_PressCancel(playerid);
			gui_atatch_menu_ShowCursor(playerid);
		}
	}
#if defined guiatachedit_OnClickTextDraw
	return guiatachedit_OnClickTextDraw(playerid, Text:clickedid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw guiatachedit_OnClickTextDraw
#if defined    guiatachedit_OnClickTextDraw
	forward guiatachedit_OnClickTextDraw(playerid, Text:clickedid);
#endif

stock gui_ath_uniqedit_ShowTextdraws(playerid)
{
	if (gui_ath_uniqedit_IsShowTD(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AtchMnuUniqEdit); i++)
	{
		TextDrawShowForPlayer(
			playerid,
			gui_AtchMnuUniqEdit[i]
		);
	}
	SelectTextDraw(playerid, COLOR_TD_CLICK);

	gui_AtchMnuUniqEditPlayerShow[playerid] = true;
	return 1;
}

stock gui_ath_uniqedit_HideTextdraws(playerid)
{
	if (!gui_ath_uniqedit_IsShowTD(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AtchMnuUniqEdit); i++)
	{
		TextDrawHideForPlayer(
			playerid,
			gui_AtchMnuUniqEdit[i]
		);
	}
	SelectTextDraw(playerid, COLOR_TD_CLICK);

	gui_AtchMnuUniqEditPlayerShow[playerid] = false;
	return 1;
}

stock gui_ath_uniqedit_HideCoord(playerid)
{
	if (!gui_ath_uniqedit_IsShowTD(playerid))
	{
		return 0;
	}
	for (new i = 27; i < 36; i++)
	{
		TextDrawHideForPlayer(playerid, gui_AtchMnuUniqEdit[i]);
	}
	return 1;
}

stock gui_ath_uniqedit_IsShowTD(playerid)
{
	return gui_AtchMnuUniqEditPlayerShow[playerid];
}

stock gui_ath_uniqedit_UpdateCoord(
	Float:pos_x,
	Float:pos_y,
	Float:pos_z,
	Float:rot_x,
	Float:rot_y,
	Float:rot_z,
	Float:scale_x,
	Float:scale_y,
	Float:scale_z)
{
	new string[10];

	format(string, sizeof(string), "%f", pos_x);
	TextDrawSetString(gui_AtchMnuUniqEdit[27], string);

	format(string, sizeof(string), "%f", pos_y);
	TextDrawSetString(gui_AtchMnuUniqEdit[28], string);

	format(string, sizeof(string), "%f", pos_z);
	TextDrawSetString(gui_AtchMnuUniqEdit[29], string);

	format(string, sizeof(string), "%f", rot_x);
	TextDrawSetString(gui_AtchMnuUniqEdit[30], string);

	format(string, sizeof(string), "%f", rot_y);
	TextDrawSetString(gui_AtchMnuUniqEdit[31], string);

	format(string, sizeof(string), "%f", rot_z);
	TextDrawSetString(gui_AtchMnuUniqEdit[32], string);

	format(string, sizeof(string), "%f", scale_x);
	TextDrawSetString(gui_AtchMnuUniqEdit[33], string);

	format(string, sizeof(string), "%f", scale_y);
	TextDrawSetString(gui_AtchMnuUniqEdit[34], string);

	format(string, sizeof(string), "%f", scale_z);
	TextDrawSetString(gui_AtchMnuUniqEdit[35], string);
	return 1;
}