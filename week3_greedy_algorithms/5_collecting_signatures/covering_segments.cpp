#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

struct right_align {
    inline bool operator() (const Segment& seg1, const Segment& seg2) {
        return (seg1.end < seg2.end);
    }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), right_align());
  int current_right = segments[0].end;
  points.push_back(current_right);
  for(int i = 1; i < segments.size(); i++){
    if(segments[i].start > current_right){
      points.push_back(segments[i].end);
      current_right = segments[i].end;
    }
  }
  return points;
}

int main() {
  int n;
  cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) 
    cin >> segments[i].start >> segments[i].end;

  vector<int> points = optimal_points(segments);

  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) 
    cout << points[i] << " ";
}
