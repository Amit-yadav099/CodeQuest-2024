//This is the Leetcode POTD of 26th November

// Find Champion- II

// problem link:-https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26

// Intution:- we need to search for the that node who doesn't defeated by the anyone
// Indirectly we want to find that node whose in-degreaa is zero 
// and if we find more than one node whose in-degree is zero , then return -1

// the conventional way to do is to use the concept of the graph to find the in-degree for all the possible nodes.
// but we haven't studied graph yet , we are going to do it by using the 1D array

// in 1D array of size n , we intialzie it with zero 
// when wwe get a new edge[a,b] we simply increae the count of arr[b] by 1
// finally we check if the (ans[i]==0). we increase our count

// if count==1  it is the required answer
// else return -1;

#include<bits/stdc++.h>
using namespace std;

int findChampion(int n, vector<vector<int>>& edges) {
   
vector<int>Indegree(n,0);//vector to maintain the count of indegree of each node(0 to n-1)
   for(int i=0;i<edges.size();i++){
    int a=edges[i][0];
    int b=edges[i][1];
    Indegree[b]++;
   } 

   int count=0;
   int champion=-1;
   for(int i=0;i<Indegree.size();i++){
    if(Indegree[i]==0){
        count++;
        champion=i;
    }
}
return (count >1 ? -1: champion);   
    }

int main(){
 int  n = 4;
 vector<vector<int>> edges = {{0,2},{1,3},{1,2}};
 
 cout<<findChampion(n,edges);
 
return 0;
}