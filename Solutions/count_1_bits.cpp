#include <iostream>
using namespace std;
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1); // Increment count if the least significant bit is 1
        n >>= 1;          // Right shift n to check the next bit
    }
    return count;
}

int main() {
    int n;
    cout<<"enter your number :"<<endl;
    cin>>n; 
    cout << "Number of 1 bits in " << n << " is " << countSetBits(n) <<endl;
    return 0;
}
