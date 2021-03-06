#pragma once

#include <cstddef>
#include <vector>

/**
 * @brief Runtime ModCombination
 * @note construct table : O(N)
 * @note CalcBinomial : O(1)
 */
struct RuntimeModComb {
private:
  unsigned int N;
  long long MOD;

public:
  std::vector<long long> fac, inv, ifac;

  RuntimeModComb(unsigned int N, long long MOD) : N(N), MOD(MOD), fac(N), inv(N), ifac(N) {
    fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
    for (std::size_t i = 2; i <= N; ++i) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      ifac[i] = ifac[i - 1] * inv[i] % MOD;
    }
  }

  long long comb(unsigned int n, unsigned int k) const {
    if (n < 0 || k < 0 || k > n) return 0;
    return (fac[n] * ifac[k] % MOD) * ifac[n - k] % MOD;
  }
};
