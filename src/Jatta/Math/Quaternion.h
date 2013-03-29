/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    struct Float2;
    struct Float3;
    struct Float4;
    struct Matrix;

    struct Quaternion
    {
        union
        {
            struct
            {
                Float32 r, i, j, k;
            };
            struct
            {
                Float32 w, x, y, z;
            };
            Float32 m[4];
        };
        Quaternion();
        Quaternion(Float32 w, Float32 x, Float32 y, Float32 z);
        /*Quaternion(double, const jVector3&);
        Quaternion(const jVector3&, double);
        jQuaternion operator+(const jQuaternion);
        void operator+=(const jQuaternion&);
        jQuaternion operator*(const double);
        jQuaternion operator*(const jQuaternion&);
        void operator*=(const jQuaternion&);
        jQuaternion operator*(const jVector3&);
        void operator*= (const jVector3&);
        void CreateBasis(jVector3*, jVector3*, jVector3*);*/
        void Normalize();

        void RotateOnAxis(const Float3& axis, Float32 angle);

        // TODO: finish the quaternion class, reference DirectX's D3DXQUATERNION
    };
}

#include "../External/Undefines.h"
