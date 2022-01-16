#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  // DP table size [str1+1][str2+1]
  vector <vector<int>> table((str1.length() + 1), vector <int> (str2.length() + 1));

  for (int i = 0; i <= str1.length(); i++) {
      for (int j = 0; j <= str2.length(); j++) {
          // If str1 is empty we insert all str2
          if (i == 0) table[i][j] = j;

          // If str2 is empty we insert all str1
          else if (j == 0) table[i][j] = i;

          // If the last letter in str1 and str2 is the same 
          // ignore it and get the result from the remaining string
          else if (str1[i - 1] == str2[j - 1]) table[i][j] = table[i - 1][j - 1];

          // If the last letter in str1 and str2 is different get the min of insertion, deletion, replacement
          else table[i][j] = 1 + min({table[i][j - 1], table[i - 1][j],  table[i - 1][j - 1]});
        }
    }

    return table[str1.length()][str2.length()];
}

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
