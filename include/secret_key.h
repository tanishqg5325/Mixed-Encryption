/*/------------------------------Secret Key Class-----------------------------------/*/

#ifndef SECRET_KEY_H_
#define SECRET_KEY_H_

#include <gmpxx.h>
#include <string>
#include "helper.h"

using std::string;


class SecretKey {
    mpz_class p, q, d;          ///< p, q and d used in RSA's decryption algorithm

public:
    /// Create a SecretKey object
    SecretKey () {}

    /// Create a SecretKey object with given p, q and d
    SecretKey (mpz_class p, mpz_class q, mpz_class d);

    /// Computes m^d mon n using CRT
    mpz_class power_CRT (mpz_class m) const;

    /**
     * Returns decrypted cipher text
     * 
     * @param cipher_text message to be decrypted
     * @param a 0 if sender and 1 if receiver
     * @return decrypted message
     */
    string decrypt (string cipher_text, int a) const;

    /// Same as power_CRT
    mpz_class decrypt (mpz_class) const;

};                                          // end of class SecretKey

#endif // SECRET_KEY_H_
