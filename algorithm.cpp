#include "algorithm.h"

using namespace std;

// --BigInt--

// --BigInt--

// --Miller-Rabin primality test--

//Calculates (a * b) % mod 
BigInt mulmod(BigInt a, BigInt b, BigInt mod)
{
    BigInt x = 0, y = a % mod;
    while (b > 0)
    {
      if (b % 2 == 1)
      {    
      x = (x + y) % mod;
      }
      y = (y * 2) % mod;
      b /= 2;
    }
    return x % mod;
}

//Calculates A^B % mod
BigInt modulo(BigInt A, BigInt B, BigInt mod)
{
    BigInt x = 1;
    BigInt y = A;
    while (B > 0)
    {
      if (B % 2 == 1){
            x = (x * y) % mod;
      }
      y = (y * y) % mod;
      B = B / 2;
    }
    return x % mod;
}


//Giải thuật
//Input số tự nhiên lẻ n
//Output Số nguyên tố: True/False
//1. Phân tích n - 1 = 2^s * m (Trong đó s > 1 và m là số tự nhiên lẻ)
//2. Chọn ngẫu nhiên số tự nhiên a thuộc {2,...., n-1}
//3. Đặt b = a^m (mod n)
//4. Nếu b%n = 1 thì trả về True. Kết thúc.
//5. Cho k chạy từ 0 đến s-1:
      //1. Nếu b mod n = -1 thì trả về True. Kết thúc.
      //2. thay b:= b^2 (mod n)
//6. Trả lời False. Kết thúc.

bool Miller(BigInt p,int iteration) 
{
    BigInt zero("0");
    BigInt two("2");
    if (p < two) return false; 

    if (p != two && p % two== zero) return false; 
    
    BigInt s = p - 1; 

    while (s % two == zero){ 
      s /= 2; 
    } 

    for (int i = 0; i < iteration; i++) { 
        BigInt a = rand() % (p - 1) + 1, temp = s; 
        BigInt mod = modulo(a, temp, p); 

        while (temp != p - 1 && mod != 1 && mod != p - 1) { 
            mod = mulmod(mod, mod, p); 
            temp *= 2; 
        } 

        if (mod != p - 1 && temp % two == zero) { 
            return false; 
        } 
    } 
    return true; 
}

// --Miller-Rabin primality test--

// --RSA--

// --RSA--