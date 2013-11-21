/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "List.h"
#include "../External/Defines.h"

#include <iostream>
namespace Jatta
{
    namespace Hash
    {
        template< typename Type >
        Size Integer(const Type& object);
    }

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
        HashMap();
        HashMap(const HashMap& copy);
        HashMap(Function hash, Size pool);
        ~HashMap();

        void SetSize(Size pool);
        void SetHashFunction(Function hash);

        void Insert(KeyType key, ValueType value);

        ValueType Get(KeyType key) const;
        bool Get(KeyType key, ValueType* value) const;

        void GetKeys(List< KeyType >* keys) const;
        void GetEntries(List< std::pair< KeyType, ValueType > >* entries) const;

        void Erase(KeyType key);

        void Clear();
        void Clear(Size pool);

        void Debug() const;
    };
}

#include "../External/Undefines.h"
#include "HashMap_Implement.h"
