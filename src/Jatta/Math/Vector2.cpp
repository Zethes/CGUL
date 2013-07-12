/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Math.h"

/**
 */
_JATTA_EXPORT const Jatta::Vector2 zero(0, 0);

/**
 */
_JATTA_EXPORT const Jatta::Vector2 one(1, 1);

/**
 */
_JATTA_EXPORT const Jatta::Vector2 unitX(1, 0);

/**
 */
_JATTA_EXPORT const Jatta::Vector2 unitY(0, 1);

/** @details Defined as (cos(angle) * magnitude, sin(angle) * magnitude).  If no magnitude is given
 *  it will default to one.
 *  @param angle The angle in radians.
 *  @param magnitude An optional magnitude.
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::FromAngle(Float32 angle, Float32 magnitude)
{
    return Jatta::Vector2(Math::Cos(angle) * magnitude, Math::Sin(angle) * magnitude);
}

/**
 */
_JATTA_EXPORT Jatta::Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
}

/** @param copy The vector to copy.
 */
_JATTA_EXPORT Jatta::Vector2::Vector2(const Vector2& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}

/** @param value The value for both x and y.
 */
_JATTA_EXPORT Jatta::Vector2::Vector2(float value)
{
    this->x = value;
    this->y = value;
}

/** @param x The x component.
 *  @param y The y component.
 */
_JATTA_EXPORT Jatta::Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

/** @param operand The other vector.
 *  @returns A reference to the current object.
 */
_JATTA_EXPORT Jatta::Vector2& Jatta::Vector2::operator=(const Vector2& operand)
{
    this->x = operand.x;
    this->y = operand.y;
    return *this;
}

/** @warning This method does not bounds check, must be 0 or 1!
 *  @param index The component index (0 for x, 1 for y).
 *  @returns The value at that index.
 */
_JATTA_EXPORT Jatta::Float32& Jatta::Vector2::operator[](UInt32 index)
{
    return m[index];
}

/** @details Unlike the other operator[], this one works on constant vectors and returns a value
 *  that cannot be modified to alter the original vector.
 *  @warning This method does not bounds check, must be 0 or 1!
 *  @param index The component index (0 for x, 1 for y).
 *  @returns The value at that index.
 */
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::operator[](UInt32 index) const
{
    return m[index];
}

/** @details The inverse is defined as (-x, -y) of the original vector.
 *  @returns The inverse vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::operator-() const
{
    return Vector2(-this->x, -this->y);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are equal, false otherwise.
 */
