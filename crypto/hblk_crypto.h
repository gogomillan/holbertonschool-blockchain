#ifndef gogomillan

#include <openssl/sha.h>
#include <stddef.h>
#include <stdint.h>

uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);

#endif /* gogomillan */
