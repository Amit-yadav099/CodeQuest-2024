// this is the leetcode POTD of 29th November

// problem link:-https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/?envType=daily-question&envId=2024-11-29

// this is again the simple problem of the graph inclduing minheap and we need to get the minimum timw to reach form cell [0][0]  to cell [n-1][m-1]

// this can be done by Dijaksatra  but the only problem is that we can go back form the previous places to spend some time more until get eligible for the current cell
// so waht we can do is calculate the time requireed to reach that cell(callled as needtime)
// result implementation is given with explalantion
#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int, int>>//to make pair eaiser to write

//for 4 -direction traversal
int rows[4] = {0, 0, 1, -1};
int cols[4] = {-1, 1, 0, 0};


// possible cases:-
// 01. when the currTime is greater than grid time , then we need to simply push (currTime +1) for the current cell
// else when the currTime is less than gridTime
// 02. we calculte the need time , if is even then push gird[x][y]+1
//  03. if needtime is odd, then push grid[x][y]


int minimumTime(vector<vector<int>> &grid)
{    // of we get gird[1][0]  and gird[0][1] is greater than '1' then we cannot able to reach to any other node
     if(grid[0][1]>1 && grid[1][0]>1){
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();

    priority_queue<P, vector<P>, greater<P>> pq;
    
    //visited vector => to get to know that the given cell is already visited or not
    vector<vector<bool>>visited(n,vector<bool>(m,false));


    pq.push({grid[0][0], {0, 0}});//first node push

   int currentTime,currRow,currCol;
   //again khandani template of the dijakstra
    while (!pq.empty())
    {
         currentTime = pq.top().first;
         currRow = pq.top().second.first;
         currCol = pq.top().second.second;
        
        pq.pop();

        // if we reach bottom right corner then return currentTime till now
        if (currRow == n - 1 && currCol == m - 1)
        {
            return currentTime;
        }

        if(visited[currRow][currCol]){//if already visited , check for other cells 
         continue;
        }
        
        visited[currRow][currCol]=1;//make them visited

        for(int i=0;i<4;i++){
            int x= currRow + rows[i];
            int y= currCol + cols[i];
        
        if(x>=0 && x<n && y>=0 && y<m){
            int newtime = 1 + currentTime;
            
            //when we ge the time to reach grid[x][y] is greater than actual time of grid[x][y] 
            if(grid[x][y]<=newtime){
               pq.push({newtime,{x,y}});
            }
            else {
                //we need to calculte the need time as time to rach here is less than the grid time
                // so we need to wait to waste time
                int needtime=grid[x][y]-currentTime;
                
                if(needtime%2==0) {//if there is even time-gap 
            // then we reach say gird[x][y] ,time =needtime+currentTime+1 
            //    or we can grid[x][y]+1 
                pq.push({currentTime+needtime+1,{x,y}});
                }
                else {
                    //here for odd needtime , when we reach the gird[x][y]
                    // time=currenttime+needtime or we can say grid[x][y]
                pq.push({grid[x][y],{x,y}});    
                } 
            }
         }
        }
    }
    return currentTime;
}
int main()
{  vector<vector<int>>grid{
    {0,1,3,2},{5,1,2,5},{4,3,8,6}
    };

cout<<minimumTime(grid);

    return 0;
}