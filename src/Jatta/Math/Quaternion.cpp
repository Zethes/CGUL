#include "Quaternion.h"
#include "Math.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"

Jatta::Quaternion::Quaternion()
{
    w = 1;
    x = y = z = 0;
}

Jatta::Quaternion::Quaternion(Float32 w, Float32 x, Float32 y, Float32 z)
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
void Jatta::Quaternion::Normalize()
{
}

void Jatta::Quaternion::RotateOnAxis(const Vector3& axis, Float32 angle)
{
    w = Math::Cos(angle / 2.0f);
    x = Math::Sin(angle / 2.0f) * axis.x;
    y = Math::Sin(angle / 2.0f) * axis.y;
    z = Math::Sin(angle / 2.0f) * axis.z;
}
