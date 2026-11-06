#include <bits/stdc++.h>
using namespace std;

void merge(vector<string>& a,int l , int m,int r){
    vector<string> t;
    int i=l,j=m+1;
    while(i<=m && j<=r){
        if(a[i].size()<=a[j].size()) t.push_back(a[i++]);
        else t.push_back(a[j++]);
    }
    while(i<=m) t.push_back(a[i++]);
    while(j<=r) t.push_back(a[j++]);  
    for(int k=0;k<t.size();k++) a[l+k] =t[k];
}

void ms(vector<string>& a,int l,int r){
    if(l>=r) return;
    int m=(l+r)/2;
    ms(a,l,m);
    ms(a,m+1,r);
    merge(a,l,m,r);
}
int main(){
    int n;
    cin >>n;
    cin.ignore();
    while(n--){
        string line,s;
        getline(cin,line);
        stringstream ss(line);
        vector<string> a;
        while(ss >>s) a.push_back(s);
        if(!a.empty()) ms(a,0,a.size()-1);
        for(int i=0;i<a.size();i++){
            if(i>0) cout<<' ';
            cout<<a[i];
        }
        cout<<'\n';
    }
}