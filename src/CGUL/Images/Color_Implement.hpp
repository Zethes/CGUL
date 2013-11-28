// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Color_Implement.hpp
 */

#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"

/** @details Each element is calculated by taking their respective values and dividing by 255.0f.
 *  This is useful when colors need to be represented as floating point numbers rather than byte
 *  values, as is the case in a lot of API's (especially graphical ones, such as OpenGL).
 *  @returns A vector containing the r, g, b values as floating point x, y, z.
 */
template< typename Type >
_CGUL_EXPORT CGUL::Vector3T< Type > CGUL::Color::ToVector3() const
{
    return Vector3T< Type >(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f);
}

/** @details Same as @ref ToVector3 except it contains the alpha value as well.
 *  @returns A vector containing the r, g, b, a values as floating point x, y, z, w.
 */
template< typename Type >
_CGUL_EXPORT CGUL::Vector4T< Type > CGUL::Color::ToVector4() const
{
    return Vector4T< Type >(this->r / 255.0f, this->g / 255.0f, this->b / 255.0f, this->a / 255.0f);
}
