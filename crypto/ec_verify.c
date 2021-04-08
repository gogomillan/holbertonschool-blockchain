#include "hblk_crypto.h"

/**
 * ec_verify - function that verifies the signature of a given set of bytes,
 * using a given EC_KEY public key
 *
 * @key: The EC_KEY to verify
 * @msg: The message to be verified
 * @msglen: The message length
 * @sig: The sign structure
 *
 * Return: 1 if valid or 0 otherwise
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen,
				sig_t const *sig)
{
	if (!key || !msg || !sig)
		return (0);

	return (ECDSA_verify(0, msg, msglen, sig->sig, sig->len, (EC_KEY *)key) == 1);
}
