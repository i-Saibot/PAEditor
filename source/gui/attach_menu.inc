#if defined _gui_attach_menu_inc
	#endinput
#endif
#define _gui_attach_menu_inc

static Text: gui_AttachMenu[57];
static bool: gui_AttachMenuPlayerShow[MAX_PLAYERS];

enum
{
	GUI_ATTACH_MENU_MANAGE,
	GUI_ATTACH_MENU_EXPORT,
	GUI_ATTACH_MENU_NEW,
	GUI_ATTACH_MENU_DELETE,
	GUI_ATTACH_MENU_DUBLICATE,
	GUI_ATTACH_MENU_OBJECT,
	GUI_ATTACH_MENU_EDIT,
	GUI_ATTACH_MENU_COLOR_1,
	GUI_ATTACH_MENU_COLOR_2,
	GUI_ATTACH_MENU_SKIN,
	GUI_ATTACH_MENU_ANIMATIONS,
	GUI_ATTACH_MENU_ANIMATION_CLEAR
}


public OnGameModeInit()
{
	gui_AttachMenu[0] = TextDrawCreate(150.4998, 413.3002, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[0], 337.0871, 34.0000);
	TextDrawAlignment(gui_AttachMenu[0], 1);
	TextDrawColor(gui_AttachMenu[0], 255);
	TextDrawBackgroundColor(gui_AttachMenu[0], 255);
	TextDrawFont(gui_AttachMenu[0], 4);
	TextDrawSetProportional(gui_AttachMenu[0], 0);
	TextDrawSetShadow(gui_AttachMenu[0], 0);

	gui_AttachMenu[1] = TextDrawCreate(151.4999, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[1], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[1], 1);
	TextDrawColor(gui_AttachMenu[1], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[1], 255);
	TextDrawFont(gui_AttachMenu[1], 4);
	TextDrawSetProportional(gui_AttachMenu[1], 0);
	TextDrawSetShadow(gui_AttachMenu[1], 0);
	TextDrawSetSelectable(gui_AttachMenu[1], true);

	gui_AttachMenu[2] = TextDrawCreate(153.8333, 420.1111, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[2], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[2], 1);
	TextDrawColor(gui_AttachMenu[2], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[2], 255);
	TextDrawFont(gui_AttachMenu[2], 4);
	TextDrawSetProportional(gui_AttachMenu[2], 0);
	TextDrawSetShadow(gui_AttachMenu[2], 0);

	gui_AttachMenu[3] = TextDrawCreate(153.8333, 424.0111, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[3], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[3], 1);
	TextDrawColor(gui_AttachMenu[3], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[3], 255);
	TextDrawFont(gui_AttachMenu[3], 4);
	TextDrawSetProportional(gui_AttachMenu[3], 0);
	TextDrawSetShadow(gui_AttachMenu[3], 0);

	gui_AttachMenu[4] = TextDrawCreate(153.8333, 428.4114, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[4], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[4], 1);
	TextDrawColor(gui_AttachMenu[4], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[4], 255);
	TextDrawFont(gui_AttachMenu[4], 4);
	TextDrawSetProportional(gui_AttachMenu[4], 0);
	TextDrawSetShadow(gui_AttachMenu[4], 0);

	gui_AttachMenu[5] = TextDrawCreate(153.8333, 432.4118, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[5], 22.0000, 1.6100);
	TextDrawAlignment(gui_AttachMenu[5], 1);
	TextDrawColor(gui_AttachMenu[5], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[5], 255);
	TextDrawFont(gui_AttachMenu[5], 4);
	TextDrawSetProportional(gui_AttachMenu[5], 0);
	TextDrawSetShadow(gui_AttachMenu[5], 0);

	gui_AttachMenu[6] = TextDrawCreate(155.1001, 437.1445, "Manage");
	TextDrawLetterSize(gui_AttachMenu[6], 0.1720, 0.8116);
	TextDrawTextSize(gui_AttachMenu[6], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[6], 1);
	TextDrawColor(gui_AttachMenu[6], -1);
	TextDrawBackgroundColor(gui_AttachMenu[6], 255);
	TextDrawFont(gui_AttachMenu[6], 1);
	TextDrawSetProportional(gui_AttachMenu[6], 1);
	TextDrawSetShadow(gui_AttachMenu[6], 0);

	gui_AttachMenu[7] = TextDrawCreate(179.6313, 414.6480, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[7], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[7], 1);
	TextDrawColor(gui_AttachMenu[7], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[7], 255);
	TextDrawFont(gui_AttachMenu[7], 4);
	TextDrawSetProportional(gui_AttachMenu[7], 0);
	TextDrawSetShadow(gui_AttachMenu[7], 0);
	TextDrawSetSelectable(gui_AttachMenu[7], true);

	gui_AttachMenu[8] = TextDrawCreate(185.8315, 416.8331, "....");
	TextDrawLetterSize(gui_AttachMenu[8], 0.3916, 1.5377);
	TextDrawAlignment(gui_AttachMenu[8], 1);
	TextDrawColor(gui_AttachMenu[8], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[8], 255);
	TextDrawFont(gui_AttachMenu[8], 1);
	TextDrawSetProportional(gui_AttachMenu[8], 1);
	TextDrawSetShadow(gui_AttachMenu[8], 0);

	gui_AttachMenu[9] = TextDrawCreate(184.3685, 436.9739, "Export");
	TextDrawLetterSize(gui_AttachMenu[9], 0.1843, 0.8198);
	TextDrawTextSize(gui_AttachMenu[9], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[9], 1);
	TextDrawColor(gui_AttachMenu[9], -1);
	TextDrawBackgroundColor(gui_AttachMenu[9], 255);
	TextDrawFont(gui_AttachMenu[9], 1);
	TextDrawSetProportional(gui_AttachMenu[9], 1);
	TextDrawSetShadow(gui_AttachMenu[9], 0);

	gui_AttachMenu[10] = TextDrawCreate(207.5033, 414.6036, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[10], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[10], 1);
	TextDrawColor(gui_AttachMenu[10], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[10], 255);
	TextDrawFont(gui_AttachMenu[10], 4);
	TextDrawSetProportional(gui_AttachMenu[10], 0);
	TextDrawSetShadow(gui_AttachMenu[10], 0);
	TextDrawSetSelectable(gui_AttachMenu[10], true);

	gui_AttachMenu[11] = TextDrawCreate(215.3043, 414.6408, "+");
	TextDrawLetterSize(gui_AttachMenu[11], 0.5015, 2.3046);
	TextDrawTextSize(gui_AttachMenu[11], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[11], 1);
	TextDrawColor(gui_AttachMenu[11], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[11], 255);
	TextDrawFont(gui_AttachMenu[11], 2);
	TextDrawSetProportional(gui_AttachMenu[11], 1);
	TextDrawSetShadow(gui_AttachMenu[11], 0);

	gui_AttachMenu[12] = TextDrawCreate(215.3037, 437.0296, "New");
	TextDrawLetterSize(gui_AttachMenu[12], 0.1949, 0.8197);
	TextDrawTextSize(gui_AttachMenu[12], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[12], 1);
	TextDrawColor(gui_AttachMenu[12], -1);
	TextDrawBackgroundColor(gui_AttachMenu[12], 255);
	TextDrawFont(gui_AttachMenu[12], 1);
	TextDrawSetProportional(gui_AttachMenu[12], 1);
	TextDrawSetShadow(gui_AttachMenu[12], 0);

	gui_AttachMenu[13] = TextDrawCreate(235.4049, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[13], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[13], 1);
	TextDrawColor(gui_AttachMenu[13], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[13], 255);
	TextDrawFont(gui_AttachMenu[13], 4);
	TextDrawSetProportional(gui_AttachMenu[13], 0);
	TextDrawSetShadow(gui_AttachMenu[13], 0);
	TextDrawSetSelectable(gui_AttachMenu[13], true);

	gui_AttachMenu[14] = TextDrawCreate(245.0727, 415.4407, "X");
	TextDrawLetterSize(gui_AttachMenu[14], 0.3114, 2.1223);
	TextDrawTextSize(gui_AttachMenu[14], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[14], 1);
	TextDrawColor(gui_AttachMenu[14], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[14], 255);
	TextDrawFont(gui_AttachMenu[14], 2);
	TextDrawSetProportional(gui_AttachMenu[14], 1);
	TextDrawSetShadow(gui_AttachMenu[14], 0);

	gui_AttachMenu[15] = TextDrawCreate(240.7054, 437.4443, "Delete");
	TextDrawLetterSize(gui_AttachMenu[15], 0.1782, 0.8155);
	TextDrawTextSize(gui_AttachMenu[15], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[15], 1);
	TextDrawColor(gui_AttachMenu[15], -1);
	TextDrawBackgroundColor(gui_AttachMenu[15], 255);
	TextDrawFont(gui_AttachMenu[15], 1);
	TextDrawSetProportional(gui_AttachMenu[15], 1);
	TextDrawSetShadow(gui_AttachMenu[15], 0);

	gui_AttachMenu[16] = TextDrawCreate(263.5068, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[16], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[16], 1);
	TextDrawColor(gui_AttachMenu[16], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[16], 255);
	TextDrawFont(gui_AttachMenu[16], 4);
	TextDrawSetProportional(gui_AttachMenu[16], 0);
	TextDrawSetShadow(gui_AttachMenu[16], 0);
	TextDrawSetSelectable(gui_AttachMenu[16], true);

	gui_AttachMenu[17] = TextDrawCreate(270.1416, 420.3630, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[17], 9.0000, 9.0000);
	TextDrawAlignment(gui_AttachMenu[17], 1);
	TextDrawColor(gui_AttachMenu[17], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[17], 255);
	TextDrawFont(gui_AttachMenu[17], 4);
	TextDrawSetProportional(gui_AttachMenu[17], 0);
	TextDrawSetShadow(gui_AttachMenu[17], 0);

	gui_AttachMenu[18] = TextDrawCreate(274.6755, 424.5111, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[18], 9.0000, 9.0000);
	TextDrawAlignment(gui_AttachMenu[18], 1);
	TextDrawColor(gui_AttachMenu[18], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[18], 255);
	TextDrawFont(gui_AttachMenu[18], 4);
	TextDrawSetProportional(gui_AttachMenu[18], 0);
	TextDrawSetShadow(gui_AttachMenu[18], 0);

	gui_AttachMenu[19] = TextDrawCreate(264.9068, 436.8442, "Dublicate");
	TextDrawLetterSize(gui_AttachMenu[19], 0.1736, 0.8327);
	TextDrawTextSize(gui_AttachMenu[19], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[19], 1);
	TextDrawColor(gui_AttachMenu[19], -1);
	TextDrawBackgroundColor(gui_AttachMenu[19], 255);
	TextDrawFont(gui_AttachMenu[19], 1);
	TextDrawSetProportional(gui_AttachMenu[19], 1);
	TextDrawSetShadow(gui_AttachMenu[19], 0);

	gui_AttachMenu[20] = TextDrawCreate(291.5084, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[20], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[20], 1);
	TextDrawColor(gui_AttachMenu[20], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[20], 255);
	TextDrawFont(gui_AttachMenu[20], 4);
	TextDrawSetProportional(gui_AttachMenu[20], 0);
	TextDrawSetShadow(gui_AttachMenu[20], 0);
	TextDrawSetSelectable(gui_AttachMenu[20], true);

	gui_AttachMenu[21] = TextDrawCreate(298.4421, 419.2369, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[21], 12.0000, 13.0000);
	TextDrawAlignment(gui_AttachMenu[21], 1);
	TextDrawColor(gui_AttachMenu[21], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[21], 255);
	TextDrawFont(gui_AttachMenu[21], 4);
	TextDrawSetProportional(gui_AttachMenu[21], 0);
	TextDrawSetShadow(gui_AttachMenu[21], 0);

	gui_AttachMenu[22] = TextDrawCreate(301.8751, 419.2369, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[22], 1.0000, 12.9299);
	TextDrawAlignment(gui_AttachMenu[22], 1);
	TextDrawColor(gui_AttachMenu[22], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[22], 255);
	TextDrawFont(gui_AttachMenu[22], 4);
	TextDrawSetProportional(gui_AttachMenu[22], 0);
	TextDrawSetShadow(gui_AttachMenu[22], 0);

	gui_AttachMenu[23] = TextDrawCreate(298.5087, 427.9776, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[23], 12.0000, 1.0000);
	TextDrawAlignment(gui_AttachMenu[23], 1);
	TextDrawColor(gui_AttachMenu[23], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[23], 255);
	TextDrawFont(gui_AttachMenu[23], 4);
	TextDrawSetProportional(gui_AttachMenu[23], 0);
	TextDrawSetShadow(gui_AttachMenu[23], 0);

	gui_AttachMenu[24] = TextDrawCreate(295.5084, 436.9443, "Objects");
	TextDrawLetterSize(gui_AttachMenu[24], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[24], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[24], 1);
	TextDrawColor(gui_AttachMenu[24], -1);
	TextDrawBackgroundColor(gui_AttachMenu[24], 255);
	TextDrawFont(gui_AttachMenu[24], 1);
	TextDrawSetProportional(gui_AttachMenu[24], 1);
	TextDrawSetShadow(gui_AttachMenu[24], 0);

	gui_AttachMenu[25] = TextDrawCreate(298.6088, 422.5704, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[25], 11.8796, 1.0000);
	TextDrawAlignment(gui_AttachMenu[25], 1);
	TextDrawColor(gui_AttachMenu[25], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[25], 255);
	TextDrawFont(gui_AttachMenu[25], 4);
	TextDrawSetProportional(gui_AttachMenu[25], 0);
	TextDrawSetShadow(gui_AttachMenu[25], 0);

	gui_AttachMenu[26] = TextDrawCreate(319.6102, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[26], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[26], 1);
	TextDrawColor(gui_AttachMenu[26], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[26], 255);
	TextDrawFont(gui_AttachMenu[26], 4);
	TextDrawSetProportional(gui_AttachMenu[26], 0);
	TextDrawSetShadow(gui_AttachMenu[26], 0);
	TextDrawSetSelectable(gui_AttachMenu[26], true);

	gui_AttachMenu[27] = TextDrawCreate(326.1089, 425.8297, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[27], 14.0000, 1.5599);
	TextDrawAlignment(gui_AttachMenu[27], 1);
	TextDrawColor(gui_AttachMenu[27], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[27], 255);
	TextDrawFont(gui_AttachMenu[27], 4);
	TextDrawSetProportional(gui_AttachMenu[27], 0);
	TextDrawSetShadow(gui_AttachMenu[27], 0);

	gui_AttachMenu[28] = TextDrawCreate(337.9420, 416.5628, ">");
	TextDrawLetterSize(gui_AttachMenu[28], 0.1967, 2.1807);
	TextDrawAlignment(gui_AttachMenu[28], 1);
	TextDrawColor(gui_AttachMenu[28], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[28], 255);
	TextDrawFont(gui_AttachMenu[28], 1);
	TextDrawSetProportional(gui_AttachMenu[28], 1);
	TextDrawSetShadow(gui_AttachMenu[28], 0);

	gui_AttachMenu[29] = TextDrawCreate(324.7751, 416.7626, "<");
	TextDrawLetterSize(gui_AttachMenu[29], 0.2152, 2.1059);
	TextDrawAlignment(gui_AttachMenu[29], 1);
	TextDrawColor(gui_AttachMenu[29], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[29], 255);
	TextDrawFont(gui_AttachMenu[29], 1);
	TextDrawSetProportional(gui_AttachMenu[29], 1);
	TextDrawSetShadow(gui_AttachMenu[29], 0);

	gui_AttachMenu[30] = TextDrawCreate(328.6107, 436.9443, "Edit");
	TextDrawLetterSize(gui_AttachMenu[30], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[30], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[30], 1);
	TextDrawColor(gui_AttachMenu[30], -1);
	TextDrawBackgroundColor(gui_AttachMenu[30], 255);
	TextDrawFont(gui_AttachMenu[30], 1);
	TextDrawSetProportional(gui_AttachMenu[30], 1);
	TextDrawSetShadow(gui_AttachMenu[30], 0);

	gui_AttachMenu[31] = TextDrawCreate(403.4154, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[31], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[31], 1);
	TextDrawColor(gui_AttachMenu[31], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[31], 255);
	TextDrawFont(gui_AttachMenu[31], 4);
	TextDrawSetProportional(gui_AttachMenu[31], 0);
	TextDrawSetShadow(gui_AttachMenu[31], 0);
	TextDrawSetSelectable(gui_AttachMenu[31], true);

	gui_AttachMenu[32] = TextDrawCreate(411.6456, 416.5888, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[32], 10.5200, 12.7199);
	TextDrawAlignment(gui_AttachMenu[32], 1);
	TextDrawColor(gui_AttachMenu[32], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[32], 255);
	TextDrawFont(gui_AttachMenu[32], 4);
	TextDrawSetProportional(gui_AttachMenu[32], 0);
	TextDrawSetShadow(gui_AttachMenu[32], 0);

	gui_AttachMenu[33] = TextDrawCreate(407.0122, 426.5444, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[33], 20.1200, 7.0000);
	TextDrawAlignment(gui_AttachMenu[33], 1);
	TextDrawColor(gui_AttachMenu[33], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[33], 255);
	TextDrawFont(gui_AttachMenu[33], 4);
	TextDrawSetProportional(gui_AttachMenu[33], 0);
	TextDrawSetShadow(gui_AttachMenu[33], 0);

	gui_AttachMenu[34] = TextDrawCreate(411.9158, 436.9443, "Skin");
	TextDrawLetterSize(gui_AttachMenu[34], 0.1668, 0.8201);
	TextDrawTextSize(gui_AttachMenu[34], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[34], 1);
	TextDrawColor(gui_AttachMenu[34], -1);
	TextDrawBackgroundColor(gui_AttachMenu[34], 255);
	TextDrawFont(gui_AttachMenu[34], 1);
	TextDrawSetProportional(gui_AttachMenu[34], 1);
	TextDrawSetShadow(gui_AttachMenu[34], 0);

	gui_AttachMenu[35] = TextDrawCreate(431.5170, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[35], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[35], 1);
	TextDrawColor(gui_AttachMenu[35], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[35], 255);
	TextDrawFont(gui_AttachMenu[35], 4);
	TextDrawSetProportional(gui_AttachMenu[35], 0);
	TextDrawSetShadow(gui_AttachMenu[35], 0);
	TextDrawSetSelectable(gui_AttachMenu[35], true);

	gui_AttachMenu[36] = TextDrawCreate(440.2453, 414.5591, "A");
	TextDrawLetterSize(gui_AttachMenu[36], 0.3366, 2.2097);
	TextDrawAlignment(gui_AttachMenu[36], 1);
	TextDrawColor(gui_AttachMenu[36], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[36], 255);
	TextDrawFont(gui_AttachMenu[36], 2);
	TextDrawSetProportional(gui_AttachMenu[36], 1);
	TextDrawSetShadow(gui_AttachMenu[36], 0);

	gui_AttachMenu[37] = TextDrawCreate(432.9505, 436.5296, "Animation");
	TextDrawLetterSize(gui_AttachMenu[37], 0.1570, 0.8284);
	TextDrawTextSize(gui_AttachMenu[37], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[37], 1);
	TextDrawColor(gui_AttachMenu[37], -1);
	TextDrawBackgroundColor(gui_AttachMenu[37], 255);
	TextDrawFont(gui_AttachMenu[37], 1);
	TextDrawSetProportional(gui_AttachMenu[37], 1);
	TextDrawSetShadow(gui_AttachMenu[37], 0);

	gui_AttachMenu[38] = TextDrawCreate(459.4187, 414.7184, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[38], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[38], 1);
	TextDrawColor(gui_AttachMenu[38], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[38], 255);
	TextDrawFont(gui_AttachMenu[38], 4);
	TextDrawSetProportional(gui_AttachMenu[38], 0);
	TextDrawSetShadow(gui_AttachMenu[38], 0);
	TextDrawSetSelectable(gui_AttachMenu[38], true);

	gui_AttachMenu[39] = TextDrawCreate(464.4136, 414.5296, "CA");
	TextDrawLetterSize(gui_AttachMenu[39], 0.3366, 2.2097);
	TextDrawAlignment(gui_AttachMenu[39], 1);
	TextDrawColor(gui_AttachMenu[39], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[39], 255);
	TextDrawFont(gui_AttachMenu[39], 2);
	TextDrawSetProportional(gui_AttachMenu[39], 1);
	TextDrawSetShadow(gui_AttachMenu[39], 0);

	gui_AttachMenu[40] = TextDrawCreate(460.8522, 436.5296, "Clear_Anim");
	TextDrawLetterSize(gui_AttachMenu[40], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[40], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[40], 1);
	TextDrawColor(gui_AttachMenu[40], -1);
	TextDrawBackgroundColor(gui_AttachMenu[40], 255);
	TextDrawFont(gui_AttachMenu[40], 1);
	TextDrawSetProportional(gui_AttachMenu[40], 1);
	TextDrawSetShadow(gui_AttachMenu[40], 0);

	gui_AttachMenu[41] = TextDrawCreate(451.4679, 401.9859, "Hide_cursor_-");
	TextDrawLetterSize(gui_AttachMenu[41], 0.1251, 0.9168);
	TextDrawTextSize(gui_AttachMenu[41], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[41], 2);
	TextDrawColor(gui_AttachMenu[41], -1);
	TextDrawBackgroundColor(gui_AttachMenu[41], 255);
	TextDrawFont(gui_AttachMenu[41], 2);
	TextDrawSetProportional(gui_AttachMenu[41], 1);
	TextDrawSetShadow(gui_AttachMenu[41], 0);

	gui_AttachMenu[42] = TextDrawCreate(428.9362, 401.4151, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[42], 58.3899, 11.0000);
	TextDrawAlignment(gui_AttachMenu[42], 1);
	TextDrawColor(gui_AttachMenu[42], 255);
	TextDrawBackgroundColor(gui_AttachMenu[42], 255);
	TextDrawFont(gui_AttachMenu[42], 4);
	TextDrawSetProportional(gui_AttachMenu[42], 0);
	TextDrawSetShadow(gui_AttachMenu[42], 0);

	gui_AttachMenu[43] = TextDrawCreate(429.5029, 402.3328, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[43], 56.7496, 9.2399);
	TextDrawAlignment(gui_AttachMenu[43], 1);
	TextDrawColor(gui_AttachMenu[43], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[43], 255);
	TextDrawFont(gui_AttachMenu[43], 4);
	TextDrawSetProportional(gui_AttachMenu[43], 0);
	TextDrawSetShadow(gui_AttachMenu[43], 0);

	gui_AttachMenu[44] = TextDrawCreate(477.4012, 401.8005, "ESC");
	TextDrawLetterSize(gui_AttachMenu[44], 0.1551, 1.0166);
	TextDrawTextSize(gui_AttachMenu[44], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[44], 2);
	TextDrawColor(gui_AttachMenu[44], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[44], 255);
	TextDrawFont(gui_AttachMenu[44], 2);
	TextDrawSetProportional(gui_AttachMenu[44], 1);
	TextDrawSetShadow(gui_AttachMenu[44], 0);

	gui_AttachMenu[45] = TextDrawCreate(175.7650, 401.9858, "Show_cursor_-");
	TextDrawLetterSize(gui_AttachMenu[45], 0.1211, 0.9268);
	TextDrawTextSize(gui_AttachMenu[45], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[45], 2);
	TextDrawColor(gui_AttachMenu[45], -1);
	TextDrawBackgroundColor(gui_AttachMenu[45], 255);
	TextDrawFont(gui_AttachMenu[45], 2);
	TextDrawSetProportional(gui_AttachMenu[45], 1);
	TextDrawSetShadow(gui_AttachMenu[45], 0);

	gui_AttachMenu[46] = TextDrawCreate(150.5330, 401.4151, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[46], 58.3899, 11.0000);
	TextDrawAlignment(gui_AttachMenu[46], 1);
	TextDrawColor(gui_AttachMenu[46], 255);
	TextDrawBackgroundColor(gui_AttachMenu[46], 255);
	TextDrawFont(gui_AttachMenu[46], 4);
	TextDrawSetProportional(gui_AttachMenu[46], 0);
	TextDrawSetShadow(gui_AttachMenu[46], 0);

	gui_AttachMenu[47] = TextDrawCreate(151.2997, 402.3327, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[47], 56.4497, 8.9799);
	TextDrawAlignment(gui_AttachMenu[47], 1);
	TextDrawColor(gui_AttachMenu[47], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[47], 255);
	TextDrawFont(gui_AttachMenu[47], 4);
	TextDrawSetProportional(gui_AttachMenu[47], 0);
	TextDrawSetShadow(gui_AttachMenu[47], 0);

	gui_AttachMenu[48] = TextDrawCreate(200.3982, 401.2005, "N");
	TextDrawLetterSize(gui_AttachMenu[48], 0.1767, 1.0609);
	TextDrawTextSize(gui_AttachMenu[48], 0.0000, 466.0000);
	TextDrawAlignment(gui_AttachMenu[48], 2);
	TextDrawColor(gui_AttachMenu[48], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[48], 255);
	TextDrawFont(gui_AttachMenu[48], 2);
	TextDrawSetProportional(gui_AttachMenu[48], 1);
	TextDrawSetShadow(gui_AttachMenu[48], 0);

	gui_AttachMenu[49] = TextDrawCreate(347.4850, 414.7183, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[49], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[49], 1);
	TextDrawColor(gui_AttachMenu[49], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[49], 255);
	TextDrawFont(gui_AttachMenu[49], 4);
	TextDrawSetProportional(gui_AttachMenu[49], 0);
	TextDrawSetShadow(gui_AttachMenu[49], 0);
	TextDrawSetSelectable(gui_AttachMenu[49], true);

	gui_AttachMenu[50] = TextDrawCreate(353.9521, 437.3887, "Color_1");
	TextDrawLetterSize(gui_AttachMenu[50], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[50], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[50], 1);
	TextDrawColor(gui_AttachMenu[50], -1);
	TextDrawBackgroundColor(gui_AttachMenu[50], 255);
	TextDrawFont(gui_AttachMenu[50], 1);
	TextDrawSetProportional(gui_AttachMenu[50], 1);
	TextDrawSetShadow(gui_AttachMenu[50], 0);

	gui_AttachMenu[51] = TextDrawCreate(375.5867, 414.7183, "LD_SPAC:white");
	TextDrawTextSize(gui_AttachMenu[51], 27.0000, 32.0000);
	TextDrawAlignment(gui_AttachMenu[51], 1);
	TextDrawColor(gui_AttachMenu[51], 370480895);
	TextDrawBackgroundColor(gui_AttachMenu[51], 255);
	TextDrawFont(gui_AttachMenu[51], 4);
	TextDrawSetProportional(gui_AttachMenu[51], 0);
	TextDrawSetShadow(gui_AttachMenu[51], 0);
	TextDrawSetSelectable(gui_AttachMenu[51], true);

	gui_AttachMenu[52] = TextDrawCreate(352.1981, 420.6075, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[52], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[52], 1);
	TextDrawColor(gui_AttachMenu[52], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[52], 255);
	TextDrawFont(gui_AttachMenu[52], 4);
	TextDrawSetProportional(gui_AttachMenu[52], 0);
	TextDrawSetShadow(gui_AttachMenu[52], 0);

	gui_AttachMenu[53] = TextDrawCreate(358.2649, 418.8074, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[53], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[53], 1);
	TextDrawColor(gui_AttachMenu[53], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[53], 255);
	TextDrawFont(gui_AttachMenu[53], 4);
	TextDrawSetProportional(gui_AttachMenu[53], 0);
	TextDrawSetShadow(gui_AttachMenu[53], 0);

	gui_AttachMenu[54] = TextDrawCreate(384.5320, 419.4222, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[54], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[54], 1);
	TextDrawColor(gui_AttachMenu[54], 950371583);
	TextDrawBackgroundColor(gui_AttachMenu[54], 255);
	TextDrawFont(gui_AttachMenu[54], 4);
	TextDrawSetProportional(gui_AttachMenu[54], 0);
	TextDrawSetShadow(gui_AttachMenu[54], 0);

	gui_AttachMenu[55] = TextDrawCreate(378.9995, 421.1075, "LD_BEAT:chit");
	TextDrawTextSize(gui_AttachMenu[55], 12.0000, 14.0000);
	TextDrawAlignment(gui_AttachMenu[55], 1);
	TextDrawColor(gui_AttachMenu[55], -1061109505);
	TextDrawBackgroundColor(gui_AttachMenu[55], 255);
	TextDrawFont(gui_AttachMenu[55], 4);
	TextDrawSetProportional(gui_AttachMenu[55], 0);
	TextDrawSetShadow(gui_AttachMenu[55], 0);

	gui_AttachMenu[56] = TextDrawCreate(381.2871, 437.3887, "Color_2");
	TextDrawLetterSize(gui_AttachMenu[56], 0.1500, 0.8284);
	TextDrawTextSize(gui_AttachMenu[56], 32.0000, 0.0000);
	TextDrawAlignment(gui_AttachMenu[56], 1);
	TextDrawColor(gui_AttachMenu[56], -1);
	TextDrawBackgroundColor(gui_AttachMenu[56], 255);
	TextDrawFont(gui_AttachMenu[56], 1);
	TextDrawSetProportional(gui_AttachMenu[56], 1);
	TextDrawSetShadow(gui_AttachMenu[56], 0);
#if defined guiatachmenu_OnGameModeInit
	return guiatachmenu_OnGameModeInit();
#else
	return 1;
#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit guiatachmenu_OnGameModeInit
#if defined    guiatachmenu_OnGameModeInit
	forward guiatachmenu_OnGameModeInit();
#endif

public OnPlayerDisconnect(playerid, reason)
{
	gui_HideAttachMenu(playerid);
#if defined guiatachmenu_OnPlayerDisconnect
	return guiatachmenu_OnPlayerDisconnect(playerid, reason);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect guiatachmenu_OnPlayerDisconnect
#if defined    guiatachmenu_OnPlayerDisconnect
	forward guiatachmenu_OnPlayerDisconnect(playerid, reason);
#endif


public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if (gui_atatch_menu_IsShow(playerid))
	{
		if (!Dialog_IsOpen(playerid) && !gui_ath_obj_IsPlayerCreateTD(playerid))
		{
			const INDEX_TD_ID = 0;
			const INDEX_TYPE_ID = 1;

			static const index[][] =
			{
				{1,		GUI_ATTACH_MENU_MANAGE},
				{7,		GUI_ATTACH_MENU_EXPORT},
				{10,	GUI_ATTACH_MENU_NEW},
				{13,	GUI_ATTACH_MENU_DELETE},
				{16,	GUI_ATTACH_MENU_DUBLICATE},
				{20,	GUI_ATTACH_MENU_OBJECT},
				{26,	GUI_ATTACH_MENU_EDIT},
				{49,	GUI_ATTACH_MENU_COLOR_1},
				{51,	GUI_ATTACH_MENU_COLOR_2},
				{31,	GUI_ATTACH_MENU_SKIN},
				{35,	GUI_ATTACH_MENU_ANIMATIONS},
				{38,	GUI_ATTACH_MENU_ANIMATION_CLEAR}
			};
			for (new i, cellid; i < sizeof(index); i++)
			{
				cellid = index[i][INDEX_TD_ID];

				if (clickedid == gui_AttachMenu[cellid])
				{
					CallRemoteFunction(
						"OnGuiAttachMenuClicked",
						"dd",
						playerid,
						index[i][INDEX_TYPE_ID]
					);
					return 1;
				}
			}
			return 1;
		}
	}
#if defined guiatachmenu_OnClickTextDraw
	return guiatachmenu_OnClickTextDraw(playerid, Text:clickedid);
#else
	return 1;
#endif
}
#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw guiatachmenu_OnClickTextDraw
#if defined    guiatachmenu_OnClickTextDraw
	forward guiatachmenu_OnClickTextDraw(playerid, Text:clickedid);
#endif


stock gui_ShowAttachMenu(playerid)
{
	if (gui_atatch_menu_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachMenu); i++)
	{
		TextDrawShowForPlayer(playerid, gui_AttachMenu[i]);
	}
	gui_AttachMenuPlayerShow[playerid] = true;
	return 1;
}

stock gui_HideAttachMenu(playerid)
{
	if (!gui_atatch_menu_IsShow(playerid))
	{
		return 0;
	}
	for (new i; i < sizeof(gui_AttachMenu); i++)
	{
		TextDrawHideForPlayer(playerid, gui_AttachMenu[i]);
	}
	gui_AttachMenuPlayerShow[playerid] = false;
	return 1;
}

static gui_atatch_menu_IsShow(playerid)
{
	return gui_AttachMenuPlayerShow[playerid];
}

stock gui_atatch_menu_ShowCursor(playerid)
{
	SelectTextDraw(playerid, COLOR_TD_CLICK);
	return 1;
}