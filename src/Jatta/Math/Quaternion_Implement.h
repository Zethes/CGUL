#include "Math.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"

template< typename Type >
Jatta::QuaternionT< Type >::QuaternionT()
{
    w = 1;
    x = y = z = 0;
}

template< typename Type >
Jatta::QuaternionT< Type >::QuaternionT(Type w, Type x, Type y, Type z)
{
    this->w = w;
    this->x = x;
    this->y = y;
    this->z = z;
}

/** @brief Normalizes the quaternion.
 *  @details In theory, a quaternion should always be normalized.  Due to floating point
 *  inconsistencies, quaternions are hardly ever normalized.  It is imperative that a quaternion be
 *  normalized regularly.  Ideally, you would normalize a quaternion once per tick.
 *  @note "A de-normalized quaternion is NOT a happy quaternion and will cause you problems"
 *  -Professor Nicholson
 */
template< typename Type >
void Jatta::QuaternionT< Type >::Normalize()
{
}

template< typename Type >
void Jatta::QuaternionT< Type >::RotateOnAxis(const Vector3T< Type >& axis, Type angle)
{
    w = Math::Cos(angle / 2.0f);
    x = Math::Sin(angle / 2.0f) * axis.x;
    y = Math::Sin(angle / 2.0f) * axis.y;
    z = Math::Sin(angle / 2.0f) * axis.z;
}
