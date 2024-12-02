// This is the leetcode POTD of 2 December

// Check If a Word Occurs As a Prefix of Any Word in a Sentence

// problem link:-https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02

// INtution:_ this problem is quite easy what we need is to run a loop through sentence ,
//  when we get an empty space simply make your str to empty
// else add new character and check if we found that srachWord or not
// maintain the count of spaces in along with that and return (count_spaces+1) if we get the searchWord else return '-1'

#include<bits/stdc++.h>
using namespace std;

 int isPrefixOfWord(string sentence, string searchWord) {
string str;//to maintian the string 
int ans=-1;//tos tore the index if we got
int countIndex=0;//to count the indexes as per the word

    for(int i=0;i<sentence.size();i++){
        if(sentence[i]==' '){
            str="";
            countIndex++;
        }
        else {
            str+=sentence[i];
            if(str==searchWord){
                ans= countIndex+1;
                break;
            }
        }
    }

    return ans;    
}

