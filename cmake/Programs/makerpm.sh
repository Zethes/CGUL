#!/bin/bash

if [[ "$1" == "" || "$2" == "" ]]; then
    echo "usage: makerpm.sh <BUILD_DIRECTORY> <VERSION>"
    exit
fi

echo "Building CGUL-$2.rpm..."

# TODO: Requires and BuildRequires
echo "Summary:            C++ General Utility Library" > CGUL.spec
echo "Name:               CGUL" >> CGUL.spec
echo "Version:            $2" >> CGUL.spec
echo "Release:            1%{dist}" >> CGUL.spec
echo "License:            BSD" >> CGUL.spec
echo "URL:                http://www.zethes.com/cgul" >> CGUL.spec
#echo "Requires:           " >> CGUL.spec
#echo "BuildRequires:      " >> CGUL.spec
echo "" >> CGUL.spec
echo "%description" >> CGUL.spec
echo "The C++ General Utility Library (CGUL) is a multi-purpose \"hybrid\" library aiming to aid in a variety of " >> CGUL.spec
echo "problems, with a consistent feel throughout the codebase. The CGUL developers are avid gamers so " >> CGUL.spec
echo "much of the library is focused around game development. CGUL is partially a thin wrapper between " >> CGUL.spec
echo "popular C libraries, but also uses and abuses the C++ syntax to extend the language. CGUL\'s goal " >> CGUL.spec
echo "is to be compliant with C++ standards instead of C standards. CGUL takes an object-oriented " >> CGUL.spec
echo "approach to common problems. Error checking occurs through exceptions and classes are RAII " >> CGUL.spec
echo "compliant. No error goes unchecked." >> CGUL.spec
echo "" >> CGUL.spec
echo "%build" >> CGUL.spec
echo "cd $1" >> CGUL.spec
echo "make" >> CGUL.spec
echo "" >> CGUL.spec
echo "%files" >> CGUL.spec
echo "/usr/local/share/CGUL-$2/*" >> CGUL.spec
echo "%install" >> CGUL.spec
echo "cd $1" >> CGUL.spec
echo "make DESTDIR=%{buildroot} install" >> CGUL.spec
#echo "%doc README.md license.txt license.md" >> CGUL.spec
echo "" >> CGUL.spec
echo "%changelog" >> CGUL.spec  # This change log is for this script only!  Do not include CGUL's changelog
echo "* Sat Apr 19 2014 Zethes Studios <cgul@zethes.com> - 0.1.8" >> CGUL.spec
echo "- Created script to generate RPM packages for CGUL" >> CGUL.spec

rpmbuild -ba CGUL.spec