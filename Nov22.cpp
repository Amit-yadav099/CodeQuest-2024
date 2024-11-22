// This is the leetcode POTD of november 23

//flip Columns for Maximum Number of equal rows

// problem link:-https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/?envType=daily-question&envId=2024-11-22

// Intution:-the main thing is tounderstand that wwe nned to observe the pattern in order to do thing.
// so, we use '*' and '#'to impllement the pattern of the zeroes and ones
// here is for the better understnading:-
// Each row's pattern is determined by grouping contiguous blocks of identical values. For instance:

// Row [0, 0, 0, 1, 1, 0, 0]  produces the pattern:* * * # # * *
// Row [0, 1, 1, 1, 1, 1, 0] produces the pattern: * # # # # # *
// The solution is simply the frequency of the most common pattern across all rows in the matrix.



#include<bits/stdc++.h>
using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
     
    unordered_map<string,int>mp;

    for(int i=0;i<matrix.size();i++){
        string str="*";//intialize with the *
        for(int j=1;j<matrix[i].size();j++){
         //case-01 if the value of the previous and current are same
          if(matrix[i][j-1]==matrix[i][j]){
            str+=str[str.size()-1];
          }
          else {
         //if the value of the previous and current are not same 
             if(str[str.size()-1]=='*')str+='#';//if the last value is '*' then we add '#' 
             if(str[str.size()-1]=='#')str+='*';//if the last value is '#' then we add '*'
          } 
        }
        mp[str]++;
    }
int count=0;
for(auto it:mp){
count=max(count,it.second);
}
return count;
}

int main(){
 
 
 
return 0;
}