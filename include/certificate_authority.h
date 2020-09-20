/*/-------------------------Certification Authority Class---------------------------/*/

#ifndef CERTIFICATE_AUTHORITY_H_
#define CERTIFICATE_AUTHORITY_H_

#include <map>
#include "prime.h"
#include "public_key.h"
#include "secret_key.h"
#include "user.h"

using std::map;
using std::pair;
class User;


class CertificateAuthority {
    map<int, PublicKey> table;  ///< Stores user id and Public Key pairs
    PublicKey pk;               ///< Public Key of Certificate Authority
    SecretKey sk;               ///< Secret Key of Certificate Authority

public:

    /// Create a CertificateAuthority object
    CertificateAuthority ();

    /// Returns self public key pk
    PublicKey get_public_key () const;

    /**
     * Registers given user of throws an exception if user id is already in use
     * 
     * @param u user to be registered
     */
    SecretKey register_user (User u);

    /**
     * Returns public key of user signed by secret key of Certificate Authority
     * 
     * @param id id of user whose public key is requested
     * @return digitally signed public key of user with given id
     */
    PublicKey get_public_key_of_user (int id);

};                                          // end of class CertificateAuthority

#endif // CERTIFICATE_AUTHORITY_H_
