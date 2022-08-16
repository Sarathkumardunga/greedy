//Maximum number of meetings

#include<bits/stdc++.h>
//#include<vector>
using namespace std;
static bool myc(pair<int,int> p1,pair<int,int> p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second<p2.second;
}

int meetingscount(int s[],int e[], int n){
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(s[i],e[i]));
    }
    /* 
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        v[i]={s[i],e[i]};
    } 
    */
    sort(v.begin(),v.end(),myc);
    int i=0,j=1,count=1;
    while(j<n){
        if(v[i].second<v[j].first){
            i=j;
            j++;
            count++;
        }
        else{
            j++;
        }
    }
    return count;
}
using namespace std;
int main(){
    int n=6;
    int s[]={1,3,0,5,8,5},e[]={2,4,6,7,9,9};
    cout<<meetingscount(s,e,n)<<endl;
    return 0;
}