#include<bits/stdc++.h>
using namespace std;
int mxpay(vector<vector<int>> v){
    int n=v.size();
    int ans=0;
    vector<vector<int>> d(n,vector<int> (3));
    //for ith day d[i][0]=skip, d[i][1]=local, d[i][2]=non-local
    for(int i=0;i<n;i++){
        if(i==0){
            d[0][0]= 0;
            d[0][1]= v[0][0];
            d[0][2]= v[0][1];
        }
        else{
        d[i][0]=max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
        d[i][1]=max(d[i-1][0],max(d[i-1][1],d[i-1][2]))+v[i][0];
        d[i][2]=d[i-1][0]+v[i][1];
        }
    }
    ans=max(d[n-1][0],max(d[n-1][1],d[n-1][2]));
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int> (2));
    //vector<int> a;
    for(int i=0;i<n;i++){
        /*
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        a.push_back(y);
        v.push_back(a);
        a.clear();
        */
        cin>>v[i][0]>>v[i][1];
    }
    cout<<mxpay(v);
    return 0;
}