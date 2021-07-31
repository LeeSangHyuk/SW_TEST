/*합승 택시 요금
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.94MB)
테스트 2 〉	통과 (0.01ms, 3.94MB)
테스트 3 〉	통과 (0.01ms, 3.94MB)
테스트 4 〉	통과 (0.04ms, 3.67MB)
테스트 5 〉	통과 (0.03ms, 3.97MB)
테스트 6 〉	통과 (0.04ms, 3.94MB)
테스트 7 〉	통과 (0.04ms, 3.95MB)
테스트 8 〉	통과 (0.06ms, 3.93MB)
테스트 9 〉	통과 (0.07ms, 3.89MB)
테스트 10 〉	통과 (0.05ms, 3.96MB)
효율성  테스트
테스트 1 〉	통과 (5.24ms, 3.95MB)
테스트 2 〉	실패 (시간 초과)
테스트 3 〉	통과 (12.71ms, 3.94MB)
테스트 4 〉	통과 (13.27ms, 3.94MB)
테스트 5 〉	통과 (11.70ms, 3.92MB)
테스트 6 〉	통과 (13.97ms, 3.86MB)
테스트 7 〉	실패 (시간 초과)
테스트 8 〉	실패 (시간 초과)
테스트 9 〉	통과 (13.18ms, 8.08MB)
테스트 10 〉	통과 (13.91ms, 7.89MB)
테스트 11 〉	통과 (13.09ms, 8.04MB)
테스트 12 〉	실패 (시간 초과)
테스트 13 〉	실패 (시간 초과)
테스트 14 〉	실패 (시간 초과)
테스트 15 〉	실패 (시간 초과)
테스트 16 〉	통과 (9.58ms, 3.93MB)
테스트 17 〉	통과 (10.65ms, 3.95MB)
테스트 18 〉	통과 (9.78ms, 3.93MB)
테스트 19 〉	통과 (26.88ms, 3.94MB)
테스트 20 〉	실패 (시간 초과)
테스트 21 〉	실패 (시간 초과)
테스트 22 〉	실패 (시간 초과)
테스트 23 〉	실패 (시간 초과)
테스트 24 〉	실패 (시간 초과)
테스트 25 〉	통과 (4.46ms, 3.94MB)
테스트 26 〉	통과 (3.55ms, 3.94MB)
테스트 27 〉	실패 (시간 초과)
테스트 28 〉	실패 (시간 초과)
테스트 29 〉	통과 (3.51ms, 3.86MB)
테스트 30 〉	통과 (3.17ms, 3.92MB)
채점 결과
정확성: 50.0
효율성: 26.7
합계: 76.7 / 100.0

*/
#include <iostream>
#include <vector>
#include <queue>

#define INF 9999999

using namespace std;

vector<pair<int, int>> map[201];
vector<int> dijjkstra(int start, int V){
	vector<int> dist (V+1,INF);
	dist[start] =0;
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(start,0));
	while(!pq.empty()){
		int current = pq.top().first;
		int distance = -pq.top().second;
		
		pq.pop();
		if(dist[current]<distance) continue;
		for(int i=0;i<map[current].size();i++){
			int next = map[current][i].first;
			int nexDistance = distance +map[current][i].second;
			if(nexDistance <dist[next]){
				dist[next] = nexDistance;
				pq.push(make_pair(next, -nexDistance));
			}
		}
	}

	return dist;
	
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
	int Min = 10000000;
	
	for(int i=0;i<fares.size();i++){
		map[fares[i][0]].push_back(make_pair(fares[i][1],fares[i][2]));
		map[fares[i][1]].push_back(make_pair(fares[i][0],fares[i][2]));
	}
	for(int i=1;i<=n;i++){
		for(int j =0;j<map[i].size();j++){
			cout<< map[i][j].first<<"("<<map[i][j].second<<")" <<" ";
		}
		cout<<endl;
	}
	vector<vector<int>> buff(1,vector<int>(n,0));
	for(int i = 1;i<=n;i++){
		buff.push_back(dijjkstra(i,n));
	}
	
	for(int i=1;i<buff.size();i++){
		for(int j =1;j<buff[i].size();j++){
			cout<< buff[i][j] <<" ";
		}
		cout<<endl;
	}
	
	for(int j =1 ;j<=n;j++){
	
		
		if(Min>buff[s][j]+buff[j][a]+buff[j][b])
		{
			Min = buff[s][j]+buff[j][a]+buff[j][b];
		}
				
	
	}
	answer = Min;
    return answer;
}
int main()
{
	int n = 6;
	int s = 4;
	int a = 6;
	int b = 2;
	vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
	
	solution(n,s,a,b,fares);
    return 0;
}