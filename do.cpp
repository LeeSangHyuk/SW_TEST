/*파티_bOJ 1238*/
#include <iostream>
#include <vector>
#define INF 999999
using namespace std;

int N;
int M;
int X;
int Max=0;
vector<vector<int>> map;

int main()
{
	freopen("input.txt", "r", stdin);
	cin>>N;
	cin>>M;
	cin>>X;
	map.resize(N+1,vector<int>(N+1,0));
	
	for(int i=1;i<=M;i++){
		int x;
		int y;
		int value;
		cin>>x;
		cin>>y;
		cin>>value;
		map[x][y]=value;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i!=j && map[i][j]==0){
				map[i][j]=INF;
			}
		}
	}
	
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(map[i][j]>map[i][k]+map[k][j]){
					map[i][j] = map[i][k]+map[k][j];
				}
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		if(Max<map[i][X]+map[X][i]){
			Max= map[i][X]+map[X][i];
		}
	}
	cout<<Max<<endl;
    return 0;
}