// this is the Leetcode POTD of  11 November

// problem link:-https://leetcode.com/problems/prime-subtraction-operation/?envType=daily-question&envId=2024-11-11

// Prime Substraction Operation

// intution:- we can do this easily by the brute force method in which we make every possible pair and finally neglect it as per the montonid condition , if we get any required possible vector then we return true else return false

// obervation :- we can divide it into two major cases-
// case-01 when we are given an already sorted array , then we only need to check it and then return true if we get an already sorted array
// case-02 else we need to go for the caser-02 for the furthur investigation that whether we can able to sort it as per the problem

#include <bits/stdc++.h>
using namespace std;

// function to check whether a given integer is prime or not , if it is prime it returns true  else it returns false
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

// function to return the optimalPrime number for the given 'number' which is strictly less than given number
// here diff stroes the previous optimal answer of the nums array result
int optimalPrime(int number, int diff)
{
    for (int i = number - 1; i >= 2; i--)
    {
        if (isPrime(i) && number - i > diff)
        { // along with being prime , we need to also check that its differne with number i(prime) must be greater than previous result 'prev' so that the original aray nums must remain stricly montonic
            return i;
        }
    }
    return 0; // if we don't get any such prime number than we return zero,
}

bool solve(vector<int> &nums, int n)
{
    int prev = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        // function to find the optimal prime number
        nums[i] = nums[i] - optimalPrime(nums[i], prev);

        if (prev >= nums[i])
            return false; // if the updated value of nums[i] is still less than or equals to previous optimal value 'prev'. it means it can't be sorted
        else
            prev = nums[i]; // else we update our optimal result to the current grater optimal result
    }

    return true;
}

bool primeSubOperation(vector<int> &nums)
{

    // case-01
    bool flag = true;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] >= nums[i])
            flag = false;
    }

    if (flag)
        return true;

    // function for case-02
    return solve(nums, nums.size());
}
