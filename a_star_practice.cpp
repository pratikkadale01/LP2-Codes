#include<bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 4
typedef pair<int,int> Pair;
typedef pair<double,pair<int,int>> pPair;

bool is_valid(int r,int c){
    return (r>-1 && r<ROW && c>-1 && c<COL);
}

bool is_unblocked(int grid[][COL],int r,int c){
    return grid[r][c];
}

bool is_destination(int r,int c,Pair dest){
    return (r==dest.first && c==dest.second);
}

double calc_h_value(int r,int c,Pair dest){
    double a = (double)(sqrt((r-dest.first)*(r-dest.first)+(c-dest.second)*(c-dest.second)));
    return a;
}

class cell{
    public:
        int par_i,par_j;
        double f,g,h;
        cell(){
            par_i=-1;
            par_j=-1;
            f = FLT_MAX;
            g=FLT_MAX;
            h = FLT_MAX;
        }
};

void tracePath(cell cellDetails[][COL], Pair dest){
    int i = dest.first;
    int j = dest.second;
    stack<Pair> st;
    while(cellDetails[i][j].par_i!=i || cellDetails[i][j].par_j!=j){
        st.push({i,j});
        int a = i;
        i = cellDetails[i][j].par_i;
        j = cellDetails[a][j].par_j;
    }
    st.push({i,j});
    while(!st.empty()){
        cout<<" ("<<st.top().first<<" ,"<<st.top().second<<") ->";
        st.pop();
    }
}

void aStarSearch(int grid[][COL],Pair src,Pair dest){
    if(!is_valid(src.first,src.second)){
        cout<<"Source not valid"<<endl;
        return ;
    }
    if(!is_valid(dest.first,dest.second)){
        cout<<"Destination not valid"<<endl;
        return ;
    }
    if(!is_unblocked(grid,src.first,src.second) && !is_unblocked(grid,dest.first,dest.second)){
        cout<<"Source or destination is blocked"<<endl;
        return ;
    }
    if(is_destination(src.first,src.second,dest)){
        cout<<"Source is destination"<<endl;
        return ;
    }
    vector<vector<bool>> closeList(ROW,vector<bool> (COL,0));

    set<pPair> openList;
    openList.insert({0.0,{src.first,src.second}});

    cell cellDetails[ROW][COL];

    cellDetails[src.first][src.second].f = 0;
    cellDetails[src.first][src.second].g = 0;
    cellDetails[src.first][src.second].h = 0;
    cellDetails[src.first][src.second].par_i = src.first;
    cellDetails[src.first][src.second].par_j = src.second;

    while(!openList.empty()){
        pPair p = *openList.begin();
        openList.erase(openList.begin());
        int i = p.second.first;
        int j = p.second.second;
        closeList[i][j] = 1;

        vector<int> dir = {1,0,-1,0,1,1,-1,-1,1};
        for(int k = 1; k<9; k++){
            int c_i = i+dir[k-1];
            int c_j = j+dir[k];

            if(is_valid(c_i,c_j) && is_unblocked(grid,c_i,c_j)){
                int g_new = cellDetails[i][j].g;
                if(k<5)
                    g_new += 1.0;
                else
                    g_new += 1.414;
                int h_new = calc_h_value(c_i,c_j,dest);
                int f_new = g_new+h_new;
                if(is_destination(c_i,c_j,dest)){
                    cellDetails[c_i][c_j].par_i = i;
                    cellDetails[c_i][c_j].par_j = j;
                    cellDetails[c_i][c_j].g = g_new;
                    cellDetails[c_i][c_j].h = h_new;
                    cellDetails[c_i][c_j].f= g_new + h_new;
                    tracePath(cellDetails,dest);
                    return;
                }
                if(!closeList[c_i][c_j]){
                    if(cellDetails[c_i][c_j].f==FLT_MAX || cellDetails[c_i][c_j].f > f_new){
                        openList.insert({f_new,{c_i,c_j}});
                        cellDetails[c_i][c_j].par_i = i;
                        cellDetails[c_i][c_j].par_j = j;
                        cellDetails[c_i][c_j].g = g_new;
                        cellDetails[c_i][c_j].h = h_new;
                        cellDetails[c_i][c_j].f= f_new;
                    }
                }
            }
        }
    }
    cout<<"Solution not found"<<endl;
}

int main(){
    int grid[ROW][COL] = {
        {1,1,1,0},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,1}
    };
    
	Pair src = {2, 3};

	Pair dest = {0, 0};

	aStarSearch(grid, src, dest);

	return (0);
}