/*BOJ 1912번 연속합*/
/*
DP[N] = Max(DP[N - 1] + Arr[i] , Arr[i])
- 2차 배열 및 2중 for문을 사용하니 메모리 초과 및 시간 초과가 뜸
- 점화식을 찾아내는 능력 필요
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> dp;
vector<int> map;

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	map.resize(N+1,0);
	dp.resize(N+1,0);
	
	for(int i=1;i<=N;i++){
		cin>>map[i];
	}
	
	dp[1] = map[1];
	int answer = dp[1];
		
	for(int i=2;i<=N;i++){
		dp[i] = max(map[i],dp[i-1]+map[i]);
		answer = max(answer,dp[i]);
	}
	
	cout<<answer;

    return 0;
}