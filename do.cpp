/*파티_bOJ 1238
다익스트라로 풀음
first를 음수로! 간선의 값이 작은것부터!
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 999999
using namespace std;

int N;
int M;
int X;
int Max=0;
vector<pair<int,int>> map[1001];

void dijkstra(int start,vector<int>&dist){
	dist[start] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,start});
	
	while(!pq.empty()){
		int distance = -pq.top().first;
		int current =pq.top().second;

		pq.pop();
		
		if (dist[current]<distance) continue;
		
		for(int i=0;i<map[current].size();i++){
			int next_distance = map[current][i].first;
			int next = map[current][i].second+ distance;
			
			if(next_distance<dist[next]){
				dist[next] = next_distance;
				pq.push({-next_distance,next});	
			}
		}
	}
	cout<<endl;
	
	
}


int main()
{
	freopen("input.txt", "r", stdin);
	cin>>N;
	cin>>M;
	cin>>X;
	
	
	for(int i=1;i<=M;i++){
		int x;
		int y;
		int value;
		cin>>x;
		cin>>y;
		cin>>value;
		map[x].push_back({y,value});	
		
		
	}

	vector<int> dist(N+1,INF);
	dijkstra(X,dist);
	
	for(int i=1;i<=N;i++){
		vector<int> dist2(N+1,INF);
		dijkstra(i,dist2);
		
		if(Max<dist2[X]+dist[i]){
			Max= dist2[X]+dist[i];
		}
		dist2.clear();
	}
	cout<<Max;
    return 0;
}