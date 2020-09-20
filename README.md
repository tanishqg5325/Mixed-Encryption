# Mixed Encryption

## Overview

A  public  key  infrastructure  (PKI)  is  an  arrangement  that binds public  keys  with  respective identities of entities (like people and organizations). The binding is established through a process of registration and issuance of certificates by a certificate authority (CA). The primary role of the CA is to digitally sign and publish the public key bound to a given user. This is done using the CA's own private key, so that trust in the user key relies on one's trust in the validity of the CA's key.

Consider a mixed encryption scheme, which  combines asymmetric key  scheme with symmetric key scheme. We can define a mixed encryption scheme for transmitting a message m by user a A to a user B, as follows:

### Definitions

- m := message
- k := key of symmetric key scheme
- sk<sub>P</sub> := secret key for user P
- pk<sub>P</sub> := public key for user P
- sk<sub>Q</sub> := secret key for user Q
- pk<sub>Q</sub> := public key for user Q
- E<sub>S</sub> := Encryption algorithm for symmetric key scheme
- D<sub>S</sub> := Decryption algorithm for symmetric key scheme
E<sub>A</sub> := Encryption algorithm for asymmetric key scheme
- D<sub>A</sub> := Decryption algorithm for asymmetric key scheme

### Encryption by User P

1. c<sub>s</sub> ← E<sub>S</sub>(m, k)
2. (c, k') ← E<sub>A</sub>(D<sub>A</sub>((c<sub>s</sub>, k), sk<sub>P</sub>), pk<sub>Q</sub>)

### Decryption by User Q

1. (c<sub>s</sub>, k) ← E<sub>A</sub>(D<sub>A</sub>((c, k'), sk<sub>Q</sub>), pk<sub>P</sub>)
2. m ← D<sub>S</sub>(c<sub>s</sub>, k)

In this project, RSA has been used as asymmetric key scheme and Vigenere as symmetric key scheme.

## Usage

### Compile

```bash
make
```
