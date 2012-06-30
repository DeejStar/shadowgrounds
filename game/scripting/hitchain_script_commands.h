// Copyright 2002-2004 Frozenbyte Ltd.

// from 900

#define GS_CMD_BASE 900

GS_CMD(0,
       GS_CMD_PROJGETORIGINDIRECTIONX,
       "projGetOriginDirectionX",
       NONE)
GS_CMD(1,
       GS_CMD_PROJGETORIGINDIRECTIONY,
       "projGetOriginDirectionY",
       NONE)
GS_CMD(2,
       GS_CMD_PROJGETORIGINDIRECTIONZ,
       "projGetOriginDirectionZ",
       NONE)
GS_CMD(3,
       GS_CMD_PROJGETORIGINALCHAINEDDIRECTIONX,
       "projGetOriginalChainedDirectionX",
       NONE)
GS_CMD(4,
       GS_CMD_PROJGETORIGINALCHAINEDDIRECTIONY,
       "projGetOriginalChainedDirectionY",
       NONE)
GS_CMD(5,
       GS_CMD_PROJGETORIGINALCHAINEDDIRECTIONZ,
       "projGetOriginalChainedDirectionZ",
       NONE)
GS_CMD(6,
       GS_CMD_PROJGETCHAINEDDIRECTIONX,
       "projGetChainedDirectionX",
       NONE)
GS_CMD(7,
       GS_CMD_PROJGETCHAINEDDIRECTIONY,
       "projGetChainedDirectionY",
       NONE)
GS_CMD(8,
       GS_CMD_PROJGETCHAINEDDIRECTIONZ,
       "projGetChainedDirectionZ",
       NONE)
GS_CMD(9,
       GS_CMD_PROJSETCHAINEDDIRECTIONX,
       "projSetChainedDirectionX",
       NONE)
GS_CMD(10,
       GS_CMD_PROJSETCHAINEDDIRECTIONY,
       "projSetChainedDirectionY",
       NONE)
GS_CMD(11,
       GS_CMD_PROJSETCHAINEDDIRECTIONZ,
       "projSetChainedDirectionZ",
       NONE)

GS_CMD(12,
       GS_CMD_PROJROTATECHAINEDDIRECTIONONAXISY,
       "projRotateChainedDirectionOnAxisY",
       INT)
GS_CMD(13,
       GS_CMD_PROJROTATECHAINEDDIRECTIONONAXISYBYVALUE,
       "projRotateChainedDirectionOnAxisYByValue",
       NONE)

GS_CMD(14,
       GS_CMD_PROJGETHITPLANENORMALX,
       "projGetHitPlaneNormalX",
       NONE)
GS_CMD(15,
       GS_CMD_PROJGETHITPLANENORMALY,
       "projGetHitPlaneNormalY",
       NONE)
GS_CMD(16,
       GS_CMD_PROJGETHITPLANENORMALZ,
       "projGetHitPlaneNormalZ",
       NONE)

GS_CMD(17,
       GS_CMD_PROJISCHAINEDINBOUNCELIMITFROMORIGINAL,
       "projIsChainedInBounceLimitFromOriginal",
       INT)
GS_CMD(18,
       GS_CMD_PROJISCHAINEDINBOUNCELIMITFROMORIGIN,
       "projIsChainedInBounceLimitFromOrigin",
       INT)

GS_CMD(19,
       GS_CMD_PROJBOUNCECHAINEDOFFPLANEFROMORIGINAL,
       "projBounceChainedOffPlaneFromOriginal",
       NONE)
GS_CMD(20,
       GS_CMD_PROJBOUNCECHAINEDOFFPLANEFROMORIGIN,
       "projBounceChainedOffPlaneFromOrigin",
       NONE)

GS_CMD(21,
       GS_CMD_PROJRESTOREORIGINALDIRECTIONTOCHAINED,
       "projRestoreOriginalDirectionToChained",
       NONE)
GS_CMD(22,
       GS_CMD_PROJCOPYORIGINDIRECTIONTOCHAINED,
       "projCopyOriginDirectionToChained",
       NONE)

GS_CMD(23,
       GS_CMD_PROJSTOPCHAINED,
       "projStopChained",
       NONE)

GS_CMD(24,
       GS_CMD_PROJGETORIGINPOSITION,
       "projGetOriginPosition",
       NONE)
