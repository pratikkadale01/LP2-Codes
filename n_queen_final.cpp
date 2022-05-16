#include<bits/stdc++.h>
using namespace std;
//branch and bound
void print(vector<vector<bool>> &b){
    int n = b.size();
    cout<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;     
    }
}

bool helper(vector<vector<bool>> &b,vector<bool> &col,vector<bool> &c1,vector<bool> &c2,int r){
    int n = b.size();
    if(r>=n) return 1;
    for(int i = 0; i<n; i++){
        if(col[i]==0 && c1[i+r]==0 && c2[r-i+n-1]==0){
            col[i] = 1;
            c1[i+r] = 1;
            c2[r-i+n-1] = 1;
            b[r][i] = 1;
            if(helper(b,col,c1,c2,r+1)){
                return 1;
            }
            col[i] = 0;
            c1[i+r] = 0;
            c2[r-i+n-1] = 0;
            b[r][i] = 0;
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<vector<bool>> b(n,vector<bool> (n,0));
    vector<bool> col(n,0);
    vector<bool> c1(2*n-1,0);
    vector<bool> c2(2*n-1,0);

    bool a = helper(b,col,c1,c2,0);
    if(!a){
        cout<<"No solution"<<endl;
    }
    else{
        print(b);
    }
}