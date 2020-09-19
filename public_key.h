/*/------------------------------Public Key Class-----------------------------------/*/

#ifndef PUBLIC_KEY_H
#define PUBLIC_KEY_H

#include <gmpxx.h>
#include <string>

using std::string;

class public_key {
    mpz_class n, e;
public:
    public_key() {}
    public_key(mpz_class n, mpz_class e) : n(n), e(e) {}
    mpz_class get_n() const {return n;}
    mpz_class get_e() const {return e;}
    string encrypt(string, int) const;
    mpz_class encrypt(mpz_class) const;
};

#endif
