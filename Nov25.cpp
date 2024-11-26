// this is the leetcode POTD of 25th November

// Sliding Puzzle

// problem link:-https://leetcode.com/problems/sliding-puzzle/?envType=daily-question&envId=2024-11-25

// Intution:- we need to try all the posiblities amoung the given possibilties
// and after every possible outcome we need to compare it by the resultant/required answer "123450"

// to get the ,minimum  step waht we can do is do the BFS
//  first we convert the vector input to the string form
//  find the possibile swap for the given zero position by storing  it into direction array
//  we also need to maintain the unordered_set to get to the know that if we get the  previous occured string then we need to skip it

#include <bits/stdc++.h>
using namespace std;
//  T.C=O(720)=O(1) 
//   S.C=O(720)=O(1)
int slidingPuzzle(vector<vector<int>> &board)
{

    // Direction map for zero's possible moves in a 1D representation of the
    // 2x3 board
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    string target = "123450";
    string currState="";

    // Convert the given 2D board into a string representation
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            currState += to_string(board[i][j]);
        }
    }

    unordered_set<string> visited;
    visited.insert(currState);

    // now we need to do BFS by using the queue
    queue<string> que;
    que.push(currState);

    // standard BFS to get the level
    int level = 0; // minimum step to get the target string

    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            string currStr = que.front();
            que.pop();

            // to check if it is a valid required string
            if (currStr == target)    return level;
            

            // to get the index of zero
            int indexZero = currStr.find('0');
            // loop onto only those 1D vector of direction whose index is matched with the index of zero
            for (int i = 0; i < directions[indexZero].size(); i++)
            {
                string newStr = currStr;
                // we need to swap the zero of the currIndex with the value present at dirctions[zeroIndex][i]
                swap(newStr[indexZero], newStr[directions[indexZero][i]]);

                // we need to check newStr that it must be not be visited earlier
                if (visited.find(newStr) == visited.end())
                {
                    que.push(newStr);
                    visited.insert(newStr);
                }
            }
        }
        level++;
    }
    return -1;
}

int main()
{

    return 0;
}