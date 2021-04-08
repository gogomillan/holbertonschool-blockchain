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
	unsigned int len;

	if (key == NULL || msg == NULL || sig == NULL)
		return (NULL);

	len = sig->len;
	/* Sign the message */
	if (ECDSA_sign(0, msg, msglen, sig->sig, &len, (EC_KEY *)key) != 1)
		return (NULL);
	sig->len = len;

	return (sig->sig);
}
