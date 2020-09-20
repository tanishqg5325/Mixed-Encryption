/*/------------------------------Public Key Class-----------------------------------/*/

#ifndef PUBLIC_KEY_H_
#define PUBLIC_KEY_H_

#include <gmpxx.h>
#include <string>
#include "helper.h"

using std::string;


class PublicKey {
    mpz_class n, e;     ///< n and e used in RSA's encryption algorithm

public:

    /// Create a PublicKey object
    PublicKey () {}

    /// Create a PublicKey object with given n and e
    PublicKey (mpz_class n, mpz_class e);

    /// Getter Function for n
    mpz_class get_n () const;

    /// Getter Function for e
    mpz_class get_e () const;

    /**
     * Returns encrypted plain text
     * 
     * @param plain_text message to be encrypted
     * @param a 0 if sender and 1 if receiver
     * @return encypted message
     */
    string encrypt (string plain_text, int a) const;

    /// Returns m^e mod n
    mpz_class encrypt (mpz_class m) const;

};                                          // end of class PublicKey

#endif // PUBLIC_KEY_H_
