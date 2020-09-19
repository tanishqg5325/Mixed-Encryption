/*/-------------------------Certification Authority Class---------------------------/*/

#ifndef CERTIFICATE_AUTHORITY_H
#define CERTIFICATE_AUTHORITY_H

#include <map>
#include "prime.h"
#include "public_key.h"
#include "secret_key.h"
#include "user.h"

using std::map;
using std::pair;
class User;

class CertificateAuthority {
    map<int, PublicKey> table;
    PublicKey pk;
    SecretKey sk;
public:
    CertificateAuthority();
    PublicKey get_public_key() const {return pk;};
    SecretKey register_user(User u);
    PublicKey get_public_key_of_user(int);
};

#endif
