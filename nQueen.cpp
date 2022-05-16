#include<bits/stdc++.h>

using namespace std;

bool find(vector<vector<int>>&ans,vector<vector<int>>temp,vector<int>back,vector<int>col,vector<int>slash,int n,int i){
    bool f=0;
    for(int j=0;j<n;++j){
        if(col[j]==0 && back[i-j+n-1]==0 && slash[i+j]==0){
        col[j]=1;back[i-j+n-1]=1;slash[i+j]=1;
        temp[i][j]=1;
        f= f || find(ans,temp,back,col,slash,n,i+1);
        temp[i][j]=0;
        col[j]=0;back[i-j+n-1]=0;slash[i+j]=0;
        }
    }
    if(i==n){
        ans=temp;
        return 1;
    }
    return f;
}

int main(){
    int n;
    cout<<"Enter the number of columns: ";
    cin>>n;
    vector<vector<int>>ans;
    vector<int>back(2*n,0);vector<int>slash(2*n,0);
    vector<int>col(n,0);
    vector<vector<int>>temp;
    for(int i=0;i<n;++i){
        vector<int>u;
        for(int j=0;j<n;++j){
            u.push_back(0);
        }
        temp.push_back(u);
    }
    if(find(ans,temp,back,col,slash,n,0)){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"There is no solution"<<endl;
    }
    return 0;
}