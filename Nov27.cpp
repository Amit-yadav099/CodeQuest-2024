//This is the leetcode POTD of 27th November

//shortest Distance after Road additon queries -I

// problem link:-https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/?envType=daily-question&envId=2024-11-27

//this is the simple problem of graph to get the shotest path in between the intial node and final node
// as all the edges are unweighted so we can use BFS to do the same.
#include<bits/stdc++.h>
using namespace std;

int BFS(int n,unordered_map<int,vector<int>>adj){
  queue<int>que;

  que.push(0);//intialize the queue

int level=0;
  vector<bool>visited(n,false);//to know that we don't need to visit anymore after visited once 
  
  while(!que.empty()){
    int size=que.size();
   while(size--){
    int node=que.front();
    que.pop();

    if(node==n-1) return level;//we rwached the destination
   
   //traversing through the vector map of the given node only  
  //  this simply show , the given vector values are on the same level
    for(int i=0;i<adj[node].size();i++){
     if(!visited[adj[node][i]]){
      que.push(adj[node][i]);
      visited[adj[node][i]]=true;}
    }
   }
  level++;
 }
return -1;
}
 


vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
 
 unordered_map<int,vector<int>>adj;
 //pushing th intailzly connceted nodes into the map of vector 
 for(int i=0;i<n-1;i++){
   adj[i].push_back(i+1);
 }


 int q=queries.size();
 vector<int>result(q,0);
 
 for(int i=0;i<q;i++){
   int u=queries[i][0];
   int v=queries[i][1];
   
   //pushing the current queries into the vector of map
   adj[u].push_back(v);
   int d=BFS(n, adj);//return the minimum steps to reach 0 to (n-1)th node
   result[i]=d;
 }

return result;
}

int main(){
 
 
 
return 0;
}