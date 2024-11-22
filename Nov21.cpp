// This is the Leetcode POTD of 20th November

//count the unguarded cells in the grid

// problem link:-https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2024-11-21

#include<bits/stdc++.h>
using namespace std;

// This is simple simulation based problem , what we need is to be do the same taskas it is said to do but in more effective way

// first we take a 2D vector of graph size mXn and intialzie it with zero
// then we put all our guards and walls to  in the map to access them O(1) time

// now for every guards cooridnates (row,col), we move in all 4 directions :- 
// we move in the left direction (row,j+1 to 0)
// we move in the right direction (row ,j+1 to n)
// we move in the down direction (i to n,col)
// we move in the upward direction  (i to 1,col)


//note:- we only fill values into the graph to '1' when there is already not present a '1' into the graph.
// and when we there is guard or walls ,then we break out from that direction 
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

int totalSize=m*n;

vector<vector<int>>graph(n,vector<int>(m,0));

unordered_map<string,int>mp;
//putting walls into the map
for(int i=0;i<walls.size();i++){
    int row=walls[i][0];
    int col=walls[i][1];
    string str=to_string(row);
    str=str+'#'+to_string(col);
    mp[str]=1;
    }

//putting guards into the map 
for(int i=0;i<guards.size();i++){
    int row=guards[i][0];
    int col=guards[i][1];
    string str=to_string(row);
    str=str+'#'+to_string(col);
    mp[str]=1;
    }

int count=0;

 for(int i=0;i<guards.size();i++){
 int row=guards[i][0];
 int col=guards[i][1];

   //to move in the upward direction
   for(int i=row-1;i>=0;i--){
    //to check if there is a wall else we move bsck
    string str=to_string(i)+'#'+to_string(col);
    if(mp[str]==1){
        break;
    }
    else {
        //we check if poen already present then move ion
        if(graph[i][col]==1)continue;
        else {graph[i][col]=1;
        count++;}
     }
   }

//to move in the down direction
for(int i=row+1;i<m;i++){
    //to check if there is a wall else we move bsck
    string str=to_string(i)+'#'+to_string(col);
    if(mp[str]==1){
        break;
    }
    else {
        //we check if poen already present then move ion
        if(graph[i][col]==1)continue;
        else {graph[i][col]=1;
        count++;}
     }
   }

//to move in the left direction
for(int j=col-1;j>=0;j--){
    //to check if there is a wall else we move bsck
    string str=to_string(row)+'#'+to_string(j);
    if(mp[str]==1){
        break;
    }
    else {
        //we check if poen already present then move ion
        if(graph[row][j]==1)continue;
        else {graph[row][j]=1;
        count++;}
     }
   }

   
//to move in the right direction
for(int j=col+1;j<n;j++){
    //to check if there is a wall else we move bsck
    string str=to_string(row)+'#'+to_string(j);
    if(mp[str]==1){
        break;
    }
    else {
        //we check if poen already present then move ion
        if(graph[row][j]==1)continue;
        else {graph[row][j]=1;
        count++;}
     }
   }
}
cout<<count<<endl;
return totalSize-count-walls.size()-guards.size();
}        

int main(){
 vector<vector<int>>guards{
{0,0},{1,1},{2,3}
 };

vector<vector<int>>walls{
{0,1},{2,2},{1,4}
 };
 cout<<countUnguarded(4,6,guards,walls); 
 
return 0;
}