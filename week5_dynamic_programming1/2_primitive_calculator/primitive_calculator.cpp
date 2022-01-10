#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> optimal_sequence(int n) {
  // The minimum number of operations required to get i
  vector <int> num_operations(n+1, INT_MAX);
  for(int i = 2; i < n + 1; i++){
    int tmp1 = INT_MAX, tmp2 = INT_MAX, tmp3 = INT_MAX;
    // tmp1 : this number can be obtained by adding one to the previous number
    tmp1 = num_operations[i - 1] + 1;
    // tmp2 : If this number can be obtained by multiplying another one (i / 2) by 2
    if(i % 2 == 0) tmp2 = num_operations[i / 2] + 1;
    // tmp3 : If this number can be obtained by multiplying another one (i / 3) by 3
    if(i % 3 == 0) tmp3 = num_operations[i / 3] + 1;
    // FInding the minimum
    num_operations[i] = min({tmp1, tmp2, tmp3});
  }

  // Backtracking the optimal number of operations
  vector <int> ans = {n};
  while(n != 1){
    if(n % 3 == 0 && num_operations[n] - 1 == num_operations[n / 3]){
      ans.push_back(n / 3);
      n /= 3;
    }
    else if(n % 2 == 0 && num_operations[n] - 1 == num_operations[n / 2]){
      ans.push_back(n / 2);
      n /= 2;
    }
    else{
      ans.push_back(n - 1);
      n -= 1;
    }
  }
  // Reversing the numbers to get ascending order of operations
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> sequence = optimal_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
}
