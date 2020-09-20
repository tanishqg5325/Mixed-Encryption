/*/-------------------------------Helper Functions------------------------------------/*/

#ifndef HELPER_H_
#define HELPER_H_

#include <gmpxx.h>
#include <string>

using std::string;


/// Returns maximum k such that 26^k < n
int get_block_size (mpz_class n);

string pre_process (string message, int block_size);

#endif // HELPER_H_
