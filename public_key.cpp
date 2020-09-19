/*/------------------------------Public Key Class-----------------------------------/*/

#include "public_key.h"

PublicKey::PublicKey(mpz_class n, mpz_class e) : n(n), e(e) {}

mpz_class PublicKey::get_n() const {return n;}

mpz_class PublicKey::get_e() const {return e;}

string PublicKey::encrypt(string plain_text, int a) const {
    int block_size = get_block_size(n);
    if(a == 1) plain_text = pre_process(plain_text, block_size+a);
    string cipher_text = "";
    for(int i=0;i<plain_text.size();i+=block_size+a) {
        mpz_class M = 0, tmp;
        for(int j=i;j<i+block_size+a;j++) {
            M *= 26;
            if(j < plain_text.size()) M += plain_text[j] - 'a';
            else M += rand() % 26;
        }
        mpz_powm(M.get_mpz_t(), M.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
        for(int j=0;j<block_size+1-a;j++) {
            tmp = M % 26;
            cipher_text += 'a' + mpz_get_ui(tmp.get_mpz_t());
            M /= 26;
        }
    }
    return cipher_text;
}

mpz_class PublicKey::encrypt(mpz_class m) const {
    mpz_class ans;
    mpz_powm(ans.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
    return ans;
}
