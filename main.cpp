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
	cout << rsa->getE() << '\n';
	cout << rsa->getD() << '\n';

	//int first_100_prime[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29,
	//						 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
	//						 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
	//						 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
	//						 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
	//						 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
	//						 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
	//						 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
	//						 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
	//						 467, 479, 487, 491, 499, 503, 509, 521, 523, 541 };

	//int total = 100;
	//int success = 0;

	//BigInt a, b("2"), temp("0"), zero("0");
	//for (int i = 0; i < total; i++)
	//{
	//	a = BigInt::genRandomNum(15);
	//	if (a % 2 == zero)
	//		a += 1;

	//	cout << a << '\n';
	//	/*cout << a % b << '\n';*/
	//	bool isPrime = false;
	//	for (int divisor : first_100_prime)
	//	{
	//		if ((BigInt)pow(divisor, 2) > a)
	//			break;
	//		if (a % divisor == zero)
	//		{
	//			isPrime = true;
	//			cout << "is product of " << divisor << "\n";
	//			break;
	//		}
	//	}
	//	// No divisor found, move to next step
	//	temp = a;
	//	if (!isPrime)
	//	{
	//		cout << "not yet detected\n";
	//		success++;
	//	}
	//}

	//cout << "Statisctic: " << success << "/" << total << "\n";

	//cout << Miller("53", 20) << '\n';
	//cout << Miller("149", 20) << '\n';
	//cout << Miller("317", 20) << '\n';
	//cout << Miller("55439", 20) << '\n';
	//cout << Miller("62501", 20) << '\n';

	return 0;
}
