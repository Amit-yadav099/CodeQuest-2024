//this is the leetcode POTD of 3rd December

//Add spaces to string

// problem link:-https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03


// Intuition:= this problem is quite simpler to implement all we need to insert the spaces at the indexes present in the spaces vector.
//  to do this ,we can maintian apointer j to maintain the index of the spaes vector
// when we get the current index is present in the spaces vector , then we need to insert a space and increase the pointer j
// along with it we need to insert the current index into the given string 'ans' too.
#include<bits/stdc++.h>
using namespace std;

 string addSpaces(string s, vector<int>& spaces) {

 string ans;
 int j=0;
 for(int i=0;i<s.size();i++){
 if(j<spaces.size() && spaces[j]==i){//when get the current index into the spaces vector , we need the values into the vector.
    ans+=' '; 
   j++;
   }
 ans+=s[i];//we need to inset the values of the string s in each iteration
 }
return ans;
    }
