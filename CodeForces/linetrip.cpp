#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> stations(n);
        for (int i = 0; i < n; ++i) {
            cin >> stations[i];
        }

        // Build full path: 0 → a1 → a2 → ... → an → x → an → ... → a1 → 0
        vector<int> fullPath;
        fullPath.push_back(0);
        for (int a : stations) fullPath.push_back(a);
        fullPath.push_back(x);
        for (int i = n - 1; i >= 0; --i) fullPath.push_back(stations[i]);
        fullPath.push_back(0);

        // Calculate maximum distance between two consecutive points
        int maxGap = 0;
        for (int i = 1; i < fullPath.size(); ++i) {
            maxGap = max(maxGap, abs(fullPath[i] - fullPath[i - 1]));
        }

        cout << maxGap << endl;
    }

    return 0;
}
