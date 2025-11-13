#include <iostream>
#include <string>
using namespace std;

string solve(int n, string s) {
    string ans(n, '+');
    int i = 0, j = n - 1;
    int count=0;
    for (char ch : s) {
        if (ch == '0' && i <= j) {
            ans[i] = '-';
            i++;
        } 
        else if (ch == '1' && i <= j) {
            ans[j] = '-';
            j--;
        } 
        else{
            count++;
        }
    }
    while(count>0){
        ans[i]='?';
        i++;
        ans[j]='?';
        j--;
        count--;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string result = solve(n, s);
    cout << result << endl;
    return 0;
}
