#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

using namespace std;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values, int n) {
  double value = 0.0;
  // Pair : Value per Weight, Actual Weight
  vector <pair <double, double>> val_per_w(n);
  for(int i = 0; i < n; i++){
    val_per_w.push_back(make_pair(values[i]/weights[i], weights[i]));
  }
  sort(val_per_w.rbegin(), val_per_w.rend());
  for(int i = 0; i < n; i++){
    int a = min(val_per_w[i].second, capacity);
    value += a*val_per_w[i].first;
    capacity -= a;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) cin >> values[i] >> weights[i];

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  cout << fixed << setprecision(4) << optimal_value << endl;
  return 0;
}
