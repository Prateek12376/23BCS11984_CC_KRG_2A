#include<bits/stdc++.h>
using namespace std;

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


// approach ==> Normal approach of dijsktra will fail here because , here there are stops limmit is also there , if we conider like that , suppose we are reaching in greater dist path but not reaching with small dist ,, but dijksta uses condition always distance less than current then only consider 

  // if(cost+adjC<dist[adjNode] && stops<=k){ here the distance will already low , then it will prevent futher , if dist  is hight at that pount but over all it take less cost with in step
  //   dist[adjNode]=cost+adjC;
  //   pq.push({dist[adjNode],adjNode,stops+1});
  // }                                                 this condition will prevent the ans due to stops given
// thats why we use dijsktra 

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<flights.size();i++){
        int price = flights[i][2];
        int u = flights[i][0];
        int v = flights[i][1];
        adj[u].push_back({v,price});
    }
    vector<int>dist(n,INT_MAX);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,src,0});    // {stops,node,cost}  ,,, here giving imp to stops to overcome the above condition fault that prevents  to take the lower cost over all  , due to more cost of stop than already present
    dist[src]=0; 
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it[1];
        int cost = it[2];
        int stops= it[0];
        if(stops>k){
            continue;
        }
        for(auto s : adj[node]){
            int adjNode = s.first;
            int adjC  = s.second;
            if(cost+adjC<dist[adjNode] && stops<=k){
                dist[adjNode]=cost+adjC;
                pq.push({stops+1,adjNode,dist[adjNode]});
            } 
        }
    }
    if(dist[dst]==INT_MAX){
        return -1;
    }
    return dist[dst];
}

int main() {
    int n = 5;
    vector<vector<int>> flights = {
        {0, 1, 5},
        {1, 2, 5},
        {0, 3, 2},
        {3, 1, 2},
        {1, 4, 1},
        {4, 2, 1}
    };

    int src = 0;
    int dst = 2;
    int k = 2;

    int result = findCheapestPrice(n, flights, src, dst, k);
    cout << result << endl;

    return 0;
}