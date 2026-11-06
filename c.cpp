#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int a,int b){
    queue<int> q;
    vector<int> dist(20001,-1);
    vector<int> parent(20001,-1);
    dist[a]=0;
    q.push(a);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int x2=curr*2;
        int m1=curr-1;
        if(x2 >= 1 && x2 <= 20000 && dist[x2] == -1 ){
            dist[x2] = dist[curr] + 1;
            parent[x2] = curr;
            q.push(x2);
        }
        if(m1 >= 1 && m1 <= 20000 && dist[m1] == -1 ){
            dist[m1] = dist[curr] + 1;
            parent[m1] = curr;
            q.push(m1);
        }
    }
    return parent;
} 
int main(){
    int a,b;
    cin >>a>>b;
    vector<int> path;
    if(a==b){
        cout<<0;
        return 0;
    }
    vector<int> parent = bfs(a,b);
    path.push_back(b);
    int cur = parent[b];
    while(cur != a){
        path.push_back(cur);
        cur= parent[cur];
    }

    reverse(path.begin(),path.end());
    cout<<path.size()<<"\n";
    for(int& x : path){
        cout<<x<<" ";
    }
    return 0;
}
