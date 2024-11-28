//this is the leetcode POTD of 28th November 

// Minimum obstacles remove to reach the corner

//probelm link:-https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/?envType=daily-question&envId=2024-11-28

//this can be by the dijakstra algorithm

//here we are using the minheap , and for every next possible outcomes.
// we need to go to next direction having low wieghts(direction at the top of minehap)

#include <bits/stdc++.h>
using namespace std;

int minimumObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Directions for moving in the grid
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Min-heap priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    // Distance array to store minimum obstacles to reach each cell
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = grid[0][0]; // Start from the top-left corner
    pq.push({dist[0][0], {0, 0}}); // Push the starting point into the priority queue
    
    while (!pq.empty()) {
        int obstacles  = pq.top().first;
        int cellRow=pq.top().second.first;
        int cellCol=pq.top().second.second;
        pq.pop();
        int x = cellRow;
        int y = cellCol;
        
        // If we reach the bottom-right corner, return the result
        if (x == n - 1 && y == m - 1) {
            return obstacles;
        }
        
        // Explore neighbors
        for (int i=0;i<directions.size();i++) {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;
            
            // Check for valid position
            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                int newObstacles = obstacles + grid[newX][newY];
                
                // If we found a path with fewer obstacles, update and push to the queue
                if (newObstacles < dist[newX][newY]) {
                    dist[newX][newY] = newObstacles;
                    pq.push({newObstacles, {newX, newY}});
                }
            }
        }
    }
    
    return dist[n - 1][m - 1]; // Return the minimum obstacles to reach bottom-right corner
}

int main(){
  
}