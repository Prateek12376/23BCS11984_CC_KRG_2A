#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& nums, int k) {
  const long long MOD = 1e9 + 7;
  vector<int> cnt(31, 0);
  for (int x : nums) {
    for (int b = 0; b < 31; b++) {
      if (x & (1 << b)) cnt[b]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    long long x = 0;
    for (int b = 0; b < 31; b++) {
      if (cnt[b] > 0) {
        x |= (1LL << b);
        cnt[b]--;
      }
    }
    ans = (ans + x * x) % MOD;
  }
  return ans;
}

int main(){
  int n,k;
  cin>>n;

  vector<int> nums(n);
  for(int i=0;i<n;i++){
  cin>>nums[i];
  }

  cin>>k;

  cout<<maxSum(nums,k)<<endl;

  return 0;
}