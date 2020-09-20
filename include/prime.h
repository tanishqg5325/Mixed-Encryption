/*/------------------Functions to generate Primes and Strong Primes-------------------/*/

#ifndef PRIME_H_
#define PRIME_H_

#include <gmpxx.h>


/**
 * Returns a prime number of specified bit length
 * 
 * @param bit_length desired bit length of prime
 * @return prime number of size bit_length
 */
mpz_class generate_prime (int bit_length);

/**
 * Returns a strong prime number using Gordon's algorithm of size 4 * bit_length 
 * 
 * @param bit_length
 * @return a strong prime of size 4 * bit_length
 */
mpz_class generate_strong_prime (int bit_length);

#endif // PRIME_H_
