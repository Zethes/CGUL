template<typename T> Jatta::List<T>::List()
{
    data = std::list<T>();
}

template<typename T> Jatta::List<T>::List(Jatta::Size count)
{
    data = std::list<T>(count);
}

template<typename T> Jatta::List<T>::List(Jatta::Size count, const T& value)
{
    data = std::list<T>(count, value);
}
template<typename T> Jatta::List<T>::List(const List& other)
{
    data = std::list<T>(other);
}
template<typename T> Jatta::List<T>::List(List&& other)
{
    data = std::list<T>(other);
}
template<typename T> Jatta::List<T>::~List()
{
}

template<typename T> Jatta::List<T>& Jatta::List<T>::operator=(const List& other)
{
    data = other;
    return this;
}
template<typename T> Jatta::List<T>& Jatta::List<T>::operator=(List&& other)
{
    data = other;
    return this;
}
template<typename T> bool Jatta::List<T>::operator==(const List& other)
{
    return data == other;
}
template<typename T> bool Jatta::List<T>::operator==(List&& other)
{
    return data == other;
}

template<typename T> bool Jatta::List<T>::operator!=(const List& other)
{
    return data != other;
}
template<typename T> bool Jatta::List<T>::operator!=(List&& other)
{
    return data != other;
}

template<typename T> bool Jatta::List<T>::operator<=(const List& other)
{
    return data <= other;
}
template<typename T> bool Jatta::List<T>::operator<=(List&& other)
{
    return data <= other;
}

template<typename T> bool Jatta::List<T>::operator>=(const List& other)
{
    return data >= other;
}
template<typename T> bool Jatta::List<T>::operator>=(List&& other)
{
    return data >= other;
}

template<typename T> bool Jatta::List<T>::operator<(const List& other)
{
    return data < other;
}
template<typename T> bool Jatta::List<T>::operator<(List&& other)
{
    return data < other;
}

template<typename T> bool Jatta::List<T>::operator>(const List& other)
{
    return data > other;
}
template<typename T> bool Jatta::List<T>::operator>(List&& other)
{
    return data > other;
}

