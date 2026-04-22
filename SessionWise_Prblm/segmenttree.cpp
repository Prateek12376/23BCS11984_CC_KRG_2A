#include<bits/stdc++.h>
using namespace std;
 vector<int> seg;
 void bulid(int ind,int low,int high,vector<int>&arr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    bulid(2*ind+1,low,mid,arr);
    bulid(2*ind+2,mid+1,high,arr);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
int query(int ind,int low,int high,int l,int r){
        if(r<low || l>high) return 0;
        if(l<=low && r>=high) return seg[ind];
        int mid=(low+high)/2;   
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return max(left,right);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(4*n);
    bulid(0,0,n-1,arr);
    int q;
    cin>>q;
    while(--q){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
}