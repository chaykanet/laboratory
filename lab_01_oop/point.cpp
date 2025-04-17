#include "point.h"

#include <stdlib.h>

#include <cmath>
#include <stdio.h>

void defaultPoint(point_t &point)
{
    point.x = 0;
    point.y = 0;
    point.z = 0;
}

void coordinatesPoint(double &x, double &y, double &z, const point_t &point)
{
    x = point.x;
    y = point.y;
    z = point.z;
}

void initPoint(point_t &point, double x, double y, double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

myerror_t readPoint(point_t &point, FILE *file)
{
    myerror_t rc = ERR_OK;

    if (file == nullptr)
        rc = ERR_INPUT_DATA;
    else
    {
        double x, y, z;
        if (fscanf(file, "%lf %lf %lf", &x, &y, &z) != 3)
            rc = ERR_INPUT_DATA;
        else
        {
            initPoint(point, x, y, z);
        }
    }

    return rc;
}

static vec_t initVecToCenter(const point_t &center)
{
    return initVec(-center.x, -center.y, -center.z);
}

static vec_t initVecFromCenter(const point_t &center)
{
    return initVec(center.x, center.y, center.z);
}

static void _scalePoint(point_t &point, const scale_t &scale)
{
    point.x *= scale.kX;
    point.y *= scale.kY;
    point.z *= scale.kZ;
}

void movePoint(point_t &point, const vec_t &vector)
{
    point.x += vector.directionX;
    point.y += vector.directionY;
    point.z += vector.directionZ;
}

void scalePoint(point_t &point, const scale_t &scale, const point_t &center)
{
    vec_t toCenter = initVecToCenter(center);
    vec_t fromCenter = initVecFromCenter(center);

    movePoint(point, toCenter);
    _scalePoint(point, scale);
    movePoint(point, fromCenter);
}

static void rotateByAngle(double &coorA, double &coorB, double angle)
{
    double Cos = cos(angle);
    double Sin = sin(angle);

    double originalCoorA = coorA;
    double originalCoorB = coorB;

    coorA = originalCoorA * Cos - originalCoorB * Sin;
    coorB = originalCoorA * Sin + originalCoorB * Cos;
}

void rotateByXOZ(point_t &point, const rotate_t& rotate)
{
    rotateByAngle(point.y, point.z, rotate.angleX);
    rotateByAngle(point.x, point.z, rotate.angleY);
    rotateByAngle(point.x, point.y, rotate.angleZ);
}

void rotatePoint(point_t &point, const point_t &center, const rotate_t& rotate)
{
    vec_t toCenter = initVecToCenter(center);
    vec_t fromCenter = initVecFromCenter(center);

    movePoint(point, toCenter);
    rotateByXOZ(point, rotate);
    movePoint(point, fromCenter);
}
