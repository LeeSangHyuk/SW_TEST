/*상범빌딩*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int L;
int R;
int C;
int Min = 9999999;
vector<vector<vector<char>>> map;
vector<vector<vector<bool>>> check;

typedef struct _point{
	int x;
	int y;
	int z;
	int time;


}Point;

Point dir[6] ={{0,-1,0},{-1,0,0},{0,1,0},{1,0,0},{0,0,1},{0,0,-1}};
queue<Point> q;

int main()
{
	freopen("input.txt", "r", stdin);

	while(1){
		int time = 0;

		cin >> L;
		cin >> R;
		cin >> C;
		if(L==0 && R==0 && C==0){
			break;
		}
		map.resize(L+1,vector<vector<char>>(R+1,vector<char>(C+1,0)));
		check.resize(L+1,vector<vector<bool>>(R+1,vector<bool>(C+1,true)));
		for(int z =1;z <=L;z++){
			for(int x=1;x<=R;x++){
				for(int y=1;y<=C;y++){
					cin>>map[z][x][y];
					if(map[z][x][y] == 'S'){
						check[z][x][y] =false;
						q.push({x,y,z,0});
					}
				}
			}
		}

		while(!q.empty()){
			Point buff = q.front();
			q.pop();

			if(map[buff.z][buff.x][buff.y]=='E'){
				if(Min>buff.time){
					time = buff.time;
				}

			}
			for(int i=0;i<6;i++){
				int new_x = buff.x + dir[i].x;
				int new_y = buff.y + dir[i].y;
				int new_z = buff.z + dir[i].z;

				if(new_x>=1 && new_x<=R && new_y>=1 &&new_y<=C && new_z>=1 && new_z<=L){
					if(check[new_z][new_x][new_y] == true){
						if(map[new_z][new_x][new_y] == '.' ||map[new_z][new_x][new_y] == 'E' ){	
							check[new_z][new_x][new_y] = false;
							q.push({new_x,new_y,new_z,buff.time+1});

						}
					}
					else{
						continue;
					}
				}

			}
		}
		if(time == 0){
			cout<<"Trapped!"<<endl;
		}
		else{
			cout<<"Escaped in "<<time<<" minute(s)."<<endl;
		}

		map.clear();
		check.clear();
		Min=9999999;

	}

    return 0;
}