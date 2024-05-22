// https://leetcode.com/problems/reverse-pairs/


//https://takeuforward.org/data-structure/count-reverse-pairs/

class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high){
        int count=0;
        bool flag=false;
        vector<int> temp;
        int left=low, right=mid+1;

        // counting reverse pair
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long ) nums[i] > (long) 2 * nums[right]) right++;
            count += (right - (mid + 1));
        }

        left=low; right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i<=high; i++){
            nums[i]= temp[i-low];
        }
        return count;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int ans = 0;
        if (low >= high) return ans;
        int mid = (low+high)/2;

        ans+= mergeSort(nums,low,mid);
        ans+= mergeSort(nums,mid+1,high);
        ans+= merge(nums,low,mid,high);

        return ans;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};