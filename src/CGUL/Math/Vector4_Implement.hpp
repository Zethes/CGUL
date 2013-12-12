// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector4_Implement.hpp
 */

#include "Vector4.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Matrix.hpp"

#include <cmath>

/**
 */
template< typename Type >
const CGUL::Vector4T< Type > CGUL::Vector4T< Type >::zero(0, 0, 0, 0);

/**
 */
template< typename Type >
const CGUL::Vector4T< Type > CGUL::Vector4T< Type >::one(1, 1, 1, 1);

/**
 */
template< typename Type >
const CGUL::Vector4T< Type > CGUL::Vector4T< Type >::unitX(1, 0, 0, 0);

/**
 */
template< typename Type >
const CGUL::Vector4T< Type > CGUL::Vector4T< Type >::unitY(0, 1, 0, 0);

/**
 */
template< typename Type >
const CGUL::Vector4T< Type > CGUL::Vector4T< Type >::unitZ(0, 0, 1, 0);

/**
 */
template< typename Type >
const CGUL::Vector4T< Type > CGUL::Vector4T< Type >::unitW(0, 0, 0, 1);

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::DotProduct(const Vector4T& valueA, const Vector4T& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y) + (valueA.z * valueB.z) + (valueA.w * valueB.w);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::Normalized(const Vector4T& value)
{
    Type inverseMagnitude = 1.0f / value.GetMagnitude();
    return Vector4T(value.x * inverseMagnitude, value.y * inverseMagnitude, value.z * inverseMagnitude, value.w * inverseMagnitude);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >::Vector4T()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

/** @param copy The vector to copy.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >::Vector4T(const Vector4T& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
    this->w = copy.w;
}

/** @param value The value for each component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >::Vector4T(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

/** @param x The x component.
 *  @param y The y component.
 *  @param z The z component.
 *  @param w The w component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >::Vector4T(Type x, Type y, Type z, Type w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

/** @param operand The other vector.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >& CGUL::Vector4T< Type >::operator=(const Vector4T& operand)
{
    this->x = operand.x;
    this->y = operand.y;
    this->z = operand.z;
    this->w = operand.w;
    return *this;
}

/** @warning This method does not bounds check, must be 0, 1, 2, or 3!
 *  @param index The component index (0 for x, 1 for y, 2 for z, 3 for w).
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type& CGUL::Vector4T< Type >::operator[](UInt32 index)
{
    return m[index];
}

/** @details Unlike the other operator[], this one works on constant vectors and returns a value
 *  that cannot be modified to alter the original vector.
 *  @warning This method does not bounds check, must be 0, 1, 2, or 3!
 *  @param index The component index (0 for x, 1 for y, 2 for z, 3 for w).
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::operator[](UInt32 index) const
{
    return m[index];
}

/** @details The inverse is defined as (-x, -y, -z, -w) of the original vector.
 *  @returns The inverse vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::operator-() const
{
    return Vector4(-this->x, -this->y, -this->z, -this->w);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are equal, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Vector4T< Type >::operator==(const Vector4T& operand) const
{
    return (this->x == operand.x &&
            this->y == operand.y &&
            this->z == operand.z &&
            this->w == operand.w);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are not equal, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Vector4T< Type >::operator!=(const Vector4T& operand) const
{
    return (this->x != operand.x ||
            this->y != operand.y ||
            this->z != operand.z ||
            this->w != operand.w);
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::operator+(const Vector4T& operand) const
{
    return Vector4T(this->x + operand.x,
                    this->y + operand.y,
                    this->z + operand.z,
                    this->w + operand.w);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >& CGUL::Vector4T< Type >::operator+=(const Vector4T& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    this->z += operand.z;
    this->w += operand.w;
    return *this;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::operator-(const Vector4T& operand) const
{
    return Vector4T(this->x - operand.x,
                    this->y - operand.y,
                    this->z - operand.z,
                    this->w - operand.w);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >& CGUL::Vector4T< Type >::operator-=(const Vector4T& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    this->z -= operand.z;
    this->w -= operand.w;
    return *this;
}

/** @param operand A scalar value.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::operator*(Type operand) const
{
    return Vector4T(this->x * operand,
                    this->y * operand,
                    this->z * operand,
                    this->w * operand);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::operator*(const MatrixT< Type >& operand) const
{
    Vector4T result;
    result.x = DotProduct(Vector4T(operand.m[0][0], operand.m[1][0], operand.m[2][0], operand.m[3][0]), *this);
    result.y = DotProduct(Vector4T(operand.m[0][1], operand.m[1][1], operand.m[2][1], operand.m[3][1]), *this);
    result.z = DotProduct(Vector4T(operand.m[0][2], operand.m[1][2], operand.m[2][2], operand.m[3][2]), *this);
    result.w = DotProduct(Vector4T(operand.m[0][3], operand.m[1][3], operand.m[2][3], operand.m[3][3]), *this);
    return result;
}

/** @param operand A scalar value.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >& CGUL::Vector4T< Type >::operator*=(Type operand)
{
    this->x *= operand;
    this->y *= operand;
    this->z *= operand;
    this->w *= operand;
    return *this;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >& CGUL::Vector4T< Type >::operator*=(const MatrixT< Type >& operand)
{
    return *this = *this * operand;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::operator/(Type operand) const
{
    return Vector4T(this->x / operand,
                    this->y / operand,
                    this->z / operand,
                    this->w / operand);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >& CGUL::Vector4T< Type >::operator/=(Type operand)
{
    this->x /= operand;
    this->y /= operand;
    this->z /= operand;
    this->w /= operand;
    return *this;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT std::ostream& CGUL::operator<<(std::ostream& stream, const CGUL::Vector4T< Type >& vector)
{
    stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
    return stream;
}

template< typename Type >
template< typename OtherType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type >::operator CGUL::Vector4T< OtherType >()
{
    return Vector4T< OtherType >((OtherType)x, (OtherType)y, (OtherType)z, (OtherType)w);
}

/** @param index The component index, so 0 for x, 1 for y, 2 for z, and 3 for w.
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type& CGUL::Vector4T< Type >::At(UInt32 index)
{
    return m[index];
}

/** @param index The component index, so 0 for x, 1 for y, 2 for z, and 3 for w.
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::At(UInt32 index) const
{
    return m[index];
}

/** @param value The value to set all components to.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Set(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
    this->w = value;
}

/** @param x The x component.
 *  @param y The y component.
 *  @param z The z component.
 *  @param w The w component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Set(Type x, Type y, Type z, Type w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Clear()
{
    this->x = this->y = this->z = this->w = 0;
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @param y The y component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector4T< Type >::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2(m[x], m[y]);
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @param y The y component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @param z The z component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector4T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3(m[x], m[y], m[z]);
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @param y The y component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @param z The z component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @param w The w component (0 for x, 1 for y, 2 for z, 3 for w).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4(m[x], m[y], m[z], m[w]);
}

/** @warning This method uses sqrt() which can be slow!
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Normalize()
{
    Type inverseMagnitude = 1.0f / GetMagnitude();
    this->x *= inverseMagnitude;
    this->y *= inverseMagnitude;
    this->z *= inverseMagnitude;
    this->w *= inverseMagnitude;
}

/** @warning This method uses sqrt() which can be slow!
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Boolean CGUL::Vector4T< Type >::IsNormalized(Type epsilon) const
{
    return Math::InEpsilon(GetMagnitude(), 1, epsilon);
}

/** @details Faster implementations of this method exist but are less accurate.  For more
 *  information, see @ref GetSquaredMagnitude and @ref GetManhattanMagnitude.
 *  @warning This method uses sqrt() which can be slow!
 *  @returns The magnitude.
 *  @see GetSquaredMagnitude
 *  @see GetManhattanMagnitude
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::GetMagnitude() const
{
    return Math::Sqrt(x * x + y * y + z * z + w * w);
}

/** @details The squared magnitude is a less accurate, but more quickly calculated alternative to
 *  the @ref GetMagnitude method.  A squared magnitude can be used to measure if one magnitude is
 *  larger than another, but cannot be used to accurately determine differences between magnitudes.
 *  @returns The squared magnitude.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::GetSquaredMagnitude() const
{
    return (x * x + y * y + z * z + w * w);
}

/** @details The Manhattan magnitude is even @em faster than the @ref GetMagnitudeSquared
 *  alternative, but far less accurate.  The squared magnitude cannot be used to determine if one
 *  magnitude is larger than another, nor can it be used to compare magnitudes.  The purpose of the
 *  Manhattan magnitude is mostly used as a guess to speed up algorithms that may use it as a
 *  heuristic.
 *  @note The name Manhattan is a reference to the city Manhattan and how all the streets are laid
 *  out in blocks.  To walk one block you would have to walk the length of the block, then the
 *  width.  The result of this function is just that, the sum of the x and y components.  A call to
 *  make the values absolute is also necessary to ensure an always positive result.
 *  @returns The manhattan magnitude.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::GetManhattanMagnitude() const
{
    return Math::Abs(x) + Math::Abs(y) + Math::Abs(z) + Math::Abs(w);
}

/** @details The distance between two vectors is defined as the magnitude of one vector subtracted
 *  by another.  In other words: @ref GetMagnitude(Vec1 - Vec2).  Because of this the same notes in
 *  @ref GetMagnitude apply to this method.
 *  @warning This method uses sqrt() which can be slow!
 *  @param other The other vector.
 *  @returns The distance between the two vectors.
 *  @see GetMagnitude
 *  @see GetSquaredDistance
 *  @see GetManhattanDistance
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::GetDistance(const Vector4T& other) const
{
    return Math::Sqrt(Math::Sqr(other.x - x) +
                      Math::Sqr(other.y - y) +
                      Math::Sqr(other.z - z) +
                      Math::Sqr(other.w - w));
}

/** @param other The other vector.
 *  @returns The squared distance between the two vectors.
 *  @see GetDistance
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::GetSquaredDistance(const Vector4T& other) const
{
    return Math::Sqr(other.x - x) +
           Math::Sqr(other.y - y) +
           Math::Sqr(other.z - z) +
           Math::Sqr(other.w - w);
}

/** @param other The other vector.
 *  @returns The manhattan distance between the two vectors.
 *  @see GetDistance
 *  @todo Check the implementation because this is actually slower than the squared distance.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::GetManhattanDistance(const Vector4T& other) const
{
    return Math::Abs(other.x - x) +
           Math::Abs(other.y - y) +
           Math::Abs(other.z - z) +
           Math::Abs(other.w - w);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Floor()
{
    this->x = Math::Floor(this->x);
    this->y = Math::Floor(this->y);
    this->z = Math::Floor(this->z);
    this->w = Math::Floor(this->w);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Round()
{
    this->x = Math::Round(this->x);
    this->y = Math::Round(this->y);
    this->z = Math::Round(this->z);
    this->w = Math::Round(this->w);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector4T< Type >::Ceil()
{
    this->x = Math::Ceil(this->x);
    this->y = Math::Ceil(this->y);
    this->z = Math::Ceil(this->z);
    this->w = Math::Ceil(this->w);
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::Floored() const
{
    return Vector4(Math::Floor(this->x),
                   Math::Floor(this->y),
                   Math::Floor(this->z),
                   Math::Floor(this->w));
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::Rounded() const
{
    return Vector4(Math::Round(this->x),
                   Math::Round(this->y),
                   Math::Round(this->z),
                   Math::Round(this->w));
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector4T< Type >::Ceiled() const
{
    return Vector4(Math::Ceil(this->x),
                   Math::Ceil(this->y),
                   Math::Ceil(this->z),
                   Math::Ceil(this->w));
}

/** @returns x + y + z + w
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::SumComponents() const
{
    return x + y + z + w;
}

/** @returns x * y * z * w
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector4T< Type >::MultiplyComponents() const
{
    return x * y * z * w;
}
