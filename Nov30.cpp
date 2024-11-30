// This is the leetcode POTD of 30th november

//valid arrrangement of pairs

// problem link:-https://leetcode.com/problems/valid-arrangement-of-pairs/?envType=daily-question&envId=2024-11-30

//here are doing it wih tthe help of max and minheap

// this graph problem revolve around the euler path

// Eulerian paths have a couple of conditions:
// In an undirected graph, either all nodes have an even degree, or exactly two have an odd degree.
// In a directed graph (which is what we have here), we need to check if:
    // Each node’s outDegree matches its inDegree.
   // Or, exactly one node has one more outgoing edge (outDegree = inDegree + 1), which indicates our starting point.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

// step-01 build the adjacency list-graph
unordered_map<int,vector<int>>adj;


// step-02 build indegree and out degree of the nodes
// we use unordered_map 
unordered_map<int ,int> Indegree , Outdegree ;
// key-> node 
// value->in-deg / out-deg

//populate the adjacent matrix
for(auto & edge :pairs){
int x= edge[0];
int y= edge[1];

  adj[x].push_back(y);// we make a edge form u to v ie., u---> v
  Outdegree[x]++;
  Indegree[y]++;
}

int startNode=pairs[0][0];//take randomly

//step-03 find the start node of the euler path
   for(auto & it:adj){
   int node=it.first;
  //check for the starting point condition
  if(Outdegree[node]-Indegree[node]==1){
   startNode = node;
   break;//as we got our starting point
  }
}

 //now we do the khadanin DFS by the stack

 vector<int>EulerPath;//to store my eulerpath
 stack<int>st;//to perform DFS

 st.push(startNode);
 
 while(!st.empty()){
 int curr=st.top();
 
  if(!adj[curr].empty()){
    //it means there are stil neighbouring connecting nodes are present in adjacency list for the current node
  int neighbour=adj[curr].back();
  adj[curr].pop_back();// now pop it out ,as it has been counted
  st.push(neighbour);
  }
  else{
    //it means there is no neighbour left right now , 
    // so it is ready to put it into the euler path list
    EulerPath.push_back(curr);
    st.pop();
  }
}
//reverse it to get the right order
reverse(EulerPath.begin(),EulerPath.end());

//build the result
vector<vector<int>>result;

 for(int i=0;i<EulerPath.size()-1;i++){
 //we need to make pair
 result.push_back({EulerPath[i],EulerPath[i+1]});
 }
return result;
}
int main(){
 
 
 
return 0;
}