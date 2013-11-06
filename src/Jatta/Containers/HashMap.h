/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "Container.h"
#include "../External/Defines.h"

#include <iostream>
namespace Jatta
{
    template< typename KeyType, typename ValueType >
    class HashMap : public Container< KeyType >
    {
        typedef Size (*Function)(const KeyType& object);
        Function hash;

        Size size;

        struct Data
        {
            KeyType key;
            ValueType value;
            Data* next;
        };

        Data** data;
    public:
        HashMap(Function hash, Size pool);
        ~HashMap();

        void Insert(KeyType key, ValueType value);

        ValueType Get(KeyType key) const;
        bool Get(KeyType key, ValueType* value) const;

        void Erase(KeyType key);

        void Clear();
        void Clear(Size pool);

        void Debug() const;
    };
}

#include "../External/Undefines.h"
#include "HashMap.ipp"
