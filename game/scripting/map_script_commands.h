// Copyright 2002-2004 Frozenbyte Ltd.

// from 1300

#define GS_CMD_BASE 1300

GS_CMD(0, GS_CMD_SETMAPLAYERSTARTTOPOSITION,        "setMapLayerStartToPosition",        NONE)
GS_CMD(1, GS_CMD_SETMAPLAYERENDTOPOSITION,          "setMapLayerEndToPosition",          NONE)
GS_CMD(2, GS_CMD_SETMAPLAYERACTIVE,                 "setMapLayerActive",                 STRING)

GS_CMD(3, GS_CMD_SETMISSIONOBJECTIVERANGE,          "setMissionObjectiveRange",          FLOAT)
GS_CMD(4, GS_CMD_SETMISSIONOBJECTIVETOPOSITION,     "setMissionObjectiveToPosition",     NONE)
GS_CMD(5, GS_CMD_ADDPRIMARYMISSIONOBJECTIVE,        "addPrimaryMissionObjective",        STRING)
GS_CMD(6, GS_CMD_ADDSECONDARYMISSIONOBJECTIVE,      "addSecondaryMissionObjective",      STRING)
GS_CMD(7, GS_CMD_REMOVEMISSIONOBJECTIVE,            "removeMissionObjective",            STRING)
GS_CMD(8, GS_CMD_COMPLETEMISSIONOBJECTIVE,          "completeMissionObjective",          STRING)
GS_CMD(9, GS_CMD_ISMISSIONOBJECTIVECOMPLETE,        "isMissionObjectiveComplete",        STRING)

GS_CMD(10, GS_CMD_SETMAPLAYERID,                     "setMapLayerId",                     STRING)

GS_CMD(11, GS_CMD_DOESMISSIONOBJECTIVEEXIST,         "doesMissionObjectiveExist",         STRING)
GS_CMD(12, GS_CMD_UPDATEMISSIONOBJECTIVETOPOSITION,  "updateMissionObjectiveToPosition",  STRING)
GS_CMD(13, GS_CMD_SETMISSIONOBJECTIVEMAPLAYER,       "setMissionObjectiveMapLayer",       STRING)

GS_CMD(14, GS_CMD_SAVEACTIVEMAPLAYER,                "saveActiveMapLayer",                NONE)
GS_CMD(15, GS_CMD_RESTORESAVEDMAPLAYER,              "restoreSavedMapLayer",              NONE)
GS_CMD(16, GS_CMD_GETACTIVEMAPLAYER,                 "getActiveMapLayer",                 NONE)

GS_CMD(17, GS_CMD_ADDACTIVEMISSIONOBJECTIVE,         "addActiveMissionObjective",         STRING)

GS_CMD(18, GS_CMD_SETMISSIONOBJECTIVELAYER,          "setMissionObjectiveLayer",          STRING)

GS_CMD(19, GS_CMD_SETMAPPORTALFROMLAYER,             "setMapPortalFromLayer",             STRING)
GS_CMD(20, GS_CMD_SETMAPPORTALTOLAYER,               "setMapPortalToLayer",               STRING)
GS_CMD(21, GS_CMD_SETMAPPORTALORIGINTOPOSITION,      "setMapPortalOriginToPosition",      NONE)
GS_CMD(22, GS_CMD_SETMAPPORTALDESTINATIONTOPOSITION, "setMapPortalDestinationToPosition", NONE)
GS_CMD(23, GS_CMD_ADDMAPPORTAL,                      "addMapPortal",                      NONE)
GS_CMD(24, GS_CMD_REMOVEMAPPORTAL,                   "removeMapPortal",                   NONE)

GS_CMD_SIMPLE(25, clearMapFog,     NONE)

GS_CMD_SIMPLE(26, renderMapToFile, STRING)

#undef GS_CMD_BASE

// up to 1349
