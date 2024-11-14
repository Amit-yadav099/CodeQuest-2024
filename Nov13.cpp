// this is the leetcode POTD of november 13th

// problem link:-https://leetcode.com/problems/count-the-number-of-fair-pairs/description/

// Intution:- first we need to sort the array to get the range of values
// then get the newlower and newupper for the each values of the array 
// then we individually new range of indexes for the lower and the upper values
// finally we find the original index values from the map 

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int target,vector<int>&nums,int sign){

int ans;
int start=0;
int end=nums.size()-1;
if(sign<0){//for the lower bound
ans=end;
while(start<=end){
    int mid=start+(end-start)/2;
    if(target<=nums[mid]){
        ans=min(ans,mid);
        end=mid-1;
    }
    else start=mid+1;
}
}
else {//for the upper bound
ans=start;
while(start<=end){
    int mid=start+(end-start)/2;
    if(target>=nums[mid]){
        ans=max(ans,mid);
        start=mid+1;
    }
    else end=mid-1;
}

}
return ans;
};

long long countFairPairs(vector<int>& nums, int lower, int upper) {

unordered_map<int,int>index;
for(int i=0;i<nums.size();i++){
    index[i]=nums[i];
}

   sort(nums.begin(),nums.end());
 
    int n=nums.size();
    int i=0;
    long long count=0;
    while(i<nums.size()){
      //now we need to search for the lower range and the upper range
     int low=lower-nums[i];
     int up =upper-nums[i];
    
    //function to get the modified lower and upper range
    int newlower=binarySearch(low,nums,-1);
    int newUpper=binarySearch(up,nums,1);

    //to only the pairs for which the values of 
    for(int j=newlower;j<=newUpper;j++){
        if(i<j){
            if(lower<=nums[i]+nums[j] && nums[i]+nums[j]<=upper){
            // cout<<i<<j<<"\n";
            count++;
            }
         }
    }    
    i++;
    }
return count; 
}
 