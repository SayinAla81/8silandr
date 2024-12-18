void dijkstra(ll source, ll n)
{
    // graph --> v[source].pb({destination, edge})
    // dist[i] --> distance(sources to i)
    ll dist[maxn];
    fill(dist, dist + maxn, inf);
    set<pair<ll, pii>> st;
    dist[source] = 0;
    st.insert({dist[source], {source, source}});
    while (st.size())
    {
        pair<ll, pii> now = (*st.begin());
        st.erase(now);
        dist[now.S.S] = min(dist[now.S.S], dist[now.S.F] + now.F);
        for (auto i : v[now.S.S])
            if(dist[now.S.S] + i.S < dist[i.F])
                st.insert({i.S, {now.S.S, i.F}});
    }
}