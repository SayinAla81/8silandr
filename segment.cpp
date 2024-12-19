const ll maxn = 1e5 + 5;
ll seg[maxn << 2];
 
void update(ll index, ll val, ll L = 0, ll R = maxn, ll i = 1)
{
    if(R - L == 1)
    {
        seg[i] = val;
        return;
    }
    ll mid = R + L >> 1;
    if(index < mid)
        update(index, val, L, mid, i << 1);
    else
        update(index, val, mid, R, i << 1 | 1);
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
}
 
ll get(ll l, ll r, ll L = 0, ll R = maxn, ll i = 1)
{
    if(r <= L || l >= R)
        return 0;
    if(l <= L && R <= r)
        return seg[i];
    ll mid = R + L >> 1;
    return get(l, r, L, mid, i << 1) + get(l, r, mid, R, i << 1 | 1);
}