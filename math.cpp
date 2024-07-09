ll binary_pow(int n, int k) {
   if (k == 0) {
      return 1;
   }
   if (k % 2 == 1) {
      return (binary_pow(n, k - 1) * n % MOD);
   } else {
      ll b = binary_pow(n, k / 2);
      return (b * b % MOD);
   }
} // БИНАРНОЕ ВОЗВЕДНИЕ В СТЕПЕНЬ

ll fac(ll x) {
   ll res = 1;
   FOR(i, 1, x) {
      res *= i;
      res %= MOD;
   }
   return (res % MOD);
} // ФАКТОРИАЛ

ll inv(ll x) {
   return binary_pow(x, MOD - 2);
} // ОБРАТНЫЙ ЭЛЕМЕНТ ПО МОДУЛЮ(ЕСЛИ НАШЕ ЧИСЛО ВЗАИМНО ПРОСТО С МОДУЛЕМ)

ll c(int n, int k) {
   if (n == k || k == 0) {
      return 1;
   }
   return (c(n - 1, k - 1) + c(n - 1, k)) % MOD;
} // РЕКУРЕНТНАЯ ФОРМУЛА С(N, K)

int d(int n) {
   if (n == 1) {
      return 0;
   }
   int x = d(n - 1);
   return n * x + pow((-1), n);
} // КОЛИЧЕСТВО БЕСПОРЯДКОВ ПОРЯДКА N
