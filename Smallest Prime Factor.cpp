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
    auto chk = [&](int n) {
        return n == spf[n];
    };

    /*
    Check if number is semi-prime
    Note: A semi-prime is the product of two prime numbers (they may be equal)

    For example:
    25 = 5 * 5
    77 = 7 * 11
    */
    auto semi = [&](int n) {
        int x = spf[n];
        int y = n / x;
        return (spf[x] == x && x > 1 && spf[y] == y && y > 1);
        // x * y == n
    };

    // Finding the prime factorization of a number
    auto fac = [&](int n) {
        vector<int> r;
        int x = n;
        while (x != 1) {
            r.push_back(spf[x]);
            x /= spf[x];
        }
        return r;
    };

    return 0;
}
