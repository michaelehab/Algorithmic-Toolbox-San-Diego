#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

struct Point {
  ll x, y;
};

// Returns the distance between two pts P1(x1, y1) and P2(x2, y2)
double dist(Point p1, Point p2) {
  return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

// Returns the minimal distance between a set of pts O(N^2) [Max : 3 pts]
double simple_minimal_distance(Point *P, int n) {
  double min_d = 1e18;
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      min_d = min(min_d, dist(P[i], P[j]));
    }
  }
  return min_d;
}

// Returns true if P1's x coordinate is smaller than P2's
bool compareX(Point &p1, Point &p2) {
    return (p1.x < p2.x);
}

// Sort a part of the array in ascending order based on its x coordinates
void sort_by_x(Point * arr, int n){
  sort(arr, arr + n, compareX);
}

// Returns true if P1's y coordinate is smaller than P2
bool compareY(Point &p1, Point &p2) {
    return (p1.y < p2.y);
}

// Sort a part of the array in ascending order based on its y coordinates
void sort_by_y(Point * arr, int n){
  sort(arr, arr + n, compareY);
}

// Returns the Minimal Distance between any set of points
double minimal_distance(Point *pts, int n) {
  if (n < 4) return simple_minimal_distance(pts, n);

  // Finds the minimal distance in both left and right halves
  int mid = n / 2;
  Point midPoint = pts[mid];
  double dl = minimal_distance(pts, mid);
  double dr = minimal_distance(pts + mid, n - mid);
  double d = min(dl, dr);

  // Creates a strip region that has all the points closer than d
  Point *strip = new Point[n];
  int strip_n = 0;
  for (int i = 0; i < n; ++i)
    if (abs(pts[i].x - midPoint.x) < d)
      strip[strip_n++] = pts[i];

  // Checks if there's any distance in the strip smaller than d
  double min_d = d;
  sort_by_y(strip, strip_n);
  for (int i = 0; i < strip_n; i++)
    for (int j = 1; j < 7; j++)
      min_d = min(min_d, dist(strip[i], strip[i + j]));
  delete []strip;

  return min_d;
}

int main() {
  int n;
  cin >> n;
  ll x, y;
  Point *pts = new Point[n];
  for(int i = 0; i < n; ++i) {
      cin >> x >> y;
      pts[i] = {x, y};
  }

  sort_by_x(pts, n);
  cout << fixed;
  cout << setprecision(9) << minimal_distance(pts, n) << "\n";

  delete []pts;
  return 0;
}