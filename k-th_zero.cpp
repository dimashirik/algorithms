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
