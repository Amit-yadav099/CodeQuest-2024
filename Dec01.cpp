// this is the leetcode POTD

// Check if N and its Double Exist

// problem link:-https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01

//this is quite a easy problem of leetcode , we can use double loop to do the same thing 

#include<bits/stdc++.h>
using namespace std;


bool checkIfExist(vector<int>& arr) {
        // Step 1: Iterate through all pairs of indices
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr.size(); j++) {
                // Step 2: Check the conditions
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        // No valid pair found
        return false;
    }
int main(){
 
 
 
return 0;
}