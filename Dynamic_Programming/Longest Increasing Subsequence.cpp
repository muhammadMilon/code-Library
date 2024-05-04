#include<bits/stdc++.h>

using namespace std;

int lis(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
               dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > max_length)
        {
            max_length = dp[i];
        }
    }

    return max_length;
}

int main()
{
    vector<int> nums = {3,9,1,5,6,7,4};
    cout << "Length of LIS: " << lis(nums) << endl;
    return 0;
}
