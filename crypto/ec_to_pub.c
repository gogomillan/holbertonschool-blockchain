#include "hblk_crypto.h"

/**
 * ec_to_pub -function that extracts the public key from an EC_KEY opaque
 * structure
 *
 * @key: The EC_KEY
 * @pub: The public key
 *
 * Return: Return a pointer to pub or NULL upon failure
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	BN_CTX *context = NULL;
	const EC_GROUP *ecgrp = NULL;
	const EC_POINT *ecpoint = NULL;
	size_t len = 0;

	if (key == NULL)
		return (NULL);

	/*  Get Big Number, Elliptic Group, Elliptic Point */
	context = BN_CTX_new();
	ecgrp = EC_KEY_get0_group(key);
	ecpoint = EC_KEY_get0_public_key(key);
	/* Get the public key */
	len = EC_POINT_point2oct(ecgrp, ecpoint,
						(point_conversion_form_t) POINT_CONVERSION_UNCOMPRESSED,
						NULL, EC_PUB_LEN, context);
	if (!EC_POINT_point2oct(ecgrp, ecpoint,
						(point_conversion_form_t) POINT_CONVERSION_UNCOMPRESSED,
						(unsigned char *) pub, len, context))
		return (NULL);

	BN_CTX_free(context);

	return (pub);
}
