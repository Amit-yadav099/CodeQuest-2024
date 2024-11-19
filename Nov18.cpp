//This the Leetcode POTD of 19th November
 

//  problem link:-https://leetcode.com/problems/defuse-the-bomb/submissions/1456538707/?envType=daily-question&envId=2024-11-19

//defuse the bomb (easy version)

// method-01 T.C=O(N*K)
//this is the brute force approach along with the using the technique of circular array
// Here we smpy the cases when k is greater than zero , less than zero and equals to zero by using  the if-else condition

// method-02
// as we can for each value of the array code , we need to find the sum of next kth or previous kth value
//we xan use the sliding winodw tevhnique to do this task in O(n) T.C 
 #include<bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
            int n=code.size();
             vector<int>nums(n,0);
        if(k>0){//when k is greater then zero
        for(int i=0;i<n;i++){
           int newValue=0;
            int j=(i+1)%n;
            for(int z=0; z<k ; z++){//inner loop for the next 'K' elements for each individual 'ith' value
             newValue+=code[j];
             j=(j+1)%n;
           }
           nums[i]=newValue;
        }
        }
        else if(k<0){
        for(int i=0;i<n;i++){
            int j=(i+ n-1)%n;
            int newValue=0;
            for(int z=0; z<abs(k) ; z++){//inner loop for the next 'K' elements for each individual 'ith' value
             newValue+=code[j];
             j=(j +n-1)%n;
           }
            nums[i]=newValue;
        }
        
        }
         
        return nums;
    }


// method 02 using  the sliding window
vector<int> decrypt(vector<int>& code, int k) {
            int n=code.size();
             vector<int>nums(n,0);
        if(k>0){
        //for the first window
        int newValue=0;
        int count=1;
        while(count!=abs(k+1)){
            newValue+=code[(count)%n];
            count++;
        }
        nums[0]=newValue;
         
         int front=(k+1)%n;
         int back=1;
           
           //now for the rest of the window
        for(int i=1;i<n;i++){
           newValue+=code[front];
           newValue-=code[back];
            front=(front+1)%n;
           back=(back+1)%n;
           nums[i]=newValue;
        }
        }
        else if(k<0){
        
        //for the first window
        int newValue=0;
        int count=0;
        while(count!=abs(k)){
            newValue+=code[(n-count-1)%n];
            count++;
        }

        nums[0]=newValue;
         
         int front=0;
         int back=n-abs(k);
        //fir the rest of the window
        for(int i=1;i<n;i++){
             newValue-=code[back];
             newValue+=code[front];
             back=(back+1)%n; 
             front=(front+1)%n;
            nums[i]=newValue;
        }
        
        }
         
        return nums;
    }
