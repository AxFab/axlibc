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
#include <crypto/murmur.h>
#include <crypto/crypto.h>

#define C1 0xcc9e2d51
#define C2 0x1b873593
#define R1 15
#define R2 13

// --------------------------------------------------------------------------
 /** Initialize a Murmur context */
void axMurmur2_init (axMurmurContext_t* ctx)
{
  ctx->_digestLg = sizeof (uint32_t);
  ctx->_digest[0] = 0x98BADCFE;
  ctx->_length = 0;
  ctx->_remains = 0;
  ctx->_bytes = 0;
}


// --------------------------------------------------------------------------
/** Feed data to a Murmur context */
void axMurmur2_data (axMurmurContext_t* ctx, uint8_t* ptr, size_t length)
{
  uint32_t k;
  uint32_t* chunk = (uint32_t*)ptr;

  if (ctx->_bytes != 0 ) {
    while (ctx->_bytes < 4 && length > 0) {
      ctx->_remains |= (*ptr << (ctx->_bytes * 8));
      ptr++;
      length--;
    }

    if (ctx->_bytes == 4) {

      k = ctx->_remains;
      ctx->_bytes = 0;
      ctx->_remains = 0;

      k *= C1;
      k = ROTL32(k, R1);
      k *= C2;

      *ctx->_digest ^= k;
      *ctx->_digest = ROTL32(*ctx->_digest, R2);
      *ctx->_digest *= 5;
      *ctx->_digest += 0xe6546b64;
      ctx->_length += 4;
    }
  }

  while (length >= 4) {

    k = *chunk;

    k *= C1;
    k = ROTL32(k, R1);
    k *= C2;

    *ctx->_digest ^= k;
    *ctx->_digest = ROTL32(*ctx->_digest, R2);
    *ctx->_digest *= 5;
    *ctx->_digest += 0xe6546b64;

    ctx->_length += 4;
    length -= 4;
    chunk ++;
  }

  while (length > 0) {
    ctx->_remains |= (*ptr << (ctx->_bytes++ * 8));
    ptr++;
    length--;
  }
}


// --------------------------------------------------------------------------
/** Compute the digest of a Murmur context */
void axMurmur2_finalize (axMurmurContext_t* ctx)
{
  uint32_t k;
  if (ctx->_bytes != 0 ) {
  
    k = ctx->_remains;
    k *= C1;
    k = ROTL32(k, R1);
    k *= C2;

    *ctx->_digest ^= k;
    ctx->_length += ctx->_bytes;
  }

  *ctx->_digest ^= ctx->_length;
  *ctx->_digest ^= *ctx->_digest >> 16;
  *ctx->_digest *= 0x85ebca6b;
  *ctx->_digest ^= *ctx->_digest >> 13;
  *ctx->_digest *= 0xc2b2ae35;
  *ctx->_digest ^= *ctx->_digest >> 16;
}


