## Blockchain - Crypto

\[ [Back](../../..#readme) \]
\[ [Objectives](#Objectives) \]
\[ [Info](#Info) \]
\[ [Tasks](#Tasks) \]

![OS Linux](https://img.shields.io/badge/OS-Linux-blue.svg)
![distro Ubuntu](https://img.shields.io/badge/distro-Ubuntu-orange.svg)
![tecnology C](https://img.shields.io/badge/technology-C-green.svg)
![OpenSSL](https://img.shields.io/badge/toolkit-OpenSSL-brown.svg)
![Crypto](https://img.shields.io/badge/discipline-Crypto-yellow.svg)

### Objectives
- How a Blockchain is considered unbreakable
- What is a hash algorithm
- What SHA stands for
- How hash algorithms apply to Blockchains
- What is asymmetric cryptography
- How asymmetric cryptography applies to cryptocurrencies
- What ECC stands for
- What ECDSA stands for
- What a digital signature is
- How digital signatures apply to cryptocurrencies

### Info
Poject's structure (It is possible to have additional files):
```
holbertonschool-blockchain
+-- crypto
|   +-- ec_create.c
|   +-- ec_from_pub.c
|   +-- ec_load.c
|   +-- ec_save.c
|   +-- ec_sign.c
|   +-- ec_to_pub.c
|   +-- ec_verify.c
|   +-- hblk_crypto.h
|   +-- libhblk_crypto.a
|   +-- Makefile
|   +-- provided
|   |   +-- _print_hex_buffer.c
|   +-- sha256.c
|   +-- test
|       +-- ec_create-main.c
|       +-- ec_from_pub-main.c
|       +-- ec_load-main.c
|       +-- ec_save-main.c
|       +-- ec_sign-main.c
|       +-- ec_to_pub-main.c
|       +-- ec_verify-main.c
|       +-- sha256-main.c
+-- README.md
```

### Tasks:
#### 0. SHA256:

Write a function that computes the hash of a sequence of bytes
- Prototype: uint8_t \*sha256(int8_t const \*s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH]);, where
  - s is the sequence of bytes to be hashed
  - len is the number of bytes to hash in s
- The resulting hash must be stored in digest
- Your function must return a pointer to digest
- If digest happens to be NULL, your function must do nothing and return NULL
- You are not allowed to allocate memory dynamically

**Example:**
```bash
alex@~/holbertonschool-blockchain/crypto$ cat test/sha256-main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hblk_crypto.h"

void _print_hex_buffer(uint8_t const *buf, size_t len);

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    uint8_t hash[SHA256_DIGEST_LENGTH];
    uint8_t *test_ptr;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    /* Test `sha256()` */
    test_ptr = sha256((int8_t *)av[1], strlen(av[1]), hash);
    if (!test_ptr)
    {
        fprintf(stderr, "sha256() failed\n");
        return (EXIT_FAILURE);
    }
    if (test_ptr != hash)
    {
        fprintf(stderr, "Return value and pointer differ\n");
        return (EXIT_FAILURE);
    }

    printf("\"%s\" hash is: ", av[1]);
    _print_hex_buffer(hash, SHA256_DIGEST_LENGTH);
    printf("\n");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-blockchain/crypto$ gcc -Wall -Wextra -Werror -pedantic -I. -o sha256-test test/sha256-main.c provided/_print_hex_buffer.c sha256.c -lssl -lcrypto
alex@~/holbertonschool-blockchain/crypto$ ./sha256-test Holberton
77c4925c01e8d9f79c8a6a61685c6b3182be10f2fa553de915f3733ee19c0204
alex@~/holbertonschool-blockchain/crypto$ ./sha256-test "Holberton School"
2a05534c3fd942dc5e5ab0a968433b747b2188d526feffdb5a6406f15bf4861c
alex@~/holbertonschool-blockchain/crypto$
```

**Files:**
\[ [sha256.c](sha256.c) \]
\[ [hblk_crypto.h](hblk_crypto.h) \]

\[ [Back](../../..#readme) \]
