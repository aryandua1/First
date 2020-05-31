/*
In tabulation we try to fill dp[profits.size()][capacity+1] matrix in an iterative way.
So, for each item at index ‘i’ (0 <= i < items.length) and capacity ‘j’ (0 <= j <= capacity), we have two options:
1) Exclude the item at index ‘i’. 
In this case, we will take whatever profit we get from the sub-array excluding this item i.e. dp[i-1][j]
2) Include the item at index ‘i’ if its weight is not more than the capacity. 
In this case, we include its profit plus whatever profit we get from the remaining capacity and from remaining items 
i.e. profit[i] + dp[i-1][j-weight[i]]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) { // base case
      return 0;
    }
    int n = profits.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1));
    // populate the capacity=0 columns with '0',as with '0' capacity we have '0' profit
    for (int i = 0; i < n; i++) {
      dp[i][0] = 0;
    }
    // if we have only one weight, we will take it if it is not more than the capacity
    for (int i = 0; i <= capacity; i++) {
      if (weights[0] <= i) {
        dp[0][i] = profits[0];
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= capacity; j++) {
        int profit1 = 0, profit2 = 0;
        if (weights[i] <= j) {
          profit1 = profits[i] + dp[i - 1][j - weights[i]];  // include the item, if it is not more than the capacity.
        }
        profit2 = dp[i - 1][j]; // exclude the item.
        dp[i][j] = max(profit1, profit2);
      }
    }
    return dp[n - 1][capacity];
  }
};
int main(){
	int n;
	int capacity; 
	cin>>n;
	vector<int> profits(n,0);
	vector<int> weights(n,0); // initializing the vectors with 0's
	for(int i = 0;i<n;i++){
		cin>>profits[i];
	}
	for(int i = 0;i<n;i++){
		cin>>weights[i];
	}
	cin>>capacity;
	
	cout<<solveKnapsack(profits,weights,capacity,0)<<endl;
	return 0;
}
