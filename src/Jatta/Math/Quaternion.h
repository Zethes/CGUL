/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    template< typename Type >
    struct Vector2T;
    template< typename Type >
    struct Vector3T;
    template< typename Type >
    struct Vector4T;
    template< typename Type >
    struct MatrixT;

    /** @brief Quaternion
     *  @todo Finish this class.
     */
    template< typename Type >
    struct QuaternionT
    {
        union
        {
            struct
            {
                Type r, i, j, k;
            };
            struct
            {
                Type w, x, y, z;
            };
            Type m[4];
        };
        QuaternionT();
        QuaternionT(Type w, Type x, Type y, Type z);
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

        void RotateOnAxis(const Vector3T< Type >& axis, Type angle);

        // TODO: finish the quaternion class, reference DirectX's D3DXQUATERNION
    };

    typedef QuaternionT<Float32> Quaternion;
    typedef QuaternionT<Float64> QuaternionD;
}

#include "../External/Undefines.h"
#include "Quaternion.ipp"
