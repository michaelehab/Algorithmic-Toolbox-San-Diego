#include <iostream>

using namespace std;

typedef long long ll;

ll fibonacci_sum_fast(ll n) {
    // The Pisano period for 10 is 60
    n = (n + 2) % 60;
    ll a = 0, b = 1, c;
    for(ll i = 2; i <= n; i++){
        c = a + b;
        a = b, b = c;
    }
    if(c == 0) return 9;
    return c;
}

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
    if(n == 0) return 0;
	ll rem = n % period(m);
	ll a = 0, b = 1, c = rem;

	for (int i = 1; i < rem; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
	}

	return c % m;
}

// F[f] + F[f + 1] + ... + F[t] = Sum of all F to F[t] - Sum of all F to F[f - 1]
ll get_fibonacci_partial_sum_fast(ll f, ll t){
    if(f == 0) return fib_mod_m(t, 10);
    ll s = fibonacci_sum_fast(t) - fibonacci_sum_fast(f - 1);
    return s % 10;
}

int main() {
    ll from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum_fast(from, to);
}
