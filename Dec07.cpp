//this is the leetcode POTD of 7th of December

//Minimum limits of balls in the bag

// problem link:-https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/


// similar questions are :- koko eating bananas , minimize the maximum distribution on the retail stores

// Intution:-agin here we need to minimize the maximum element , thus it indicates to use the concept of biaray sesrch on the answer 
// one more thing remember is that we can use the operations at max maxOperations times

#include<bits/stdc++.h>
using namespace std;


//fucntion to check whether we can able to divide with for the given mid value in less then or equal to maxOperations 
bool solve(int mid ,vector<int>nums,int maxOperations){

//note:- we can use the operatiosn at most maxoperation times
int operationRequired=0;
for(int i=0;i<nums.size();i++){
    int maxdistribution=(nums[i]+mid-1)/mid;
    // as for the n distribution , we need exactly (n-1) operations to do so
    operationRequired+=maxdistribution-1;
  if(operationRequired>maxOperations)  return false;
   }
   return true;
}

int minimumSize(vector<int>& nums, int maxOperations) {

 int start=1;//smallest divsion possible
 int end=*max_element(nums.begin(),nums.end());//largest division possible 
 int ans=end;  

 //as we need to minimize the result , when we ge the answer  , we gonna save it and move to smaller valeu for the check else we check for the larger value
 while(start<=end){
int mid=start+(end-start)/2;
    if(solve(mid,nums,maxOperations)){
      ans=mid;
      end=mid-1;//as we need to minimize the result
    }
    else {
 start=mid+1;//we need to chek for the larger value
    }
 }   
 return ans;
    }
int main(){
vector<int>nums{
7,17
};
int maxOperations = 2; 
 cout<<minimumSize(nums,maxOperations);
 
return 0;
}