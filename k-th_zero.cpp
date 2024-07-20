#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;
const ll INF = INT32_MAX / 2;
const ll MOD = 998244353; // 1e9 + 7
const long double eps = 1e-13;


#define all(x) x.begin(), x.end()
#define eb emplace_back
#define pb push_back
#define FOR(i, j, k) for (ll i = (j); i <= (k); i++)
#define ROF(i, j, k) for (ll i = (j); i >= (k); i--)
#define sz(x) (ll)(x).size()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream &operator<<(ostream &out, const W &v) {
    out << "{ ";
    for (const auto &x: v) out << x << ", ";
    return out << '}';
}
template<class U, class V>
ostream &operator<<(ostream &out, const pair<U, V> &a) {
    return out << "(" << a.first << ", " << a.second << ")";
}
template<class U, class V>
istream &operator>>(istream &in, pair<U, V> &a) {
    return in >> a.first >> a.second;
}


long long max(long long a, long long b) {
    if (a < b) {
        return b;
    }
    return a;
}
long long min(long long a, long long b) {
    if (a < b) {
        return a;
    }
    return b;
}


struct Node{
    int sum;
    Node(int sum) : sum(sum){}
    Node() : sum(0){}
};

Node merge(Node f, Node s) {
    return Node(f.sum + s.sum);
}

struct segtree{

    int n;
    vector<Node> tree;

    segtree(int x) : n(x), tree(4 * x){}

    void print() {
        int layer = 4 * n;
        for (int i = 0; i < 4 * n; i++) {
            cout << setw(layer) << tree[i].sum << " ";
            if (__builtin_popcount(i + 2) == 1) {
                layer /= 2;
                cout << "\n";
            }
        }
        cout << "\n";
    }

    void build(vi &a, int v, int l, int r) {
        if (r - l == 1) {
            if (a[l] == 0) {
                tree[v] = 1;
            } else {
                tree[v] = 0;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * v + 1, l, mid);
        build(a, 2 * v + 2, mid, r);
        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }



    void update(const vi &a, int i, int x, int v, int l, int r) {
        if (r - l == 1) {
            if (a[l] == 0 && x != 0) {
                tree[v] = 0;
                return;
            } else if (a[l] != 0 && x == 0){
                tree[v] = 1;
                return;
            }
        } else {
            int mid = (l + r) / 2;
            if (i < mid) {
                // cout << "!1\n";
                update(a, i, x, 2 * v + 1, l, mid);
            } else {
                // cout << "!2\n";
                update(a, i, x, 2 * v + 2, mid, r);
            }
            tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
        }
    }

    int get(int v, int lt, int rt, int k) {
//        cout << v << ": " << lt << " " << rt << " " << tree[v].sum << '\n';
        if (rt - lt == 1) {
            return lt;
        }
        int mid = (lt + rt) / 2;
        if (tree[2 * v + 1].sum < k) {
            return get(2 * v + 2, mid, rt, k - tree[2 * v + 1].sum);
        } else {
            return get(2 * v + 1, lt, mid, k);
        }
    }


    int getnum(int v, int lt, int rt, int lq, int rq) {
        if (rt <= lq || rq <= lt) {
            return 0;
        }
        if (lq <= lt && rt <= rq) {
            return tree[v].sum;
        }
        int mid = (lt + rt) / 2;
        return getnum(2 * v + 1, lt, mid, lq, rq) + getnum(2 * v + 2, mid, rt, lq, rq);

    }

    void build(vi &a) {
        build(a, 0, 0, n);
    }
    void update(const vi &a, int i, int x) {
        update(a, i, x, 0, 0, n);
    }
    int get(int k) {
        return get(0, 0, n, k);
    }
    int getnum(int lq, int rq) {
        return getnum(0, 0, n, lq, rq);
    }
};



void solve() {
   int n;
   cin >> n;
   vi v(n);
   FOR(i, 0, n - 1) cin >> v[i];
   vi tmp = v;
   sort(all(tmp));
   map<int, int> mp;
   int cur = 0;
   FOR(i, 0, n - 1) {
       if (i == 0) {
           mp[tmp[i]] = cur;
           continue;
       }
       if (tmp[i] != tmp[i - 1]) {
           cur++;
       }
       mp[tmp[i]] = cur;
   }
   FOR(i, 0, n - 1) {
       v[i] = mp[v[i]];
   }
   for (auto el: v) {
       cout << el << ' ';
   }
   vi last(n); // 1
    
   segtree tree(n);
   
   FOR(i, 0, n - 1) {
       int x = v[i];
       if (last)
   }

}

/*
Tests:




__________________

6
2 2 1 5 3 4 6 6 1 5 3 4

*/

signed main() {
// ios_base::sync_with_stdio(false);
// cin.tie(nullptr);
// cout.tie(nullptr);
#ifdef ONLINEJUDGE
    clock_t tStart = clock();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    // freopen("circlecross.in", "r", stdin);
    // freopen("circlecross.out", "w", stdout);
    // cout << std::fixed << std::setprecision();
    long long T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

#ifdef ONLINEJUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}
