#include <iostream>

using namespace std;

typedef long long ll;

// Calculating the Pisano period
ll period(ll m){
    ll period = 1;
    ll a = 0, b = 1, c = (a + b)%m;
    a = b, b = c;
    while(true){
        c = (a + b) % m, a = b, b = c;
        period++;
        if(a == 0 && b == 1) return period;
    }

    return period;
}

// Calculating the n-th fibonacci number mod m
int fib_mod_m(ll n, ll m) {
	ll rem = n % period(m);
	ll a = 0, b = 1, c = rem;

	for (int i = 1; i < rem; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
	}

	return c % m;
}

// F[0] + F[1] + ..... + F[n] = F[n+2] - 1
int fibonacci_sum_fast(ll n){
    return fib_mod_m(n + 2, 10) - 1;
}


int main() {
    ll n = 0;
    cin >> n;
    cout << fibonacci_sum_fast(n);
}
