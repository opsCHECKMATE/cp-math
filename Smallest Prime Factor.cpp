#include <bits/stdc++.h>
using namespace std;

constexpr int n = 1e5 + 5;
int spf[n];

void sieve() {
    for (int i = 1; i <= 100000; ++i) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= 100000; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= 100000; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve();

    // Check if number is prime
    auto is_prime = [&](int n) {
        return n == spf[n] && n > 1;
    };

    /*
    Check if number is semi-prime
    A semi-prime is the product of two prime numbers (they may be equal)
    */
    auto semi_prime = [&](int n) {
        int x = spf[n];
        int y = n / x;
        return (spf[x] == x && x > 1 && spf[y] == y && y > 1);
        // x * y == n
    };

    // Finding the prime factorization of a number
    auto factorization = [&](int n) {
        vector<int> r;
        int x = n;
        while (x != 1) {
            r.push_back(spf[x]);
            x /= spf[x];
        }
        return r;
    };

    // Divisors count
    auto count_divisors = [&](int x) {
        int ans = 1;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            ans *= (cnt + 1);
        }
        return ans;
    };

    // Check if number is square-free
    auto square_free = [&](int x) {
        while (x > 1) {
            int p = spf[x];
            x /= p;
            if (x % p == 0) return false;
        }
        return true;
    };

    // Generate all divisors
    auto get_divisors = [&](int x) {
        vector<int> divs = {1};
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            int sz = divs.size();
            int mul = 1;
            for (int i = 0; i < cnt; i++) {
                mul *= p;
                for (int j = 0; j < sz; j++) {
                    divs.push_back(divs[j] * mul);
                }
            }
        }
        return divs;
    };

    return 0;
}
