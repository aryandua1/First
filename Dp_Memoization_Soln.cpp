/*We can use memoization to overcome the overlapping sub-problems.

Since we have two changing values (capacity and currentIndex) in our recursive function Solveknapsack(),

we can use a two-dimensional array to store the results of all the solved sub-problems.

we need to store results for every sub-array (i.e. for every possible index ‘i’) and for every possible capacity ‘c’

and return result from array for every sub problem that is already solved*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Solveknapsack(vector<int>& Profits,vector<int>& Weights,int Capacity,int currentIndex, vector<vector<int>>& dp){
	
	if(Capacity <= 0 || currentIndex == Profits.size()) // base condition
	    return 0;
	if(dp[currentIndex][Capacity] != -1){
		return dp[currentIndex][Capacity]; // return the result if it is already solved
	}
	int profit1 = Solveknapsack(Profits,Weights,Capacity,currentIndex + 1,dp); //considering current element is not the part of the answer.
	
	int profit2 = 0;
	
	if(Capacity >= Weights[currentIndex]){
		profit2 = Profits[currentIndex] + Solveknapsack(Profits,Weights,Capacity - Weights[currentIndex],currentIndex + 1,dp); //considering
	
		// current element is a part of the answer.Thus we have to subtract the weight of the current element from the capacity
	}
	
	dp[currentIndex][Capacity] = max(profit1,profit2); // storing the result in the array.
	return dp[currentIndex][Capacity];
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
	
	vector<vector<int>> dp(profits.size(),vector<int>(capacity+1,-1)); // initializing 2d dp vector od size = (profits.size()*capacity)
	//with -1

	cout<<Solveknapsack(profits,weights,capacity,0,dp)<<endl;
	return 0;
}

// So that was dp with memoization soln of 0/1 Knapsack Problem. 

// Time Complexity of this is O(N*C), where 'N' is number of items and 'C' is the capacity of the knapsack. 
// as we are solving not more the N*C subproblems.

// Space Complexity is O(N*C+N).O(N*C) space will be used to storing answer of the subproblems in our dp 2d vector.
// also O(N) space will be used for storing the recursion stack.
// O(N*C+N) is eqivalent to O(N*C) (asymptotically)
