#include "hblk_crypto.h"

/**
 * ec-sign - function that signs a given set of bytes, using a given EC_KEY
 * private key
 *
 * @key: The private EC_KEY
 * @msg: The data collection to be signed
 * @msglen: Message length
 * @sig: holds the address at which to store the signatur
 *
 * Return: A pointer to the signature buffer upon success or NULL if fails
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
				size_t msglen, sig_t *sig)
{
	uint32_t len = 0;

	if (!key || !msg || !msglen)
		return (NULL);

	bzero(sig->sig, sizeof(sig->sig));
	if (!ECDSA_sign(0, msg, msglen, sig->sig, &len, (EC_KEY *)key))
	{
		sig->len = 0;
		return (NULL);
	}

	sig->len = (uint8_t)len;
	return ((uint8_t *)sig->sig);
}
