// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Math.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief A namespace containing many common mathematical functions.
     *  @details Some mathematical concepts were ruthlessly stolen from MathGeoLib.  Be sure to
     *  check it out as an awesome standalone math library!
     *  http://clb.demon.fi/MathGeoLib/nightly/reference.html
     */
    namespace Math
    {
        //! @brief The constant Zero, defined as 0
        const Float64 Zero = 0;
        //! @brief The constant One, defined as 1
        const Float64 One = 1;
        //! @brief The constant Unity, defined as 1
        const Float64 Unity = 1;
        //! @brief The constant E, Napier's constant, defined as 2.71828182845904523536028747135266249
        const Float64 E = 2.71828182845904523536028747135266249;
        //! @brief The the log of E in base 2, defined as Log(E, 2)
        const Float64 Log2E = 1.44269504089;
        //! @brief The log of E in base 10, defined as Log(E)
        const Float64 LogE = 0.4342944819;
        //! @brief The natural log of 2, defined as Log(2, E) = Ln(2)
        const Float64 Ln2 = 0.69314718056;
        //! @brief The natural log of 10, defined as Log(10, E) = Ln(10)
        const Float64 Ln10 = 2.30258509299;
        //! @brief The natural log of Pi, defined as Log(10, Pi) = Ln(Pi)
        const Float64 LnPi = 1.14472988585;
        //! @brief The natural log of Tau divided by 2, defined as Ln(Tau) / 2
        const Float64 LnTauOver2 = 0.9189385332;
        //! @brief The natural log of 2 * Pi divided by 2, defined as Ln(2 * Pi) / 2
        const Float64 Ln2PiOver2 = 0.9189385332;
        //! @brief The inverse of E, defined as 1 / e
        const Float64 InvE = 0.36787944117;
        //! @brief The square root of E, defined as Sqrt(E)
        const Float64 SqrtE = 1.6487212707;
        //! @brief Pythagoras' constant, defined as Sqrt(2);
        const Float64 Sqrt2 = 1.41421356237309504880168872420969807;
        //! @brief Theodorus' constant, defined as Sqrt(2)
        const Float64 Sqrt3 = 1.73205080756887729352744634150587236;
        //! @brief The square root of 5, defined as Sqrt(5)
        const Float64 Sqrt5 = 2.23606797749978969640917366873127623;
        //! @brief The square root of 1/2, defined as Sqrt(1/2)
        const Float64 SqrtOneHalf = 0.70710678118;
        //! @brief Half the square root of 3, defined as Sqrt(3)/2
        const Float64 HalfSqrt3 = 0.86602540378;
        //! @brief The constant Pi, Archimedes' constant, defined as 3.14159265358979323846264338327950288
        const Float64 Pi =  3.14159265358979323846264338327950288;
        //! @brief The constant Tau, defined as 2 * Pi
        const Float64 Tau = 6.2831853071795864;
        //! @brief The constant Pi2, defined as 2 * Pi
        const Float64 Pi2 = 6.2831853071795864;
        //! @brief One divided by Pi, defined as 1 / Pi
        const Float64 OneOverPi = 0.31830988618;
        //! @brief Half of Pi, defined as Pi / 2
        const Float64 HalfPi = 1.57079632679;
        //! @brief Quarter of Pi, defined as Pi / 4
        const Float64 QuarterPi = 0.78539816339;
        //! @brief The square root of Pi, defined as Sqrt(Pi)
        const Float64 SqrtPi = 1.77245385091;
        //! @brief The square root of Tau, defined as Sqrt(Tau)
        const Float64 SqrtTau = 2.50662827463;
        //! @brief The square root of 2 * Pi, defined as Sqrt(Pi * 2)
        const Float64 Sqrt2Pi = 2.50662827463;
        //! @brief The square root of Tau * E, defined as Sqrt(Tau * E)
        const Float64 SqrtTauE = 4.13273135412;
        //! @brief The square root of 2 * Pi * E, defined as Sqrt(Pi * 2 * E)
        const Float64 Sqrt2PiE = 4.13273135412;
        //! @brief The log of the square root of Tau in base 10, defined as Log(Sqrt(Tau))
        const Float64 LogSqrtTau = 0.39908993417;
        //! @brief The log of the square root of 2 * Pi in base 10, defined as Log(Sqrt(Pi * 2))
        const Float64 LogSqrt2Pi = 0.39908993417;
        //! @brief The log of the square root of Tau * E in base 10, defined as Log(Sqrt(Tau * E))
        const Float64 LogSqrtTauE = 0.61623717513;
        //! @brief The log of the square root of 2 * Pi * E in base 10, defined as Log(Sqrt(Pi * 2 * E))
        const Float64 LogSqrt2PiE = 0.61623717513;
        //! @brief The log of 2 times the square root of E divied by Pi in base 10, defined as Log(2 * Sqrt(E / Pi))
        const Float64 Log2SqrtEOverPi = 0.26960230026;
        //! @brief Inverse of Pi, defined as 1 / Pi
        const Float64 InvPi = 0.31830988618;
        //! @brief The inverse of Pi times 2, defined as 2 / Pi
        const Float64 TwoInvPi = 0.63661977236;
        //! @brief The inverse of the square root of Pi, defined as 1 / Sqrt(Pi)
        const Float64 InvSqrtPi = 0.56418958354;
        //! @brief The inverse of the square root of Tau, defined as 1 / Sqrt(Tau)
        const Float64 InvSqrtTau = 0.3989422804;
        //! @brief The inverse of the square root of 2 * Pi, defined as 1 / Sqrt(Pi * 2)
        const Float64 InvSqrt2Pi = 0.3989422804;
        //! @brief The the inverse of the square root of Pi times 2, defined as 2 / Sqrt(Pi)
        const Float64 TwoInvSqrtPi = 1.1283791671;
        //! @brief The square root of E divided by Pi times 2, defined as 2 / Sqrt(E/Pi)
        const Float64 TwoSqrtEOverPi = 1.86038273421;
        //! @brief The factor to convert from Degree (deg) to Radians (rad), defined as Pi / 180
        const Float64 Degree = 0.01745329251;
        //! @brief The factor to convert from NewGrad (grad) to Radians (rad), defined as Pi / 200
        const Float64 Grad = 0.01570796326;
        //! @brief The Euler-Masceroni constant, defined as 0.57721 56649 01532 86060 65120 90082 40243 
        const Float64 EulerMascheroni = 0.57721566490153286060651209008240243;
        //! @brief The Golden Ratio, defined as 1.61803 39887 49894 84820 45868 34365 63811
        const Float64 GoldenRatio = 1.61803398834989484820458683436563811;
        //! @brief The Plastic constant, defined as 1.32471 79572 44746 02596 09088 54478 09734
        const Float64 Plastic = 1.32471795724474602596090885447809734;
        //! @brief The Embree-Trefethen constant, defined as 0.70258
        const Float64 EmbreeTrefethen = 0.70258;
        //! @brief The Feigenbaum constant, defined as 2.50290 78750 95892 82228 39028 73218 21578
        const Float64 Feigenbaum = 2.50290787509589282228390287321821578;
        //! @brief The Feigenbaum constant, defined as 2.50290 78750 95892 82228 39028 73218 21578
        const Float64 Feigenbaum2 = 4.66920160910299067185320382046620161;
        //! @brief The Twin prime constant, defined as 0.66016 18158 46869 57392 78121 10014 55577
        const Float64 TwinPrime = 0.66016181584686957392781211001455577;
        //! @brief The Miessel-Mertens constant, defined as  0.26149 72128 47642 78375 54268 38608 69585
        const Float64 MeisselMertens = 0.26149721284764278375542683860869585;
        //! @brief Brun's constant for twin primes, defined as 1.90216 05823
        const Float64 BrunsTwinPrimes = 1.9021605823;
        //! @brief Brun's constant for prime quadruplets, defined as 0.87058 83800
        const Float64 BrunsPrimeQuadruplets = 0.8705883800;
        //! @brief Catalan's constant, defined as 0.91596 55941 77219 01505 46035 14932 38411
        const Float64 Catalans = 0.91596559417721901505460351493238411;
        //! @brief The Landau-Ramanujan constant, defined as 0.76422 36535 89220 66299 06987 31250 09232
        const Float64 LandauRamanujan =  0.76422365358922066299069833125009232;
        //! @brief Viswanath's constant, defined as 1.13198 824
        const Float64 Viswanaths = 1.13198824;
        //! @brief Legendre's constant, defined as 1
        const Float64 Legendre = 1;
        //! @brief The Ramanujan-Soldner constant, defined as 1.45136 92348 83381 05028 39684 85892 02744
        const Float64 RamanujanSoldner = 1.45136923488338105028396848589202744;
        //! @brief The Erdos-Borwein constant, defined as 1.60669 51524 15291 76378 33015 23190 92458
        const Float64 ErdosBorwein = 1.60669515241529176378330152319092458;
        //! @brief Bernstein's constant, defined as 0.28016 94990 23869 13303
        const Float64 Bernsteins = 0.28016949902386913303;
        //! @brief The Gauss-Kuzmin-Wirsing constant, defined as 0.30366 30028 98732 65859 74481 21901 55623
        const Float64 GaussKuzminWirsing = 0.30366300289873265859744812190155623;
        //! @brief The Hafner-Sarnak-McMurley constant, defined as 0.35323 63718 54995 98454
        const Float64 HafnerSarnakMcCurley = 0.35323637185499598454;
        //! @brief The Golomb-Dickman constant, defined as 0.62432 99885 43550 87099 29363 83100 83724
        const Float64 GolombDickman = 0.62432998854355087099293638310083724;
        //! @brief Cahen's constant, defined as 0.64341 05463
        const Float64 Cahens = 0.6434105463;
        //! @brief The Laplace limit, defined as 0.66274 34193 49181 58097 47420 97109 25290
        const Float64 LaplaceLimit =  0.66274341934918158093474209710925290;
        //! @brief The Alladi-Grinstead constant, defined as 0.80939 40205
        const Float64 AlladiGrinstead = 0.8093940205;
        //! @brief Lengyel's constant, defined as 1.09868 58055
        const Float64 Lengyels = 1.0986858055;
        //! @brief Levy's constant, defined as 3.27582 29187 21811 15978 76818 82453 84386
        const Float64 Levys = 3.27582291832181115978768188245384386;
        //! @brief Apery's constant, defined as 1.20205 69031 59594 28539 97381 61511 44999
        const Float64 Aperys = 1.20205690315959428539973816151144999;
        //! @brief Mills' constant, defined as 1.30637 78838 63080 69046 86144 92602 60571
        const Float64 Mills = 1.30633788386308069046861449260260571;
        //! @brief Backhouse's constant, defined as 1.45607 49485 82689 67139 95953 51116 54356
        const Float64 Backhouses = 1.45603494858268967139959535111654356;
        //! @brief Porter's constant, defined as 1.46707 80794
        const Float64 Porters = 1.4670380794;
        //! @brief Lieb's square ice constant, defined as 1.53960 07178
        const Float64 LiebsSquareIce = 1.5396007178;
        //! @brief Niven's constant, defined as 1.70521 11401 05367 76428 85514 53434 50816
        const Float64 Nivens = 1.70521114010536376428855145343450816;
        //! @brief Sierpinski's constant, defined as 2.58498 17595 79253 21706 58935 87383 17116
        const Float64 Sierpinskis = 2.58498175957925321706589358738317116;
        //! @brief Khinchin's constant, defined as 2.68545 20010 65306 44530 97148 35481 79569
        const Float64 Khinchins = 2.68545200106530644530971483548179569;
        //! @brief The Fransen-Robinson constant, defined as 2.80777 02420 28519 36522 15011 86557 77293
        const Float64 FransenRobinson = 2.80773024202851936522150118655377293;
        //! @brief Landau's constant, defined as 0.5
        const Float64 Landaus = 0.5;
        //! @brief The Universal parabolic constant, defined as 2.29558 71493 92638 07403 42980 49189 49039
        const Float64 UniversalParabolic = 2.29558714939263807403429804918949039;
        //! @brief The Omega constant, defined as 0.56714 32904 09783 87299 99686 62210 35555
        const Float64 Omega = 0.56714329040978387299996866221035555;
        //! @brief The MRB constant, defined as 0.187859
        const Float64 MRB = 0.187859;
        //! @brief The Reciprocal Fibonacci constant, defined as 3.35988 56662 43177 55317 20113 02918 ....
        const Float64 ReciprocalFibonacci = 3.359885666243173553132011302918;
        //! @brief The factor to convert from Power Decibel (dB) to Neper(Np), defined as ln(10) / 20
        const Float64 PowerDecibel = 0.11512925465;
        //! @brief The factor to convert from Neutral Decibel (dB) to Neper(Np), defined as ln(10) / 10
        const Float64 NeutralDecibel = 0.23025850929;
        //! @brief The size of a 32-bit double, defined as 4
        const UInt32 SizeOfDouble32 = 4;
        //! @brief The size of a 64-bit double, defined as 8
        const UInt32 SizeOfDouble64 = 8;
        //! @brief The size of a 32-bit integer, defined as 4
        const UInt32 SizeOfInt32 = 4;
        //! @brief The size of a 64-bit integer, defined as 8
        const UInt32 SizeOfInt64 = 8;
        //! @brief The size of a 32-bit float, defined as 4
        const UInt32 SizeOfFloat32 = 4;
        //! @brief The size of a 64-bit float, defined as 8
        const UInt32 SizeOfFloat64 = 8;
        //! @brief The speed of light in a vacuum, defined as 2.99792458e8 [m/s]
        const Float64 SpeedOfLight = 299792458;
        //! @brief The magnetic permeability in a vacuum, defined as (4 * Pi)e-7 [N/A^2]
        const Float64 MagneticPermeability = 0.00000125663706;
        //! @brief The electric permittivity in a vacuum, defined as 1 / (MagneticPermeability * SpeedOfLight^2) [F/m]
        const Float64 ElectricPermittivity = 0.0000000000088541878;
        //! @brief The characteristic impedance of vacuum, defined as MagneticPermeability * SpeedOfLight [Ohm]
        const Float64 CharacteristicImpedanceVacuum = 376.730313031;
        //! @brief The Newtonian Constant of Gravitation, defined as 6.67429e-11 [m^3/(kg*s^2)]
        const Float64 GravitationalConstant = 0.0000000000667429;
        //! @brief The SI prefix factor corresponding to 1000000000000000000
        const Float64 Exa =   1000000000000000000.0;
        //! @brief The SI prefix factor corresponding to 1000000000000000
        const Float64 Peta =  1000000000000000.0;
        //! @brief The SI prefix factor corresponding to 1000000000000
        const Float64 Tera =  1000000000000.0;
        //! @brief The SI prefix factor corresponding to 1000000000
        const Float64 Giga =  1000000000.0;
        //! @brief The SI prefix factor corresponding to 1000000
        const Float64 Mega =  1000000.0;
        //! @brief The SI prefix factor corresponding to 1000
        const Float64 Kilo =  1000.0;
        //! @brief The SI prefix factor corresponding to 100
        const Float64 Hecto = 100.0;
        //! @brief The SI prefix factor corresponding to 10
        const Float64 Deca =  10.0;
        //! @brief The SI prefix factor corresponding to 0.1
        const Float64 Deci =  0.1;
        //! @brief The SI prefix factor corresponding to 0.01
        const Float64 Centi = 0.01;
        //! @brief The SI prefix factor corresponding to 0.001
        const Float64 Milli = 0.001;
        //! @brief The SI prefix factor corresponding to 0.000001
        const Float64 Micro = 0.000001;
        //! @brief The SI prefix factor corresponding to 0.000000001
        const Float64 Nano =  0.000000001;
        //! @brief The SI prefix factor corresponding to 0.000000000001
        const Float64 Pico =  0.000000000001;
        //! @brief The SI prefix factor corresponding to 0.000000000000001
        const Float64 Femto = 0.000000000000001;
        //! @brief The SI prefix factor corresponding to 0.000000000000000001
        const Float64 Atto =  0.000000000000000001;
    }
}

// Undefines
#include "../External/Undefines.hpp"
