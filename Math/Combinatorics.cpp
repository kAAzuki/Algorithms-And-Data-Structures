/// kAAzuki Hoshino
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define MAX 3000

int pascal[MAX][MAX];

  long long mul(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
   }
	long long modpow(long long x, long long y, long long p){
		long long ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
/*
int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}
*/

int fac[MAX], inv[MAX], finv[MAX];

void pre(){
	inv[1]=1;
	for (int i = 2; i <MAX ; i++)
	{
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	}
	fac[0]=finv[0]=1;
	for (int i = 1; i < MAX; ++i)
	{
		fac[i]=fac[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
int ncr(int n, int r){
	if(r<0||r>n)return 0;
	return fac[n]*finv[r]%mod*finv[n-r]%mod;
}

signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
pascal[0][0] = 1;
for (int i = 1; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
    {
        pascal[i][j] = pascal[i-1][j];
        if (j)
            pascal[i][j] = (pascal[i][j] + pascal[i-1][j-1]) % mod;
}
int q;
cin >> q;
pre();
while(q--){

    int i,j;
    cin >> i >> j;
    cout << ncr(i,j) << " " << pascal[i][j] << endl;

}

return 0;
}
///....
