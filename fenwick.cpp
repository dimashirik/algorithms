struct fenwick {
    ll n;
    vector<ll> f;
    fenwick(ll n) : n(n), f(n){};
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
        return (sum(r - 1) - sum(l - 2));
    }
    void inc(ll x) {
        x -= 1;
        while (x < n) {
            f[x]++;
            x = (x | (x + 1));
        }
    }
};
