// This is the leetcode POTD of 16th November

// problem link:https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/submissions/1454470456/?envType=daily-question&envId=2024-11-16

// Intution:it can be done by the sliding window of winodw size ='K' but we are using the brute force approach as the constraints are low
// we simply maintai a vector array and we iterate for the each of the index  if the power of that window is possible then we put the maximum element into the array else we put '-1'

#include<bits/stdc++.h>
using namespace std;

vector<int> resultsArray(vector<int>& nums, int k) {
       int first,second;
        int size=nums.size();
        if(k==1) return nums;//if size of k=1 , then the given array is the required answer

        vector<int>result(size-k+1,-1);//vector to store the answer array

        for(int i=0;i<=size-k+1;i++){
        first=i,second=i+1;//here we take the first two indexes
        int count=1;
        while(count<k && second<size){//we maintian the count until it becomes equals to 'K' and second is less then size of the array

      if(nums[second]-nums[first]==1){//if power od the array condition satisifed then we continue it else we break it
        second++;
        count++;
        first++;
        }
        else break;//here we break it
        }

        if(count==k){//if count is equals to required window size 'K' then simply return it 
        result[i]=nums[first];
        }
     }
return result;
        }