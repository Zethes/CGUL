/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

template< class T > Jatta::AutoRelease< T >::AutoRelease()
{
    this->release = NULL;
}

template< class T > Jatta::AutoRelease< T >::~AutoRelease()
{
    if (release != NULL)
    {
        (((T*)this)->*release)();
    }
}

/** @details When the AutoRelease object goes out of scope it will destroy the object it wraps by
 *  calling the release function provided by this method.  If an object is no longer desired to be
 *  autorelease, it is possible to pass NULL to this method to remove the autorelease functionality
 *  from the class.
 */
template< class T > void Jatta::AutoRelease< T >::SetRelease(Release release)
{
    this->release = release;
}
