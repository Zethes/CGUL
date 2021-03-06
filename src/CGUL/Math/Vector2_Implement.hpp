// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector2_Implement.hpp
 */

// CGUL Includes
#include "../Math/Constants.hpp"
#include "../Math/Math.hpp"
#include "../Math/Vector3.hpp"
#include "../Math/Vector4.hpp"

/**
 */
template< typename Type >
const CGUL::Vector2T< Type > CGUL::Vector2T< Type >::zero(0, 0);

/**
 */
template< typename Type >
const CGUL::Vector2T< Type > CGUL::Vector2T< Type >::one(1, 1);

/**
 */
template< typename Type >
const CGUL::Vector2T< Type > CGUL::Vector2T< Type >::unitX(1, 0);

/**
 */
template< typename Type >
const CGUL::Vector2T< Type > CGUL::Vector2T< Type >::unitY(0, 1);

/**
 */
template< typename Type >
const CGUL::Vector2T< Type > CGUL::Vector2T< Type >::nan(Math::Nan, Math::Nan);

/** @details Defined as (cos(angle) * magnitude, sin(angle) * magnitude).  If no magnitude is given
 *  it will default to one.
 *  @param angle The angle in radians.
 *  @param magnitude An optional magnitude.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::FromAngle(Type angle, Type magnitude)
{
    return CGUL::Vector2T< Type >(Math::Cos(angle) * magnitude, Math::Sin(angle) * magnitude);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::DotProduct(const Vector2T& valueA, const Vector2T& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::CrossProduct(const Vector2T& valueA, const Vector2T& valueB)
{
    return valueA.y * valueB.x - valueA.x * valueB.y;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::Normalized(const Vector2T& value)
{
    if (value.GetSquaredMagnitude() != 0)
    {
        Type inverseMagnitude = 1.0f / value.GetMagnitude();
        return Vector2T(value.x * inverseMagnitude, value.y * inverseMagnitude);
    }
    return Vector2T(0, 0);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::Distance(const Vector2T& vectorA, const Vector2T& vectorB)
{
    return Math::Sqrt(Math::Sqr(vectorA.x - vectorB.x) + Math::Sqr(vectorA.y - vectorB.y));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::DistanceSquared(const Vector2T& vectorA, const Vector2T& vectorB)
{
    return Math::Sqr(vectorA.x - vectorB.x) + Math::Sqr(vectorA.y - vectorB.y);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::DistanceManhattan(const Vector2T& vectorA, const Vector2T& vectorB)
{
    return Math::Abs(vectorA.x - vectorB.x) + Math::Abs(vectorA.y - vectorB.y);
}

template< typename Type >
_CGUL_INLINE_DEFINE CGUL::Vector2T< Type > CGUL::Vector2T< Type >::Lerp(const Vector2T& from, const Vector2T& to, Type t)
{
    return from + (to - from) * t;
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >::Vector2T()
{
    this->x = 0;
    this->y = 0;
}

/** @param copy The vector to copy.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >::Vector2T(const Vector2T& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}

/** @param value The value for each component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >::Vector2T(Type value)
{
    this->x = value;
    this->y = value;
}

/** @param x The x component.
 *  @param y The y component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >::Vector2T(Type x, Type y)
{
    this->x = x;
    this->y = y;
}

/** @param operand The other vector.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >& CGUL::Vector2T< Type >::operator=(const Vector2T& operand)
{
    this->x = operand.x;
    this->y = operand.y;
    return *this;
}

/** @warning This method does not bounds check, must be 0 or 1!
 *  @param index The component index (0 for x, 1 for y).
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type& CGUL::Vector2T< Type >::operator[](UInt32 index)
{
    return operator[](index);
}

/** @details Unlike the other operator[], this one works on constant vectors and returns a value
 *  that cannot be modified to alter the original vector.
 *  @warning This method does not bounds check, must be 0 or 1!
 *  @param index The component index (0 for x, 1 for y).
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::operator[](UInt32 index) const
{
    return operator[](index);
}

/** @details The inverse is defined as (-x, -y) of the original vector.
 *  @returns The inverse vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::operator-() const
{
    return Vector2T(-this->x, -this->y);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are equal, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Vector2T< Type >::operator==(const Vector2T& operand) const
{
    return (this->x == operand.x && this->y == operand.y);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are not equal, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Vector2T< Type >::operator!=(const Vector2T& operand) const
{
    return (this->x != operand.x || this->y != operand.y);
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::operator+(const Vector2T& operand) const
{
    return Vector2T(this->x + operand.x, this->y + operand.y);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >& CGUL::Vector2T< Type >::operator+=(const Vector2T& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    return *this;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::operator-(const Vector2T& operand) const
{
    return Vector2T(this->x - operand.x, this->y - operand.y);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >& CGUL::Vector2T< Type >::operator-=(const Vector2T& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    return *this;
}

/** @param operand A scalar value.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::operator*(Type operand) const
{
    return Vector2T(this->x * operand, this->y * operand);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::operator*(const MatrixT< Type >& operand) const
{
    Vector2T result;
    result.x = Vector4T< Type >::DotProduct(Vector4T< Type >(operand.m[0][0], operand.m[1][0], operand.m[2][0], operand.m[3][0]), Vector4T< Type >(x, y, 1, 1));
    result.y = Vector4T< Type >::DotProduct(Vector4T< Type >(operand.m[0][1], operand.m[1][1], operand.m[2][1], operand.m[3][1]), Vector4T< Type >(x, y, 1, 1));
    return result;
}

/** @param operand A scalar value.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >& CGUL::Vector2T< Type >::operator*=(Type operand)
{
    this->x *= operand;
    this->y *= operand;
    return *this;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >& CGUL::Vector2T< Type >::operator*=(const MatrixT< Type >& operand)
{
    return *this = *this * operand;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::operator/(Type operand) const
{
    return Vector2T(this->x / operand, this->y / operand);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >& CGUL::Vector2T< Type >::operator/=(Type operand)
{
    this->x /= operand;
    this->y /= operand;
    return *this;
}

template< typename Type >
std::ostream& CGUL::operator<<(std::ostream& stream, const CGUL::Vector2T< Type >& vector)
{
    stream << "[" << vector.x << ", " << vector.y << "]";
    return stream;
}

template< typename Type >
template< typename OtherType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type >::operator CGUL::Vector2T< OtherType >() const
{
    return Vector2T< OtherType >((OtherType)x, (OtherType)y);
}

/** @param index The component index, so 0 for x, and 1 for y.
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type& CGUL::Vector2T< Type >::At(UInt32 index)
{
    return operator[](index);
}

/** @param index The component index, so 0 for x, and 1 for y.
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::At(UInt32 index) const
{
    return operator[](index);
}

/** @param value The value to set all components to.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Set(Type value)
{
    this->x = value;
    this->y = value;
}

/** @param x The x component.
 *  @param y The y component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Set(Type x, Type y)
{
    this->x = x;
    this->y = y;
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Clear()
{
    this->x = this->y = 0;
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y).
 *  @param y The y component (0 for x, 1 for y).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2(operator[](x), operator[](y));
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y).
 *  @param y The y component (0 for x, 1 for y).
 *  @param z The z component (0 for x, 1 for y).
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector2T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3(operator[](x), operator[](y), operator[](z));
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y).
 *  @param y The y component (0 for x, 1 for y).
 *  @param z The z component (0 for x, 1 for y).
 *  @param w The w component (0 for x, 1 for y).
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector2T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4(operator[](x), operator[](y), operator[](z), operator[](w));
}

/** @warning This method uses sqrt() which can be slow!
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Normalize()
{
    if (GetSquaredMagnitude() != 0)
    {
        Type inverseMagnitude = 1.0f / GetMagnitude();
        x *= inverseMagnitude;
        y *= inverseMagnitude;
    }
}

/** @warning This method uses sqrt() which can be slow!
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Boolean CGUL::Vector2T< Type >::IsNormalized(Type epsilon) const
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
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetMagnitude() const
{
    return Math::Sqrt(x * x + y * y);
}

/** @details The squared magnitude is a less accurate, but more quickly calculated alternative to
 *  the @ref GetMagnitude method.  A squared magnitude can be used to measure if one magnitude is
 *  larger than another, but cannot be used to accurately determine differences between magnitudes.
 *  @returns The squared magnitude.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetSquaredMagnitude() const
{
    return (x * x + y * y);
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
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetManhattanMagnitude() const
{
    return Math::Abs(x) + Math::Abs(y);
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
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetDistance(const Vector2T& other) const
{
    return Math::Sqrt(Math::Sqr(other.x - x) + Math::Sqr(other.y - y));
}

/** @param other The other vector.
 *  @returns The squared distance between the two vectors.
 *  @see GetDistance
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetSquaredDistance(const Vector2T& other) const
{
    return Math::Sqr(other.x - x) + Math::Sqr(other.y - y);
}

/** @param other The other vector.
 *  @returns The manhattan distance between the two vectors.
 *  @see GetDistance
 *  @todo Check the implementation because this is actually slower than the squared distance.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetManhattanDistance(const Vector2T& other) const
{
    //return Math::Abs(other.x - x) + Math::Abs(other.y - y);
    //return (other.x > x ? other.x - x : x - other.x) + (other.y > y ? other.y - y : y - other.y);
    return (other.x > x ? 1.0f : -1.0f) + (other.y > y ? 1.0f : -1.0f);
}

/** @details Sets the vector's angle while preserving its magnitude.  The new x is calculated based
 *  off the cosine function and the new y is based off the sine function.  The existing magnitude
 *  is calculated via @ref GetMagnitude and applied back to the vector after the x and y have been
 *  calculated.
 *  @warning This method uses sqrt() which can be slow!
 *  @param angle The new angle (in radians) for the vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::SetAngle(Type angle)
{
    Type magnitude = GetMagnitude();
    x = Math::Cos(angle) * magnitude;
    y = Math::Sin(angle) * magnitude;
}

/** @details Set the angle and length of a 2D vector.
 *  @param angle The new angle (in radians) for the vector.
 *  @param angle The new length for the vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::SetAngle(Type angle, Type length)
{
    x = Math::Cos(angle) * length;
    y = Math::Sin(angle) * length;
}

/** @details Gets an angle from the vector.
 *  @todo Check, does the vector have to be normalized for this to work?
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::GetAngle() const
{
    return Math::ATan2(y, x);
}

/** @returns A vector perpendicular to this one.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::GetPerpendicular() const
{
    return Vector2T(-y, x);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Floor()
{
    this->x = Math::Floor(this->x);
    this->y = Math::Floor(this->y);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Round()
{
    this->x = Math::Round(this->x);
    this->y = Math::Round(this->y);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector2T< Type >::Ceil()
{
    this->x = Math::Ceil(this->x);
    this->y = Math::Ceil(this->y);
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::Floored() const
{
    return Vector2(Math::Floor(this->x), Math::Floor(this->y));
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::Rounded() const
{
    return Vector2(Math::Round(this->x), Math::Round(this->y));
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector2T< Type >::Ceiled() const
{
    return Vector2(Math::Ceil(this->x), Math::Ceil(this->y));
}

/** @returns x + y
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::SumComponents() const
{
    return x + y;
}

/** @returns x * y
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::MultiplyComponents() const
{
    return x * y;
}

/** @returns True if the vector contains NaN values, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector2T< Type >::IsNaN() const
{
    return (x != x) || (y != y);
}
