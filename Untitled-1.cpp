#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> v;
    int N=3,M=2;
    
    vector<int> f={5,2,7,9,11};
    int n=f.size();
    vector<int> b={2,8,6,12,1};

    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[b[i]]=f[i];
    }
    vector<int> d;
    
    for(int i=0;i<n;i++){
        d.push_back(f[i]-b[i]);
    }
    
    for(auto i:d){
        cout<<i<<" ";
    }
    
    vector<int> a;
    for(int i=0;i<n;i++){
        a.push_back(d[i]);
        a.push_back(b[i]);
        v.push_back(a);
        a.clear();
    }
    
    
    cout<<"SORT\n"<<endl;
    sort(v.begin(),v.end());
    for(auto i:d){
        cout<<i<<" ";
    }
     for(int i=0;i<n;i++){
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    }
    
    for(int i=0;i<n;i++){
        v[i][0]=map[v[i][1]];
    }
   
    int sum=0;
    int k=0;
    while(N>0){
        sum+=v[k][0];
        N--;
        k++;
    }
    while(M>0){
        sum+=v[k][1];
        M--;
        k++;
    }
    cout<<"sum is:"<<sum<<endl;

    
    return 0;

}