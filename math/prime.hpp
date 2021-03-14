#pragma once

// naive check O(sqrt(N))
inline bool is_prime(long long x) {
  if (x <= 1) return false;
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

/**
 * @brief Sieve of Eratosthenes
 * @note List primes O(NloglogN)
 */
vector<int> sieve_of_eratosthenes(int n = 200010) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 0; i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i + i; j <= n; j += i) is_prime[j] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) primes.push_back(i);
  }
  return primes;
}

/**
 * @brief Prime Factorization
 * @note prime table up to sqrt(N) is enough to factorize.
 * @note O(sqrt(N))
 */
map<long long, int> prime_factorize(long long n, const vector<int> &primes) {
  map<long long, int> prime_factor;
  for (int p : primes) {
    if (n < (long long)p * p) break;
    while (n % p == 0) {
      prime_factor[p] += 1;
      n /= p;
    }
  }
  if (n != 1) prime_factor[n] += 1;
  return prime_factor;
}

/**
 * @brief List divisors
 */
vector<long long> calc_divisors(long long n, const map<long long, int> &prime_factor) {
  vector<long long> divisors(1, 1);
  for (auto it : prime_factor) {
    long long p;
    int k;
    tie(p, k) = it;
    int size = divisors.size();
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < size; ++j) divisors.push_back(divisors[i * size + j] * p);
    }
  }
  sort(divisors.begin(), divisors.end());
  return divisors;
}