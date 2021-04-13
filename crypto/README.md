## >> BlockChain - Crypto

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

<details>
<summary>Example [CLICK ME]:</summary>

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

</details>

**Files:**
\[ [sha256.c](sha256.c) \]
\[ [hblk_crypto.h](hblk_crypto.h) \]

#### 1. EC_KEY creation

Write a function that creates a new EC key pair.
- Prototype: EC_KEY \*ec_create(void);
- Your function must return a pointer to an EC_KEY structure, containing both the public and private keys, or NULL upon failure
- Both the private and the public keys must be generated
- You have to use the secp256k1 elliptic curve to create the new pair (See EC_CURVE macro)

<summary>Example [CLICK ME]:</summary>

```bash
alex@~/holbertonschool-blockchain/crypto$ cat test/ec_create-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "hblk_crypto.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    EC_KEY *key;

    /* Test `ec_create()` */
    key = ec_create();
    if (!key)
    {
        fprintf(stderr, "ec_create() failed\n");
        return (EXIT_FAILURE);
    }
    if (!EC_KEY_check_key(key))
    {
        fprintf(stderr, "Key verification failed\n");
        return (EXIT_FAILURE);
    }

    printf("Successfully created EC key pair\n");

    /* Cleanup */
    EC_KEY_free(key);

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-blockchain/crypto$ gcc -Wall -Wextra -Werror -pedantic -I. -o ec_create-test test/ec_create-main.c ec_create.c -lssl -lcrypto
alex@~/holbertonschool-blockchain/crypto$ valgrind ./ec_create-test
==17436== Memcheck, a memory error detector
==17436== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==17436== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==17436== Command: ./ec_create-test
==17436== 
Successfully created EC key pair
==17436== 
==17436== HEAP SUMMARY:
==17436==     in use at exit: 0 bytes in 0 blocks
==17436==   total heap usage: X allocs, X frees, Y bytes allocated
==17436== 
==17436== All heap blocks were freed -- no leaks are possible
==17436== 
==17436== For counts of detected and suppressed errors, rerun with: -v
==17436== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@~/holbertonschool-blockchain/crypto$
```

</details>

**Files:**
\[ [ec_create.c](ec_create.c) \]

\[ [Back](../../..#readme) \]
