#ifndef CRC32_H
#define CRC32_H

#include <stdint.h>
#include <stddef.h>

#define POLY 0xedb88320

inline uint32_t crc32c(uint32_t crc, const unsigned char *buf, size_t len)
{
    int k;

    crc = ~crc;
    while (len--) {
        crc ^= *buf++;
        for (k = 0; k < 8; k++)
            crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    }
    return ~crc;
}

#endif // !CRC32_H
