typedef pair<int, int> ii;
const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		set<ii> A;
		for (auto& it : obstacles) {
			A.insert({it[0], it[1]});
		}
		int dir = 0, x = 0, y = 0;
		int ret = 0;
		for (auto& it : commands) {
			if (it == -2) {
				dir = (dir + 3) % 4;
			} else if (it == -1) {
				dir = (dir + 1) % 4;
			} else {
				for (int k = 0; k < it; ++k) {// fabulous!!!
					int nx = x + d[dir][0];
					int ny = y + d[dir][1];
					if (A.count({nx, ny})) break;
					x = nx;
					y = ny;
				}
			}
//            cout << x << " " << y << " " << dir << endl;
			ret = max(ret, x * x + y * y);
		}
		return ret;
	}
};
//- it's so amazing that violance is the correct algorithm.

//there is still a bug I haven't find;.
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int n = commands.size();
		int x=0,y=0;
		int dir = 0;
		map<int,vector<int>> obsx;
		map<int,vector<int>> obsy;
		for(int i=0;i<obstacles.size();i++){
			sort(obstacles[i].begin(),obstacles[i].end());
			int x=obstacles[i][0];
			int y=obstacles[i][1];
			obsx[x].push_back(y);
			obsy[y].push_back(x);
		}
		for(int i=0;i<n;i++){
			move(x,y,commands[i],dir,obsx,obsy);
		}
		
		return x*x+y*y;
	}
	void move(int& x,int& y,int op,int& toward,map<int,vector<int>>& obsx,
		map<int,vector<int>>& obsy){
		int dir[4][2]={0,1,-1,0,0,-1,1,0};
		if(op==-2){
			toward=(toward+1)%4;
		}
		else if(op==-1){
			toward=(toward-1+4)%4;
		}
		else if(op>=1 && op<=9){
			int dirx,diry;
			dirx=dir[toward][0];
			diry=dir[toward][1];
			int finaly=y;
			int finalx=x;
			int obb=0;
			vector<int> obs;
			if(dirx==0){
				obs=obsx[x];
				
				for(int i=0;i<obs.size();i++){
					int ty=obs[i];
					if(diry==1){
						if(y+op>ty&&y<ty){
							if(finaly==y) finaly=ty-1;
							finaly=min(finaly,ty-1);
							
							obb++;
						}
					}
					else{
						if(y-op<ty&&y>ty){
							if(finaly==y) finaly=ty+1;
							finaly=max(finaly,ty+1);
							
							obb++;
						}
					}
				}
				
			}
			else{
				obs=obsy[y];
				
				for(int i=0;i<obs.size();i++){
					int tx=obs[i];
					if(dirx==1){
						if(x+op>tx&&x<tx){
							if(finalx==x) finalx=tx-1;
							finalx=min(finalx,tx-1);
							
							obb++;
						}
					}
					else{
						if(x-op<tx&&x>tx){
							if(finalx==x) finalx=tx+1;
							finalx=max(finalx,tx+1);
							
							obb++;
						}
					}
				}
				
			}
			if(!obb){
				x=x+dirx*op;
				y=y+diry*op;
			}
			else{
				x=finalx;
				y=finaly;
			}
		}
		//return x*x+y*y;
	}
};