//this is the leetcode POTD of 9th of december

//specail Array-II

// problem link:-https://leetcode.com/problems/special-array-ii/description/?envType=daily-question&envId=2024-12-09

// Intution- here form the question we can see we need to fidn the special array
// this can easily be done by the line sweep algorithm or difference araay method with the slight modification

// so what we do is we take an vector of size n, named as lineSweep intialze all values by '1' 
// when we get the condition of parity for given index i, we do (lineSweep[i]=lineSweep[i-1]+1)
// else we moved for the next index


#include<bits/stdc++.h>
using namespace std;

vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

 //by the line sweep algorithm 
    int n=nums.size();
     vector<int>lineSweep(n,1);//take a line sweep space
     
     for(int i=1;i<n;i++){
        if(nums[i]%2!= nums[i-1]%2){//when get the parity increase the current sweep form the (previous value+1)
            lineSweep[i]=lineSweep[i-1]+1;
        }
        }
   

//for the final check
   int m=queries.size(); 
    vector<bool>result(m,true);//take the answer array
    
    int idx1,idx2,length;
    for(int i=0;i<m;i++){
        int idx1=queries[i][0];
        int idx2=queries[i][1];
       length=idx2-idx1+1;//find the length of the special Array
      if(lineSweep[idx2]<length){//if length at the line    sweep is less than the length
        result[i]=false;
      }
    }
    return result;
    }

int main(){
 
 
 
return 0;
}