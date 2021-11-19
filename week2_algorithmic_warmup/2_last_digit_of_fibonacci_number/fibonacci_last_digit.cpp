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

int main() {
    ll n;
    cin >> n;
    int c = fib_mod_m(n, 10);
    cout << c;
}
