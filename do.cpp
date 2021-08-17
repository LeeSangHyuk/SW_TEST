/*알고리즘 공부 BOJ 17942
- 1시간 반 정도 풀다가 답지 봄
- 다익스트라의 응용
- 공부량이 적은 알고리즘 부터 ㄱㄱ
- auto 의 사용법 확인
- priority_queue 의 사용법 다시 확인
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;
int R;

vector<int> study_size;


int main()
{
	freopen("input.txt", "r", stdin);
	cin >>N;
	cin>> M;
	study_size.resize(N+1);
	
	for(int i=1;i<=N;i++){
		cin>>study_size[i];
	}
	
	cin>>R;
	
	vector<vector<pair<int,int>>> map(N+1);
	
	for(int i=0;i<R;i++){
		int from,to,sub_size;
		cin>>from;
		cin>>to;
		cin>>sub_size;
		map[from].push_back({to,sub_size});
		
	}
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	
	vector<bool> visit(N+1,false);
	
	for(int i=1;i<=N;i++){
		pq.push({study_size[i],i});
	}
	
	
	int ans = -1, cnt =0;

	while(!pq.empty() && cnt<M){
		pair<int,int> buff = pq.top();
		
		int cost = buff.first;
		int node = buff.second;
		
		pq.pop();
		if(visit[node]) continue;
		cnt++;
		visit[node] =true;
		
		if(ans<cost){
			ans = cost;
		}
		
		for(int j =0;j<map[node].size();j++){
			int next_node = map[node][j].first;
			int next_cost = map[node][j].second;
		
			
			if(visit[next_node]==true) continue;
			if(study_size[next_node] >= next_cost){
				study_size[next_node]=study_size[next_node]-next_cost;
			}
			else{
				study_size[next_node]= 0;
			}
			pq.push({study_size[next_node],next_node});

		}
		
	}
	
	cout<< ans<<endl;
	
	
    return 0;
}