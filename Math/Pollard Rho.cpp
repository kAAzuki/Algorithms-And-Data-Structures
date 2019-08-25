
// Use Modpow if Number to check is less than 1e9

namespace miller_rabin
{
  long long mul(long long a,long long b,long long c)
  {
    long long x = 0,y=a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
   }
	int ipow(int x, int y, int p)
	{
		int ret = 1, piv = x % p;
		while(y)
        {
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	int modpow(int x, int n, int m) 
	{
    		if (n == 0) return 1%m;
    		long long u = modpow(x,n/2,m);
    		u = (u*u)%m;
    		if (n%2 == 1) u = (u*x)%m;
    		return u;
	}
	bool miller_rabin(int x, int a)
	{
		if(x % a == 0) return 0;
		int d = x - 1;
		while(1)
        {
			int tmp = ipow(a, d, x); // Replace Here with modpow
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(int x)
	{
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
        {
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}
}

namespace pollard_rho
{
	int f(int x, int n, int c)
	{
		return (c + miller_rabin::mul(x, x, n)) % n;
	}
	void rec(int n, vector<int> &v)
	{
		if(n == 1) return;
		if(n % 2 == 0)
        {
			v.push_back(2);
			rec(n/2, v);
			return;
		}
		if(miller_rabin::isprime(n))
		{
			v.push_back(n);
			return;
		}
		int a, b, c;
		while(1)
		{
			a = rand() % (n-2) + 2;
			b = a;
			c = rand() % 20 + 1;
			do{
				a = f(a, n, c);
				b = f(f(b, n, c), n, c);
			}while(__gcd(abs(a-b), n) == 1);

			if(a != b) break;
		}
		int x = __gcd(abs(a-b), n);
		rec(x, v);
		rec(n/x, v);
	}
	vector<int> factorize(int n)
	{
		vector<int> ret;
		rec(n, ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};
