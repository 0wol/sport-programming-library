#include <vector>
#include <math.h>
#include <map>

template<typename T>
bool is_prime(T n) {
    /* checks whether n is prime */
    for(T i = 2; i * i <= n; ++i) {
        if (n % i == 0) 
            return true;
    }
    return false;
}

template<typename T>
std::vector<T> get_all_divisors(T n) {
    /* returns a vector containing all divisors of the number */
    std::vector<T> res(cbrt(n) + 1);
    int cnt = 0;
    for(T i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res[cnt++] = i;
            if (i != n / i)
                res[cnt++] = n / i;
        }
    }
    res.resize(cnt);
    return res;
}

template<typename T>
std::map<T, int> factorization(T n) {
    /* returns a map where the key is a prime divisor and value is its power */
    std::map<T, int> res;
    for(T i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n > 1) res[n]++;
    return res;
}
 
std::vector<long long> sieve_eratosthenes(long long limit) {
    /* returns a vector of all primes less or equal than limit */
    std::vector<bool> sieve(limit + 1, true);
    std::vector<long long> res(limit);
    int t = 0;
    for(long long i = 2; i <= limit; ++i) {
        if (!sieve[i]) continue;
        res[t++] = i;
        for(long long j = i * i; j <= limit; j += i)
            sieve[j] = false;
    }
    res.resize(t);
    return res;
}
