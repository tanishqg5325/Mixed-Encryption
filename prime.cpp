/*/------------------Functions to generate Primes and Strong Primes-------------------/*/

#include "prime.h"

extern gmp_randstate_t state;

mpz_class generate_prime (int bit_length) {
    mpz_class p;
    mpz_urandomb(p.get_mpz_t(), state, bit_length);
    while(mpz_probab_prime_p(p.get_mpz_t(), 50) == 0)
        mpz_urandomb(p.get_mpz_t(), state, bit_length);
    return p;
}

mpz_class generate_strong_prime (int bit_length) {
    mpz_class r, s, t, i, j, p0, p, e;
    s = generate_prime(bit_length); t = generate_prime(bit_length);
    mpz_urandomb(i.get_mpz_t(), state, bit_length);
    r = 2 * i * t + 1;
    while(mpz_probab_prime_p(r.get_mpz_t(), 50) == 0) r += 2 * t;
    e = r - 2;
    mpz_powm(p0.get_mpz_t(), s.get_mpz_t(), e.get_mpz_t(), r.get_mpz_t());
    p0 = 2 * p0 * s - 1;
    mpz_urandomb(j.get_mpz_t(), state, bit_length);
    p = p0 + 2 * j * r * s;
    while(mpz_probab_prime_p(p.get_mpz_t(), 50) == 0) p += 2 * r * s;
    // p nearly of size 4 * bit_length
    return p;
}
