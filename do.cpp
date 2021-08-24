/*알고리즘 공부 
<그리디알고리즘>
BOJ 11399 ATM
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> P;

int main()
{
	freopen("input.txt", "r", stdin);
	cin>>N;
	P.resize(N,0);
	for(int i=0;i<N;i++){
		cin>>P[i];
	}
	
	sort(P.begin(),P.end());

	int buff = 0;
	int total = 0;
	for(int i=0;i<P.size();i++){
		buff= P[i]+buff;
		total = buff+total;
	}

	
	cout<<total;
    return 0;
}