// Copyright 2002-2004 Frozenbyte Ltd.

// from 1800

#define GS_CMD_BASE 1800

GS_CMD(0, GS_CMD_PLAYSOUNDEFFECT,                     "playSoundEffect",                     STRING)
GS_CMD(1, GS_CMD_SETMUSIC,                            "setMusic",                            STRING)
GS_CMD(2, GS_CMD_LOADMUSICPLAYLIST,                   "loadMusicPlaylist",                   STRING)
GS_CMD(3, GS_CMD_PLAYMUSIC,                           "playMusic",                           NONE)
GS_CMD(4, GS_CMD_STOPMUSIC,                           "stopMusic",                           NONE)
GS_CMD(5, GS_CMD_NEXTMUSIC,                           "nextMusic",                           NONE)
GS_CMD(6, GS_CMD_PREVIOUSMUSIC,                       "previousMusic",                       NONE)
GS_CMD(7, GS_CMD_MUSICPLAYLIST,                       "musicPlaylist",                       STRING)
GS_CMD(8, GS_CMD_PLAYSPEECH,                          "playSpeech",                          STRING)
GS_CMD(9, GS_CMD_CLEARALLAMBIENTSOUNDS,               "clearAllAmbientSounds",               NONE)
GS_CMD(10, GS_CMD_SETAMBIENTSOUNDNUMBER,               "setAmbientSoundNumber",               INT)
GS_CMD(11, GS_CMD_SETAMBIENTSOUNDRANGE,                "setAmbientSoundRange",                INT)
GS_CMD(12, GS_CMD_SETAMBIENTSOUNDROLLOFF,              "setAmbientSoundRolloff",              INT)
GS_CMD(13, GS_CMD_MAKEAMBIENTSOUND,                    "makeAmbientSound",                    STRING)
GS_CMD(14, GS_CMD_STARTAMBIENTSOUNDBYNUMBER,           "startAmbientSoundByNumber",           INT)
GS_CMD(15, GS_CMD_STOPAMBIENTSOUNDBYNUMBER,            "stopAmbientSoundByNumber",            INT)
GS_CMD(16, GS_CMD_STOPAMBIENTSOUNDIMMEDIATELYBYNUMBER, "stopAmbientSoundImmediatelyByNumber", INT)
GS_CMD(17, GS_CMD_SETSOUNDVOLUME,                      "setSoundVolume",                      INT)
GS_CMD(18, GS_CMD_PLAYSOUNDEFFECTWITHVOLUME,           "playSoundEffectWithVolume",           STRING)
GS_CMD(19, GS_CMD_PLAYSPEECHWITHVOLUME,                "playSpeechWithVolume",                STRING)
GS_CMD(20, GS_CMD_PRELOADSOUND,                        "preloadSound",                        STRING)
GS_CMD(21, GS_CMD_PRELOADTEMPORARYSOUND,               "preloadTemporarySound",               STRING)
GS_CMD(22, GS_CMD_CLEANSOUNDCACHE,                     "cleanSoundCache",                     NONE)
GS_CMD(23, GS_CMD_CLEANTEMPORARYSOUNDCACHE,            "cleanTemporarySoundCache",            NONE)
GS_CMD(24, GS_CMD_SETMUSICFADETIME,                    "setMusicFadeTime",                    INT)

GS_CMD(25, GS_CMD_LOADAMBIENTPLAYLIST,                 "loadAmbientPlaylist",                 STRING)
GS_CMD(26, GS_CMD_PLAYAMBIENTAREASOUNDS,               "playAmbientAreaSounds",               NONE)
GS_CMD(27, GS_CMD_FADEOUTAMBIENTAREASOUNDS,            "fadeOutAmbientAreaSounds",            INT)
GS_CMD(28, GS_CMD_SETAMBIENTOUTDOORAREA,               "setAmbientOutdoorArea",               STRING)
GS_CMD(29, GS_CMD_SETAMBIENTINDOORAREA,                "setAmbientIndoorArea",                STRING)
GS_CMD(30, GS_CMD_SETAMBIENTOUTDOORAREABYSTRINGVALUE,  "setAmbientOutdoorAreaByStringValue",  NONE)
GS_CMD(31, GS_CMD_SETAMBIENTINDOORAREABYSTRINGVALUE,   "setAmbientIndoorAreaByStringValue",   NONE)

GS_CMD(32, GS_CMD_SETAMBIENTSOUNDNAME,                 "setAmbientSoundName",                 STRING)
GS_CMD(33, GS_CMD_SETAMBIENTSOUNDNUMBERBYNAME,         "setAmbientSoundNumberByName",         STRING)
GS_CMD(34, GS_CMD_STARTAMBIENTSOUNDBYNAME,             "startAmbientSoundByName",             STRING)
GS_CMD(35, GS_CMD_STOPAMBIENTSOUNDBYNAME,              "stopAmbientSoundByName",              STRING)
GS_CMD(36, GS_CMD_STOPAMBIENTSOUNDIMMEDIATELYBYNAME,   "stopAmbientSoundImmediatelyByName",   STRING)
GS_CMD(37, GS_CMD_SETNEXTFREEAMBIENTSOUNDNUMBER,       "setNextFreeAmbientSoundNumber",       NONE)
GS_CMD(38, GS_CMD_STARTSELECTEDAMBIENTSOUND,           "startSelectedAmbientSound",           NONE)
GS_CMD(39, GS_CMD_STOPSELECTEDAMBIENTSOUND,            "stopSelectedAmbientSound",            NONE)
GS_CMD(40, GS_CMD_STOPSELECTEDAMBIENTSOUNDIMMEDIATELY, "stopSelectedAmbientSoundImmediately", NONE)
GS_CMD(41, GS_CMD_SETAMBIENTSOUNDCLIPTOVALUE,          "setAmbientSoundClipToValue",          INT)
GS_CMD(42, GS_CMD_PLAYSTREAMEDSOUND,                   "playStreamedSound",                   STRING)
GS_CMD(43, GS_CMD_STOPALLSTREAMEDSOUNDS,               "stopAllStreamedSounds",               NONE)
GS_CMD(44, GS_CMD_DISABLEAMBIENTAREASOUNDS,            "disableAmbientAreaSounds",            NONE)
GS_CMD(45, GS_CMD_ENABLEAMBIENTAREASOUNDS,             "enableAmbientAreaSounds",             NONE)
GS_CMD(46, GS_CMD_STOPALLSPEECHES,                     "stopAllSpeeches",                     NONE)

GS_CMD_SIMPLE(47, setEaxOutdoorArea,              STRING)
GS_CMD_SIMPLE(48, setEaxIndoorArea,               STRING)
GS_CMD_SIMPLE(49, setEaxOutdoorAreaByStringValue, STRING)
GS_CMD_SIMPLE(50, setEaxIndoorAreaByStringValue,  STRING)
GS_CMD_SIMPLE(51, getWaveLength,                  STRING)

GS_CMD_SIMPLE(52, startAmbientSoundByNumberValue, NONE)
GS_CMD_SIMPLE(53, stopAmbientSoundByNumberValue,  NONE)
GS_CMD_SIMPLE(54, getAmbientSoundNumber,          NONE)
GS_CMD_SIMPLE(55, setAmbientSoundNumberByValue,   NONE)

GS_CMD_SIMPLE(56, reloadSoundMaterials,           NONE)
GS_CMD_SIMPLE(57, setAmbientSoundVolume,          INT)
GS_CMD_SIMPLE(58, playSoundEffectFromStringValue, NONE)

#undef GS_CMD_BASE

// up to 1899
