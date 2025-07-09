//finds both the leftmost and right most occurance of target in the array
int binarysearch(vector<int> &nums,int target,bool issearchingleft){
    int left=0;
    int right=nums.size()-1;
    int id=-1;
    while(left<=right){
        int mid=left + (right-left)/2;
        if(nums[mid]>target){
            right=mid-1;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            id=mid;
            if(issearchingleft){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
    }
    return id;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int left=binarysearch(nums,target,true);
    int right=binarysearch(nums,target,false);
    return {left,right};
}