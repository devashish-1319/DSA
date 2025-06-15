#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int cnt_minus = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == -1) cnt_minus++;
        }

        int cnt1 = n - cnt_minus;
        int sum = cnt1 - cnt_minus;

        int ops = 0;

        // Flip -1 to 1 until sum ≥ 0
        while(sum < 0){
            ops++;
            cnt_minus--;  // flipping one -1
            sum += 2;
        }

        // After sum is good, ensure product is good (even -1 count)
        if(cnt_minus % 2 == 1){
            ops++;  // flip one more -1
        }

        cout << ops << endl;
    }
    return 0;
}
