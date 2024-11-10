//this is the leecode POTD
// conecpt used here is :-  bit manipualtion with sliding window 

// this is the problem link:-https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/?envType=daily-question&envId=2024-11-10


//the main thing to get to know about bitwise OR is that it is always non decreasing and bitwise AND is just its reverse  

//here we got to know about to how to update the bit values stored in the vector and how to convert that values into decimal form
//the main thing here is how to reduce the window size ,to do this we must know how to reach to the ith bit position of a given number 
#include<bits/stdc++.h>
using namespace std;


void addInWindow(int number,vector<int>&vec){

    for(int i=0;i<32;i++){
        // by using the right shift operator
        if(((number >> i)& 1) !=0){
     //(number >> i) it means given number ki ith bit pe chle jaana aur pta krna ki vha '1' hai ya '0'
    //  on taking AND with '1', we get to know that at that ith position , bit is definitely 1 

      vec[i]++;//so we update vec[i] value at that point by 1             
        }
    }
}
  
void removeFromWindow(int number ,vector<int>&vec){
    for(int i=0;i<32;i++){
        if(((number>>i) &1)!=0){
         //it means at the ith position ,bit is high , sowe need to decrease it by 1 beacuse we are shrinking the data
         vec[i]--;
        }
    }
}

int decimalValue(vector<int>&vec){
int num=0;
for(int i=0;i<32;i++){
    if(vec[i]>0){
       //means ith position me at lest onr set bit high hai
       num =num | (1 << i);//update the nums  
    }
}
return num;
}

int minimumSubarrayLength(vector<int>& nums, int k) {
    int n=nums.size();

    int result=INT_MAX;
    int i=0;
    int j=0;
    vector<int>vec(32,0);
    //vec[i] represnts the total number of set bits(no. of '1' bit values) in its position

//now the regular sliding window template 
    while(j<n){

    //to add value in the window i.e, to add value in the vec
    addInWindow(nums[j],vec);
     
     //decimal value function  to return the decimal equivalent value present in vec and if it greater than K, then we need to shrink the window size  
    while(i<=j && decimalValue(vec)>=k){
    
    //update the result each time with the window size
    result=min(result,j-i+1);
    removeFromWindow(nums[i],vec);//function to remove the values form vec and also form the current window
    i++;
    }
//the upper loops remains continue until we got the equivalent decimal value of vec is not greater than or equal to k , then we search for new window size
j++;
    }
    
if(result==INT_MAX)return -1;//means we don't any required  window size for the current array nums
else return result; 
    }


