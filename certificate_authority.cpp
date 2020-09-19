/*/-------------------------Certification Authority Class---------------------------/*/

#include "certificate_authority.h"

extern gmp_randstate_t state;
pair<PublicKey, SecretKey> generate_key(int);

CertificateAuthority::CertificateAuthority() {
    pair<PublicKey, SecretKey> key = generate_key(200);
    this->pk = key.first;
    this->sk = key.second;
}

SecretKey CertificateAuthority::register_user(User u) {
    if(table.find(u.get_ID()) != table.end()) {
        throw "This ID is already with another user !";
        exit(0);
    }
    else {
        pair<PublicKey, SecretKey> key = generate_key(128);
        table[u.get_ID()] = PublicKey(sk.decrypt(key.first.get_n()), sk.decrypt(key.first.get_e()));
        return key.second;
    }
}

PublicKey CertificateAuthority::get_public_key_of_user(int id) {
    if(table.find(id) == table.end()) {
        throw "No such user !";
        exit(0);
    }
    else return table[id];
}

pair<PublicKey, SecretKey> generate_key(int bit_length) {
    mpz_class p = generate_strong_prime(bit_length), q = generate_strong_prime(bit_length);
    mpz_class threshold;
    mpz_ui_pow_ui(threshold.get_mpz_t(), 2, 4 * bit_length);
    while(abs(p - q) < threshold) q = generate_strong_prime(bit_length);
    mpz_class n = p * q, phi_n = (p - 1) * (q - 1), d, e;
    // n has size nearly 8 * bit_length
    mpz_urandomb(e.get_mpz_t(), state, bit_length);
    while(gcd(e, phi_n) != 1) mpz_urandomb(e.get_mpz_t(), state, bit_length);
    mpz_invert(d.get_mpz_t(), e.get_mpz_t(), phi_n.get_mpz_t());
    return {PublicKey(n, e), SecretKey(p, q, d)};
}
