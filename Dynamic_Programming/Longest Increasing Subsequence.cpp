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
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
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
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Length of LIS: " << lis(nums) << endl;
    return 0;
}
