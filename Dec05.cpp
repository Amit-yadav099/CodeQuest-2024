// this is the leetcode POTd of december 15

//Move Pieces to obtain a string

// problem link:-https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05

// intution:- this problem is little more obersvation based,
//  i.e, the seqeuence of the character doesn't change 
// so, we need to move forward whennver get an space on any of the string either start or target,
// now we we counter the 'L' or 'R', we need to check whether start[i]==target[j]

// if both values are equal, then we need to check for 
//  if (currValue'L') then  then (i>=j) is a must conditon    
//    if (currValue'R') then  then (i<=j) is a must conditon    


#include <bits/stdc++.h>
using namespace std;

bool canChange(string start, string target)
{

    int n = start.size();
 
    int Lcount1=0,Rcount1=0;
    int Lcount2=0,Rcount2=0;


//to maintain the L-count and R-count on each string and compare it  
   for(int i=0;i<start.size();i++){
    if(start[i]=='L')Lcount1++;
    if(target[i]=='L')Lcount2++;
    if(start[i]=='R')Rcount1++;
    if(target[i]=='R')Rcount2++;
   }

if(Lcount1!=Lcount2 || Rcount2!=Rcount1) return false;//comaparison of characters count
   
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {

        while (start[i] == '_'  && i < n)//loop continue until not get 'L' or 'R' in start
        {
            i++;
        }

        while (target[j] == '_'  && j < n)////loop continue until not get 'L' or 'R' in target
        {
            j++;
        }

        if (start[i] != target[j])//useual condition
            return false;

          //     condition for the L values   and condition for the R values      
        else if (start[i] == 'L' && i < j || start[i] == 'R' && i > j)
        {
            return false;
        }
        i++;
        j++;
    }
    return true;
}
