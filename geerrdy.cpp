//Greedy Minimum platforms gfs
#include<bits/stdc++.h>
using namespace std;
int minplatforms(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int count=1;
    int i=1,j=0;
    while(i<n){
        if(arr[i]<dep[j]){
            count++;
        }
        else{
            j++;
        }
        i++;
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int arr[]={1,2,6,8};
    int dep[]={5,9,7,10};
    cout<<minplatforms(arr,dep,n);
    return 0;
}