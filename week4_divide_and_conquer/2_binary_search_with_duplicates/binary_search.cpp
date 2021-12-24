#include <iostream>
#include <vector>

using namespace std;

// Binary Search with duplicates
int binary_search(const vector<long long> &a, long long x) {
  int l = 0, r = (int)a.size() - 1;
  int idx = -1;
  while(l <= r){
    int mid = (l + r)/2;
    if(a[mid] < x) l = mid + 1;
    else if(a[mid] > x) r = mid - 1;
    else {
      idx = mid;
      r = mid - 1;
    }
  }
  return idx;
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) cin >> a[i];
  int m;
  cin >> m;
  vector<long long> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int i = 0; i < m; ++i) cout << binary_search(a, b[i]) << ' ';
}
