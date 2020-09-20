#include <iostream>
#include <string>
#include <gmpxx.h>
#include "certificate_authority.h"
#include "user.h"

using namespace std;

gmp_randstate_t state;

CertificateAuthority *CA;

int main() {
    gmp_randinit_mt(state);
    gmp_randseed_ui(state, time(0));
    CA = new CertificateAuthority();
    User a(123), b(251);
    string vignere_key = "afeshadfkaklnljabjdsvhkjdfhsjgvbsduofvvlbdfsn";
    string msg; cin >> msg;
    string c = a.encrypt(msg, vignere_key, b.get_ID());
    cout << c << "\n\n";
    cout << b.decrypt(c, a.get_ID()) << "\n";
    return 0;
}
