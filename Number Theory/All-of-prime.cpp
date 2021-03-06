// YT resource: https://youtu.be/ykZvMA-8S6s

#include <bits/stdc++.h>
using namespace std;

vector<bool> flag(1000000, true);
vector<int> primes;

void sieve() {
	flag[0] = false;
	flag[1] = false;

	for(int i = 2; i*i < 1000000; i++)
		if(flag[i])
			for(int j = 2; i*j < 1000000; j++)
				flag[i*j] = false;

	/*
	primes.push_back(2);
	for(int i = 3; i < 1000000; i += 2)
		if(flag[i])
			primes.push_back(i);
	*/
}

int main() { }

// Segmented sieve
// problem link: https://www.spoj.com/problems/PRIME1/
// resource video: https://youtu.be/ykZvMA-8S6s
/*
const int N = 32000;

vector<int> flag(N, true);
vector<int> primes;

void sieve() {
    flag[0] = false;
    flag[1] = false;
    for(int i = 2; i*i < N; i++)
        if(flag[i])
            for(int j = 2; i*j < N; j++)
                flag[i*j] = false;

    primes.pb(2);
    for(int i = 3; i < N; i += 2)
        if(flag[i])
            primes.pb(i);
    
}

void segSieve(int l, int r) {
    bool isPrime[r-l+1];
    memset(isPrime, true, sizeof(isPrime));
    if(l == 1) isPrime[0] = false;
    for(int i = 0; sq(primes[i]) <= r; i++) {
        int base = (l / primes[i]) * primes[i];
        if(base < l) base += primes[i];
        for(int j = base; j <= r; j += primes[i])
            isPrime[j - l] = false;
        if(base == primes[i]) isPrime[base - l] = true;
    }

    for(int i = 0; i < r-l+1; i++)
        if(isPrime[i])
            cout << i+l << nl;
    puts("");
}

int main() {
    sieve();
    TC{
        int l, r;
        cin >> l >> r;
        segSieve(l, r);
    }
}

*/





// bitwise sieve
// resource video: https://youtu.be/ytxsaKqAPng
/*
bitset<1000000> bs;
vector<int> primes;

void sieve(ll upper_bound) {
    bs.set();
    bs[0] = bs[1] = 0;
    primes.pb(2);
    for(ll i = 3; i <= upper_bound + 1; i += 2)
        if(bs[i]) {
            for(ll j = i*i; j <= upper_bound; j += i)
                bs[j] = 0;
            primes.pb((int) i);
        }
}

int main() {
    sieve(1000000);
    for(int i = 0; i < 100; i++)
        cout << primes[i] << nl;
}

*/
