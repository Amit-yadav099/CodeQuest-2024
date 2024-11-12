//this is the Lettcode POTD of 12th November

// problem link:-https://leetcode.com/problems/most-beautiful-item-for-each-query/?envType=daily-question&envId=2024-11-12


//Most beautiful item for the Each query

// Intution:- This problem is quite simple , what we do is to sort the items 2D vector 
        // then , we stoe the prices with its maximum value of beuty into vector pair to avoid the double values of prices

    //   method-01  we can make the vector of size (maximum beauty) and fills the values are per the reuired result
    // drawback of this method is ,for the large values of max beauty we cannot make such size of vector   
    
    // method-02 as ,we know this the data present in our vector pair is in the sorted order , so for the monotoic data set ->we can think of the binary seach. and before that we store the maximum beauty in the beauty part of every index 0<='i'<items.size()
    // so,here we would implment binary seach to do the task
    // T.C=O(max(nlogn, plogz),where
    //  n->size of items vector
    //  p->soze of query vector
    //  z->size of vector pair

#include<bits/stdc++.h>
using namespace std;

//custom binary search function to do the bianry serach in order to get the maximum beauty
// if given query is less than the lowest price ,then it returns zero 
// if given query is greater than the maximum price ,then it returns maximum beauty ,present at the last index 
int binarySeach(int target,vector<vector<int>> & storage){
  int ans=0;
  int start=0;
  int end=storage.size()-1;
 while(start<=end){
   int mid=start+(end-start)/2;
    if(target>=storage[mid][0]){
      ans=max(ans,storage[mid][1]);
      start=mid+1;
    }
    else {
        end=mid-1;
    }
 }
 return ans;
 }

vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n=queries.size();
   
   //we need to sort the  items vector
   sort(items.begin(),items.end());


//here we are setting the maxBeauty till each index form the start of the 2D vector till that index
//we are doing it in originalspace,so no extra space is being used 
int maxBeauty=items[0][1];
for(int i=1;i<items.size();i++){
maxBeauty=max(items[i][1],maxBeauty);
items[i][1]=maxBeauty;
}
   
//now here we are using the binary search to get the needed beauty for each query

vector<int>result;//to store the resultant values
 
 for(int i=0;i<queries.size();i++){
 int target=queries[i];
 //fucntion call to do the required task
  result.push_back(binarySeach(target,items));

 }
return result;
}


