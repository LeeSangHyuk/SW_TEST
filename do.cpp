/*벽 부수고 이동하기2*/
/*
- 걸린시간 1시간 15분(1시간 정도에 풀었지만, 계속된 오답에 반례를 확인하고 풀었다...
- 오답 이유 : 벽 부수는 횟수를 큐에 넣고 돌리려 했지만, 반례로 visit 함수의 겹침이 생기는 경우가 있었음
- 3차원 배열사용 필요
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 9999999
using namespace std;

int N;
int M;
int K;
int Min = INF;
int dir_x[4] = {0,-1,0,1};
int dir_y[4] = {-1,0,1,0};

vector<vector<int>> map;
vector<vector<vector<bool>>> visit;

typedef struct _point{
	int x;
	int y;
	int move_cnt;
	int break_cnt;

}Point;

int main()
{
	freopen("input.txt", "r", stdin);
	cin>>N;
	cin>>M;
	cin>>K;

	map.resize(N+1,vector<int>(M+1,-1));
	visit.resize(K+1,vector<vector<bool>>(N+1,vector<bool>(M+1,true)));
	queue<Point> q;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	visit[1][1][1] = false;
	q.push({1,1,1,K});
	
	while(!q.empty()){
		Point buff = q.front();
		q.pop();
		
		if(buff.x==N && buff.y==M){
			if(Min>buff.move_cnt){
				Min = buff.move_cnt;
			}
		}
		for(int i=0;i<4;i++){
			int new_x = buff.x + dir_x[i];
			int new_y = buff.y + dir_y[i];
			
			if(new_x>=1 && new_x<=N && new_y>=1 && new_y<=M){
				if(visit[buff.break_cnt][new_x][new_y]){
					
					if(map[new_x][new_y]==0){
						q.push({new_x,new_y,buff.move_cnt+1,buff.break_cnt});
						visit[buff.break_cnt][new_x][new_y]= false;
					}
					else{
						if(buff.break_cnt!=0){
							q.push({new_x,new_y,buff.move_cnt+1,buff.break_cnt-1});
							visit[buff.break_cnt-1][new_x][new_y]= false;
						}
						
					}
				}
				else{
					continue;
				}
			}
		}
		
	}
	if(Min == INF){
		cout<< -1<<endl;
	}
	else{
		cout<< Min<<endl;
	}
	
	

    return 0;
}