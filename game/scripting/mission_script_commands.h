// Copyright 2002-2004 Frozenbyte Ltd.

// from 1600

#define GS_CMD_BASE 1600

GS_CMD(0, GS_CMD_SETMISSIONSUCCESSCOUNTER,      "setMissionSuccessCounter",      INT)
GS_CMD(1, GS_CMD_SETMISSIONFAILURECOUNTER,      "setMissionFailureCounter",      INT)
GS_CMD(2, GS_CMD_COUNTALIVEUNITS,               "countAliveUnits",               NONE)
GS_CMD(3, GS_CMD_COUNTALIVEHOSTILEUNITS,        "countAliveHostileUnits",        NONE)
GS_CMD(4, GS_CMD_ISMISSIONSUCCESS,              "isMissionSuccess",              NONE)
GS_CMD(5, GS_CMD_ISMISSIONFAILURE,              "isMissionFailure",              NONE)
GS_CMD(6, GS_CMD_ELAPSEDMISSIONTIME,            "elapsedMissionTime",            NONE)
GS_CMD(7, GS_CMD_SETMISSION,                    "setMission",                    STRING)
GS_CMD(8, GS_CMD_ENDCOMBAT,                     "endCombat",                     NONE)
GS_CMD(9, GS_CMD_HOSTILESNEARPOSITION,          "hostilesNearPosition",          INT)
GS_CMD(10, GS_CMD_FRIENDLYSNEARPOSITION,         "friendlysNearPosition",         INT)
GS_CMD(11, GS_CMD_ISEVERYUNITNEARCHECKPOINT,     "isEveryUnitNearCheckpoint",     INT)
GS_CMD(12, GS_CMD_ISANYUNITNEARCHECKPOINT,       "isAnyUnitNearCheckpoint",       INT)
GS_CMD(13, GS_CMD_ISPOSITIONNEARCHECKPOINT,      "isPositionNearCheckpoint",      INT)
GS_CMD(14, GS_CMD_SETCHECKPOINTTOPOSITION,       "setCheckpointToPosition",       NONE)
GS_CMD(15, GS_CMD_CLEARCHECKPOINT,               "clearCheckpoint",               NONE)
GS_CMD(16, GS_CMD_ISEVERYUNITNEARPOSITION,       "isEveryUnitNearPosition",       INT)
GS_CMD(17, GS_CMD_ISANYUNITNEARPOSITION,         "isAnyUnitNearPosition",         INT)
GS_CMD(18, GS_CMD_ADDBUILDINGTOPOSITION,         "addBuildingToPosition",         STRING)
GS_CMD(19, GS_CMD_ADDMONEY,                      "addMoney",                      INT)
GS_CMD(20, GS_CMD_SETHOSTILE,                    "setHostile",                    INT)
GS_CMD(21, GS_CMD_SETFRIENDLY,                   "setFriendly",                   INT)
GS_CMD(22, GS_CMD_SETSPAWN,                      "setSpawn",                      STRING)
GS_CMD(23, GS_CMD_ALLOWPARTTYPE,                 "allowPartType",                 STRING)
GS_CMD(24, GS_CMD_ADDSTORAGEPART,                "addStoragePart",                STRING)
GS_CMD(25, GS_CMD_CONSCIOUSHOSTILESNEARPOSITION, "consciousHostilesNearPosition", INT)
GS_CMD(26, GS_CMD_PLAYERUNITSINACTION,           "playerUnitsInAction",           NONE)
GS_CMD(27, GS_CMD_COUNTCONSCIOUSUNITS,           "countConsciousUnits",           NONE)
GS_CMD(28, GS_CMD_OWNEDNEARPOSITION,             "ownedNearPosition",             INT)
GS_CMD(29, GS_CMD_ISMISSIONRUNNING,              "isMissionRunning",              NONE)
GS_CMD(30, GS_CMD_OWNEDNEARPOSITIONBYVALUE,      "ownedNearPositionByValue",      NONE)
GS_CMD(31, GS_CMD_SETTERRAINCUT,                 "setTerrainCut",                 INT)

GS_CMD(32, GS_CMD_SETMISSIONFILE,                "setMissionFile",                STRING)
GS_CMD(33, GS_CMD_SETLOADMISSIONFILE,            "setLoadMissionFile",            STRING)

GS_CMD(34, GS_CMD_GETMISSIONIDSTRING,            "getMissionIdString",            NONE)
GS_CMD(35, GS_CMD_SETMISSIONID,                  "setMissionId",                  STRING)

// maybe these don't belong here?
GS_CMD_SIMPLE(36, setTerrainMaterial,      STRING)
GS_CMD_SIMPLE(37, setPhysicsWaterSettings, STRING)
GS_CMD_SIMPLE(38, setAlphaTestPassEnabled, INT)

GS_CMD_SIMPLE(39, setSuccessMission,       STRING)
GS_CMD_SIMPLE(40, unlockSurvivalMission,   STRING)

GS_CMD_SIMPLE(41, setMissionAbortCounter,  INT)
#undef GS_CMD_BASE

// up to 1649
