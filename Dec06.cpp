// this is the leetcode POTD of 7th of december

//maximum number of integers choosing from a range-I

// problem link:-https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-06

// intution:-the intution is quite simple , we need to avoid the integers present in the array banned , 
// and we need to choose the integers form [1 to n] in optimal way ,
//  so what we can do is to choose the first elements in order to select the maxmimum number of elements form [1 to n] 

#include<bits/stdc++.h>
using namespace std;
    int maxCount(vector<int>& banned, int n, int maxSum) {

//unordered map to maintian whether is present in the array banned 
unordered_map<int,bool>mp;
//filling the map
for(int i=0;i<banned.size();i++){
    mp[banned[i]]=true;
}    


long long sum=0;//contians the sum
int i=1;
int count=0; 
//loop until sum>maxSum or interstor i reach to the 'n'
while(sum<=maxSum &&i<=n){
    
    //we only add the value of 'i' of when it is not present in the banned
    if(!mp[i]){
        sum+=i;
        count++; }
i++;
}

if(sum>maxSum) return count-1;//shows sum surpasses the maSum so we need to return (number_count -1)
else return count; //returns the value of count only , as i reaches to the end of the range 'n'
}
