// https://leetcode.com/problems/two-sum/

//T.C = O(N logN)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n= nums.size();
//         vector<pair<int,int>> temp;
//         for(int i=0;i<n ;i++){
//             temp.push_back({nums[i],i});
//         }
//         sort(temp.begin(),temp.end());

//         for(auto i=0,j=n-1; i<j;){
//             int sum = temp[i].first + temp[j].first;
//             if(sum == target) return {temp[i].second, temp[j].second};
//             else if(sum < target) i++;
//             else j--;
//         }
//         return {-1,-1};
//     }
// };


// T.C = > O(N logN) or O(N^2) becaure mp can take worst T.C of O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int el= target - nums[i];
            if(mp.find(el)!=mp.end()){
                return {i,mp.find(el)->second};
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};