#include<bits/stdc++.h>
using namespace std;


class Graph{
    set<vector<int>> edgeList;
    vector<int> v;
    vector<int> s;
    vector<vector<int>> finalAns;
    int n,e;
    public:
        Graph(int n,int e){
            this->n = n; this->e=e;
            vector<int> a(n);
            vector<int> b(n,1);
            s = b;
            v = a;
            for(int i = 0; i<n; i++){
                v[i]=i;
            }
        }
        
        void inputGraph(){
            cout<<"Enter weight and end points of edges(v1 v2): "<<endl;
            while(e--){
                int e,a,b;
                cin>>e>>a>>b;
                edgeList.insert({e,a,b});
            }
        }
        void displayGraph(){
            for(auto i: edgeList){
                cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            }
        }

        int find_(int b){
            int a = b;
            while(a!=v[a]){
                a = v[a];
            }
            return v[b]=a;
        }
        void union_(int x,int y){
            if(s[x]<s[y]){
                v[x]=y;
                s[y]+=s[x];
            }
            else{
                v[y]=x;
                s[x]+=s[y];
            }
        }
        
        void ans(){
            for(auto i:edgeList){
                int x = find_(i[1]);
                int y = find_(i[2]);
                if(x!=y){
                    finalAns.push_back(i);
                    this->union_(x,y);
                }
            }
        }
        void displayAns(){
            for(auto i: finalAns){
                cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
            }
        }
};

int main(){
    Graph g(4,5);
    g.inputGraph();
    g.ans();
    cout<<endl;
    g.displayGraph();
    cout<<endl;
    g.displayAns();
}