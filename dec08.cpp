//this is the leetcode POTD of 8th of december

// Two Best  Non-overlapping Events

// problem link:-https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2024-12-08

// Intution: we know for the events timing problems , sorting is essential to do either by the startTime or endTime
//  here we first sort the array then take a minheap who store the end time  and value.

#include<bits/stdc++.h>
using namespace std;

#define  P pair<int,int> 

int maxTwoEvents(vector<vector<int>>& events) {

priority_queue<P,vector<P>,greater<P>>Minheap;//to store the ( endtime and values ) respectively 

//sort the events 
sort(events.begin(),events.end());

int maxValue=0;// contains the maximum value of the un-overlapped events to pair with the next successive events
int maxSum=0;//to conatins the maximum possible value of the events

for(int i=0;i<events.size();i++){

//we pop the valeus form the minheap until we get the get overlapping value or  the heap becomes empty 
  while(Minheap.size() && Minheap.top().first < events[i][0]){

    maxValue=max(maxValue,Minheap.top().second);//maxValue is maximum value hwich is poppped out from the minheap
     Minheap.pop();
  } 
 
 //for the all the next values , the maxValue can make a pair with all of them , so we include it with our successive events
 maxSum=max(maxSum,maxValue+events[i][2]);
   Minheap.push({events[i][1],events[i][2]});
}
return maxSum;
}
int main(){
 vector<vector<int>>events = {{6,6,6},{7,9,4},{4,5,4},{3,7,9},{6,10,8},{4,7,6}};
 cout<<maxTwoEvents(events);
 
return 0;
}