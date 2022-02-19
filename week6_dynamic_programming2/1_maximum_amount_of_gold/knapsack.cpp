#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal_weight(int W, const vector<int> &weights) {
  int N = weights.size();
  vector<vector<int>> value(N + 1, vector<int>(W + 1, 0));

  for (size_t i = 1; i <= N; i++){
    for (int w = 1; w <= W; w++){
      value[i][w] = value[i - 1][w];
      if (weights[i - 1] <= w){
        int val = value[i - 1][w - weights[i - 1]] + weights[i - 1];
        if (value[i][w] < val) value[i][w] = val;
      }
    }
  }
  return value[N][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  cout << optimal_weight(W, w) << '\n';
}
