//this is the leetcode POTD of 20th November

//take K of each character from left and right 

//problem link:-https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

// Intution:-first we need to maintain the count of all characters 'a', 'b' and 'c'
// if we don't get any of the count is greater than or equals to 'K' then return -1


// if the count is more than or equals to 'K' then we need to pwrform the sliding window approach 
// where we need to maximize the window , provided the comdition of count >=k must not break
#include<bits/stdc++.h>
using namespace std;
int takeCharacters(string s, int k) {

vector<int>count(3,0);
for(int i=0;i<s.size();i++){
    if(s[i]=='a') count[0]++;
    else if(s[i]=='b')  count[1]++;
    else count[2]++;
}

if(count[0]<k || count[1]<k || count[2]<k){
    return -1;
}

int minutes=s.size();
//now we need to perform the sliding window
   int i=0,j=0;
   int currwindow=0;
   int maxWindow=0;
   while(j<s.size()){
    //now we need to increase the size until the unfavourable condition
    if(count[s[j]-'a']>=k ){
        count[s[j]-'a']--; 
    currwindow++;
    }
    //now we need to shrink it  
    if(count[s[j]-'a']<k){
     while(i<=j && count[s[j]-'a']!=k){
        count[s[i]-'a']++;
        i++;
     currwindow--;
     }
    }
    j++;
    maxWindow=max(maxWindow,currwindow); //update the maxWindow window
    }
    return minutes-maxWindow;
      }
    
int main(){
 
 
 
return 0;
}