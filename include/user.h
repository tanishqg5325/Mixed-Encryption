/*/-----------------------------------User Class-----------------------------------/*/

#ifndef USER_H_
#define USER_H_

#include "public_key.h"
#include "secret_key.h"
#include "vignere.h"
#include "certificate_authority.h"


class User {
    int id;                     ///< identity of user
    SecretKey sk;               ///< secret key of user

public:

     /// Create a User object with given id
    User (int id);

    /// Getter function for id
    int get_ID () const;

    /**
     * Signs and encrypts the message using given vignere key for other user
     * 
     * @param message message to be encrypted by user
     * @param vignere_key vignere key
     * @param b_id identity of other user to whom message has to be sent
     * @return encrypted message signed by current user
     */
    string encrypt (string message, string vignere_key, int b_id) const;

    /**
     * Decrypts the message received from other user
     * 
     * @param message message to be decrypted
     * @param a_id identity of ther user from whom message has been received
     * @return decypted message
     */
    string decrypt (string message, int a_id) const;

};                                          // end of class User

#endif // USER_H_
