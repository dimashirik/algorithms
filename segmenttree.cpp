struct Node{
   int min;
   int cnt;
   Node(int min, int cnt) : min(min), cnt(cnt){}
   Node() : min(INF), cnt(0){}
};

Node merge(Node f, Node s) {
   if (f.min < s.min) {
      return(Node(f.min, f.cnt));
   } else if (f.min > s.min) {
      return(Node(s.min, s.cnt));
   } 
   return(Node(f.min, f.cnt + s.cnt));
}

struct segtree{

   int n;
   vector<Node> tree;

   segtree(int x) : n(x), tree(4 * x){}

   void print() {
    int layer = 4 * n;
    for (int i = 0; i < 4 * n; i++) {
        cout << setw(layer) << tree[i].min << " ";
        if (__builtin_popcount(i + 2) == 1) {
            layer /= 2;
            cout << "\n";
         }
      }
      cout << "\n";
   }

   void build(vi &a, int v, int l, int r) {
      if (r - l == 1) {
         tree[v] = {a[l], 1};
         return;
      }
      int mid = (l + r + 1) / 2;
      build(a, 2 * v + 1, l, mid);
      build(a, 2 * v + 2, mid, r);
      tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
   }

   

   void update(int i, int x, int v, int l, int r) {
      if (r - l == 1) {
         tree[v] = Node(x, 1);
      } else {
         int mid = (l + r + 1) / 2;
         if (i < mid) {
            // cout << "!1\n";
            update(i, x, 2 * v + 1, l, mid);
         } else {
            // cout << "!2\n";
            update(i, x, 2 * v + 2, mid, r);
         }
         tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
      }
   }

   Node getmin(int v, int lt, int rt, int lq, int rq) {
      if (rq <= lt || rt <= lq) {
         return Node(INF, 0);
      }
      if (lq <= lt && rt <= rq) {
         return tree[v];
      }
      int mid = (lt + rt + 1) / 2;
      return merge(getmin(2 * v + 1, lt, mid, lq, rq), getmin(2 * v + 2, mid, rt, lq, rq));
   }

   void build(vi &a) {
      build(a, 0, 0, n);
   }
   void update(int i, int x) {
      update(i, x, 0, 0, n);
   }
   Node getmin(int lq, int rq) {
      return getmin(0, 0, n, lq, rq);
   }
};
