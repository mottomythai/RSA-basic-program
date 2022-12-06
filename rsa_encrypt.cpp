#include "rsa_encrypt.h"

RSA* RSA::instance = nullptr;

RSA::RSA()
{
	regen();
}

RSA::~RSA()
{
	delete instance;
}

RSA* RSA::getInstance()
{
	if (instance == nullptr)
		instance = new RSA();

	return instance;
}

BigInt RSA::getE()
{
	return e;
}

BigInt RSA::getD()
{
	return d;
}

BigInt RSA::getN()
{
	return n;
}

RSA* RSA::regen()
{
	cout << ((DEBUG) ? "-------------Regenerator Started-------------\n" : "");
	cout << ((DEBUG) ? "Initializing variables\n" : "");
	BigInt p; // 77bit
	BigInt q; // 77bit

	// For low-level compare
	int first_100_prime[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29,
							 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
							 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
							 127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
							 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
							 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
							 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
							 353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
							 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
							 467, 479, 487, 491, 499, 503, 509, 521, 523, 541 };
	bool isPrime = false;
	BigInt zero("0");

	// Gen p
	cout << ((DEBUG) ? "Generaing P:...\n" : "");
	while (true)
	{
		// Get a 77-bit number
		p = BigInt::genRandomNum(77);
		if (p % 2 == zero)
			p += 1;

		// Low level process
		isPrime = false;
		for (int divisor : first_100_prime)
		{
			if ((BigInt)pow(divisor, 2) > p)
				break;
			if (p % divisor == zero)
			{
				isPrime = true;
				break;
			}
		}
		if (isPrime)
			continue; // p gen again
		// No divisor found, move to next step

		// High-level process using Rabin Miller Primality Test
		// If p IS prime then break and go to next step, else re-generate p
		if (Miller(p, MILLER_ITER))
			break;
	}
	cout << ((DEBUG) ? "Generating P: Successful\n" : "");
	cout << ((DEBUG) ? "Selected P: " : "");
	cout << ((DEBUG) ? p : "");
	cout << ((DEBUG) ? "\n" : "");

	// Gen q
	cout << ((DEBUG) ? "Generating Q:...\n" : "");
	while (true)
	{
		// Get a 77-bit number
		q = BigInt::genRandomNum(78);
		if (q % 2 == zero)
			q += 1;

		// Low level process
		isPrime = false;
		for (int divisor : first_100_prime)
		{
			if ((BigInt)pow(divisor, 2) > q)
				break;
			if (q % divisor == zero)
			{
				isPrime = true;
				break;
			}
		}
		if (isPrime)
			continue; // q gen again
		// No divisor found, move to next step

		// High-level process using Rabin Miller Primality Test
		// If q IS prime then break and go to next step, else re-generate q
		if (Miller(q, MILLER_ITER))
			break;
	}
	cout << ((DEBUG) ? "Generating Q: Successful\n" : "");
	cout << ((DEBUG) ? "Selected Q: " : "");
	cout << ((DEBUG) ? q : "");
	cout << ((DEBUG) ? "\n" : "");

	cout << ((DEBUG) ? "Calculating N:...\n" : "");
	// Calculate n
	n = p * q;
	cout << ((DEBUG) ? "Calculating N: Successful\n" : "");

	cout << ((DEBUG) ? "Generating E:...\n" : "");
	BigInt phi = (p - 1) * (q - 1);
	// Gen e
	// e must be co-prime to phi and smaller than phi
	while (true)
	{
		srand(GetTickCount64());
		e = BigInt::genRandomNum(rand() % 65537 + 3);
		while (e < phi)
		{
			// Check co-prime of e and phi
			if (BigInt::gcd(e, phi) == 1)
				break;
			else
				e++;
		}
		if (e >= phi)
			continue;
		break;
	}
	cout << ((DEBUG) ? "Generating E: Successful\n" : "");

	cout << ((DEBUG) ? "Calculating D:...\n" : "");
	// Calculate d
	//  d*e = 1 + k*phi
	d = (1 + (CONSTANT_K * phi)) / e;
	cout << ((DEBUG) ? "Calculating D: Successful\n" : "");
	cout << ((DEBUG) ? "-------------Regenerator Terminated-------------\n" : "");

	return this;
}