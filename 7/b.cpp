#include <bits/stdc++.h>
using namespace std;

int gdc(int a,int b){
    while(b!=0){
        int r =a%b;
        a=b;
        b=r;
    }
    return a;
}


int main(){
    int n,m;
    cin >>n>>m;
    cout<<gdc(n,m);
}