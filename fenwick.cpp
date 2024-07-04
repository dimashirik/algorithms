struct fenwick {
    ll n;
    vector<ll> f;
    fenwick(ll n) : n(n), f(n + 1){};
    ll sum(ll ind) {
        ll res = 0;
        ll i = ind;
        while (i >= 0) {
            res += f[i];
            i = (i & (i + 1)) - 1;
        }
        return res;
    }
    ll sum(ll l, ll r) {
        return (sum(r) - sum(l - 1));
    }
    void inc(ll x, int v) {
        while (x < n) {
            f[x] += v;
            x = (x | (x + 1));
        }
    }
};
