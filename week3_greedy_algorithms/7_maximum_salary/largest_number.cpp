#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool GreaterOrEqual(string& a, string& b) {
  //If we put A before B it should give us a larger number then B before A.
	return(b + a < a + b);
}

string largest_number(vector<string> a) {
  stringstream salary; 
  sort(a.begin(), a.end(), GreaterOrEqual); 
  for (size_t i = 0; i < a.size(); i++) salary << a[i];
  string result;
  salary >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a);
}
