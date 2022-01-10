#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// The possible coins are 1, 3, 4
int coins[3] = {1, 3, 4};

int get_change(int m) {
	vector<int> total(m + 1, INT_MAX);
	total[0] = 0;
	for(int i = 1; i <= m; i++){
		for(int c = 0; c < 3; c++){
			if(i >= coins[c]){
				int prev = total[i - coins[c]];
				// Check if the number can be obtained by adding this coin value to a previous number
				if(prev != INT_MAX) total[i] = min(total[i], prev + 1);
			}
		}
	}
	return total[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
