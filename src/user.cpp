/*/-----------------------------------User Class-----------------------------------/*/

#include "user.h"

extern CertificateAuthority *CA;

string number_to_string(int);
int string_to_number(string);

User::User(int id) {
    this->id = id;
    this->sk = CA->register_user(*this);
}

int User::get_ID() const {return id;}

string User::encrypt(string message, string vignere_key, int b_id) const {
    PublicKey pkCA = CA->get_public_key();
    PublicKey pkb = CA->get_public_key_of_user(b_id);
    PublicKey pkb_actual(pkCA.encrypt(pkb.get_n()), pkCA.encrypt(pkb.get_e()));
    message = number_to_string(vignere_key.size()) + 'x' + number_to_string(message.size()) + 'x' + vignere_key + encrypt_vignere(message, vignere_key);
    return pkb_actual.encrypt(sk.decrypt(message, 0), 0);
}

string User::decrypt(string message, int a_id) const {
    PublicKey pkCA = CA->get_public_key();
    PublicKey pka = CA->get_public_key_of_user(a_id);
    PublicKey pka_actual(pkCA.encrypt(pka.get_n()), pkCA.encrypt(pka.get_e()));
    message = pka_actual.encrypt(sk.decrypt(message, 1), 1);
    int pos = -1, new_pos = -1;
    for(int i=0;i<message.size();i++)
        if(message[i] == 'x') {pos = i; break;}
    int vignere_key_length = string_to_number(message.substr(0, pos));
    for(int i=pos+1;i<message.size();i++)
        if(message[i] == 'x') {new_pos = i; break;}
    int message_length = string_to_number(message.substr(pos+1, new_pos-pos-1));
    string vignere_key = message.substr(new_pos+1, vignere_key_length);
    message = message.substr(new_pos+vignere_key_length+1, message_length);
    return decrypt_vignere(message, vignere_key);
}

string number_to_string(int n) {
    string ans = "";
    while(n) {
        ans += 'a' + (n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int string_to_number(string s) {
    int ans = 0;
    for(char c : s)
        ans = ans * 10 + (c - 'a');
    return ans;
}
