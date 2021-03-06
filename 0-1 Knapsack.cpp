#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define fastio                              ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define read                                freopen("input.txt", "r", stdin);
#define write                               freopen("output.txt", "w", stdout);
#define nl                                  '\n'
#define debug(x)                            cerr << #x << " = " << x << endl
#define LCM(a,b)                            (a / __gcd(a,b) ) *b
#define GCD(a,b)                            __gcd(a,b)

#define ll                                  long long
#define vi                                  vector<int>
#define pb                                  push_back
#define vpii                                vector<pair<int, int>>
#define mp                                  make_pair
#define ff                                  first
#define ss                                  second
#define all(v)                              v.begin(), v.end()
#define rsort(v)                            sort(v.rbegin(), v.rend())

using namespace std;

const double pi = acos(-1.0);


int dp[2010][2010];
vector<int> value, weight; // weight = {0, ...};
                           // value - {0, ...};

int ks(int n, int capacity) {
    if(dp[n][capacity] != -1) return dp[n][capacity];
    int result;
    if(!capacity or !n) result = 0;
    else if(weight[n] > capacity) result = ks(n-1, capacity);
    else {
        int profit1 = value[n] + ks(n-1, capacity-weight[n]);
        int profit2 = ks(n-1, capacity);
        result = max(profit1, profit2);
    }

    dp[n][capacity] = result;
    return dp[n][capacity];
}






int main() {
    // classic knapsack


    memset(dp, -1, sizeof(dp));
    value.pb(0);
    weight.pb(0);
    int capacity, n, a, b;
    cin >> capacity >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        weight.pb(a);
        value.pb(b);
    }

    cout << ks(n, capacity);

}

// http://www.shafaetsplanet.com/?p=3638
