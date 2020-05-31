
//when m is prime and this alogrithm when a and b are coprime are same
// because any number is coprime with a prime numberll gcdExtended(ll a, ll b, ll *x, ll *y) 
{
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 
	ll x1, y1; 
	ll gcd = gcdExtended(b%a, a, &x1, &y1); 
	*x = y1 - (b/a) * x1; 
	*y = x1; 
	return gcd; 
} 
ll modInverse(ll a, ll m) 
{ 
	ll x, y; 
	ll g = gcdExtended(a, m, &x, &y); 
	if (g != 1) 
		return -1;
	else
	{ 
		ll res = (x%m + m) % m; 
		return res;
	} 
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		ll a=6;
		ll m=998244353;
		modInverse(a, m); 
}