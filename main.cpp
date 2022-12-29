#include <iostream>
#include <fstream>
#include "dos.h"
#include "rsa.h"
using namespace std;

void encrypt(string dirP, BigInt key, BigInt n, string dirC)
{
	fstream inp, out;
	inp.open(dirP, ios::in);
	out.open(dirC, ios::out);

	char c;
	string data;

	// load all data
	while (inp.get(c))
	{
		data += c;
	}

	// processing
	vector<BigInt> temp;
	for (auto ch : data)
	{
		temp.push_back(modulo(ch, key, n));
	}

	// save all data
	for (auto rs : temp)
	{
		out << rs << '\n';
	}

	inp.close();
	out.close();
}

void decrypt(string dirC, string dirP)
{
	fstream inp, out;
	inp.open(dirC, ios::in);
	out.open(dirP, ios::out);

	RSA* rsa = RSA::getInstance();

	string temp;
	vector<string> inputData;
	// load all data
	while (getline(inp, temp))
	{
		inputData.push_back(temp);
	}

	vector<BigInt> data;
	// processing
	for (auto bigInt : inputData)
	{
		data.push_back(modulo(bigInt, rsa->getD(), rsa->getN()));
	}

	// saving all data
	for (auto d : data)
	{
		out << (char)stoi(d.strconvert()); // NOT YET TESTED
	}

	inp.close();
	out.close();
}

int main()
{
	try
	{
		char keyChoice;
		RSA* rsa;
		BigInt dA;

		cout << "-----------Key Selection-----------\n";
		cout << "1. Manual\n";
		cout << "2. Automatic\n";
		cin >> keyChoice;

		switch (keyChoice)
		{
		case '1':
		{
			string temp;
			cout << "Enter your personal private key:\n";
			getline(cin, temp);
			dA = temp;
			break;
		}
		case '2':
		{
			rsa = RSA::getInstance(10);
			break;
		}
		default:
			throw exception("Illegal choice");
			break;
		}

		cin.ignore();
		cin.clear();
		system("cls");

		char choice;
		cout << "Enter your choice:\n";
		cout << "1. Encrypt\n";
		cout << "2. Encrypt\n";
		cin >> choice;
		cin.ignore();
		cin.clear();

		switch (choice)
		{
		case '1':
		{
			break;
		}
		case '2':
		{
			break;
		}
		default:
			throw exception("Illegal choice");
			break;
		}

	}
	catch (const exception& e)
	{
		cout << e.what() << '\n';
	}


	return 0;
}
