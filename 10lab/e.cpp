#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >>n>>q;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n;j++) {
            cin >>g[i][j];
        }
    }
    for(int i =0;i<q;i++){
        int x,y,z;
        cin >>x>>y>>z;
        if(a[x][y]==1 && a[][] && a[][]) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}
