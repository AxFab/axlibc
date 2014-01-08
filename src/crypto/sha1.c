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
#include <crypto/sha1.h>
#include <crypto/crypto.h>



// TODO Why is doesn't work without AND !?
#define Sha1Shift(b,w)  ( (((w) << (b)) & 0xFFFFFFFF) |  ((w) >> (32-(b))) )


// --------------------------------------------------------------------------
/** Process a chunk of sha-1 (512 bits) */
static void axSha1_process (axSha1Context_t* ctx)
{
  const uint32_t K[] = {0x5A827999, 0x6ED9EBA1, 0x8F1BBCDC, 0xCA62C1D6 };
  uint32_t tmp = 0;
  uint32_t seq[80];
  uint32_t buf[5];
  int i;

  for (i = 0; i < 16; i++) {
    seq[i] =  ((uint32_t) ctx->_block[i*4] << 24);
    seq[i] |= ((uint32_t) ctx->_block[i*4+1] << 16);
    seq[i] |= ((uint32_t) ctx->_block[i*4+2] << 8);
    seq[i] |= ((uint32_t) ctx->_block[i*4+3]);
  }

  for ( ; i < 80; i++) {
     seq[i] = Sha1Shift(1, seq[i-3] ^ seq[i-8] ^ seq[i-14] ^ seq[i-16]);
  }

  for (i=0 ; i < 5; i++) {
    buf[i] = ctx->_digest[i];
  }


  #define A  buf[0]
  #define B  buf[1]
  #define C  buf[2]
  #define D  buf[3]
  #define E  buf[4]

  for (i = 0; i < 20; i++) {
    tmp =  Sha1Shift(5, A) + ((B & C) | ((~B) & D)) + E + seq[i] + K[0];
    tmp &= 0xFFFFFFFF;
    E = D;
    D = C;
    C = Sha1Shift(30, B);
    B = A;
    A = tmp;
  }

  for ( ; i < 40; i++)
  {
    tmp = Sha1Shift(5, A) + (B ^ C ^ D) + E + seq[i] + K[1];
    E = D;
    D = C;
    C = Sha1Shift(30, B);
    B = A;
    A = tmp;
  }

  for ( ; i < 60; i++)
  {
    tmp = Sha1Shift(5, A) + ((B & C) | (B & D) | (C & D)) + E + seq[i] + K[2];
    E = D;
    D = C;
    C = Sha1Shift(30, B);
    B = A;
    A = tmp;
  }

  for ( ; i < 80; i++)
  {
    tmp = Sha1Shift(5, A) + (B ^ C ^ D) + E + seq[i] + K[3];
    E = D;
    D = C;
    C = Sha1Shift(30, B);
    B = A;
    A = tmp;
  }

  #undef A
  #undef B
  #undef C
  #undef D
  #undef E

  for (i=0 ; i < 5; i++) {
    ctx->_digest[i] = ctx->_digest[i] + buf[i];
  }

  ctx->_idx = 0; 
}


// --------------------------------------------------------------------------
/** Initialize a SHA-1 context */
void axSha1_init (axSha1Context_t* ctx)
{
  ctx->_digestLg = 5 * sizeof (uint32_t);
  ctx->_digest[0] = 0x67452301;
  ctx->_digest[1] = 0xEFCDAB89;
  ctx->_digest[2] = 0x98BADCFE;
  ctx->_digest[3] = 0x10325476;
  ctx->_digest[4] = 0xC3D2E1F0;

  ctx->_length = 0;
  ctx->_idx = 0;
}


// --------------------------------------------------------------------------
/** Feed data to a SHA-1 context */
void axSha1_data (axSha1Context_t* ctx, uint8_t* ptr, size_t length)
{
  while (length-- > 0) {
    ctx->_block [ctx->_idx++] = *ptr;
    ctx->_length += 8;
    if (ctx->_idx >= 64) {
      axSha1_process(ctx);
    }

    ptr++;
  }
}


// --------------------------------------------------------------------------
/** Compute the digest of a SHA-1 context */
void axSha1_finalize (axSha1Context_t* ctx)
{
  ctx->_block[ctx->_idx++] = 0x80;

  if (ctx->_idx > 55) {
    while (ctx->_idx < 64) {
      ctx->_block[ctx->_idx++] = 0;
    }

    axSha1_process (ctx);

  }

  while (ctx->_idx < 56) {
    ctx->_block[ctx->_idx++] = 0;
  }

  while (ctx->_idx < 64) {
    ctx->_block[ctx->_idx++] = (ctx->_length >> 56) & 0xff;
    ctx->_length = ctx->_length << 8;
  }

  axSha1_process (ctx);
}

