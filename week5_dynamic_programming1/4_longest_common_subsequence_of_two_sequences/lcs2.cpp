#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  // DP table size [a+1][b+1]
  vector <vector<int>> table((a.size() + 1), vector <int> (b.size() + 1));

  // Filling the table
  for(int i = 0; i <= a.size(); i++){
    for(int j = 0; j <= b.size(); j++){
      // Adding Zeros to the first row and column
      if(i == 0 || j == 0) table[i][j] = 0;

      // If the last character is the same we include the value in the diagonal
      else if(a[i - 1] == b[j - 1]) table[i][j] = 1 + table[i - 1][j - 1];

      else table[i][j] = max(table[i][j - 1], table[i - 1][j]);
    }
  }
  
  return table[a.size()][b.size()];
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) cin >> a[i];

  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) cin >> b[i];

  cout << lcs2(a, b) << endl;
}
