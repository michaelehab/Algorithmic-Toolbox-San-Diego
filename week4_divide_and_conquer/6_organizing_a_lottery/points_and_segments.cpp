#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

vector<ll> fast_count_segments(vector<ll> starts, vector<ll> ends, vector<ll> points) {
  vector<ll> cnt(points.size());

	vector<pair<ll, ll>> arr;
	unordered_map<ll, ll> counts;

	for (auto i : starts) arr.push_back(make_pair(i, 0));
  for (auto i : ends) arr.push_back(make_pair(i, 2));
	for (auto i : points) arr.push_back(make_pair(i, 1)); 

	sort(arr.begin(), arr.end());

	ll overlap = 0;
	for (auto i : arr) {
    if (i.second == 0) overlap++;
		else if (i.second == 2) overlap--;
		else counts.insert(make_pair(i.first, overlap));
	}

	for (ll i = 0; i < points.size(); i++) cnt[i] = counts[points[i]];
	return cnt;
}

int main() {
  ll n, m;
  cin >> n >> m;
  
  vector<ll> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) cin >> starts[i] >> ends[i];

  vector<ll> points(m);
  for (size_t i = 0; i < points.size(); i++) cin >> points[i];

  vector<ll> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) cout << cnt[i] << ' ';
}
