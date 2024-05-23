//https://www.interviewbit.com/problems/subarray-with-given-xor/
//https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/

int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int,int> mp;
    mp[0]++;
    int count=0;
    int xors=0;
    for(int i=0;i<A.size();i++){
        xors = xors ^ A[i];
        if(mp.find(xors^B) != mp.end()) count+= mp.find(xors^B)->second;
        mp[xors]++;
    }
    return count;
}


// or
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}