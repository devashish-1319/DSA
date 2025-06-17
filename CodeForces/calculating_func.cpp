#include<iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long evenCount = n / 2;
    long long oddCount = n - evenCount;

    long long sum = evenCount * (evenCount + 1) - oddCount * oddCount;

    cout << sum << endl;
    return 0;
}
