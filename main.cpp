#include <iostream>
#include "algorithm.h"
using namespace std;

int main()
{
    char choice;
    cout << "--- SINH KHOA ---\n"
        << "Chon kich thuoc khoa:\n1. 512 bits\n2. 1024 bits\n3. 2048 bits\n"
        << "-----------------\nLua chon cua ban: ";
    
    cin >> choice;

    cout << "Khoa cong khai: ";
    publicKeyGen(choice);

    cout << "\nKhoa rieng tu: ";
    privateKeyGen(choice);

    BigInt a("1214321434235313121");
    cout << a;
    return 0;
}
