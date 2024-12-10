//this is the leetcode POTD of the December 11

// Find the longest Special Substring That Occurs-1

// Intution:-as the constraint are very small 
// what we can do is to find all the possible substring contianing the same elements and
//  store their count in the  unordered map 

// then we need to give the final traversal in the map , and check if the count of any stored string is more than or equal to 3 , 
// then we need to update the special length


#include<bits/stdc++.h>
using namespace std;

//T.C=O(2*N)
int maximumLength(string s) {

    unordered_map<string,int>mp;//to stroe the count of the each of the possible substring

    int count=1,j;
    string subString="",currString="";
    subString+=s[0];
    for(int i=1;i < s.length() ;i++){
     //when the current character and the previous character of the subString doesn't match 
     if(s[i]!=subString[0] ){
       
    //then we need to maintian thr count of the all possible substring
        currString=subString[0];
        j=subString.size();
        mp[subString]++;
        //maintian the count of the all possible substring stored in the subString string
        while(currString.size()<subString.size() && j>0){
         mp[currString]+=j;
         currString+=subString[0];
         j--;
        }
        subString=s[i];
     }
    else  subString+=s[i];
    }

//finaly  added the lastly stored subString in the map 
    currString=subString[0];
    mp[subString]++;
    j=subString.size();
        while(currString.size()<subString.size() && j>0){
         mp[currString]+=j;
         currString+=subString[0];
         j--;
        }

    //traversal in the map and when ge the count equals to or greater than 3 , simply update the longestSpecial
 int longestSpecial=-1;
 for(auto it: mp){
    cout<<it.first<<" "<<it.second<<endl;
  if(it.second>=3){
    j=it.first.size();
    longestSpecial=max(j,longestSpecial);
  }
 }
 return longestSpecial;
}


int main(){
 string s="abcccccdddd";
 cout<<maximumLength(s);
 
return 0;
}