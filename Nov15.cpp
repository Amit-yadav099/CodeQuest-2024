// this is the leetcode POTD of 15th November

// Shortest Subarray to be Removed to Make Array Sorted

// problem link:-https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=daily-question&envId=2024-11-15


// Intution:- the appoach is preety simple, first we find the monotonic non-decreasuing from the start and then find the it again form the end
// then we need to compare btween  themselves to ge the final answer
#include<bits/stdc++.h>
using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
int n=arr.size();
stack<int>st1;//to store first monotonic sequence


for(int i=0;i<n;i++){
    if(st1.empty()){
     st1.push(arr[i]);
    }
    else {
        if(!st1.empty() && st1.top()<=arr[i]){
            st1.push(arr[i]);
           }
        else break;
        }
}
if(st1.size()==n)return 0;

vector<int>final;//to store the second monontonic form the end
final.push_back(arr[n-1]);
for(int j=n-2;j>=0;j--){
     if(arr[j+1]>=arr[j]){
    final.push_back(arr[j]);
    }
    else break;
    }

reverse(final.rbegin(),final.rend());//reverse it get the right order


int ans=max(st1.size(),final.size());//intializie it wih max of size of both the monotonic sequence

while(!st1.empty()){
    if(st1.top()>final.back()){//it means the top value of stack is ourt of bound for any of the values of the final aaray  
        st1.pop();
    }
    else {
        //here we ge the any top value of stack is less than the first value of the array then what we do is to take the final size and break the loop
        if(!st1.empty() && st1.top()<=final[0]){
            int size=st1.size();
            int montonic2=size+final.size();
            ans=max(ans,montonic2);
            break;
        }
        //else we count manully for each index the max possible pair
        int count=0;
      for(int i=0;i<final.size();i++){
        if(!st1.empty() && st1.top()<=final[i]){
           count++;
        }
      }
      int size=st1.size();
      ans=max(ans,size+count);
      st1.pop();
    }
}
return n-ans;
}

