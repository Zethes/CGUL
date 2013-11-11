/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "../Math/Vector3.h"
#include "../Math/Vector4.h"

/** @details Each element is calculated by taking their respective values and dividing by 255.0f.
 *  This is useful when colors need to be represented as floating point numbers rather than byte
 *  values, as is the case in a lot of API's (especially graphical ones, such as OpenGL).
 *  @returns A vector containing the r, g, b values as floating point x, y, z.
 */
template< typename Type >
_JATTA_EXPORT Jatta::Vector3T< Type > Jatta::Color::ToVector3() const
{
    return Vector3T< Type >(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f);
}

/** @details Same as @ref ToVector3 except it contains the alpha value as well.
 *  @returns A vector containing the r, g, b, a values as floating point x, y, z, w.
 */
template< typename Type >
_JATTA_EXPORT Jatta::Vector4T< Type > Jatta::Color::ToVector4() const
{
    return Vector4T< Type >(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, this->a / 255.0f);
}
