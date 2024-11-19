//This is the leetcode POTD of 19th November

// maximum sum of Distinct subaarays of length 'K'

// problem link:-https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19

#include<bits/stdc++.h>
using namespace std;

// Intution:-as per the problem , this is the standard problem of the sliding window 
// step-01 Here we are using the unordered_set ,by which we would chekc if whether multiple occurence of an element into the current window
// step-02 if we don't get the element into the set , then we need to insert into the set
// step-03 finally we need to check if wre get the desired window size , then we compare and save into the answer and update the ith pointer and set adn currSUm
//   

long long maximumSubarraySum(vector<int>& nums, int k) {
unordered_set<int>newSet;
long long ans=0;
long long currSum=0;

int i=0,j=0;
while(j<nums.size()){
    //   step-01
    //to check if nums[j] is already present in the set or not
    // if it is present , then we need to erase the values from the set and  move the ith pointer 
    while(newSet.count(nums[j])){
        currSum-=nums[i];
        newSet.erase(nums[i]);
        i++;
    } 

// step-02
 //it means nums[j] is the fresh element so, we need to insert it into the set and update the currSum 
    currSum+=nums[j];
    newSet.insert(nums[j]);


// step-03
 //now finally we need check for the window size and update i pointer and currSum
 if(j-i+1==k){
    ans=max(ans,currSum);//take the answer

    currSum-=nums[i];//update the currSum
    newSet.erase(nums[i]);//update the set
    i++;//move the ith pointer
 }
j++;
}

return ans;
}


int main(){
    vector<int>nums{5,3,3,1,1};
    int k=3;
cout<<maximumSubarraySum(nums,k);

}

