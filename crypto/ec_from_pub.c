#include "hblk_crypto.h"

/**
 * ec_from_pub - creates an EC_KEY structure given a public key
 *
 * @pub: The public key to be converted
 *
 * Return: EC_KEY or NULL if fails
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *eckey;
	const EC_GROUP *ecgrp;
	EC_POINT *ecpoint;

	if (pub == NULL)
		return (NULL);

	/* Get an ECC_KEY */
	eckey = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!eckey)
		return (NULL);
	/* Get an ECC_PINT from ECC_KEY */
	ecgrp = EC_KEY_get0_group(eckey);
	ecpoint = EC_POINT_new(ecgrp);
	if (!ecpoint)
	{
		EC_KEY_free(eckey);
		return (NULL);
	}
	/* Populate EC_KEY structure from the public key*/
	if (!EC_POINT_oct2point(ecgrp, ecpoint, pub, EC_PUB_LEN, NULL)
		|| !EC_KEY_set_public_key(eckey, ecpoint))
	{
		EC_KEY_free(eckey);
		EC_POINT_free(ecpoint);
		return (NULL);
	}
	EC_POINT_free(ecpoint);

	return (eckey);
}
