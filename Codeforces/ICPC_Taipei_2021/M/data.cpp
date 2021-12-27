#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<pair<ll,ll>> vt;
int main(){
    ll m,n;
    cin>>m>>n;
    ll a[m][n];
    for(ll i=0;i<m;i++)
    for(ll j=0;j<n;j++) cin>>a[i][j];
    ll s,f,r;
    cin>>s>>f>>r;
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++) if(a[i][j]!=s) continue;
        else{
            ll check_f;
            ll check_r;
            // Huong 1
            if(i-1<0) check_f = 0; else check_f = a[i-1][j];
            if(j+1>n-1) check_r = 0; else check_r = a[i][j+1];
            if(f==check_f && r==check_r) vt.push_back({i,j});
            // Huong 2
            if(j+1>n-1) check_f = 0; else check_f = a[i][j+1];
            if(i+1>m-1) check_r = 0; else check_r = a[i+1][j];
            if(f==check_f && r==check_r) vt.push_back({i,j});
            // Huong 3
            if(i+1>m-1) check_f = 0; else check_f = a[i+1][j];
            if(j-1<0) check_r = 0; else check_r = a[i][j-1];
            if(f==check_f && r==check_r) vt.push_back({i,j});
            // Huong 4
            if(j-1<0) check_f = 0; else check_f = a[i][j-1];
            if(i-1<0) check_r = 0; else check_r = a[i-1][j];
            if(f==check_f && r==check_r) vt.push_back({i,j});
        }
    }
    sort(vt.begin(),vt.end());
    for(auto p: vt){
        cout<<p.first<<" "<<p.second<<'\n';
    }
}
