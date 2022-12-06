#ifndef RSA_ENCRYPT_H
#define RSA_ENCRYPT_H

#include <math.h>
#include <string>
#include <iostream>
#include "algorithm.h"
using namespace std;

#define MILLER_ITER 20
#define CONSTANT_K 2 // Constant number
#define DEBUG true

class RSA
{
private:
    //------Atributes------
    static RSA *instance;

    BigInt e;
    BigInt d;
    BigInt n;

    //------Function------
    RSA();

public:
    ~RSA();
    static RSA *getInstance();

    BigInt getE();
    BigInt getD();
    BigInt getN();
    RSA *regen();
};

#endif // !RSA_ENCRYPT_H