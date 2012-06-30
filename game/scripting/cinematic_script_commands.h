// Copyright 2002-2004 Frozenbyte Ltd.

// from 600

#define GS_CMD_BASE 600

GS_CMD(0, GS_CMD_HIDEGUI,                                   "hideGUI",                                   NONE)
GS_CMD(1, GS_CMD_SHOWGUI,                                   "showGUI",                                   NONE)
GS_CMD(2, GS_CMD_FADEIN,                                    "fadeIn",                                    INT)
GS_CMD(3, GS_CMD_FADEOUT,                                   "fadeOut",                                   INT)
GS_CMD(4, GS_CMD_FADED,                                     "faded",                                     NONE)
GS_CMD(5, GS_CMD_NOFADE,                                    "noFade",                                    NONE)
GS_CMD(6, GS_CMD_STARTCINEMATIC,                            "startCinematic",                            NONE)
GS_CMD(7, GS_CMD_ENDCINEMATIC,                              "endCinematic",                              NONE)
GS_CMD(8, GS_CMD_CINEMATICSCRIPT,                           "cinematicScript",                           STRING)
GS_CMD(9, GS_CMD_MOVIEASPECTRATIO,                          "movieAspectRatio",                          NONE)
GS_CMD(10, GS_CMD_NORMALASPECTRATIO,                         "normalAspectRatio",                         NONE)
GS_CMD(11, GS_CMD_SETMASKPICTURE,                            "setMaskPicture",                            STRING)
GS_CMD(12, GS_CMD_SETMASKPICTUREPOSITION,                    "setMaskPicturePosition",                    INT)
GS_CMD(13, GS_CMD_CLEARMASKPICTURE,                          "clearMaskPicture",                          NONE)
GS_CMD(14, GS_CMD_SETMASKPICTURESIZEX,                       "setMaskPictureSizeX",                       INT)
GS_CMD(15, GS_CMD_SETMASKPICTURESIZEY,                       "setMaskPictureSizeY",                       INT)
GS_CMD(16, GS_CMD_ISSKIPPINGCINEMATIC,                       "isSkippingCinematic",                       NONE)
GS_CMD(17, GS_CMD_ISCINEMATICSCRIPTRUNNING,                  "isCinematicScriptRunning",                  NONE)
GS_CMD(18, GS_CMD_SETACTIVEMASKPICTURELAYER,                 "setActiveMaskPictureLayer",                 INT)
GS_CMD(19, GS_CMD_SETMASKPICTUREFONT,                        "setMaskPictureFont",                        STRING)
GS_CMD(20, GS_CMD_SETMASKPICTURETEXT,                        "setMaskPictureText",                        STRING)
GS_CMD(21, GS_CMD_CLEARMASKPICTURETEXT,                      "clearMaskPictureText",                      NONE)
GS_CMD(22, GS_CMD_SETMASKPICTURETEXTPOSITIONX,               "setMaskPictureTextPositionX",               INT)
GS_CMD(23, GS_CMD_SETMASKPICTURETEXTPOSITIONY,               "setMaskPictureTextPositionY",               INT)
GS_CMD(24, GS_CMD_SETMASKPICTURETEXTTOSTRING,                "setMaskPictureTextToString",                NONE)
GS_CMD(25, GS_CMD_ENABLESCROLLY,                             "enableScrolly",                             NONE)
GS_CMD(26, GS_CMD_DISABLESCROLLY,                            "disableScrolly",                            NONE)
GS_CMD(27, GS_CMD_SETMASKPICTURETEXTAREASIZEX,               "setMaskPictureTextAreaSizeX",               INT)
GS_CMD(28, GS_CMD_SETMASKPICTURETEXTAREASIZEY,               "setMaskPictureTextAreaSizeY",               INT)
GS_CMD(29, GS_CMD_ADDMASKPICTURETEXTLINE,                    "addMaskPictureTextLine",                    STRING)

