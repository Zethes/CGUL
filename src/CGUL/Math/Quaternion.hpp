// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Quarternion.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

namespace CGUL
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
        struct
        {
            Type w, x, y, z;
        };
        Type m[4];
        QuaternionT();
        QuaternionT(Type w, Type x, Type y, Type z);

        QuaternionT< Type > operator*(const QuaternionT< Type >& operand) const;
        QuaternionT< Type >& operator*=(const QuaternionT< Type >& operand);

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
    };

    typedef QuaternionT< Float32 > Quaternion;
    typedef QuaternionT< Float64 > QuaternionD;
}

#include "../External/Undefines.hpp"
#include "Quaternion_Implement.hpp"
