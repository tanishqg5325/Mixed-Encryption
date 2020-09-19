/*/------------------------------Secret Key Class-----------------------------------/*/

#ifndef SECRET_KEY_H
#define SECRET_KEY_H

#include <gmpxx.h>
#include <string>

using std::string;

class SecretKey {
    mpz_class p, q, d;
public:
    SecretKey() {}
    SecretKey(mpz_class, mpz_class, mpz_class);
    mpz_class power_CRT(mpz_class) const;
    string decrypt(string, int) const;
    mpz_class decrypt(mpz_class) const;
};

#endif
