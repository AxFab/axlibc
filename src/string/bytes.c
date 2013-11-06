#include <stdint.h>


int bpw2 (unsigned long v) 
{
	int i=1;
	while ((v & 1) == 0)  {
		v = v >> 1;
		i++;
	}
	if (v != 1)
		return 0;
	return i;
}


/**
 * @brief Set a suite of bits on a single byte 
 */
int bsetbyte (uint8_t* byte, int off, int lg)
{
	uint8_t v = byte[0];
	int mask = (0xFF << off) & 0xFF;
	if (lg + off < 8) {
		mask = (mask & ~(0xFF << (off + lg))) & 0xFF;
	}

	byte[0] = v | mask;
	return v & mask;
}

/**
 * @brief Clear a suite of bits on a single byte 
 */
int bclearbyte (uint8_t* byte, int off, int lg)
{
	uint8_t v = byte[0];
	int mask = (0xFF << off) & 0xFF;
	if (lg + off < 8) {
		mask = (mask & ~(0xFF << (off + lg))) & 0xFF;
	}

	byte[0] = v & ~mask;
	return (v ^ mask) & mask;
}

/**
 * @brief Set a suite of bits on a byte map
 */
int bsetbytes (uint8_t* table, int offset, int length)
{
	int ox = offset / 8;
	int oy = offset % 8;
	int r = 0;
	if (oy != 0 || length < 8) {
		if (length + oy < 8) {
			r |= bsetbyte(&table[ox], oy, length);
			length = 0;
		} else {
			r |= bsetbyte(&table[ox], oy, 8 - oy);
			length -= 8 - oy;
		}
		ox++;
	}

	while (length >= 8) {
		r |= table[ox];
		table[ox] = 0xff;
		ox++;
		length -= 8;
	}

	if (length > 0) {
		r |= bsetbyte(&table[ox], 0, length);
	}
	return r;
}

/**
 * @brief Unset a suite of bits on a byte map
 */
int bclearbytes (uint8_t* table, int offset, int length)
{
	int ox = offset / 8;
	int oy = offset % 8;
	int r = 0;
	if (oy != 0 || length < 8) {
		if (length + oy < 8) {
			r |= bclearbyte(&table[ox], oy, length);
			length = 0;
		} else {
			r |= bclearbyte(&table[ox], oy, 8 - oy);
			length -= 8 - oy;
		}
		ox++;
	}

	while (length >= 8) {
		r |= ~table[ox];
		table[ox] = 0;
		ox++;
		length -= 8;
	}

	if (length > 0) {
		r |= bclearbyte(&table[ox], 0, length);
	}
	return r;
}
