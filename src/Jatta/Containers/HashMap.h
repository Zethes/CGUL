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
    template< typename T, typename V > class HashMap : public Container< T >
    {
        typedef Size (*Function)(const T& object);
        Function hash;

        Size size;

        struct Data
        {
            T key;
            V value;
            Data* next;
        };

        Data** data;
    public:
        HashMap(Function hash, Size pool)
        {
            this->hash = hash;
            data = new Data*[pool];
            this->size = pool;
            for (unsigned int i = 0; i < pool; i++)
            {
                data[i] = NULL;
            }
        }

        ~HashMap()
        {
            Clear();
            delete[] data;
        }

        void Insert(T key, V value)
        {
            Size index = hash(key);
            index %= this->size;
            Data** slot = &this->data[index];
            while (*slot)
            {
                if ((*slot)->key == key)
                {
                    (*slot)->value = value;
                    return;
                }
                slot = &((*slot)->next);
            }
            Data* newData = new Data;
            newData->key = key;
            newData->value = value;
            newData->next = NULL;
            *slot = newData;
        }

        V Get(T key)
        {
            Size index = hash(key);
            index %= this->size;
            Data** slot = &this->data[index];
            while (*slot)
            {
                if ((*slot)->key == key)
                {
                    return (*slot)->value;
                }
                slot = &((*slot)->next);
            }
            return V();
        }

        bool Get(T key, V* value)
        {
            Size index = hash(key);
            index %= this->size;
            Data** slot = &this->data[index];
            while (*slot)
            {
                if ((*slot)->key == key)
                {
                    if (value)
                    {
                        *value = (*slot)->value;
                    }
                    return true;
                }
                slot = &((*slot)->next);
            }
            return false;
        }

        void Clear()
        {
            for (Size i = 0; i < size; i++)
            {
                Data** slot = &data[i];
                Size it = 0;
                while (*slot)
                {
                    Data** last = slot;
                    slot = &((*slot)->next);
                    delete *last;
                    *last = NULL;
                }
            }
        }

        void Clear(Size pool)
        {
            Clear();
            delete[] data;
            data = new Data*[pool];
            this->size = pool;
        }

        void Debug()
        {
            for (Size i = 0; i < size; i++)
            {
                Data* slot = data[i];
                Size it = 0;
                while (slot)
                {
                    std::cout << "[" << i << " - " << (it++) << "] " << slot->key << " -> " << slot->value << std::endl;
                    slot = slot->next;
                }
            }
        }
    };
}

#include "../External/Undefines.h"
//#include "HashMap.ipp"
