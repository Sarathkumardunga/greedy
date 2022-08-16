#include<bits/stdc++.h>
//#include<unordered_map>
using namespace std;
bool comp(pair<float,int> p1, pair<float,int> p2){
    if(p1.first==p2.first) return p1.second<p2.second;
    return p1.first>p2.first;
}
//Function to find the maxval of the knapsack of given capacity
int maxval(int val[],int wt[],int n,int w){
    float r[n];
    for(int i=0;i<n;i++){
        r[i]=((val[i]*1.0)/(wt[i]*1.0));
    }
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[wt[i]]=val[i];
    }
    vector<pair<float,int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(r[i],wt[i]));
    }
    sort(v.begin(),v.end(),comp);
    int currval=0;
    int currwt=0;
    for(int i=0;i<n;i++){
        while(currwt<=w){
            if((v[i].second+currwt)>w){
                break;
            }
            currval+=map[v[i].second];
            currwt+=v[i].second;
            i++;
        }
        int remwt=w-currwt;
        currwt+=remwt;
        currval+=remwt*(v[i].first);
        if(currwt==w){
            break;
        }
    }
    return currval;
}

int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;
    int val[n]={30,100,120};
    int wt[n]={10,20,30};
    cout<<maxval(val,wt,n,w)<<endl;
    return 0;
}