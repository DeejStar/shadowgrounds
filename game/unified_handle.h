#ifndef UNIFIED_HANDLE_H
#define UNIFIED_HANDLE_H

#include "unified_handle_type.h"

// the no-object handle
#define UNIFIED_HANDLE_NONE 0

// reserved (0-16777215, 0x80000000 - 0xffffffff)
// low values reserved to catch some obvious scripting errors (trying to use some other random value as a handle)
//#define UNIFIED_HANDLE_FIRST_RESERVED_LOW (0)
//#define UNIFIED_HANDLE_LAST_RESERVED_LOW ((1<<7)-1)
// last bit reserved because of signedness (value range 0x80000000 - 0xffffffff)
//#define UNIFIED_HANDLE_FIRST_RESERVED_HIGH (1<<31)
//#define UNIFIED_HANDLE_LAST_RESERVED_HIGH (0xffffffff)

#define UNIFIED_HANDLE_VALUE_RANGE ( (1 << 24) - 1 )

// units (when 25th bit set) (value range 16777216 - 33554431)
#define UNIFIED_HANDLE_BIT_UNIT    (1 << 24)

#define UNIFIED_HANDLE_FIRST_UNIT  (1 << 24)
#define UNIFIED_HANDLE_LAST_UNIT   (UNIFIED_HANDLE_FIRST_UNIT + UNIFIED_HANDLE_VALUE_RANGE)
#define UNIFIED_HANDLE_MAX_UNITS   (UNIFIED_HANDLE_LAST_UNIT - UNIFIED_HANDLE_FIRST_UNIT + 1)

#define IS_UNIFIED_HANDLE_UNIT(x) ( (x & UNIFIED_HANDLE_BIT_UNIT) != 0 )

// terrain objects (when 26th bit set) (value range 33554431 - 67108864)
// (split to bit mask, does not represent actual max terr.obj amount)
#define UNIFIED_HANDLE_BIT_TERRAIN_OBJECT   (1 << 25)

#define UNIFIED_HANDLE_FIRST_TERRAIN_OBJECT (1 << 25)
#define UNIFIED_HANDLE_LAST_TERRAIN_OBJECT  (UNIFIED_HANDLE_FIRST_TERRAIN_OBJECT + UNIFIED_HANDLE_VALUE_RANGE)
//#define UNIFIED_HANDLE_MAX_TERRAIN_OBJECTS (UNIFIED_HANDLE_LAST_TERRAIN_OBJECT - UNIFIED_HANDLE_FIRST_TERRAIN_OBJECT + 1)

#define IS_UNIFIED_HANDLE_TERRAIN_OBJECT(x) ( ( (x) & UNIFIED_HANDLE_BIT_TERRAIN_OBJECT ) != 0 )

// (part of internal terrain object implementation...)
// (total 2048 diff. model ids)
// (total 8192 diff. instance ids)
#define UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_SHIFT         0
#define UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_BITS          11
#define UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_MASK          ( (1 << 10) - 1 )
#define UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_LAST_VALUE    (UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_MASK \
                                                              >> UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_SHIFT)
#define UNIFIED_HANDLE_TERRAIN_OBJECT_INSTANCE_ID_SHIFT      11
#define UNIFIED_HANDLE_TERRAIN_OBJECT_INSTANCE_ID_BITS       13
#define UNIFIED_HANDLE_TERRAIN_OBJECT_INSTANCE_ID_MASK       ( ( (1 \
                                                                  << 23) \
                                                                 - 1 ) - UNIFIED_HANDLE_TERRAIN_OBJECT_MODEL_ID_MASK )
#define UNIFIED_HANDLE_TERRAIN_OBJECT_INSTANCE_ID_LAST_VALUE (UNIFIED_HANDLE_TERRAIN_OBJECT_INSTANCE_ID_MASK \
                                                              >> UNIFIED_HANDLE_TERRAIN_OBJECT_INSTANCE_ID_SHIFT)

// dynamic light
// (split to bit mask, does not represent actual max dynamic light amount)
#define UNIFIED_HANDLE_BIT_DYNAMIC_LIGHT                     (1 << 26)

#define UNIFIED_HANDLE_FIRST_DYNAMIC_LIGHT                   (1 << 26)
#define UNIFIED_HANDLE_LAST_DYNAMIC_LIGHT                    (UNIFIED_HANDLE_FIRST_DYNAMIC_LIGHT \
                                                              + UNIFIED_HANDLE_VALUE_RANGE)

#define IS_UNIFIED_HANDLE_DYNAMIC_LIGHT(x) ( (x & UNIFIED_HANDLE_BIT_DYNAMIC_LIGHT) != 0 )

// (part of internal dynamic light implementation...)
// (total 2048 diff. type ids)
// (total 8192 diff. instance ids)
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_SHIFT          0
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_BITS           11
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_MASK           ( (1 << 10) - 1 )
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_LAST_VALUE     (UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_MASK \
                                                             >> UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_SHIFT)
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_INSTANCE_ID_SHIFT      11
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_INSTANCE_ID_BITS       13
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_INSTANCE_ID_MASK       ( ( (1 \
                                                                 << 23) \
                                                                - 1 ) - UNIFIED_HANDLE_DYNAMIC_LIGHT_TYPE_ID_MASK )
