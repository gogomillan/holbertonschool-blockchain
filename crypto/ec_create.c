#include "hblk_crypto.h"

/**
 * ex_create - Create a EC_KEY pair (private/public)
 * Return:  A pointer to an EC_KEY structure, containing both the public and
 * private keys, or NULL upon failure
 */
EC_KEY *ec_create(void)
{
	BIO *outbio = NULL;
	EC_KEY *myecc  = NULL;
	EVP_PKEY *pkey   = NULL;
	int eccgrp;

	/* Initializing OpenSSL */
	OpenSSL_add_all_algorithms(), ERR_load_BIO_strings();
	ERR_load_crypto_strings();
	/* Creating I/O BIO's */
	outbio = BIO_new(BIO_s_file());
	outbio = BIO_new_fp(stdout, BIO_NOCLOSE);
	/* EC Structure, group type from NID */
	eccgrp = OBJ_txt2nid(ECCTYPE);
	myecc = EC_KEY_new_by_curve_name(eccgrp);
	/* Flag for cert signing */
	EC_KEY_set_asn1_flag(myecc, OPENSSL_EC_NAMED_CURVE);
	/* EC key pair */
	if (!(EC_KEY_generate_key(myecc)))
		BIO_printf(outbio, "Error generating the ECC key.");
	/* From EC key to a PKEY structure */
	pkey = EVP_PKEY_new();
	if (!EVP_PKEY_assign_EC_KEY(pkey, myecc))
		BIO_printf(outbio, "Error assigning ECC key to EVP_PKEY structure.");
	/* Get EC-specifics from the key */
	myecc = EVP_PKEY_get1_EC_KEY(pkey);

	EVP_PKEY_free(pkey);
	BIO_free_all(outbio);

	return (myecc);
}
