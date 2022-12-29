#ifndef RSA_ENCRYPT_H
#define RSA_ENCRYPT_H

#include <math.h>
#include <string>
#include <iostream>
#include "algorithm.h"
using namespace std;

#define MILLER_ITER 10
#define CONSTANT_K 2 // Constant number
#define DEBUG false

class RSA
{
private:
    //------Atributes------
    static RSA *instance;

    BigInt e;
    BigInt d;
    BigInt n;
    int numLen = -1;

    //------Function------
    RSA();
    RSA(int len);
    RSA(BigInt e, BigInt d, BigInt n);

public:
    ~RSA();
    static RSA *getInstance();
    static RSA *getInstance(int);
    static RSA *getInstance(BigInt, BigInt, BigInt);

    BigInt getE();
    BigInt getD();
    BigInt getN();
    RSA *keygen();
    string encrypt(string);
    string decrypt(string);
};

#endif // !RSA_ENCRYPT_H