#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUP(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUP(parent[node]);
    }
    void UnionBySize(int u, int v){
        int pu = findUP(u);
        int pv = findUP(v);
        if(pu==pv) return;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>> edges;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({wt,{i,j}});
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(n);
        int mst = 0;

        for(auto &it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUP(u) != ds.findUP(v)){
                mst += wt;
                ds.UnionBySize(u, v);
            }
        }

        return mst;
    }
};

int main(){
    vector<vector<int>> points = {
        {0,0},{2,2},{3,10},{5,2},{7,0}
    };

    Solution obj;
    cout << obj.minCostConnectPoints(points);
    return 0;
}