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

    return 0;
}
