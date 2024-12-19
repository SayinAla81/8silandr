class Seg
{
    public:
        ll seg, pref, suf, sum;
        Seg(ll val = 0)
        {
            seg = suf = pref = sum = val;
        }
};
 
const ll maxn = 1e5 + 5, inf = 1e9 + 7;
Seg seg[maxn << 2];
 
Seg merge(Seg l, Seg r)
{
    Seg ans(0);
    ans.pref = max(l.pref, l.sum + r.pref);
    ans.suf = max(r.suf, r.sum + l.suf);
    ans.seg = max(l.suf + r.pref , max(l.seg, r.seg));
    ans.sum = l.sum + r.sum;
    return ans;
}
 
void update(ll index, ll val, ll L = 0, ll R = maxn, ll i = 1)
{
    if(R - L == 1)
    {
        seg[i].seg = seg[i].suf = seg[i].pref = seg[i].sum = val;
        return;
    }
    ll mid = R + L >> 1;
    if(index < mid)
        update(index, val, L, mid, i << 1);
    else
        update(index, val, mid, R, i << 1 | 1);
    seg[i] = merge(seg[i << 1], seg[i << 1 | 1]);
}
 
Seg get(ll l, ll r, ll L = 0, ll R = maxn, ll i = 1)
{
    Seg ans(0);
    if(l >= R || r <= L)
        return ans;
    if(l <= L && R <= r)
        return seg[i];
    ll mid = R + L >> 1;
    return merge(get(l, r, L, mid, i << 1), get(l, r, mid, R, i << 1 | 1));
}