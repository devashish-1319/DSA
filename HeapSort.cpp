    //#include<iostream>
    #include<vector>
    using namespace std;
    
    //Heap Sort using min heap
    //Use max heap for descending sort
    void heapify(vector<int> &nums,int n,int i){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && nums[smallest]>nums[left]){
            smallest=left;
        }
        if(right<n && nums[smallest]>nums[right]){
            smallest=right;
        }
        if(smallest!=i){
            swap(nums[smallest],nums[i]);
            heapify(nums,n,smallest);
        }
    }
    vector<int>builtminheap(vector<int> &nums){
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        return nums;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int>result;
        int n=nums.size();
        builtminheap(nums);
        for(int i=n-1;i>=0;i--){
            result.push_back(nums[0]);
            nums[0]=nums[i];
            heapify(nums,i,0);
        }
        return result;
    }