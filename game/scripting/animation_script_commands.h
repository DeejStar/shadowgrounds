// Copyright 2002-2004 Frozenbyte Ltd.

// from 400

#define GS_CMD_BASE 400

GS_CMD(0, GS_CMD_ANISTART,              "aniStart",                 NONE)
GS_CMD(1, GS_CMD_ANIEND,                "aniEnd",                   NONE)
GS_CMD(2, GS_CMD_ANIWARP,               "aniWarp",                  STRING)
GS_CMD(3, GS_CMD_ANIHEIGHT,             "aniHeight",                FLOAT)
GS_CMD(4, GS_CMD_ANIROTS,               "aniRots",                  STRING)
GS_CMD(5, GS_CMD_ANIANIM,               "aniAnim",                  STRING)
GS_CMD(6, GS_CMD_ANIENDANIM,            "aniEndAnim",               STRING)
GS_CMD(7, GS_CMD_ANIMOVEX,              "aniMoveX",                 FLOAT)
GS_CMD(8, GS_CMD_ANIMOVEZ,              "aniMoveZ",                 FLOAT)
GS_CMD(9, GS_CMD_ANIMOVEY,              "aniMoveY",                 FLOAT)
GS_CMD(10, GS_CMD_ANIROTY,               "aniRotY",                  FLOAT)
GS_CMD(11, GS_CMD_ANIROTX,               "aniRotX",                  FLOAT)
GS_CMD(12, GS_CMD_ANIROTZ,               "aniRotZ",                  FLOAT)
GS_CMD(13, GS_CMD_ANIAIM,                "aniAim",                   FLOAT)
GS_CMD(14, GS_CMD_ANIENDAIM,             "aniEndAim",                NONE)
GS_CMD(15, GS_CMD_ANIMARK,               "aniMark",                  STRING)
GS_CMD(16, GS_CMD_ANITICK,               "aniTick",                  NONE)

GS_CMD(17, GS_CMD_ISALLANICOMPLETE,      "isAllAniComplete",         NONE)
GS_CMD(18, GS_CMD_STARTANIPLAY,          "startAniPlay",             STRING)
GS_CMD(19, GS_CMD_STARTANIRECORD,        "startAniRecord",           STRING)
GS_CMD(20, GS_CMD_STOPANIPLAY,           "stopAniPlay",              STRING)
GS_CMD(21, GS_CMD_STOPANIRECORD,         "stopAniRecord",            STRING)
GS_CMD(22, GS_CMD_CANCELANIRECORD,       "cancelAniRecord",          STRING)
GS_CMD(23, GS_CMD_HASANIPLAYENDED,       "hasAniPlayEnded",          STRING)
GS_CMD(24, GS_CMD_SETANIRECORDPATH,      "setAniRecordPath",         STRING)
GS_CMD(25, GS_CMD_GETANIRECORDPATH,      "getAniRecordPathToString", NONE)

GS_CMD(26, GS_CMD_ANIAXIS,               "aniAxis",                  FLOAT)

GS_CMD(27, GS_CMD_ANIAXISTOVALUE,        "aniAxisToValue",           NONE)

GS_CMD(28, GS_CMD_STOPALLANIPLAY,        "stopAllAniPlay",           NONE)
GS_CMD(29, GS_CMD_LEAPALLANIPLAYTOEND,   "leapAllAniPlayToEnd",      NONE)

GS_CMD(30, GS_CMD_ANIONGROUND,           "aniOnGround",              NONE)

GS_CMD(31, GS_CMD_ADDANISCRIPTCOMMANDS,  "addAniScriptCommands",     STRING)

GS_CMD(32, GS_CMD_ANIWAITUNTILANISENDED, "aniWaitUntilAnisEnded",    NONE)

GS_CMD(33, GS_CMD_ANIMUZZLEFLASH,        "aniMuzzleflash",           NONE)
GS_CMD(34, GS_CMD_ANIBLEND,              "aniBlend",                 STRING)
GS_CMD(35, GS_CMD_ANIENDBLEND,           "aniEndBlend",              NONE)

GS_CMD(36, GS_CMD_ANIFIREPOSITION,       "aniFirePosition",          STRING)
GS_CMD(37, GS_CMD_ANIFIREHEIGHT,         "aniFireHeight",            FLOAT)
GS_CMD(38, GS_CMD_ANIFIREPROJECTILE,     "aniFireProjectile",        STRING)
GS_CMD(39, GS_CMD_ANIFIRETARGETHEIGHT,   "aniFireTargetHeight",      FLOAT)
GS_CMD(40, GS_CMD_ANIFIRETARGETPOSITION, "aniFireTargetPosition",    STRING)

GS_CMD_SIMPLE(41, setGlobalAniOffsetSourceToPosition, NONE)
GS_CMD_SIMPLE(42, setGlobalAniOffsetTargetToPosition, NONE)
GS_CMD_SIMPLE(43, setGlobalAniRotationToValue,        NONE)
GS_CMD_SIMPLE(44, resetGlobalAniOffsetAndRotation,    NONE)

GS_CMD_SIMPLE(45, aniWarpToPosition,                  NONE)
GS_CMD_SIMPLE(46, aniAxisToValue,                     NONE)

#undef GS_CMD_BASE

// up to 499
