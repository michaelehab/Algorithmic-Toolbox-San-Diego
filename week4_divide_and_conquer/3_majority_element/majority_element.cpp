#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  map <ll, int> freq;
  bool has_majority_element = false;

  for(size_t i = 0; i < n; ++i){
    ll x; 
    cin>>x;
    freq[x]++;
    if(freq[x] > n/2){
      has_majority_element = true;
      break;
    }
  }
  cout << has_majority_element << '\n';
}
