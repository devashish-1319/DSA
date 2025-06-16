//Doubt in this question

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Count how many 2s in prefix and suffix
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        // Build prefix array
        if (a[0] == 2) {
            prefix[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (a[i] == 2) {
                prefix[i]++;
            }
        }

        // Build suffix array
        if (a[n - 1] == 2) {
            suffix[n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1];
            if (a[i] == 2) {
                suffix[i]++;
            }
        }

        // Find smallest k such that prefix[k - 1] == suffix[k]
        int answer = -1;
        for (int k = 1; k < n; k++) {
            if (prefix[k - 1] == suffix[k]) {
                answer = k;
                break;
            }
        }

        cout << answer << endl;
    }

    return 0;
}
