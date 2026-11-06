#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int start,int end,int n,vector<vector<int>>& g){
    queue<int> q;
    vector<int> dist(n,-1);
    dist[start]=0;
    q.push(start);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0;i < n;i++){
            if(dist[i] == -1 && g[curr][i] == 1 ){
                dist[i] = dist[curr] + 1;
                q.push(i);
            }
        }
    }
    return dist;
} 
int main(){
    int n;
    cin >>n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n;j++) {
            cin >>g[i][j];
        }
    }
    int start,end;
    cin >>start>>end;
    start--; end--;
    vector<int> path = bfs(start, end, n,g);
    cout<<path[end];
    return 0;
}
