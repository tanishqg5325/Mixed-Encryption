/*/------------------------------Public Key Class-----------------------------------/*/

#ifndef PUBLIC_KEY_H
#define PUBLIC_KEY_H

#include <gmpxx.h>
#include <string>
#include "helper.h"

using std::string;

class PublicKey {
    mpz_class n, e;
public:
    PublicKey() {}
    PublicKey(mpz_class, mpz_class);
    mpz_class get_n() const;
    mpz_class get_e() const;
    string encrypt(string, int) const;
    mpz_class encrypt(mpz_class) const;
};

#endif
