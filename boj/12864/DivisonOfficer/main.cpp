/**
 * Problem Link : https://www.acmicpc.net/problem/12846
 * Problem Name : 꿀 아르바이트
 * Category: Segment Tree, Dp with Stack, Histogram
 * Solution Type : Dp with Stack
*/



#include<iostream>
#include<vector>
#include<stack>
#include<cmath>


using namespace std;

//Historygram Problem
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n ;
	long long pos = 0;
	long long ret = 0;
	//Save all Height information
	long long H[100002];
	H[0] = 0;
	for(long long i=0;i<n;i++){
		cin >> H[i+1];		
	}
	H[n+1] = 0;	
	stack<long long> P;
	P.push(0);

	// keep stack value is increasing by its Height
	// same value is fine
	for(int i=1;i<=n + 1;i++){
		//while new Height is less than top of stack
		//pop the value and calculate the area
		while(!P.empty() && H[P.top()] > H[i]){
			int h = H[P.top()];
			P.pop();
			ret = max(ret, h * (i - P.top() - 1));
		}
		P.push(i);
	}
	cout << ret << endl;
	return 0;
}