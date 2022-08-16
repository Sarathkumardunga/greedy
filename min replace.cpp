#include<bits/stdc++.h>
using namespace std;

int minreplace(int arr[],int n){
    set<int> check;
    for(int i=0;i<n;i++){
        check.insert(arr[i]);
    }
    if(check.size()==1){
        return 0;
    }
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    int ans=0;
    int i=n-1;
    while(i>0){
        if(arr[i]>=arr[i-1]){
            if(map[arr[i]]>1){
                ans+=1;
                map[arr[i]]=1;
            }
            i--;
        }
        else{
            break;
        }
    }
    set<int> s;
    for(int k=0;k<i;k++){
        s.insert(arr[k]);
    }
    return ans+s.size();

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<minreplace(a,n)<<endl;
    return 0;
}