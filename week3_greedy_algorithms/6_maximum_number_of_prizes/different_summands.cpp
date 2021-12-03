#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int k = 0;
  for (int i = 1; n; i++){
    if (n > 2 * i) {
      summands.push_back(i);
      k++;
      n -= i;
    } 
    else {
      summands.push_back(n);
      k++;
      break;
    }
  }
  return summands;
}

int main(){
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
