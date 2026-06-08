#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Smallest Prime Factor (SPF)
vector<int> spf;
void build_spf(int n) {
    for(int i = 0; i < n; ++i) {
        spf[i] = i;
    }
    /*
        if n = 10
        spf = [ 0 1 2 3 4 5 6 7 8 9 ]
    */

    for(int i = 2; i * i < n; ++i) {
        if(spf[i] == i) { // is prime -> but why? because the value has not changed
            for(int j = i * i; j < n; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    /*
                spf = [ 0 1 2 3 4 5 6 7 8 9 ]
                            i
                Note:
                We start from 2 because 0 and 1 are not prime numbers,
                and 2 is the smallest prime number. Also, every composite
                number has a prime factor greater than or equal to 2.

                i = 2 {
                            condition (for): i * i < 10 -> 2 * 2 < 10 -> true
                            condition (if): spf[i] == i -> 2 == 2 -> true
                            condition (for): j < n -> i * i < n -> 4 < 10 -> true

                            spf = [ 0 1 2 3 4 5 6 7 8 9 ]
                                            j

                            then j takes the next values: 4, 6, 8.
                            but why? because we increment by i in each iteration.

                            condition (if): spf[j] == j -> 4 == 4 -> true
                            so we change the value of spf[j] to i.

                            before:
                            spf = [ 0 1 2 3 4 5 6 7 8 9 ]
                                            j

                            after:
                            spf = [ 0 1 2 3 2 5 6 7 8 9 ]
                                            j

                            and so on...
                      }
    
    */
}

inline void done() {
    int n;  cin >> n;

    spf.assign(n, 0);
    // spf = [ 0 0 0 0 0 0 0 0 0 0 ]
    build_spf(n);

    for(auto i: spf) {
        cout << i << ' ';
    }
    /*
    before: 
        spf = [ 0 1 2 3 4 5 6 7 8 9 ]

    after: 
        spf = [ 0 1 2 3 2 5 2 7 2 3 ]
    */
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    done();
    return 0;
}
