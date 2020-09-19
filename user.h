/*/-----------------------------------User Class-----------------------------------/*/

#ifndef USER_H
#define USER_H

#include "public_key.h"
#include "secret_key.h"
#include "vignere.h"
#include "certificate_authority.h"

class User {
    int id;         // identity of user
    SecretKey sk;   // secret key
public:
    User(int);
    int get_ID() const;
    string encrypt(string, string, int) const;
    string decrypt(string, int) const;
};

#endif
