#include <bits/stdc++.h>
using namespace std;

struct Node{
    int nxt[3];
    bool end;
    Node(){
        nxt[0]=nxt[1]=nxt[2]=-1;
        end=false;
    }
};

vector<Node> trie(1);

void insert(string &s){
    int node=0;
    for(char c:s){
        int x=c-'a';
        if(trie[node].nxt[x]==-1){
            trie[node].nxt[x]=trie.size();
            trie.push_back(Node());
        }
        node=trie[node].nxt[x];
    }
    trie[node].end=true;
}

bool dfs(int node,string &s,int pos,bool changed){
    if(pos==s.size()) return changed && trie[node].end;

    int x=s[pos]-'a';

    for(int i=0;i<3;i++){
        if(trie[node].nxt[i]==-1) continue;

        if(i==x){
            if(dfs(trie[node].nxt[i],s,pos+1,changed)) return true;
        }else{
            if(!changed){
                if(dfs(trie[node].nxt[i],s,pos+1,true)) return true;
            }
        }
    }

    return false;
}

int main(){
 

    int n,m;
    cin>>n>>m;

    string s;

    for(int i=0;i<n;i++){
        cin>>s;
        insert(s);
    }

    while(m--){
        cin>>s;
        if(dfs(0,s,0,false)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
