#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int SolveKnapsack(vector<int>& Profits,vector<int>& Weights,int Capacity,int currentIndex){
	
	//There are 2 possibilities at any point of time i.e. either take the current element in your final soln or skip it.
	//So we can do it recursively
	
	if(Capacity <= 0 || currentIndex == Profits.size())
	    return 0;
	
	int profit1 = SolveKnapsack(Profits,Weights,Capacity,currentIndex + 1); //considering current element is not the part of the answer.
	
	int profit2 = 0;
	
	if(Capacity >= Weights[currentIndex]){
		profit2 = Profits[currentIndex] + SolveKnapsack(Profits,Weights,Capacity - Weights[currentIndex],currentIndex + 1); //considering
	
		// current element is a part of the answer.Thus we have to subtract the weight of the current element from the capacity
	}
	
	return max(profit1,profit2);  //finally returning the maximun of the two profits.
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
	
	cout<<SolveKnapsack(profits,weights,capacity,0)<<endl;
	return 0;
}

// So that was the brute force soln of 0/1 Knapsack Problem. 

// Time Complexity of this is O(2^n), as at every point we are calculating 2 possible outcomes.

// Space Complexity is O(n).This space will be used to store the recursion stack.
//Since our recursive algorithm works in a depth-first fashion, which means, we can’t have more than ‘n’ recursive calls on the call stack at any time.
