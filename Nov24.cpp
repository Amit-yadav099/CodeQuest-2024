//This is the Leetcode POTD of 24th November

// Maximum Matrix Sum

// problem link:-https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2024-11-24

// observation: we got to know that negative sign  can transfer to any of the element of the intire 2D martrix
//so ,we try to give to an (absolute lowest number) to get the maixmum result sum

// Intution:-we maintain the count of the negative values present in the 2D vector
// and we select the minimum absloute value of the 2D vector
// and we take the absolute sum of the all of the 2D vector


// if we get the count of negative numbers is even , then they can cancel each other effect
// if count od negative number is odd, means we need to give it to absolute minimuum value  

#include<bits/stdc++.h>
using namespace std;
//function to return the miinimum value between a and b 
long long minimum(long long a , long long b){
    if(a>b)return b;
    else return a;
  }

    long long maxMatrixSum(vector<vector<int>>& matrix) {
       long long sum=0;//to calculate sum

       long long count=0;//to consider count
       
       long long absoluteMin=INT_MAX;//to get the  absolute minimum value

       int n=matrix.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]<=0){
                count++;
            }
        absoluteMin=minimum(absoluteMin,abs(matrix[i][j]));
            sum+=abs(matrix[i][j]);
        }
       }

    if(count%2!=0){//if count is odd , we need to subtract the sum by the 2*absolutemin value
       return sum-2*absoluteMin;
    }
    else return sum; //count is even , so we don't need to do any subtraction, as all negative can cancel each other.
 }
