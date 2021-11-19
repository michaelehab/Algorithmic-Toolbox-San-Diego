#include <iostream>

using namespace std; 

typedef long long ll;

ll gcd_fast(ll a, ll b){
  if(b == 0) return a;
  else return gcd_fast(b, a % b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << gcd_fast(a, b);
  return 0;
}
