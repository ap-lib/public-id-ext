#include "utils.h"

static inline int count_digits(uint64_t n) {
    if (n == 0) {
        return 1;
    }
    int count = 1;
    while (n >= 10) {
        n /= 10;
        count++;
    }
    return count;
}

static inline uint64_t xorshift64_with_secret(uint64_t x, uint64_t secret) {
    x ^= x >> 12;
    x ^= x << 25;
    x ^= x >> 27;
    return x * (secret | 1ULL);
}

static inline uint64_t pow10ul(int exp) {
    static const uint64_t table[19] = {
            1ULL,
            10ULL,
            100ULL,
            1000ULL,
            10000ULL,
            100000ULL,
            1000000ULL,
            10000000ULL,
            100000000ULL,
            1000000000ULL,
            10000000000ULL,
            100000000000ULL,
            1000000000000ULL,
            10000000000000ULL,
            100000000000000ULL,
            1000000000000000ULL,
            10000000000000000ULL,
            100000000000000000ULL,
            1000000000000000000ULL
    };
    return (exp >= 0 && exp < 19) ? table[exp] : 0ULL;
}

static inline uint64_t mask(uint64_t original, uint64_t secret) {
    int msb;
    if (original == 0) {
        msb = 0;
    } else {
        msb = 63 - __builtin_clzll(original);
    }

    uint64_t lowerBitsMask = ((uint64_t) 1 << msb) - 1;
    uint64_t topBits = original & ~lowerBitsMask;
    uint64_t lowBits = (original & lowerBitsMask) ^ (secret & lowerBitsMask);

    return topBits | lowBits;
}

uint64_t encode(uint64_t original, uint64_t secret, int digitsDivider) {
    uint64_t b = pow10ul(digitsDivider - 1);
    uint64_t hash = xorshift64_with_secret(original, secret);
    uint64_t d = hash % (9 * b) + b;

    uint64_t mod = original % d;
    uint64_t div = original / d;
    int digitsDiv = count_digits(div);
    uint64_t pow1 = pow10ul(digitsDivider + digitsDiv);
    uint64_t pow2 = pow10ul(digitsDiv);

    return d * pow1 + mod * pow2 + div;
}

uint64_t decode(uint64_t pub, int digitsDivider) {
    int totalDigits = count_digits(pub);
    int dDigits = digitsDivider;
    int remDigits = totalDigits - dDigits;

    uint64_t pow = pow10ul(remDigits);
    uint64_t d = pub / pow;
    uint64_t rest = pub % pow;

    uint64_t modPow = pow10ul(remDigits - digitsDivider);
    uint64_t mod = rest / modPow;
    uint64_t div = rest % modPow;

    return d * div + mod;
}

uint64_t encode_safe(uint64_t original, uint64_t secret, int digitsDivider) {
    return mask(encode(original, secret, digitsDivider), secret);
}

uint64_t decode_safe(uint64_t pub, uint64_t secret, int digitsDivider) {
    return decode(mask(pub, secret), digitsDivider);
}