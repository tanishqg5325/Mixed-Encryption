/*/------------------------------Secret Key Class-----------------------------------/*/

#include "secret_key.h"

SecretKey::SecretKey(mpz_class p, mpz_class q, mpz_class d) : p(p), q(q), d(d) {}

mpz_class SecretKey::power_CRT(mpz_class m) const {
    mpz_class mp = m % p, mq = m % q;
    mpz_powm(mp.get_mpz_t(), mp.get_mpz_t(), d.get_mpz_t(), p.get_mpz_t());
    mpz_powm(mq.get_mpz_t(), mq.get_mpz_t(), d.get_mpz_t(), q.get_mpz_t());
    mpz_class p_1, q_1;
    mpz_invert(p_1.get_mpz_t(), p.get_mpz_t(), q.get_mpz_t());
    mpz_invert(q_1.get_mpz_t(), q.get_mpz_t(), p.get_mpz_t());
    return (mp * q * q_1 + mq * p * p_1) % (p * q);
}

string SecretKey::decrypt(string cipher_text, int a) const {
    mpz_class n = p * q;
    int block_size = get_block_size(n);
    string plain_text = "";
    for(int i=0;i<cipher_text.size();i+=block_size+a) {
        mpz_class M = 0, pow_26 = 1, tmp;
        for(int j=i;j<i+block_size+a;j++) {
            if(j < cipher_text.size()) M += pow_26 * (cipher_text[j] - 'a');
            else M += pow_26 * rand() % 26;
            pow_26 *= 26;
        }
        M = power_CRT(M);
        string rev = "";
        for(int j=0;j<block_size+1-a;j++) {
            tmp = M % 26;
            rev += 'a' + mpz_get_ui(tmp.get_mpz_t());
            M /= 26;
        }
        reverse(rev.begin(), rev.end());
        plain_text += rev;
    }
    return plain_text;
}

mpz_class SecretKey::decrypt(mpz_class m) const {return power_CRT(m);}
