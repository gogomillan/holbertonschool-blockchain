#include "hblk_crypto.h"

/**
 * ex_create - Create a EC_KEY pair (private/public)
 * Return:  A pointer to an EC_KEY structure, containing both the public and
 * private keys, or NULL upon failure
 */
EC_KEY *ec_create(void)
{
	EC_KEY *ecckey  = NULL;

	/* Put key generation by curve */
	ecckey = EC_KEY_new_by_curve_name(EC_CURVE);
	/* Generate the EC key pair*/
	if (!(EC_KEY_generate_key(ecckey)))
		return (NULL);

	return (ecckey);
}
