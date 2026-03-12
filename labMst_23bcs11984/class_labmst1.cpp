#include<bits/stdc++.h>
using namespace std;


int find_maxP(vector<int>nums, int maxOp){
  int l=1;
  int r= INT_MIN;
  int ans=-1;
  for(int i=0;i<nums.size();i++){
    r=max(r,nums[i]);
  }
  while(l<r){
    int mid = l+ (r-l)/2;
    int op=0;
    for(int x : nums){
      op+=(x-1)/mid;
    }
    if(op<=maxOp){
      ans= mid;
      r=mid-1;
    }
    else{
      l=mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int>nums={2,4,8,2};
  int maxOp=4;
  int rs=find_maxP(nums,maxOp);
  cout<<rs;
  return 0;
}