#include "hblk_crypto.h"

/**
 * ec_load - function that loads an EC key pair from the disk.
 * @folder: path to the folder from which to load the keys
 * Return: a pointer to the created EC key pair upon success, or NULL upon
 * failure
 */
EC_KEY *ec_load(char const *folder)
{
	FILE *fp;
	char path[256];
	EC_KEY *key = NULL;

	if (!folder)
		return (NULL);
	/* PATH to the file with public key info */
	sprintf(path, "%s/%s", folder, PUB_FILENAME);
	fp = fopen(path, "r");
	if (!fp)
		return (NULL);
	/* Get the ECC info  */
	if (!PEM_read_EC_PUBKEY(fp, &key, NULL, NULL))
	{
		fclose(fp);
		return (NULL);
	}
	fclose(fp);
	/* PATH to the file with private key info */
	sprintf(path, "%s/%s", folder, PRI_FILENAME);
	fp = fopen(path, "r");
	if (!fp)
	{
		EC_KEY_free(key);
		return (NULL);
	}
	/* Get the ECC info  */
	if (!PEM_read_ECPrivateKey(fp, &key, NULL, NULL))
	{
		EC_KEY_free(key);
		fclose(fp);
		return (NULL);
	}
	fclose(fp);

	return (key);
}