GS_CMD(25,
       GS_CMD_PROJGETORIGINALCHAINEDPOSITION,
       "projGetOriginalChainedPosition",
       NONE)
GS_CMD(26,
       GS_CMD_PROJGETCHAINEDPOSITION,
       "projGetChainedPosition",
       NONE)
GS_CMD(27,
       GS_CMD_PROJSETCHAINEDPOSITION,
       "projSetChainedPosition",
       NONE)

GS_CMD(28,
       GS_CMD_PROJSOLVECHAINEDPASSDISTANCE,
       "projSolveChainedPassDistance",
       NONE)
GS_CMD(29,
       GS_CMD_PROJMOVECHAINEDPOSITIONFORWARD,
       "projMoveChainedPositionForward",
       INT)
GS_CMD(30,
       GS_CMD_PROJMOVECHAINEDPOSITIONFORWARDBYVALUE,
       "projMoveChainedPositionForwardByValue",
       NONE)
GS_CMD(31,
       GS_CMD_PROJSETSKIPRAYTRACEDISTANCE,
       "projSetSkipRaytraceDistance",
       INT)
GS_CMD(32,
       GS_CMD_PROJSETSKIPRAYTRACEDISTANCEBYVALUE,
       "projSetSkipRaytraceDistanceByValue",
       NONE)

GS_CMD(33,
       GS_CMD_PROJGETHITUNIT,
       "projGetHitUnit",
       NONE)
GS_CMD(34,
       GS_CMD_PROJGETSHOOTERUNIT,
       "projGetShooterUnit",
       NONE)

GS_CMD(35,
       GS_CMD_PROJISORIGINBULLET,
       "projIsOriginBullet",
       STRING)

GS_CMD(36,
       GS_CMD_PROJISHITCHAINNAME,
       "projIsHitChainName",
       STRING)
GS_CMD(37,
       GS_CMD_PROJGETHITCHAINNAME,
       "projGetHitChainName",
       NONE)

GS_CMD(38,
       GS_CMD_PROJISHITCHAINNUMBER,
       "projIsHitChainNumber",
       INT)
GS_CMD(39,
       GS_CMD_PROJGETHITCHAINNUMBER,
       "projGetHitChainNumber",
       NONE)

GS_CMD(40,
       GS_CMD_PROJSETCHAINEDBULLET,
       "projSetChainedBullet",
       STRING)
GS_CMD(41,
       GS_CMD_PROJSETCHAINEDRANGE,
       "projSetChainedRange",
       FLOAT)

GS_CMD(42,
       GS_CMD_PROJSPAWNCHAINED,
       "projSpawnChained",
       NONE)

GS_CMD(43,
       GS_CMD_PROJBOUNCECHAINEDOFFPLANEFROMORIGINALKEEPINGDIRECTIONY,
       "projBounceChainedOffPlaneFromOriginalKeepingDirectionY",
       NONE)
GS_CMD(44,
       GS_CMD_PROJBOUNCECHAINEDOFFPLANEFROMORIGINKEEPINGDIRECTIONY,
       "projBounceChainedOffPlaneFromOriginKeepingDirectionY",
       NONE)

GS_CMD(45,
       GS_CMD_PROJGETCHAINEDCUSTOMVALUE,
       "projGetChainedCustomValue",
       NONE)
GS_CMD(46,
       GS_CMD_PROJSETCHAINEDCUSTOMVALUE,
       "projSetChainedCustomValue",
       NONE)
GS_CMD(47,
       GS_CMD_PROJSETCHAINEDROTATIONRANDOMIZATION,
       "projSetChainedRotationRandomization",
       INT)

GS_CMD(48,
       GS_CMD_PROJFLATTENCHAINEDONPLANE,
       "projFlattenChainedOnPlane",
       FLOAT)
GS_CMD(49,
       GS_CMD_PROJSETCHAINEDVELOCITYFACTOR,
       "projSetChainedVelocityFactor",
       FLOAT)
GS_CMD(50,
       GS_CMD_PROJSETCHAINEDORIGINTOHITUNIT,
       "projSetChainedOriginToHitUnit",
       INT)

GS_CMD(51,
       GS_CMD_PROJSETCHAINEDLIFETIMETOVALUE,
       "projSetChainedLifeTimeToValue",
       NONE)

#undef GS_CMD_BASE

// up to 999
