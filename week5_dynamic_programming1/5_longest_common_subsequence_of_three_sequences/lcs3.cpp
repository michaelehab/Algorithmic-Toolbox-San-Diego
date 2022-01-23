#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<vv32> vvv32;
#define forv(i, a) for(int i = 0; i <= a.size(); i++)

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  // 3D DP Array size [a+1][b+1][c+1]
  vvv32 arr((a.size() + 1), vv32 (b.size() + 1, v32 (c.size() + 1)));

  // Filling the 3D Array
  forv(i, a){
    forv(j, b){
      forv(k, c){
        if(i == 0 || j == 0 || k == 0) arr[i][j][k] = 0;

        else if(a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) arr[i][j][k] = 1 + arr[i - 1][j - 1][k - 1];

        else arr[i][j][k] = max({arr[i][j - 1][k], arr[i - 1][j][k], arr[i][j][k - 1]});
      }
    }
  }
  
  return arr[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) cin >> a[i];

  size_t bn;
  cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) cin >> b[i];

  size_t cn;
  cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) cin >> c[i];

  cout << lcs3(a, b, c) << endl;
}
