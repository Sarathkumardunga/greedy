//Max Stocks
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.first==p2.first) return p1.second>p2.second;
    return p1.first<p2.first;
}

int maxstocks(int prices[],int n,int k){
    int ce=0;
    int count=0;
    vector<pair<int,int>> v;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(prices[i],i+1));
    }
    sort(v.begin(),v.end(),comp);
    int i=0;
    while(i<n && (ce+v[i].second*v[i].first)<=k){
        ce+=v[i].second*v[i].first;
        count+=v[i].second;
        i++;
    }
    if(ce==k) return count;
    int t=1;
    while(t<v[i].second){
        if((ce+t*v[i].first)>k) return count;
        else{
            ce+=(t*v[i].first);
            count+=1;
        }
        t++;
    }
    return count;
}
int main(){
    int n=3;
    int k=45;
    int prices[]={7,10,4};
    cout<<maxstocks(prices,n,k)<<endl;
    return 0;
}