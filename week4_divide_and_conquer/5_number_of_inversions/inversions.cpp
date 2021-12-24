#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


// Counts the number of inversions during the merging process of the two halves
int merge(vector<int> &a, vector<int> &temp, int left, int mid, int right) {
  int i = left, j = mid, k = left; 
  ll number_of_inversions = 0;
  while ((i <= mid - 1) && (j <= right)) { 
      if (a[i] <= a[j]) temp[k++] = a[i++];
      else { 
          temp[k++] = a[j++]; 
          // Because the both parts of the array are sorted
          number_of_inversions += mid - i; 
      } 
  }
  // Filling the rest of the array
  while (i <= mid - 1) temp[k++] = a[i++]; 
  while (j <= right) temp[k++] = a[j++]; 
  for (i = left; i <= right; i++) a[i] = temp[i]; 
  
  return number_of_inversions; 
} 

// Sorts the input array (a) and returns the number of inversions in the array.
ll get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
  number_of_inversions += merge(a, b, left, ave + 1, right); 
  return number_of_inversions;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) cin >> a[i];
  vector<int> b(a.size());
  cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
