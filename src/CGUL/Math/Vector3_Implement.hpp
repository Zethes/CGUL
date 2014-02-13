// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Vector3_Implement.hpp
 */

// CGUL Includes
#include "../Math/Vector2.hpp"
#include "../Math/Vector4.hpp"

/**
 */
template< typename Type >
const CGUL::Vector3T< Type > CGUL::Vector3T< Type >::zero(0, 0, 0);

/**
 */
template< typename Type >
const CGUL::Vector3T< Type > CGUL::Vector3T< Type >::one(1, 1, 1);

/**
 */
template< typename Type >
const CGUL::Vector3T< Type > CGUL::Vector3T< Type >::unitX(1, 0, 0);

/**
 */
template< typename Type >
const CGUL::Vector3T< Type > CGUL::Vector3T< Type >::unitY(0, 1, 0);

/**
 */
template< typename Type >
const CGUL::Vector3T< Type > CGUL::Vector3T< Type >::unitZ(0, 0, 1);

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::DotProduct(const Vector3T& valueA, const Vector3T& valueB)
{
    return (valueA.x * valueB.x) + (valueA.y * valueB.y) + (valueA.z * valueB.z);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::CrossProduct(const Vector3T& valueA, const Vector3T& valueB)
{
    return Vector3T(valueA.y * valueB.z - valueA.z * valueB.y, valueA.z * valueB.x - valueA.x * valueB.z, valueA.x * valueB.y - valueA.y * valueB.x);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::Distance(const Vector3T& vectorA, const Vector3T& vectorB)
{
    return Math::Sqrt(Math::Sqr(vectorA.x - vectorB.x) + Math::Sqr(vectorA.y - vectorB.y) + Math::Sqr(vectorA.z - vectorB.z));
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::DistanceSquared(const Vector3T& vectorA, const Vector3T& vectorB)
{
    return Math::Sqr(vectorA.x - vectorB.x) + Math::Sqr(vectorA.y - vectorB.y) + Math::Sqr(vectorA.z - vectorB.z);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::DistanceManhattan(const Vector3T& vectorA, const Vector3T& vectorB)
{
    return Math::Abs(vectorA.x - vectorB.x) + Math::Abs(vectorA.y - vectorB.y) + Math::Abs(vectorA.z - vectorB.z);
}

template< typename Type >
_CGUL_INLINE_DEFINE CGUL::Vector3T< Type > CGUL::Vector3T< Type >::Lerp(const Vector3T& from, const Vector3T& to, Type t)
{
    return from + (to - from) * t;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::Normalized(const Vector3T& value)
{
    Type inverseMagnitude = 1.0f / value.GetMagnitude();
    return Vector3T(value.x * inverseMagnitude, value.y * inverseMagnitude, value.z * inverseMagnitude);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::Vector3T()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

/** @param copy The vector to copy.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::Vector3T(const Vector3T& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = copy.z;
}

/** @param copy The vector to copy.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::Vector3T(const Vector2T< Type >& copy)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = 0;
}

/** @param copy The vector to copy.
 *  @param z The z component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::Vector3T(const Vector2T< Type >& copy, Type value)
{
    this->x = copy.x;
    this->y = copy.y;
    this->z = value;
}

/** @param value The value for each component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::Vector3T(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

/** @param x The x component.
 *  @param y The y component.
 *  @param z The z component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::Vector3T(Type x, Type y, Type z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

/** @param operand The other vector.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator=(const Vector3T& operand)
{
    this->x = operand.x;
    this->y = operand.y;
    this->z = operand.z;
    return *this;
}

/** @warning This method does not bounds check, must be 0, 1, or 2!
 *  @param index The component index (0 for x, 1 for y, 2 for z).
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type& CGUL::Vector3T< Type >::operator[](UInt32 index)
{
    return operator[](index);
}

/** @details Unlike the other operator[], this one works on constant vectors and returns a value
 *  that cannot be modified to alter the original vector.
 *  @warning This method does not bounds check, must be 0, 1, or 2!
 *  @param index The component index (0 for x, 1 for y, 2 for z).
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::operator[](UInt32 index) const
{
    return operator[](index);
}

/** @details The inverse is defined as (-x, -y, -z) of the original vector.
 *  @returns The inverse vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::operator-() const
{
    return Vector3(-this->x, -this->y, -this->z);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are equal, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Vector3T< Type >::operator==(const Vector3T& operand) const
{
    return (this->x == operand.x &&
            this->y == operand.y &&
            this->z == operand.z);
}

/** @details Due to floating point imprecision, vectors are rarely ever @em exactly equal.  Use
 *  with care.
 *  @param operand The other vector.
 *  @returns True if they are not equal, false otherwise.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT bool CGUL::Vector3T< Type >::operator!=(const Vector3T& operand) const
{
    return (this->x != operand.x ||
            this->y != operand.y ||
            this->z != operand.z);
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::operator+(const Vector3T& operand) const
{
    return Vector3T(this->x + operand.x,
                    this->y + operand.y,
                    this->z + operand.z);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator+=(const Vector3T& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    this->z += operand.z;
    return *this;
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator+=(const Vector2T< Type >& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    return *this;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::operator-(const Vector3T& operand) const
{
    return Vector3T(this->x - operand.x,
                    this->y - operand.y,
                    this->z - operand.z);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator-=(const Vector3T& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    this->z -= operand.z;
    return *this;
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator-=(const Vector2T< Type >& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    return *this;
}

/** @param operand A scalar value.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::operator*(Type operand) const
{
    return Vector3T(this->x * operand,
                    this->y * operand,
                    this->z * operand);
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::operator*(const MatrixT< Type >& operand) const
{
    Vector3T result;
    result.x = Vector4T< Type >::DotProduct(Vector4T< Type >(operand.m[0][0], operand.m[1][0], operand.m[2][0], operand.m[3][0]), Vector4T< Type >(x, y, z, 1));
    result.y = Vector4T< Type >::DotProduct(Vector4T< Type >(operand.m[0][1], operand.m[1][1], operand.m[2][1], operand.m[3][1]), Vector4T< Type >(x, y, z, 1));
    result.z = Vector4T< Type >::DotProduct(Vector4T< Type >(operand.m[0][2], operand.m[1][2], operand.m[2][2], operand.m[3][2]), Vector4T< Type >(x, y, z, 1));
    return result;
}

/** @param operand A scalar value.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator*=(Type operand)
{
    this->x *= operand;
    this->y *= operand;
    this->z *= operand;
    return *this;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator*=(const MatrixT< Type >& operand)
{
    return *this = *this * operand;
}

/** @param operand The other vector.
 *  @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::operator/(Type operand) const
{
    return Vector3T(this->x / operand,
                    this->y / operand,
                    this->z / operand);
}

/** @param operand The other operand.
 *  @returns A reference to the current object.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >& CGUL::Vector3T< Type >::operator/=(Type operand)
{
    this->x /= operand;
    this->y /= operand;
    this->z /= operand;
    return *this;
}

template< typename Type >
std::ostream& CGUL::operator<<(std::ostream& stream, const CGUL::Vector3T< Type >& vector)
{
    stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
    return stream;
}

template< typename Type >
template< typename OtherType >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type >::operator CGUL::Vector3T< OtherType >()
{
    return Vector3T< OtherType >((OtherType)x, (OtherType)y, (OtherType)z);
}

/** @param index The component index, so 0 for x, 1 for y, and 2 for z.
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type& CGUL::Vector3T< Type >::At(UInt32 index)
{
    return operator[](index);
}

/** @param index The component index, so 0 for x, 1 for y, and 2 for z.
 *  @returns The value at that index.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::At(UInt32 index) const
{
    return operator[](index);
}

/** @param value The value to set all components to.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Set(Type value)
{
    this->x = value;
    this->y = value;
    this->z = value;
}

/** @param x The x component.
 *  @param y The y component.
 *  @param z The z component.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Set(Type x, Type y, Type z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Clear()
{
    this->x = this->y = this->z = 0;
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y, 2 for z).
 *  @param y The y component (0 for x, 1 for y, 2 for z).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector2T< Type > CGUL::Vector3T< Type >::Swizzle(UInt32 x, UInt32 y) const
{
    return Vector2T< Type >(operator[](x), operator[](y));
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y, 2 for z).
 *  @param y The y component (0 for x, 1 for y, 2 for z).
 *  @param z The z component (0 for x, 1 for y, 2 for z).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z) const
{
    return Vector3T< Type >(operator[](x), operator[](y), operator[](z));
}

/** @details Swizzles the vector allowing the components to be re-arranged into a new vector.
 *  @param x The x component (0 for x, 1 for y, 2 for z).
 *  @param y The y component (0 for x, 1 for y, 2 for z).
 *  @param z The z component (0 for x, 1 for y, 2 for z).
 *  @param w The w component (0 for x, 1 for y, 2 for z).
 *  @returns The resulting vector.
 *  @todo Better documentation on swizzle (for now just look it up!)
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector4T< Type > CGUL::Vector3T< Type >::Swizzle(UInt32 x, UInt32 y, UInt32 z, UInt32 w) const
{
    return Vector4T< Type >(operator[](x), operator[](y), operator[](z), operator[](w));
}

/** @warning This method uses sqrt() which can be slow!
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Normalize()
{
    Type inverseMagnitude = 1.0f / GetMagnitude();
    this->x *= inverseMagnitude;
    this->y *= inverseMagnitude;
    this->z *= inverseMagnitude;
}

/** @warning This method uses sqrt() which can be slow!
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Boolean CGUL::Vector3T< Type >::IsNormalized(Type epsilon) const
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
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::GetMagnitude() const
{
    return Math::Sqrt(x * x + y * y + z * z);
}

/** @details The squared magnitude is a less accurate, but more quickly calculated alternative to
 *  the @ref GetMagnitude method.  A squared magnitude can be used to measure if one magnitude is
 *  larger than another, but cannot be used to accurately determine differences between magnitudes.
 *  @returns The squared magnitude.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::GetSquaredMagnitude() const
{
    return (x * x + y * y + z * z);
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
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::GetManhattanMagnitude() const
{
    return Math::Abs(x) + Math::Abs(y) + Math::Abs(z);
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
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::GetDistance(const Vector3T& other) const
{
    return Math::Sqrt(Math::Sqr(other.x - x) +
                      Math::Sqr(other.y - y) +
                      Math::Sqr(other.z - z));
}

/** @param other The other vector.
 *  @returns The squared distance between the two vectors.
 *  @see GetDistance
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::GetSquaredDistance(const Vector3T& other) const
{
    return Math::Sqr(other.x - x) +
           Math::Sqr(other.y - y) +
           Math::Sqr(other.z - z);
}

/** @param other The other vector.
 *  @returns The manhattan distance between the two vectors.
 *  @see GetDistance
 *  @todo Check the implementation because this is actually slower than the squared distance.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::GetManhattanDistance(const Vector3T& other) const
{
    return Math::Abs(other.x - x) +
           Math::Abs(other.y - y) +
           Math::Abs(other.z - z);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Floor()
{
    this->x = Math::Floor(this->x);
    this->y = Math::Floor(this->y);
    this->z = Math::Floor(this->z);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Round()
{
    this->x = Math::Round(this->x);
    this->y = Math::Round(this->y);
    this->z = Math::Round(this->z);
}

/**
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::Ceil()
{
    this->x = Math::Ceil(this->x);
    this->y = Math::Ceil(this->y);
    this->z = Math::Ceil(this->z);
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::Floored() const
{
    return Vector3(Math::Floor(this->x),
                   Math::Floor(this->y),
                   Math::Floor(this->z));
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::Rounded() const
{
    return Vector3(Math::Round(this->x),
                   Math::Round(this->y),
                   Math::Round(this->z));
}

/** @returns The resulting vector.
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT CGUL::Vector3T< Type > CGUL::Vector3T< Type >::Ceiled() const
{
    return Vector3(Math::Ceil(this->x),
                   Math::Ceil(this->y),
                   Math::Ceil(this->z));
}

/** @returns x + y + z
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::SumComponents() const
{
    return x + y + z;
}

/** @returns x * y * z
 */
template< typename Type >
_CGUL_INLINE_IMPLEMENT Type CGUL::Vector3T< Type >::MultiplyComponents() const
{
    return x * y * z;
}

template< typename Type >
_CGUL_INLINE_IMPLEMENT void CGUL::Vector3T< Type >::MakeOrthonormalBasis(Vector3T< Type >* vectorB, Vector3T< Type >* vectorC)
{
    Vector3T< Type > vectorA(*this);
    if (vectorA.GetManhattanMagnitude() == 0)
    {
        return;
    }
    vectorA.Normalize();
    vectorB->Set(1, 0, 0);
    *vectorC = CrossProduct(vectorA, *vectorB);
    if (vectorC->GetManhattanMagnitude() == 0)
    {
        vectorB->Set(0, 1, 0);
        *vectorC = CrossProduct(vectorA, *vectorB);
    }
    *vectorB = CrossProduct(vectorA, *vectorC);
    vectorB->Normalize();
    vectorC->Normalize();
}
