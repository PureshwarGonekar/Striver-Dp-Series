// https://www.naukri.com/code360/problems/three-sum_6922132?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=SUBMISSION

// #include <unordered_map>
// #include <set>

//T.C = > O(N2 x log N)
//S.C = > O(N) [for hashmap] + O(no of unique triplet)
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    
    set<vector<int>> st;
    for(int i=0; i<n;i++){
        unordered_map<int,int> mp;
        for(int j=i+1; j<n; j++){
            int elk = - (arr[i]+arr[j]);
            if(mp.find(elk)!=mp.end()){
                vector<int> triplet({arr[i],arr[j],elk});
                sort(triplet.begin(), triplet.end());
                st.insert(triplet);
            }
            else{
                mp[arr[j]]++;
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end() );
    return ans;
}


// T.C = > O(N log N) + O(NxN) => sorting and inner loops
// S.C => O(no of unique triplet)
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end() );
    for(int i=0; i<n;i++){

        if(i > 0 && arr[i]== arr[i-1]) continue;
        int j= i+1;
        int k= n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if (sum > 0){
                k--;
            }
            else{
                vector<int> temp({arr[i], arr[j], arr[k]});
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]== arr[j-1]) j++;
                while(j<k && arr[k]== arr[k-1])k--;
            }
        }
    }
    return ans;
}

