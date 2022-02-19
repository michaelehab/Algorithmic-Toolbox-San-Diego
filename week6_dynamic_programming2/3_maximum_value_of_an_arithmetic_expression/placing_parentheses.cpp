#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int eval(int a, int b, char op) {
  if (op == '*') return a * b;
  else if (op == '+') return a + b;
  else if (op == '-') return a - b;
}

int get_maximum_value(const string &exp) {
  int N = exp.size();
	int operands = (N + 1) / 2;
  vector<vector<int>> Min(operands, vector<int>(operands, 0));
  vector<vector<int>> Max(operands, vector<int>(operands, 0));

  for (int i = 0; i < operands; i++) {
		Min[i][i] = int(exp[2 * i]) - 48;
		Max[i][i] = int(exp[2 * i]) - 48;
	}

	for(int s = 0; s < operands - 1; s++) {
		for(int i = 0; i < operands - s - 1; i++) {
			int j = i + s + 1;
			int minVal = INT_MAX;
			int maxVal = INT_MIN;

			for(int k = i; k < j; k++) {
				int a = eval(Min[i][k], Min[k + 1][j], exp[2 * k + 1]);
				int b = eval(Min[i][k], Max[k + 1][j], exp[2 * k + 1]);
				int c = eval(Max[i][k], Min[k + 1][j], exp[2 * k + 1]);
				int d = eval(Max[i][k], Max[k + 1][j], exp[2 * k + 1]);

				minVal = min({minVal, a, b, c, d});
				maxVal = max({maxVal, a, b, c, d});
			}
			Min[i][j] = minVal;
			Max[i][j] = maxVal;
		}
	}

	return Max[0][operands - 1];
}

int main() {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
