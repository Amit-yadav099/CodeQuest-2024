//this is the leetocde POTd of 14th november

// problem link:-https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=daily-question&envId=2024-11-14

#include<bits/stdc++.h>
using namespace std;

// intution:-as the question asked to minimize the maximum results  we found , 
// as here the answer 'ans' we got from the given values , we can even able to distribute the quantities  for the values greater than 'ans' too

//for the such type of problem , we use technique of binary search in the answer 
//first we get the answer , then we saved it and search for the more more value of x
// if we ddon't ge the answer , then go for the larger values


//function to check whether we are able to distribute the answer or not

bool canDistributeInPair(int n,vector<int>&nums,int mid){

for(int i=0;i<nums.size();i++){
    n=n-nums[i]/mid;
   if(nums[i]%mid)n--;

   if(n<0)return false;
}
return true;
}


int minimizedMaximum(int n, vector<int>& nums) {

int start=1;
int end=*max_element(nums.begin(),nums.end());

int ans=0;


while(start<=end){

    int mid=start+(end-start)/2;

    //function to check that can we able to distribute the quantities for the given mid value  
      if(canDistributeInPair(n,nums,mid)){
       ans=mid;
       //as we got the answer, then we searhc for the any more lower possible value 
       end=mid-1;
      }
      else {
        //as we don't get the answer for the given mid value , so we need to increase our mid value
        start=mid+1;      
     }
}
return ans;
}


