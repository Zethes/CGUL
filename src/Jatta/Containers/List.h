/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    template <typename T>
    class List
    {
    private:
        std::list<T>data;
    public:
        typedef typename std::list<T>::iterator Iterator;
        typedef typename std::list<T>::const_iterator ConstIterator;
        typedef typename std::list<T>::reverse_iterator ReverseIterator;
        typedef typename std::list<T>::const_reverse_iterator ConstReverseIterator;

        List();
        List(Jatta::Size count);
        List(Jatta::Size count, const T& value);
        List(const List& other);
        List(List&& other);
        ~List();

        List<T>& operator=(const List& other);
        List<T>& operator=(List&& other);
        bool operator==(const List&other);
        bool operator==(List&& other);
        bool operator!=(const List&other);
        bool operator!=(List&& other);
        bool operator<=(const List&other);
        bool operator<=(List&& other);
        bool operator<(const List&other);
        bool operator<(List&& other);
        bool operator>=(const List&other);
        bool operator>=(List&& other);
        bool operator>(const List&other);
        bool operator>(List&& other);
        friend std::ostream& operator<<(std::ostream& stream, const List<T>& list)
        {
            bool first = true;
            for (Jatta::List<T>::ConstIterator i = list.Begin(); i != list.End(); i++)
            {
                if (!first) stream << ",";
                first = false;
                stream << *i;
            }
            return stream;
        }

        bool Empty() const;
        bool Exists(const T& value);
        const T& Back() const;
        const T& Front() const;
        Iterator Find(const T& value);
        Iterator Find(const T& value, Iterator offset);
        Iterator FindFirst(const T& value);
        Iterator FindLast(const T& value);
        Jatta::Size MaxSize() const;
        Jatta::Size Size() const;
        List<Iterator> FindAll(const T& value);
        T& Back();
        T& Front();
        void Add(const T& value);
        void Add(T&& value);
        void AddToFront(const T& value);
        void AddToFront(T&& value);
        void Assign(Jatta::Size count, const T& value);
        void Assign(Iterator first, Iterator last, const T& value);
        Iterator Begin();
        ConstIterator Begin() const;
        void Clear();
        Iterator End();
        ConstIterator End() const;
        void Insert(Jatta::Size pos, const List<T>& values, Jatta::Size first, Jatta::Size last);
        void Insert(Jatta::Size pos, const List<T>&& values, Jatta::Size first, Jatta::Size last);
        void Insert(Jatta::Size pos, const T& value);
        void Insert(Jatta::Size pos, const T&& value);
        void Pop();
        void PopFront();
        void Remove(Iterator pos);
        void Remove(ConstIterator pos);
        void Remove(Iterator first, Iterator last);
        void Remove(ConstIterator first, ConstIterator last);
        void RemoveConsecutiveDuplicates();
        void Replace(Iterator pos, const T& value);
        void Resize(Jatta::Size count);
        void Resize(Jatta::Size count, const T& value);
        void Reverse();
        ReverseIterator ReverseBegin();
        ConstReverseIterator ReverseBegin() const;
        ReverseIterator ReverseEnd();
        ConstReverseIterator ReverseEnd() const;
        void Swap(Iterator p1, Iterator p2);
        void Swap(List<T>& other);

        void BubbleSort();
    };
}

#include "../External/Undefines.h"

#include "List.ipp"
