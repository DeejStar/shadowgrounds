#ifndef CLOUD_PARTICLE_SYSTEM_H
#define CLOUD_PARTICLE_SYSTEM_H

namespace frozenbyte
{
    namespace particle
    {
        enum CLOUD_PARTICLE_SYSTEM_PARAMS {
            PB_PCLOUD_RANDOM_DIRECTION = GEN_PARTICLE_SYSTEM_PARAM_COUNT,
            PB_PCLOUD_DIRECTION,
            PB_PCLOUD_SHAPE,
            PB_PCLOUD_SPHERE_INNER_RADIUS,
            PB_PCLOUD_SPHERE_OUTER_RADIUS,
            PB_PCLOUD_BOX_MIN,
            PB_PCLOUD_BOX_MAX,
            PB_PCLOUD_CYLINDER_HEIGHT,
            PB_PCLOUD_CYLINDER_RADIUS
        };

        ParticleSystemClassDesc *getCloudParticleSystemClassDesc();

    } // particle

}     // frozenbyte

#endif
