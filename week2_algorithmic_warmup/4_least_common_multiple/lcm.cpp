#include <iostream>

using namespace std;

typedef long long ll;

ll gcd_fast(ll a, ll b){
  if(b == 0) return a;
  else return gcd_fast(b, a % b);
}

// a * b = LCM(a, b) * GCD(a, b)
ll lcm_fast(ll a, ll b) {
  return (a * b) / gcd_fast(a, b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b);
  return 0;
}