GS_CMD(30, GS_CMD_SETFADEIMAGE,                              "setFadeImage",                              STRING)
GS_CMD(31, GS_CMD_SETFADEIMAGETODEFAULT,                     "setFadeImageToDefault",                     NONE)
GS_CMD(32, GS_CMD_STARTMASKPICTUREFADEIN,                    "startMaskPictureFadeIn",                    INT)
GS_CMD(33, GS_CMD_STARTMASKPICTUREFADEOUT,                   "startMaskPictureFadeOut",                   INT)
GS_CMD(34, GS_CMD_STARTMASKPICTUREMOVEIN,                    "startMaskPictureMoveIn",                    INT)
GS_CMD(35, GS_CMD_STARTMASKPICTUREMOVEOUT,                   "startMaskPictureMoveOut",                   INT)

GS_CMD(36, GS_CMD_SETMASKPICTURESIZEXTOVALUE,                "setMaskPictureSizeXToValue",                NONE)
GS_CMD(37, GS_CMD_SETMASKPICTURESIZEYTOVALUE,                "setMaskPictureSizeYToValue",                NONE)
GS_CMD(38, GS_CMD_PLAYVIDEO,                                 "playVideo",                                 STRING)

GS_CMD(39, GS_CMD_DISABLEPLAYERSELFILLUMINATION,             "disablePlayerSelfIllumination",             NONE)
GS_CMD(40, GS_CMD_ENABLEPLAYERSELFILLUMINATION,              "enablePlayerSelfIllumination",              NONE)

GS_CMD(41, GS_CMD_ENDCONVERSATION,                           "endConversation",                           NONE)
GS_CMD(42, GS_CMD_STARTCONVERSATION,                         "startConversation",                         NONE)
GS_CMD(43, GS_CMD_SETCONVERSATIONUNITLEFT,                   "setConversationUnitLeft",                   NONE)
GS_CMD(44, GS_CMD_SETCONVERSATIONUNITRIGHT,                  "setConversationUnitRight",                  NONE)
GS_CMD(45, GS_CMD_SETCONVERSATIONIDLEANIMATIONFORUNIT,       "setConversationIdleAnimationForUnit",       STRING)
GS_CMD(46, GS_CMD_SETCONVERSATIONEXPRESSIONANIMATIONFORUNIT, "setConversationExpressionAnimationForUnit", STRING)

GS_CMD(47, GS_CMD_SETMASKPICTUREPOSITIONX,                   "setMaskPicturePositionX",                   INT)
GS_CMD(48, GS_CMD_SETMASKPICTUREPOSITIONY,                   "setMaskPicturePositionY",                   INT)
GS_CMD(49, GS_CMD_SETMASKPICTUREPOSITIONXTOVALUE,            "setMaskPicturePositionXToValue",            NONE)
GS_CMD(50, GS_CMD_SETMASKPICTUREPOSITIONYTOVALUE,            "setMaskPicturePositionYToValue",            NONE)
GS_CMD_SIMPLE(51, setConversationNoiseLeft,       INT)
GS_CMD_SIMPLE(52, setConversationNoiseRight,      INT)
GS_CMD_SIMPLE(53, setConversationNoiseForUnit,    INT)

GS_CMD_SIMPLE(54, openCinematicScreen,            STRING)
GS_CMD_SIMPLE(55, closeCinematicScreen,           NONE)
GS_CMD_SIMPLE(56, isCinematicScreenOpen,          NONE)

GS_CMD_SIMPLE(57, setVehicleGUI,                  STRING)

GS_CMD_SIMPLE(58, openCharacterSelectionWindow,   STRING)

GS_CMD_SIMPLE(59, setNVGoggleEnabled,             INT)
GS_CMD_SIMPLE(60, setSlomoEffectEnabled,          INT)
GS_CMD_SIMPLE(61, setNapalmEffectEnabled,         INT)
GS_CMD_SIMPLE(62, setHealEffectEnabled,           INT)
GS_CMD_SIMPLE(63, setCustomFilterEffect,          STRING)

GS_CMD_SIMPLE(64, waitUntilCinematicScreenClosed, NONE)
GS_CMD_SIMPLE(65, openMissionFailureWindow,       NONE)
GS_CMD_SIMPLE(66, isCharacterSelectionOpen,       NONE)

#undef GS_CMD_BASE

// up to 699
