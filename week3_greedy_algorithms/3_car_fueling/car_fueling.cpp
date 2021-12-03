#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> stops) {
    // If a full tank can reach the final destination, there's no need to refill
    if(tank >= dist) return 0;
    // Tracking the current position and the number of refills
    int at = 0, refills = 0;
    while(at < dist){
        // Finding the furthest station possible
        int new_stop = *(upper_bound(stops.begin(), stops.end(), (at + tank)) - 1);
        if(new_stop > at){
            at = new_stop;
            refills++;
            if(at + tank >= dist) return refills;
        }
        // If we can't find another station it's impossible to reach the destination
        else return -1;
    }
    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
