#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &table, int &n, int i, int j){
    for(int k = 0; k<i; k++){
        if(table[k][j]==1){
            return 0;
        }
    }
    int k = i-1;
    int l = j-1;
    while(k>-1 && l>-1){
        if(table[k][l]==1){
            return 0;
        }
        k--;l--;
    }
    k = i-1;
    l = j+1;
    while(k>-1 && l<n){
        if(table[k][l]==1){
            return 0;
        }
        k--;
        l++;
    }
    return 1;
}

bool fun(vector<vector<int>> & table, int &n, int i){
    if(i>=n){
        return 1;
    }
    for(int k = 0; k<n; k++){
        if(isSafe(table,n,i,k)){
            table[i][k]=1;
            if(fun(table,n,i+1)) return 1;
            table[i][k]=0;
        }
    }
    return 0;
}


bool funCount(vector<vector<int>> & table, int &n, int i,int &count){
    if(i>=n){
        return 1;
    }
    for(int k = 0; k<n; k++){
        if(isSafe(table,n,i,k)){
            table[i][k]=1;
            if(funCount(table,n,i+1,count)){
                for(auto i: table){
                    for(auto j: i){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                } 
                cout<<endl;   
                count++;
            }
            table[i][k]=0;
        }
    }
    return 0;
}

void nQueen(int n){
    vector<vector<int>> table(n, vector<int> (n,0));
    int count = 0;
    funCount(table,n,0,count);
    bool a = fun(table,n,0);
    if(!a){
        cout <<endl<< "Solution does not exist"<<endl;
        return;
    }
    /*for(auto i: table){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    cout<<endl<<"Count: "<<count<<endl;
}

int main(){
    while(true){
        cout<<"1:Enter the value of n"<<endl;
        cout<<"2:End"<<endl;
        int x; cin>>x;
        if(x==1){
            cout<<"Enter: ";
            int n; cin>>n;
            nQueen(n);
        }
        else if(x==2){
            return 0;
        }
        else{
            cout<<endl<<"Enter correct input"<<endl;
        }
        cout<<"****************************************************"<<endl;
    }
    return 0;   
}