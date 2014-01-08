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
#include <crypto/crypto.h>

/** Write the digest hexadecimal string on a buffer 
 * @return Return the length of the string on success, or -1 if the buffer is 
 *      too small
 * @param ctx Any digest context
 * @param str String buffer
 * @param lg Max length for the buffer.
 */
int axDigest_print (axDigestContext_t* ctx, char* str, size_t lg) 
{
  uint8_t* ptr = (uint8_t*)ctx->_digest;
  unsigned i, j = 0;

  if (lg == 0) return -1;
  for (i = 0; i < ctx->_digestLg; i++) {
    if (lg < 3) {
      str[j] = '\0';
      return -1;
    }
    str[j] = ((ptr[i] >> 4) & 0xf);
    str[j] += (str[j] < 10) ? '0' : 'a'-10;
    j++;
    str[j] = ((ptr[i] >> 0) & 0xf);
    str[j] += (str[j] < 10) ? '0' : 'a'-10;
    j++;
    lg-=2;
  }

  str[j] = '\0';
  return ctx->_digestLg;
}

