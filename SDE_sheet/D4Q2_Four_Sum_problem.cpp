#include<bits/stdc++.h>
using namespace std;

// Brute Force => O (N^4)

//Betther Approch

// int range 2,147,483,648

//TC=> O(N3 x log M) 
//SC=> O(N) + O(no of unique quadruplet)x2 [for st and for returning the answer]
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    int n= nums.size();
    set<vector<int>> st;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            unordered_map<long long,int> mp;
            for(int k=j+1; k<n;k++){
                long long sums= (long long)(nums[i]+ nums[j]) + (long long) nums[k];
                long long fourth = (long long)(target) - sums;

                if(mp.find(fourth)!=mp.end()){
                    vector<int> quadruplet({nums[i], nums[j], nums[k], (int)fourth});
                    sort(quadruplet.begin(), quadruplet.end());
                    st.insert(quadruplet);
                }
                else{
                    mp[nums[k]]=1;
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = -294967296;
    vector<vector<int>> ans = fourSum(nums, target);

    return 0;
}

//Optimal Approch

// T.C => O(N^3)
// T.C => O(no of quadrauples)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

