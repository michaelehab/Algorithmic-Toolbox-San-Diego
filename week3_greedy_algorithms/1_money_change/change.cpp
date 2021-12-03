#include <iostream>

using namespace std;

int get_change(int m) {
  int n = 0;
  int coins[3] = {10, 5, 1};
  for(int i = 0; i < 3; i++){
    if(m > 0){
      n += (m / coins[i]);
      m = m % coins[i];
    }
    else break;
  }
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
