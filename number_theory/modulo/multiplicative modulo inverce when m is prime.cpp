//when a nad b are coprime and this alogrithm when m is prime are same
// because any number is coprime with a prime number
int power(int x,  int y, int m) 
{ 
	if (y == 0) 
		return 1; 
	int p = power(x, y/2, m) % m; 
	p = (p * p) % m; 
	return (y%2 == 0)? p : (x * p) % m; 
} 
int modInverse(int a, int m) 
{ 
	int g = gcd(a, m); 
	if (g != 1) 
		return -1;
	else
		return(power(a, m-2, m));  
} 
int main() 
{ 
	int a = 3, m = 11; 
	modInverse(a, m); 
	return 0; 
} 
