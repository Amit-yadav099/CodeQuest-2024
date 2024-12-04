//this is the leetcode POTD of the 4th december

// Make a string  a subsequence using cyclic Increments

// problem link:-https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04


// Intution:- here we use two pointers to do the same , what we need to do is for every index of str1
//   we compare str2[j] to the current index value or the next character value , if we get it , then we need to increase the pointer 'j'

#include<bits/stdc++.h>
using namespace std;
    bool canMakeSubsequence(string str1, string str2) {
    
       
    int j=0;
    int i=0;
    // to iterate ove the next character we need to do in such way => a+(str[i]-'a'+1)%26
    while(i<str1.size() && j<str2.size()){
            char nextchar='a'+(str1[i]-'a'+1)%26;//to ge the next character

        if(str1[i] == str2[j] || nextchar == str2[j]){
            j++;//incresing the J value
        }
    i++;//always increase
    }

    if(j==str2.size()) return true;//means J reaches to the end of the array 
    else return false;
    
    }

