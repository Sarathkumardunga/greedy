#include<bits/stdc++.h>
using namespace std;
string lexosmall(string s){
    set<char> u;
    for(int i=0;i<s.length();i++){
        u.insert(s[i]);
    }
    char ch1,ch2;
    for(int i=0;i<s.length();i++){
        if(u.size()==0) break;
        u.erase(s[i]);
        if(s[i]<*u.begin()){
            continue;
        }
        else if(s[i]>*u.begin()){
            ch1=s[i];
            ch2=*u.begin();
            break;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==ch1){
            s[i]=ch2;
        }
        else if(s[i]==ch2){
            s[i]=ch1;
        }
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    string ans=lexosmall(s);
    cout<<ans<<endl;
    return 0;
}