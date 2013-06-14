/*
 * Ork: a small object-oriented OpenGL Rendering Kernel.
 * Copyright (c) 2008-2010 INRIA
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#ifndef _ATOMIC_H_
#define _ATOMIC_H_

#if defined(_MSC_VER) // MSVC
#include <intrin.h>
#endif

namespace ork
{

//#define SINGLE_THREAD

/**
 * This file defines some atomic operations.
 * Those are supported across MSVC and GCC.
 *
 * Implements needed atomic operations.
 * - atomic_exchange_and_add(*pw, dv)
 *        adds dv to *pw and returns the old value of pw
 *
 * - atomic_increment(*pw)
 *        adds 1 to *pw and returns void
 *
 * - atomic_decrement(*pw)
 *        adds 1 to *pw and returns its *previous* value
 */

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE __attribute__((always_inline))
#endif

#ifdef SINGLE_THREAD

static FORCE_INLINE int atomic_exchange_and_add(int volatile * pw, int dv)
{
    int r = *pw;
    *pw += dv;
    return r;
}

static FORCE_INLINE void atomic_increment(int volatile * pw)
{
    (*pw)++;
}

static FORCE_INLINE int atomic_decrement(int volatile * pw)
{
    return (*pw)--;
}

#elif defined(_MSC_VER) // MSVC

#define atomic_exchange_and_add(pw,dv) _InterlockedExchangeAdd((volatile long*)(pw),(dv))
#define atomic_increment(pw) (_InterlockedIncrement((volatile long*)(pw)))
#define atomic_decrement(pw) (_InterlockedDecrement((volatile long*)(pw))+1)
#elif defined(__GNUC__) // GCC

#define atomic_exchange_and_add(pw,dv) __sync_fetch_and_add((volatile long*)(pw), dv)
#define atomic_increment(pw) __sync_fetch_and_add((volatile long*)(pw), 1)
#define atomic_decrement(pw) __sync_fetch_and_sub((volatile long*)(pw), 1)

#else

#error Unsupported compiler

#endif

}

#endif
