#include "hblk_crypto.h"

/**
 * ec_save - Function that saves an existing EC key pair on the disk.
 * @key: The EC_KEY to be save on disk
 * @folder: The path where the keys should be saved
 * Return: 1 or 0 upon success or failure respectively
 */
int ec_save(EC_KEY *key, char const *folder)
{
	FILE *fp;
	char path[256];

	if (key == NULL || folder == NULL)
		return (0);

	/* Make a dir if cecessary */
	mkdir(folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	/* PATH to the private key file and Open it */
	sprintf(path, "%s/%s", folder, PRI_FILENAME);
	fp = fopen(path, "w");
	if (!fp)
		return (0);
	/* Write the private key to the file */
	if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	/* PATH to the public key file and Open it */
	sprintf(path, "%s/%s", folder, PUB_FILENAME);
	fp = fopen(path, "w");
	if (!fp)
		return (0);
	/* Write the public key to the file */
	if (!PEM_write_EC_PUBKEY(fp, key))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);

	return (1);
}
