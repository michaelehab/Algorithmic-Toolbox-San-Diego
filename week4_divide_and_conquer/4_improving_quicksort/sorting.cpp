#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/* This function partitions a[] in three parts
   Part One : a[l..i] contains all elements smaller than the pivot
   Part Two : a[i+1..j-1] contains all occurrences of the pivot
   Part Three : a[j..r] contains all elements greater than the pivot */
void partition3(vector<int> &a, int l, int r, int &m1, int &m2) {
	int x = a[l];
	m1 = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			m1++;
			swap(a[i], a[m1]);
		}
	}
	swap(a[l], a[m1]);
  
	m2 = m1 - 1;
  int i = l;
  while(i < m1 && m2 >= l && m2 > i){
    if (a[m1] == a[i]) swap(a[i], a[m2--]);
		else i++;
  }
	m2++;
}

/* This function partitions a[] in three parts
   Part One : a[l..i] contains all elements smaller than the pivot
   Part Two : a[j..r] contains all elements greater than the pivot */
void partition2(vector<int> &a, int l, int r, int &j) {
  int x = a[l];
  j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m1, m2;
  partition3(a, l, r, m1, m2);

  randomized_quick_sort(a, l, m2 - 1);
  randomized_quick_sort(a, m1 + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) cin >> a[i];
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << ' ';
}