template<typename T> bool Jatta::List<T>::Empty() const
{
    return data.empty();
}
template<typename T> bool Jatta::List<T>::Exists(const T& value)
{
    //TODO: Exists
}
template<typename T> const T& Jatta::List<T>::Back() const
{
    return data.back();
}
template<typename T> T& Jatta::List<T>::Back()
{
    return data.back();
}
template<typename T> const T& Jatta::List<T>::Front() const
{
    return data.front();
}
template<typename T> T& Jatta::List<T>::Front()
{
    return data.front();
}
template<typename T> typename Jatta::List<T>::Iterator Jatta::List<T>::Find(const T& value, Jatta::List<T>::Iterator offset)
{
    for (Iterator i = offset; i != End(); i++)
    {
        if ((*i) == value)
            return i;
    }
}
template<typename T> typename Jatta::List<T>::Iterator Jatta::List<T>::FindFirst(const T& value)
{
    for (Iterator i = Begin(); i != End(); i++)
    {
        if ((*i) == value)
            return i;
    }
}
template<typename T> typename Jatta::List<T>::Iterator Jatta::List<T>::FindLast(const T& value)
{
    Iterator ret;
    for (Iterator i = Begin(); i != End(); i++)
    {
        if ((*i) == value)
            ret = i;
    }
    return ret;

    /*for (ReverseIterator i = ReverseBegin(); i != ReverseEnd(); i++)
    {
        if ((*i) == value)
            return i.base();
    }*/
}
template<typename T> Jatta::Size Jatta::List<T>::MaxSize() const
{
    return data.max_size();
}
template<typename T> Jatta::Size Jatta::List<T>::Size() const
{
    return data.size();
}
template<typename T> Jatta::List<typename Jatta::List<T>::Iterator> Jatta::List<T>::FindAll(const T& value)
{
    List<Jatta::Size> ret;
    for (Iterator i = Begin(); i != End(); i++)
    {
        if ((*i) == value)
            ret.Add(i);
    }
    return ret;
}
template<typename T> void Jatta::List<T>::Add(const T& value)
{
    data.push_back(value);
}
template<typename T> void Jatta::List<T>::Add(T&& value)
{
    data.push_back(value);
}
template<typename T> void Jatta::List<T>::AddToFront(const T& value)
{
    data.push_front(value);
}
template<typename T> void Jatta::List<T>::AddToFront(T&& value)
{
    data.push_front(value);
}
template<typename T> void Jatta::List<T>::Assign(Jatta::Size count, const T& value)
{
    data.assign(count, value);
}
template<typename T> void Jatta::List<T>::Assign(Jatta::List<T>::Iterator first, Jatta::List<T>::Iterator last, const T& value)
{
    //TODO: Assign range
}
template<typename T> typename Jatta::List<T>::Iterator Jatta::List<T>::Begin()
{
    return data.begin();
}
template<typename T> typename Jatta::List<T>::ConstIterator Jatta::List<T>::Begin() const
{
    return data.begin();
}
template<typename T> void Jatta::List<T>::Clear()
{
    data.clear();
}
template<typename T> typename Jatta::List<T>::Iterator Jatta::List<T>::End()
{
    return data.end();
}
template<typename T> typename Jatta::List<T>::ConstIterator Jatta::List<T>::End() const
{
    return data.end();
}
template<typename T> void Jatta::List<T>::Insert(Jatta::Size pos, const List<T>& values, Jatta::Size first, Jatta::Size last)
{
    //Todo: Insert
}
template<typename T> void Jatta::List<T>::Insert(Jatta::Size pos, const List<T>&& values, Jatta::Size first, Jatta::Size last)
{
    //Todo: Insert
}
template<typename T> void Jatta::List<T>::Insert(Jatta::Size pos, const T& value)
{
    data.insert(pos, value);
}
template<typename T> void Jatta::List<T>::Insert(Jatta::Size pos, const T&& value)
{
    data.insert(pos, value);
}
template<typename T> void Jatta::List<T>::Pop()
{
    data.pop_back();
}
template<typename T> void Jatta::List<T>::PopFront()
{
    data.pop_front();
}
template<typename T> void Jatta::List<T>::Remove(Jatta::List<T>::Iterator pos)
{
    data.erase(pos);
}
template<typename T> void Jatta::List<T>::Remove(Jatta::List<T>::ConstIterator pos)
{
    data.erase(pos);
}
template<typename T> void Jatta::List<T>::Remove(Jatta::List<T>::Iterator first, Jatta::List<T>::Iterator last)
{
    data.erase(first, last);
}
template<typename T> void Jatta::List<T>::Remove(Jatta::List<T>::ConstIterator first, Jatta::List<T>::ConstIterator last)
{
    data.erase(first, last);
}
template<typename T> void Jatta::List<T>::RemoveConsecutiveDuplicates()
{
    data.unique();
}
template<typename T> void Jatta::List<T>::Replace(Jatta::List<T>::Iterator pos, const T& value)
{
    (*pos) = value;
}
template<typename T> void Jatta::List<T>::Resize(Jatta::Size count)
{
    data.resize(count);
}
template<typename T> void Jatta::List<T>::Resize(Jatta::Size count, const T& value)
{
    data.resize(count, value);
}
template<typename T> void Jatta::List<T>::Reverse()
{
    data.reverse();
}
template<typename T> typename Jatta::List<T>::ReverseIterator Jatta::List<T>::ReverseBegin()
{
    return data.rbegin();
}
template<typename T> typename Jatta::List<T>::ConstReverseIterator Jatta::List<T>::ReverseBegin() const
{
    return data.rbegin();
}
template<typename T> typename Jatta::List<T>::ReverseIterator Jatta::List<T>::ReverseEnd()
{
    return data.rend();
}
template<typename T> typename Jatta::List<T>::ConstReverseIterator Jatta::List<T>::ReverseEnd() const
{
    return data.rend();
}
template<typename T> void Jatta::List<T>::Swap(Iterator p1, Iterator p2)
{
    T temp = (*p1);
    (*p1) = (*p2);
    (*p2) = temp;
}
template<typename T> void Jatta::List<T>::Swap(List<T>& other)
{
    data.swap(other);
}

template<typename T> void Jatta::List<T>::BubbleSort()
{
    for (Iterator i = Begin(); i != End(); i++)
    {
        bool swapped = false;
        for (Iterator j = Begin(); j != End(); j++)
        {
            if ( (*i) < (*j) )
            {
                Swap(i, j);
                swapped = true;
            }
            if (!swapped)
                break;
        }
    }
}