/*
 *  This source file is part of the "Ax c library"
 * 
 *  The zlib/libpng License
 *    Copyright (c) 2012 F.Bavent <me@axfab.net>
 *
 *  This software is provided 'as-is', without any express or implied warranty.
 *  In no event will the authors be held liable for any damages arising from 
 *  the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose, 
 *  including commercial applications, and to alter it and redistribute it 
 *  freely, subject to the following restrictions:
 *
 *    1. The origin of this software must not be misrepresented; you must not 
 *       claim that you wrote the original software. If you use this software 
 *       in a product, an acknowledgment in the product documentation would 
 *       be appreciated but is not required.
 * 
 *    2. Altered source versions must be plainly marked as such, and must not 
 *       be misrepresented as being the original software.
 *
 *    3. This notice may not be removed or altered from any source 
 *       distribution.
 */
#ifndef CRYPTO_H__
#define CRYPTO_H__

#include <stdint.h>
#include <stddef.h>


typedef struct axDigestContext    axDigestContext_t;

/**
 * Header of any axDigestContext
 */
struct axDigestContext
{
    uint32_t    _digestLg;
    uint32_t    _digest[0];
};

/** Write the digest hexadecimal string on a buffer */
int axDigest_print (axDigestContext_t* ctx, char* str, size_t lg);


// MACRO ---------------------------------------------------------------------
#define ROTL32(n,s)   (((n) << (s)) | ((n) >> (32 - (s))))
#define ROTL64(n,s)   (((n) << (s)) | ((n) >> (64 - (s))))


#endif /* CRYPTO_H__ */

