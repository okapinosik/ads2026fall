#include <bits/stdc++.h>
using namespace std;


int binary(const vector<int>& a,int x){
    int l = 0;
    int r = a.size() - 1;

    while(l <= r){
        int mid = l + (r-l) /2;
        
        if(a[mid] == x ){
            return mid;
        } else if (a[mid] < x ){
            l = mid + 1;
        } else {
            r = mid -1;
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin >>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin >>a[i];
    }
    cin >>x;

    int res = binary(a,x);

    if(res == -1 ){
        cout<<"No";
    } else {
        cout<<"Yes";
    }
    return 0;
}