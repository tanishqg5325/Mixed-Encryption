/*/-------------------Encryption and Decryption using Vignere Cipher------------------/*/


#ifndef VIGNERE_H_
#define VIGNERE_H_

#include <string>
using std::string;


/**
 * Encrypts the message according to vignere cipher
 * 
 * @param plain_text message to be encrypted
 * @param key key to be used for encryption
 * @return encrypted message using vignere cipher
 */
string encrypt_vignere (string plain_text, string key);

/**
 * Decrypts the message according to vignere cipher
 * 
 * @param cipher_text message to be decrypted
 * @param key to be used for decryption
 * @return decrypted message using vignere cipher
 */
string decrypt_vignere (string cipher_text, string key);

#endif // VIGNERE_H_
