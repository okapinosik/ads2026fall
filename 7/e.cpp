#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin >>r>>c;
    int counter=0;
    vector<vector<int>> a(r,vector<int>(c));
    queue<pair<int, int>> q;
    int mushrooms = 0;
    for(int i =0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >>a[i][j];
            if (a[i][j] == 2) {
                q.push({i, j});
            }
            if (a[i][j] == 1) {
                mushrooms++;
            }
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    bool changed =false;
    while(!q.empty()){
        int s =q.size();
        changed =false;
        for (int i = 0; i < s; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
        for(int j=0;j<4;j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
            if (a[nx][ny] == 1) {
                a[nx][ny] = 2;
                changed = true;
                q.push({nx, ny});
                mushrooms--;
            } 
        }   
    } 
}

    if(changed==true) counter++;
    }
    if(mushrooms > 0) cout<<"-1";
    else cout<<counter;
    return 0;
}