int modpow(int x, int n, int mod)
{
    x %= mod ;
    int res = 1;
    while(n>0){
        if(n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
