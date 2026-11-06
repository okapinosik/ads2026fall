#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
vector<int> dist(20001,inf);

void bfs(int v,vector<vector<int>>&  g){
    queue<int> q;
    dist[v]=0;
    q.push(v);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int x : g[curr]){
            if(dist[x] > dist[curr] + 1){
                dist[x]=dist[curr]+1;
                q.push(x);
            }
        }
    }
} 
int main(){
    int n,m,q;
    cin >>n>>m>>q;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<q;i++){
        int c,v;
        cin >>c>>v;
        if(c == 1){
            bfs(v,g);
        } else{
            if(dist[v] == inf) cout<<-1<<"\n";
            else cout<<dist[v]<<"\n";
        } 
    }
    return 0;
}
