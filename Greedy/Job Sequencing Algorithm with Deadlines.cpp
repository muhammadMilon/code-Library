#include<bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int totalProfit = 0;
    vector<char> sequence;

    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                totalProfit += arr[i].profit;
                sequence.push_back(arr[i].id);
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Job Sequence: ";
    for (char job : sequence)
        cout << job << " ";
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main()
{
    int n;
    cin >> n;

    Job arr[n];
    cout << "Enter job details (id, deadline, profit):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Job " << i + 1 << ": ";
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    }

    cout << "Following is the maximum profit sequence of jobs:\n";

    printJobScheduling(arr, n);
    return 0;
}
