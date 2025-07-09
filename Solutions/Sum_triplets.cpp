#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > findTriplets(vector<int> arr, int n, int K) {
    // Sort the array
    sort(arr.begin(), arr.end());

    vector<vector<int> > ans;

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements for the first element of the triplet
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == K) {
                ans.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicate elements for the second and third elements of the triplet
                while (left < right && arr[left] == arr[left + 1]) {
                    left++;
                }
                while (left < right && arr[right] == arr[right - 1]) {
                    right--;
                }

                // Move the pointers
                left++;
                right--;
            } else if (sum < K) {
                left++;
            } else {
                right--;
            }
        }
    }

    return ans;
}
