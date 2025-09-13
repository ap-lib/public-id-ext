#ifndef PUBLIC_ID_UTILS_H
#define PUBLIC_ID_UTILS_H

#include <stdint.h>

uint64_t encode_safe(uint64_t original, uint64_t secret, int digitsDivider);

uint64_t decode_safe(uint64_t pub, uint64_t secret, int digitsDivider);

uint64_t encode(uint64_t original, uint64_t secret, int digitsDivider);

uint64_t decode(uint64_t pub, int digitsDivider);

#endif // PUBLIC_ID_UTILS_H