// this is the leetcode POTD of 23 November 

// Rotating the box

// problem link:-https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2024-11-23

// Intution:- as per the question, first what we need is to change the box into its position after the gravational change.
// this can be done using the two pointer on the each row of  the 2D vector box 
// then we simply take the another 2D vector and put the valeus in the 90 deg into this new vector ans.  

#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
int rows=box.size();
int cols=box[0].size();


//step-01 here we change our box into its gravitational change form after rotatiting it  by 90 deg
for(int i=0;i<rows;i++){
    int pointer1=box[i].size()-1;//first pointer

    for(int j=box[i].size()-1;j>=0;j--){//here we use two pointer approach from the end row of the matrix
    //second pointer is our 'j'
    
    //if we tackle with the obstacles
    if(box[i][j]=='*'){
        pointer1=j-1;
    }
    //if we tackle with the stone
    if(box[i][j]=='#' && pointer1>=0 ){
        swap(box[i][j],box[i][pointer1]);
        pointer1--;
    }
    //if we tackle with '.' then we simply have to move on 
    }
}


//step-02 converting the values into the 
// for(int i=0;i<box.size();i++){
//     for(int j=0;j<box[i].size();j++){
//      cout<<box[i][j]<<" ";
//     }

// }
// cout<<endl;

vector<vector<char>>ans(cols,vector<char>(rows));

//step-02 putting the values of the box(mXn) into the 2D vector ans (nXm)  
for(int i=0;i<cols;i++){  
    for(int j=0;j<rows;j++){
        ans[i][j]=box[rows-1-j][i];
        
    }
}

return ans;
    }

int main(){
 vector<vector<char>>box{
{'#','.','*','.'},
{'#','#','*','.'}
 };
 vector<vector<char>>ans=rotateTheBox(box);
 for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
 }
 
 
return 0;
}