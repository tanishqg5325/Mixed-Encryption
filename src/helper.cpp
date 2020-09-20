/*/-------------------------------Helper Functions------------------------------------/*/

#include "helper.h"

int get_block_size(mpz_class n) {
    int r = 0;
    mpz_class ans = 1;
    while(ans < n) {ans *= 26; r++;}
    return r-1;
}

string pre_process(string message, int block_size) {
    int pos = -1;
    for(int i=message.size()-1;i>=0;i--)
        if(message[i] != 'x')
            {pos = i; break;}
    int new_n = ((pos + block_size) / block_size) * block_size;
    return message.substr(0, new_n);
}
