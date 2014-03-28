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
#ifndef CRYPTO_SHA1_H__
#define CRYPTO_SHA1_H__

/* --------------------
 * SHA-1 hashing 
 * Thread-safe implementation 
 * 120 bits crypto-hash 
 * -------------------- */
#include <stdint.h>
#include <stddef.h>


typedef struct 
{
    uint32_t    _digestLg;
    uint32_t    _digest[5];
    uint64_t    _length;
    uint8_t     _block[64];
    int         _idx;
}
axSha1Context_t;

/** Initialize a SHA-1 context */
void axSha1_init (axSha1Context_t* ctx);

/** Feed data to a SHA-1 context */
void axSha1_data (axSha1Context_t* ctx, uint8_t* ptr, size_t length); 

/** Compute the digest of a SHA-1 context */
void axSha1_finalize (axSha1Context_t* ctx); 


#endif /* CRYPTO_SHA1_H__ */

