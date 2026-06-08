#include <bits/stdc++.h>
using namespace std;

vector<int> spf;

void build_spf(int n) {
    spf.assign(n + 1, 0);

    for (int i = 0; i <= n; i++)
        spf[i] = i;

    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

inline void done() {
    
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    done();
    return 0;
}
