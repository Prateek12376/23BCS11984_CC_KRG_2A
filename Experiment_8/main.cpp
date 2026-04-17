class Solution {
public:

    int n, k;
    vector<int>memo;

    int solve(vector<int>&arr, int i){
        if(i >= n) return 0;

        if(memo[i]!=-1) return memo[i];

        int mx = INT_MIN;
        int ans = INT_MIN;
        int j = i;

        while(j < i+k && j<n){
            mx = max(mx, arr[j]);
            ans = max(ans, mx * (j-i+1) + solve(arr, j+1));
            j++;
        }

        return  memo[i] = ans;

    }

    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        n = arr.size();
        k = K;
        memo.resize(n, -1);
        return solve(arr, 0);
    }
};