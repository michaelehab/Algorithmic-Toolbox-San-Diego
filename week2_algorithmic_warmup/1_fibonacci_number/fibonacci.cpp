#include <iostream>
#include <cassert>

using namespace std;

typedef long long ll;

// Naive Algorithm for Calculating the n-th fibonacci number
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// Faster Algorithm for Calculating the n-th fibonacci number
int fibonacci_fast(ll n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    
	ll a = 0, b = 1, c = a + b;

	for (int i = 1; i < n; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    ll n = 0;
    cin >> n;
    cout << fibonacci_fast(n);
    return 0;
}
