//#include <iostream>
#include<map>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int>freq;
        for(int card : hand){
            freq[card]++;
        }

        for(auto it=freq.begin();it!=freq.end();it++){
            int card=it->first;
            int count=it->second;

            if(count>0){
                for(int i=0;i<groupSize;i++){
                    int nextcard=card+i;
                    if(freq[nextcard]<count){
                        return false;
                    }
                    freq[nextcard]-=count;
                }
            }
        }
        return true;
    }
};