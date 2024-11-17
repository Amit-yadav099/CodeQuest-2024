//this is the leetcode POTD of the 17th november

// problem link:-https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/?envType=daily-question&envId=2024-11-17

// Intution:-

#include<bits/stdc++.h>
using namespace std;

// Intution:the main thing to understand here is whenever there is curr commulative sum is less then the previous commulative sum , then it means there is no use of the previous positive values for the subaaray formation
// so ,if there is any ditch , it means we need to consider the values after the ditch , no relevance of before ditch values now  

//method-01 by the sliding window with the monotonic deque 
int shortestSubarray(vector<int>& nums, int k) {
int n=nums.size();

int result=INT_MAX;

deque<int>deq;//to stores the indexed of the monotonic increasing order of commulation

vector<long long>commulativeSum(n,0);//this stores the commulative sum

int j=0;
while(j<n){
  if(j==0){
    commulativeSum[j]=nums[j];
  }
  else{
  commulativeSum[j]+=commulativeSum[j-1]+nums[j];
}

if(commulativeSum[j]>=k){
result=min(result,j+1);
}

//to shrink the window or not
while(!deq.empty() && commulativeSum[j]-commulativeSum[deq.front()]>=k){
result=min(result,j-deq.front());//tak the minimum value
deq.pop_front();//pop it form drck
}

//we also need to put the values in the monotonic nature into deq
 while(!deq.empty() && commulativeSum[j]<=commulativeSum[deq.back()]){
  deq.pop_back();//for there is the smaller commulative sum, we pop it as no relevance of the positive values before the negative values
 }
 deq.push_back(j);//usual condition always execute
 j++;
 }

if(result==INT_MAX)return -1;
else return result;
}
   

int main(){
 vector<int>nums{
84,-37,32,40,95
 };
int k=167;
 cout<<shortestSubarray(nums,k);
 
 
return 0;
}