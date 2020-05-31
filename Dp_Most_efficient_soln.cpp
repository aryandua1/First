/*
This soln is even more efficient than tabulation as in this we only require one array to solve the problem.
In tabulation soln for every dp[i][j] we required dp[i-1][j] and dp[i-1][j-weight[i]]
So basically we only required the last row to solve this not the whole matrix.
Moreover we can solve this just by single array if we start filling the array in decreasing order i.e. from capacity to 0.
This is possible as the value of dp[j-weight[i]] will be same as it would have been on the previous row.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsack_most_efficient(vector<int>& profits,vector<int>& weights,int capacity){
	 if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) { // base case
      return 0;
    }
	vector<int> dp(capacity+1,0);
	for(int i = 0;i<=capacity;i++){
		if(i>=weights[0]){
			dp[i] = profits[0]; // if we have only one weight, we will take it if it is not more than the capacity
		}
	}
	for(int i = 1;i<profits.size();i++){
		for(int j = capacity;j>=1;j--){
			int profit1 = 0;
			if(j>=weights[i]){
				profit1 = profits[i] + dp[j-weights[i]];
			}
			dp[j] = max(dp[j],profit1);
		}
	}
	return dp[capacity];
}
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
	
	cout<<knapsack_most_efficient(profits,weights,capacity)<<endl;

	return 0;
}
