#ifndef gogomillan
#define gogomillan

#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <stddef.h>
#include <stdint.h>

#define ECCTYPE "secp521r1"

uint8_t *sha256(int8_t const *s, size_t len,
				uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);

#endif /* gogomillan */
