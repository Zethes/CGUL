/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template< typename KeyType, typename ValueType >
Jatta::HashMap< KeyType, ValueType >::HashMap(Function hash, Size pool)
{
    this->hash = hash;
    data = new Data*[pool];
    this->size = pool;
    for (unsigned int i = 0; i < pool; i++)
    {
        data[i] = NULL;
    }
}


template< typename KeyType, typename ValueType >
Jatta::HashMap< KeyType, ValueType>::~HashMap()
{
    Clear();
    delete[] data;
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType >::Insert(KeyType key, ValueType value)
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

template< typename KeyType, typename ValueType >
ValueType Jatta::HashMap< KeyType, ValueType >::Get(KeyType key) const
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
    return ValueType();
}

template< typename KeyType, typename ValueType >
bool Jatta::HashMap< KeyType, ValueType >::Get(KeyType key, ValueType* value) const
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

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType >::Erase(KeyType key)
{
    Size index = hash(key);
    index %= this->size;
    Data** slot = &this->data[index];
    while (*slot)
    {
        if ((*slot)->key == key)
        {
            Data* last = *slot;
            *slot = (*slot)->next;
            delete last;
            return;
        }
        slot = &((*slot)->next);
    }
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType>::Clear()
{
    for (Size i = 0; i < size; i++)
    {
        Data** slot = &data[i];
        Data** last;
        Size it = 0;
        while (*slot)
        {
            last = slot;
            slot = &((*slot)->next);
            delete *last;
            *last = NULL;
        }
    }
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType>::Clear(Size pool)
{
    Clear();
    delete[] data;
    data = new Data*[pool];
    this->size = pool;
}

template< typename KeyType, typename ValueType>
void Jatta::HashMap< KeyType, ValueType>::Debug() const
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
