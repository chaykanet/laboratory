#include "actions.h"

vec_t initVec(double dX, double dY, double dZ)
{
    vec_t vector;
    vector.directionX = dX;
    vector.directionY = dY;
    vector.directionZ = dZ;

    return vector;
}

scale_t initScale(double kx, double ky, double kz)
{
    scale_t scale;
    scale.kX = kx;
    scale.kY = ky;
    scale.kZ = kz;
    return scale;
}

rotate_t initRotate(double angleX, double angleY, double angleZ)
{
    rotate_t rotate;
    rotate.angleX = angleX;
    rotate.angleY = angleY;
    rotate.angleZ = angleZ;
    return rotate;
}
