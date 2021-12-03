#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll max_dot_product(vector<int> a, vector<int> b) {
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  ll result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((ll) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) cin >> a[i];
  for (size_t i = 0; i < n; i++) cin >> b[i];
  cout << max_dot_product(a, b) << endl;
}
