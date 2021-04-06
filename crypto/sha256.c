#include "hblk_crypto.h"

/**
 * Function that produce a hash from s to digest
 *
 * @s: The input
 * @len: The lenght
 * @digest: Where the hash will be stored
 *
 * Return: the digest or NULL if fails
 */
uint8_t *sha256(int8_t const *s, size_t len,
				uint8_t digest[SHA256_DIGEST_LENGTH])
{
	SHA256_CTX context;

	if (digest == NULL)
		return (NULL);

	if (!SHA256_Init(&context))
		return (NULL);

	if (!SHA256_Update(&context, (unsigned char *)s, len))
		return (NULL);

	if (!SHA256_Final(digest, &context))
		return (NULL);

	return (digest);
}
