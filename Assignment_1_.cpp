#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> adj;
    int n = -1;
    public:
        Graph(int n){
            for(int i = 0; i<n; i++){
                adj.push_back({});
            }
            this->n=n;
        }

        void create(int e){
            int s, d;
            cout<<"Enter source and destination for each edge : "<<endl;
            for(int i=0; i<e; i++){
                cout<<"Edge "<<i<<" : ";
                cin>>s>>d;
                adj[s].push_back(d);
                adj[d].push_back(s);
            }
        }

        void displayAdjList(){
            if(n==-1){
                cout<<"Graph is not created"<<endl;
                return;
            }
            for (int i = 0; i < n; i++) {
                cout << i << "---> ";
                for(auto j:adj[i]){
                    cout<<j<<" ";
                }
                cout << endl;
            }
        }

        void DFS(int v){
            if(n==-1){
                cout<<"Graph is not created"<<endl;
                return;
            }
            if(v>=n){
                cout<<endl<<"Vertex is not present in graph"<<endl;
                return;
            }
            vector<bool> visited(n,0);
            dfs(visited,adj,v);
            cout<<endl;
        }
        
        void dfs(vector<bool> &v, vector<vector<int>> & adj, int s){
            v[s]=1;
            cout<<s<<" ";
            for(auto i:adj[s]){
                if(!v[i]){
                    dfs(v,adj,i);
                }
            }
        }

        void DFS_SEARCH(int v){
            if(n==-1){
                cout<<"Graph is not created"<<endl;
                return;
            }
            vector<bool> visited(n,0);
            if(dfs_search(visited,adj,0,v)){
                cout<<endl<<"Vertex "<<v<<" is present in graph"<<endl;
            }
            else{
                cout<<endl<<"Vertex "<<v<<" is not present in graph"<<endl;
            }
        }

        bool dfs_search(vector<bool> &v, vector<vector<int>> & adj, int s,int & find){
            if(s==find){
                return 1;
            }
            v[s]=1;
            bool ans = 0;
            for(auto i:adj[s]){
                if(!v[i]){
                    ans = (ans || dfs_search(v,adj,i,find));
                }
            }
            return ans;
        }

        void bfs(int v){
            if(n==-1){
                cout<<"Graph is not created"<<endl;
                return;
            }
            if(v>=n){
                cout<<endl<<"Vertex is not present in graph"<<endl;
                return;
            }
            vector<int> visited(n,0);
            queue<int> q;
            q.push(v);
            cout<<v<<" ";
            visited[v]=1;
            while(!q.empty()){
                int s = q.front();
                q.pop();
                for(auto i:adj[s]){
                    if(!visited[i]){
                        visited[i]=1;
                        cout<<i<<" ";
                        q.push(i);
                    }
                }
            }
            cout<<endl;
        }
};

int main(){ 
	Graph * g = nullptr;  
	while(1){
		cout<<"\n\n******Graph******\n";
		cout<<"1. Create Graph"<<endl;
		cout<<"2. BFS traversal"<<endl;
		cout<<"3. DFS traversal"<<endl;
		cout<<"4. Display adjacency list"<<endl;
        cout<<"5. Search for a vertex"<<endl;
		cout<<"0. End"<<endl;
		cout<<"Enter choice: ";
		int m; cin>>m;
		if(m==1){
			int n;
			cout<<"Enter number of vertices in the graph : ";
			cin>>n;
			g = new Graph(n);

			cout<<"Enter number of edges in your graph : ";
			cin>>n;
			g->create(n);
		}
		else if(m==2){
			cout<<"Enter the vertex for initiating BFS : ";
			int n; cin>>n;
			g->bfs(n);
		}
		else if(m==3){
			cout<<"\nEnter the vertex for initiating DFS : ";
			int n; cin>>n;
			g->DFS(n);
		}
		else if(m==4){
			g->displayAdjList();
		}
        else if(m==5){
			cout<<"\nEnter the vertex : ";
			int n; cin>>n;
			g->DFS_SEARCH(n);
		}
		else if(m==0){
			break;
		}
		else{
			cout<<"\nEnter valid choice"<<endl;
		}
	}
	delete g;
	return 0;
}


/*
#Output

******Graph******        
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex   
0. End
Enter choice: 1
Enter number of vertices in the graph : 5
Enter number of edges in your graph : 7
Enter source and destination for each edge : 
Edge 0 : 0 1
Edge 1 : 0 4
Edge 2 : 1 4
Edge 3 : 1 3
Edge 4 : 3 4
Edge 5 : 3 2
Edge 6 : 1 2


******Graph******
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex
0. End
Enter choice: 2
Enter the vertex for initiating BFS : 2
2 3 1 4 0 


******Graph******
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex
0. End
Enter choice: 3

Enter the vertex for initiating DFS : 2
2 3 1 0 4 


******Graph******
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex
0. End
Enter choice: 4
0---> 1 4 
1---> 0 4 3 2
2---> 3 1
3---> 1 4 2
4---> 0 1 3


******Graph******
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex
0. End
Enter choice: 5

Enter the vertex : 3

Vertex 3 is present in graph


******Graph******
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex
0. End
Enter choice: 5

Enter the vertex : 7

Vertex 7 is not present in graph


******Graph******
1. Create Graph
2. BFS traversal
3. DFS traversal
4. Display adjacency list
5. Search for a vertex
0. End
Enter choice: 0

*/