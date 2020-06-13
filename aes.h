/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 * Based on the document FIPS PUB 197
 */

#ifndef AES_H
#define AES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t *aes_init(size_t key_size); /* key_size - 16,24,32 */

void aes_key_expansion(uint8_t *key, uint8_t *w);
void aes_cipher(uint8_t *in, uint8_t *out, uint8_t *w);
void aes_inv_cipher(uint8_t *in, uint8_t *out, uint8_t *w);

void aes_encode(uint8_t *in, uint8_t *out, size_t length, uint8_t *w); /* 'in' length must be a multiple of 16 */
void aes_decode(uint8_t *in, uint8_t *out, size_t length, uint8_t *w); /* 'in' length must be a multiple of 16 */

typedef struct MD5_CTX MD5_CTX;

MD5_CTX *md5_init();
void md5_update(MD5_CTX *ctx, const uint8_t data[], size_t len);
void md5_final(MD5_CTX *ctx, uint8_t hash[]);

void md5_hash(const char *phrase, uint8_t key[], size_t key_size); /* key_size - 16,24,32 */
void print_hex(uint8_t str[], int len);

#ifdef __cplusplus
}
#endif

#endif