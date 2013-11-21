/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template< typename Type >
Jatta::Size Jatta::Hash::Integer(const Type& object)
{
    return static_cast<Size>(object);
}

template< typename KeyType, typename ValueType >
Jatta::HashMap< KeyType, ValueType >::HashMap() :
    hash(NULL),
    size(0),
    data(NULL)
{
}

template< typename KeyType, typename ValueType >
Jatta::HashMap< KeyType, ValueType>::HashMap(const HashMap& copy) :
    hash(copy.hash),
    size(copy.size),
    data(new Data*[copy.size])
{
    for (Size i = 0; i < size; i++)
    {
        data[i] = NULL;

        Data* slot = copy.data[i];
        Size it = 0;
        while (slot)
        {
            Insert(slot->key, slot->value);
            slot = slot->next;
        }
    }
}

template< typename KeyType, typename ValueType >
Jatta::HashMap< KeyType, ValueType >::HashMap(Function hash, Size pool) :
    hash(hash),
    size(pool),
    data(new Data*[pool])
{
    for (Size i = 0; i < pool; i++)
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
void Jatta::HashMap< KeyType, ValueType >::SetSize(Size pool)
{
    if (size == 0)
    {
        delete[] data;
        data = new Data*[pool];
        size = pool;
        for (Size i = 0; i < pool; i++)
        {
            data[i] = NULL;
        }
    }
    else
    {
        // TODO: remove this, add logic for resize
        throw std::runtime_error("Cannot resize a hash map, can only set its size once.");
    }
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType >::SetHashFunction(Function hash)
{
    if (this->hash == NULL)
    {
        this->hash = hash;
    }
    else
    {
        // TODO: remove this, add logic to reorder contents with new hash function
        throw std::runtime_error("Cannot change the hash function for a hash map after it has already been set.");
    }
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType >::Insert(KeyType key, ValueType value)
{
    if (hash == NULL)
    {
        throw std::runtime_error("Cannot insert into a hash map that has no hashing function.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Cannot insert into a hash map with new data pools.  Use SetSize() first.");
    }

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
    if (hash == NULL)
    {
        throw std::runtime_error("Cannot get from a hash map that has no hashing function.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Cannot get from a hash map with new data pools.  Use SetSize() first.");
    }

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
    if (hash == NULL)
    {
        throw std::runtime_error("Cannot get from a hash map that has no hashing function.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Cannot get from a hash map with new data pools.  Use SetSize() first.");
    }

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
void Jatta::HashMap< KeyType, ValueType >::GetKeys(List< KeyType >* keys) const
{
    for (Size i = 0; i < size; i++)
    {
        Data* slot = data[i];
        Size it = 0;
        while (slot)
        {
            keys->Push(slot->key);
            slot = slot->next;
        }
    }
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType >::GetEntries(List< std::pair< KeyType, ValueType > >* entries) const
{
    for (Size i = 0; i < size; i++)
    {
        Data* slot = data[i];
        Size it = 0;
        while (slot)
        {
            entries->Push(std::make_pair(slot->key, slot->value));
            slot = slot->next;
        }
    }
}

template< typename KeyType, typename ValueType >
void Jatta::HashMap< KeyType, ValueType >::Erase(KeyType key)
{
    if (hash == NULL)
    {
        throw std::runtime_error("Cannot erase from a hash map that has no hashing function.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Cannot erase from a hash map with new data pools.  Use SetSize() first.");
    }

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
