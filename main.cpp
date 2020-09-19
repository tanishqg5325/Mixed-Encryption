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
    string vignereKey = "afeshadfkaklnljabjdsvhkjdfhsjgvbsduofvvlbdfsn";
    string msg; cin >> msg;
    string c = a.encrypt(msg, vignereKey, b.get_ID());
    cout << b.decrypt(c, a.get_ID()) << "\n";
    c = b.encrypt(msg, vignereKey, a.get_ID());
    cout<< a.decrypt(c, b.get_ID()) << "\n";
    return 0;
}
