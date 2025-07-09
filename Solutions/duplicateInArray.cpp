#include <iostream>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		int count=0;
		for(int num:arr){
			if(num<=mid){
				count++;
			}
		}
		if(count>mid){ //count se pata laga liya duplicate upper half
			e=mid-1;   //mai hai ya lower half mai
			
		}
		else{
			s=mid+1;
		}
		mid=s+(e-s)/2;
	}
	return s;
}
int main(){
    
}