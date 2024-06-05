#include<bits/stdc++.h>
#define ll long long int
#define faster() ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int sz = 1e5 + 5, mod = 1e9 + 7;

void selectionSort(int a[],int n){
	for (int i = 0; i < n-1; ++i)
	{
		int mini = i;
		 for (int j = i+1; j < n; ++j)
		 {
		 	if(a[j] < a[mini]){
		 		mini = j;
		 	}
		 }
		 if(mini != i){
		 	int temp = a[i];
		 		a[i] = a[mini];
		 		a[mini] = temp;
		 	}
	}
}
int main()
{
    faster();
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    }

    selectionSort(a,n);

    for (int i = 0; i < n; ++i)
    {
    	cout<<a[i]<<' ';
    }
    return 0;
}
