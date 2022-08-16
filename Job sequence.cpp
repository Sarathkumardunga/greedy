//Job sequence sum
#include<bits/stdc++.h>
using namespace std;
static bool comp(pair<int,int> p1,pair<int,int>p2){
    return p1.first>p2.first;
}
pair<int,int> maxprofit(vector<vector<int>> v){
    pair<int,int> ans;
    int n=v.size();
    vector<pair<int,int>> t;

    for(int i=0;i<n;i++){
        t.push_back(make_pair(v[i][2],v[i][1]));
    }
    sort(t.begin(),t.end(),comp);
    bool done[n]={0};
    int mxprof=0;
    int count=0;
    for(int j=0;j<n;j++){
        for(int i=min(n,t[j].second-1);i>=0;i--){
            if(done[t[i].second-1]==0){
                mxprof+=t[i].first;
                done[t[i].second-1]=1;
                count++;
                break;
            }
        }
    }
    ans.first=count;
    ans.second=mxprof;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    int ji,dl,pf;
    vector<int> k;
    for(int i=0;i<n;i++){
        cin>>ji>>dl>>pf;
        k.push_back(ji);
        k.push_back(dl);
        k.push_back(pf);
        v.push_back(k);
        k.clear();
    }
    pair<int,int> p=maxprofit(v);
    cout<<p.first<<" "<<p.second;
    return 0;
}