#define UNIFIED_HANDLE_DYNAMIC_LIGHT_INSTANCE_ID_LAST_VALUE (UNIFIED_HANDLE_DYNAMIC_LIGHT_INSTANCE_ID_MASK \
                                                             >> UNIFIED_HANDLE_DYNAMIC_LIGHT_INSTANCE_ID_SHIFT)

// extended... (the following ones are part of this...)
#define UNIFIED_HANDLE_BIT_EXTENDED                         (1 << 27)
#define UNIFIED_HANDLE_BIT_EXTENDED_VALUE                   (7 << 28)
// (this should equal to the one above.)
//#define UNIFIED_HANDLE_BIT_EXTENDED_VALUE ((1<<28)|(1<<29)|(1<<30))

#define IS_UNIFIED_HANDLE_EXTENDED(x) ( (x & UNIFIED_HANDLE_BIT_EXTENDED) != 0 )

// ambient sound points
#define UNIFIED_HANDLE_EXTENDED_VALUE_AMBIENT_SOUND (1 << 28)

#define UNIFIED_HANDLE_FIRST_AMBIENT_SOUND          ( UNIFIED_HANDLE_BIT_EXTENDED | (1 << 28) )
#define UNIFIED_HANDLE_LAST_AMBIENT_SOUND           (UNIFIED_HANDLE_FIRST_AMBIENT_SOUND + UNIFIED_HANDLE_VALUE_RANGE)

#define IS_UNIFIED_HANDLE_AMBIENT_SOUND(x) ( ( x \
                                               & (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_BIT_EXTENDED_VALUE) ) == \
                                             (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_AMBIENT_SOUND) )

// particle spawners
#define UNIFIED_HANDLE_EXTENDED_VALUE_PARTICLE_SPAWNER (2 << 28)

#define UNIFIED_HANDLE_FIRST_PARTICLE_SPAWNER          ( UNIFIED_HANDLE_BIT_EXTENDED | (2 << 28) )
#define UNIFIED_HANDLE_LAST_PARTICLE_SPAWNER           (UNIFIED_HANDLE_FIRST_PARTICLE_SPAWNER \
                                                        + UNIFIED_HANDLE_VALUE_RANGE)

#define IS_UNIFIED_HANDLE_PARTICLE_SPAWNER(x) ( ( x \
                                                  & (UNIFIED_HANDLE_BIT_EXTENDED \
                                                     | UNIFIED_HANDLE_BIT_EXTENDED_VALUE) ) == \
                                                (UNIFIED_HANDLE_BIT_EXTENDED \
                                                 | UNIFIED_HANDLE_EXTENDED_VALUE_PARTICLE_SPAWNER) )

// items
#define UNIFIED_HANDLE_EXTENDED_VALUE_ITEM (3 << 28)

#define UNIFIED_HANDLE_FIRST_ITEM          ( UNIFIED_HANDLE_BIT_EXTENDED | (3 << 28) )
#define UNIFIED_HANDLE_LAST_ITEM           (UNIFIED_HANDLE_FIRST_ITEM + UNIFIED_HANDLE_VALUE_RANGE)

#define IS_UNIFIED_HANDLE_ITEM(x) ( ( x & (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_BIT_EXTENDED_VALUE) ) == \
                                    (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_ITEM) )

// trackers
#define UNIFIED_HANDLE_EXTENDED_VALUE_TRACKER (4 << 28)

#define UNIFIED_HANDLE_FIRST_TRACKER          ( UNIFIED_HANDLE_BIT_EXTENDED | (4 << 28) )
#define UNIFIED_HANDLE_LAST_TRACKER           (UNIFIED_HANDLE_FIRST_TRACKER + UNIFIED_HANDLE_VALUE_RANGE)

#define IS_UNIFIED_HANDLE_TRACKER(x) ( ( x & (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_BIT_EXTENDED_VALUE) ) == \
                                       (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_TRACKER) )

// lights
#define UNIFIED_HANDLE_EXTENDED_VALUE_LIGHT (5 << 28)

#define UNIFIED_HANDLE_FIRST_LIGHT          ( UNIFIED_HANDLE_BIT_EXTENDED | (5 << 28) )
#define UNIFIED_HANDLE_LAST_LIGHT           (UNIFIED_HANDLE_FIRST_LIGHT + UNIFIED_HANDLE_VALUE_RANGE)

#define IS_UNIFIED_HANDLE_LIGHT(x) ( ( x & (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_BIT_EXTENDED_VALUE) ) == \
                                     (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_LIGHT) )

// validates the type selection bits... (only one of 25th-31th bits set, 32nd bit not set)
// (1st-24th bit for each type's internal id)
#define VALIDATE_UNIFIED_HANDLE_BITS(x) \
    ( (x & 0xff000000) == UNIFIED_HANDLE_BIT_UNIT \
      || (x & 0xff000000) == UNIFIED_HANDLE_BIT_TERRAIN_OBJECT \
      || (x & 0xff000000) == UNIFIED_HANDLE_BIT_DYNAMIC_LIGHT \
      || (x & 0xff000000) == (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_ITEM) \
      || (x & 0xff000000) == (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_TRACKER) \
      || (x & 0xff000000) == (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_AMBIENT_SOUND) \
      || (x & 0xff000000) == (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_PARTICLE_SPAWNER) \
      || (x & 0xff000000) == (UNIFIED_HANDLE_BIT_EXTENDED | UNIFIED_HANDLE_EXTENDED_VALUE_LIGHT) )

#endif
