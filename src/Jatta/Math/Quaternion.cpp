#include "Quaternion.h"

Jatta::Quaternion::Quaternion()
{
}

Jatta::Quaternion::Quaternion(Float32 w, Float32 x, Float32 y, Float32 z)
{
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