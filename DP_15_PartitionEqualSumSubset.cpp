//Problem - https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980


// LOGIC
/*
if we found sum/2 or one subset whose sum is equal to half of totalSum, then we can say Array can be equally partioned into two subset
*/

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> front(k+1,0);
    vector<bool> curr(k+1,0);

    for(int i=0;i<n;i++) front[0]= true;
    front[arr[0]] = true;
    for(int ind=1; ind<n; ind++){

        for(int target=1; target<=k; target++){
            bool not_take= front[target];
            bool take = false;

            if (target >= arr[ind]) {
                take =  front[target- arr[ind]];
            }
            curr[target]= not_take || take;
        }
        front = curr;
    }
    return front[k];
}


bool canPartition(vector<int> &arr, int n)
{
    int totalSum = 0;
    for(int i=0;i<n;i++) totalSum+= arr[i];
    if(totalSum %2) return false;

    int target = totalSum/2;
	return subsetSumToK(n,target,arr);
}
