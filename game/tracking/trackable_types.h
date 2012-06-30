#ifndef TRACKABLE_TYPES_H
#define TRACKABLE_TYPES_H

#include "trackable_typeid.h"

// these are game specific

#define TRACKABLE_TYPE_BURNABLE               (1 << 0)
#define TRACKABLE_TYPE_LEAKABLE               (1 << 1)
#define TRACKABLE_TYPE_TARGET_FOR_HOSTILE_AI  (1 << 2)
#define TRACKABLE_TYPE_TARGET_FOR_FRIENDLY_AI (1 << 3)
#define TRACKABLE_TYPE_NET_SELF               (1 << 4)
#define TRACKABLE_TYPE_NET_OTHER              (1 << 5)

#define TRACKABLE_TYPE_RESERVED_6             (1 << 6)
#define TRACKABLE_TYPE_RESERVED_7             (1 << 7)
#define TRACKABLE_TYPE_RESERVED_8             (1 << 8)
#define TRACKABLE_TYPE_RESERVED_9             (1 << 9)
#define TRACKABLE_TYPE_RESERVED_10            (1 << 10)
#define TRACKABLE_TYPE_RESERVED_11            (1 << 11)
#define TRACKABLE_TYPE_RESERVED_12            (1 << 12)
#define TRACKABLE_TYPE_RESERVED_13            (1 << 13)
#define TRACKABLE_TYPE_RESERVED_14            (1 << 14)
#define TRACKABLE_TYPE_RESERVED_15            (1 << 15)
#define TRACKABLE_TYPE_RESERVED_16            (1 << 16)
#define TRACKABLE_TYPE_RESERVED_17            (1 << 17)
#define TRACKABLE_TYPE_RESERVED_18            (1 << 18)
#define TRACKABLE_TYPE_RESERVED_19            (1 << 19)
#define TRACKABLE_TYPE_RESERVED_20            (1 << 20)
#define TRACKABLE_TYPE_RESERVED_21            (1 << 21)
#define TRACKABLE_TYPE_RESERVED_22            (1 << 22)
#define TRACKABLE_TYPE_RESERVED_23            (1 << 23)

TRACKABLE_TYPEID_DATATYPE getTrackableTypeIdForName(const char *trackableTypeName);

#endif
