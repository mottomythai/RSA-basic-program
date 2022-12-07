#include <iostream>
#include "dos.h"
#include "rsa_encrypt.h"
using namespace std;

int main()
{
	// char choice;
	// cout << "--- SINH KHOA ---\n"
	//     << "Chon kich thuoc khoa:\n1. 512 bits\n2. 1024 bits\n3. 2048 bits\n"
	//     << "-----------------\nLua chon cua ban: ";

	// cin >> choice;

	// cout << "Khoa cong khai: ";
	// // publicKeyGen(choice);

	// cout << "\nKhoa rieng tu: ";
	// // privateKeyGen(choice);

	// BigInt a("1214321434235313121");
	// cout << a;
	// cin;

	RSA* rsa = RSA::getInstance();
	cout << "E:" << rsa->getE() << ": " << Length(rsa->getE()) << '\n';
	cout << "D:" << rsa->getD() << ": " << Length(rsa->getD()) << '\n';
	cout << "N:" << rsa->getN() << ": " << Length(rsa->getN()) << '\n';

	return 0;
}
