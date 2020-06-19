#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002], kq[1002];
int BFS(int v){
	int count = 0;
	stack<int> s;
	queue<int> q;
	for(int u=1; u<=v; u++){
		if(kt[u]==0){
			count++;
			q.push(u);
			kt[u] = 1;
			while(!q.empty()){
				for(int i=1; i<=v; i++){
					if(kt[i]==0 && mt[q.front()][i]){
						kt[i] = 1;
						q.push(i);
					}
				}
				q.pop();
			}
		}
	}
	return count;
}
int main(){
	int t; cin >> t;
	while(t--){
		memset(mt, 0, sizeof(mt));
		memset(kt, 0, sizeof(kt));
		int v, e, u, x, y, k;
		cin >> v >> e;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y] = 1;
			mt[y][x] = 1;
		}
		cout << BFS(v) << "\n";
	}
	return 0;
}
