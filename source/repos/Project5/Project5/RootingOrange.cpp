class Solution {
   /* int distance[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int minutes =0;
        queue<pair<int,int>>rotten;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1)
                    fresh++;
                else if(grid[i][j] == 2)
                        rotten.push({i,j});
            }
        }
        
        while(!rotten.empty() && fresh >0){
            
            for(int rot =0; rot<rotten.size();++rot){
                auto it = rotten.front();
                int i = it.first;
                int j = it.second;
                rotten.pop();
                for(int index=0;index<4;++index){
                    int id = i + distance[index][0];
                    int jd = j + distance[index][1];
                    if(id>=0 && jd>=0 && id<grid.size() && jd<grid[0].size() && grid[id][jd] == 1){
                        grid[id][jd] = 2;
                        rotten.push({id,jd});
                        --fresh;
                    }     
                }
            }
            if(!rotten.empty()) ++minutes;
        }
        if(fresh > 0)
            return -1;
        else
            return minutes;
    }*/
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int r = grid.size(), c = grid[0].size(), fresh = 0, t = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 2) rotten.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        while(!rotten.empty()){
            int num = rotten.size();
            for(int i = 0; i < num; ++i){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                if(x > 0 && grid[x-1][y] == 1){ grid[x-1][y] = 2; fresh--; rotten.push({x-1, y});};
                if(y > 0 && grid[x][y-1] == 1){ grid[x][y-1] = 2; fresh--; rotten.push({x, y-1});};
                if(x < r-1 && grid[x+1][y] == 1){ grid[x+1][y] = 2; fresh--; rotten.push({x+1, y});};
                if(y < c-1 && grid[x][y+1] == 1){ grid[x][y+1] = 2; fresh--; rotten.push({x, y+1});};
            }
            if(!rotten.empty()) t++;
        }
        return (fresh == 0) ? t : -1;
    }
};
