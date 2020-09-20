/*/-------------------Encryption and Decryption using Vignere Cipher------------------/*/

#include "vignere.h"

string encrypt_vignere(string plain_text, string key) {
    string cipher_text = ""; int m_size = plain_text.size(), k_size = key.size();
    char c;
    for(int i=0;i<m_size;i++) {
        c = (plain_text[i] - 'a' + key[i % k_size] - 'a') % 26 + 'a';
        cipher_text += c;
    }
    return cipher_text;
}

string decrypt_vignere(string cipher_text, string key) {
    string plain_text = ""; int c_size = cipher_text.size(), k_size = key.size();
    char c;
    for(int i=0;i<c_size;i++) {
        c = (cipher_text[i] - key[i % k_size] + 26) % 26 + 'a';
        plain_text += c;
    }
    return plain_text;
}
