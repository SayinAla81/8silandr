const ll mod = 1e9 + 7;

ll power(ll a, ll b)
{
    if(b == 0) return 1;
    return power((a * a) % mod, b / 2)  * (b % 2 ? a : (ll)1) % mod;
}

ll comb(ll k, ll n)
{
    ll ans = 1;
    for(int i = 1; i <= k; i++) ans = ans * i % mod;
    ans = power(ans, mod - 2);
    for(int i = n; i > n - k; i--) ans = ans * i % mod;
    return ans;
}