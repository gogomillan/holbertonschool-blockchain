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
	EC_KEY *ecckey;
	EC_POINT *point;

	if (pub == NULL)
		return (NULL);

	/* Initialize OpenSSL */
	OpenSSL_add_all_algorithms();
	ERR_load_BIO_strings();
	ERR_load_crypto_strings();
	/* Get an ECC_KEY */
	ecckey = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!ecckey)
		return (NULL);
	/* Get an ECC_PINT from ECC_KEY */
	point = EC_POINT_new(EC_KEY_get0_group(ecckey));
	if (!point)
	{
		EC_KEY_free(ecckey);
		return (NULL);
	}
	/* Populate EC_KEY structure from the public key*/
	if (!EC_POINT_oct2point(EC_KEY_get0_group(ecckey), point, pub, EC_PUB_LEN, NULL)
		|| !EC_KEY_set_public_key(ecckey, point))
	{
		EC_KEY_free(ecckey);
		EC_POINT_free(point);
		return (NULL);
	}
	EC_POINT_free(point);

	return (ecckey);
}