_JATTA_EXPORT bool Jatta::Vector2::operator==(const Vector2& operand) const
{
    return (this->x == operand.x && this->y == operand.y);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are not equal, false otherwise.
 */
_JATTA_EXPORT bool Jatta::Vector2::operator!=(const Vector2& operand) const
{
    return (this->x != operand.x || this->y != operand.y);
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::operator+(const Vector2& operand) const
{
    return Vector2(this->x + operand.x, this->y + operand.y);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
_JATTA_EXPORT Jatta::Vector2& Jatta::Vector2::operator+=(const Vector2& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    return *this;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::operator-(const Vector2& operand) const
{
    return Vector2(this->x - operand.x, this->y - operand.y);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
_JATTA_EXPORT Jatta::Vector2& Jatta::Vector2::operator-=(const Vector2& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    return *this;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::operator*(float operand) const
{
    return Vector2(this->x * operand, this->y * operand);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
_JATTA_EXPORT Jatta::Vector2& Jatta::Vector2::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    return *this;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::operator/(Float32 operand) const
{
    return Vector2(this->x / operand, this->y / operand);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
_JATTA_EXPORT Jatta::Vector2& Jatta::Vector2::operator/=(Float32 operand)
{
    this->x /= operand;
    this->y /= operand;
    return *this;
}

/** @details Outputs the vector as "[x, y]" so for example: [3.54, 1.23]
 *  @param stream The output stream.
 *  @param vector The vector to output.
 */
_JATTA_EXPORT std::ostream& operator<<(std::ostream& stream, const Jatta::Vector2& vector)
{
    stream << "[" << vector.x << ", " << vector.y << "]";
    return stream;
}

/** @param index The component index, so 0 for x and 1 for y.
 *  @returns The value at that index.
 */
_JATTA_EXPORT Jatta::Float32& Jatta::Vector2::At(UInt32 index)
{
    return m[index];
}

/** @param index The component index, so 0 for x and 1 for y.
 *  @returns The value at that index.
 */
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::At(UInt32 index) const
{
    return m[index];
}

/** @param value The value to set both x and y to.
 */
_JATTA_EXPORT void Jatta::Vector2::Set(Float32 value)
{
    this->x = value;
    this->y = value;
}

/** @param x The x component.
 *  @param y The y component.
 */
_JATTA_EXPORT void Jatta::Vector2::Set(Float32 x, Float32 y)
{
    this->x = x;
    this->y = y;
}

/**
 */
_JATTA_EXPORT void Jatta::Vector2::Clear()
{
    this->x = 0;
    this->y = 0;
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y).
 *  @param y The y component (0 for x, 1 for y).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2(m[x], m[y]);
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y).
 *  @param y The y component (0 for x, 1 for y).
 *  @param z The z component (0 for x, 1 for y).
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector3 Jatta::Vector2::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3(m[x], m[y], m[z]);
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y).
 *  @param y The y component (0 for x, 1 for y).
 *  @param z The z component (0 for x, 1 for y).
 *  @param w The w component (0 for x, 1 for y).
 *  @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector4 Jatta::Vector2::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4(m[x], m[y], m[z], m[w]);
}

/** @warning This method uses sqrt() which can be slow!
 */
_JATTA_EXPORT void Jatta::Vector2::Normalize()
{
    Float32 inverseMagnitude = 1.0f / GetMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
}

/** @warning This method uses sqrt() which can be slow!
 */
_JATTA_EXPORT Jatta::Boolean Jatta::Vector2::IsNormalized(Float32 epsilon) const
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
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetMagnitude() const
{
    return Math::Sqrt(x * x + y * y);
}

/** @details The squared magnitude is a less accurate, but more quickly calculated alternative to
 *  the @ref GetMagnitude method.  A squared magnitude can be used to measure if one magnitude is
 *  larger than another, but cannot be used to accurately determine differences between magnitudes.
 *  @returns The squared magnitude.
 */
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetSquaredMagnitude() const
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
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetManhattanMagnitude() const
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
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetDistance(const Vector2& other) const
{
    return Math::Sqrt(Math::Sqr(other.x - x) + Math::Sqr(other.y - y));
}

/** @param other The other vector.
 *  @returns The squared distance between the two vectors.
 *  @see GetDistance
 */
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetSquaredDistance(const Vector2& other) const
{
    return Math::Sqr(other.x - x) + Math::Sqr(other.y - y);
}

/** @param other The other vector.
 *  @returns The manhattan distance between the two vectors.
 *  @see GetDistance
 *  @todo Check the implementation because this is actually slower than the squared distance.
 */
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetManhattanDistance(const Vector2& other) const
{
    //return Math::Abs(other.x - x) + Math::Abs(other.y - y);
    //return (other.x > x ? other.x - x : x - other.x) + (other.y > y ? other.y - y : y - other.y);
    return (other.x > x ? 1 : -1) + (other.y > y ? 1 : -1);
}

/** @details Sets the vector's angle while preserving its magnitude.  The new x is calculated based
 *  off the cosine function and the new y is based off the sine function.  The existing magnitude
 *  is calculated via @ref GetMagnitude and applied back to the vector after the x and y have been
 *  calculated.
 *  @warning This method uses sqrt() which can be slow!
 *  @param angle The new angle (in radians) for the vector.
 */
_JATTA_EXPORT void Jatta::Vector2::SetAngle(Float32 angle)
{
    Float32 magnitude = GetMagnitude();
    x = Math::Cos(angle) * magnitude;
    y = Math::Sin(angle) * magnitude;
}

/** @details Gets an angle from the vector.
 *  @todo Check, does the vector have to be normalized for this to work?
 */
_JATTA_EXPORT Jatta::Float32 Jatta::Vector2::GetAngle() const
{
    return Math::ATan2(y, x);
}

/**
 */
_JATTA_EXPORT void Jatta::Vector2::Floor()
{
    this->x = Math::Floor(this->x);
    this->y = Math::Floor(this->y);
}

/**
 */
_JATTA_EXPORT void Jatta::Vector2::Round()
{
    this->x = Math::Round(this->x);
    this->y = Math::Round(this->y);
}

/**
 */
_JATTA_EXPORT void Jatta::Vector2::Ceil()
{
    this->x = Math::Ceil(this->x);
    this->y = Math::Ceil(this->y);
}

/** @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::Floored()
{
    return Vector2(Math::Floor(this->x), Math::Floor(this->y));
}

/** @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::Rounded()
{
    return Vector2(Math::Round(this->x), Math::Round(this->y));
}

/** @returns The resulting vector.
 */
_JATTA_EXPORT Jatta::Vector2 Jatta::Vector2::Ceiled()
{
    return Vector2(Math::Ceil(this->x), Math::Ceil(this->y));
}
