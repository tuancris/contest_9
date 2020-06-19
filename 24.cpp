#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002], dau[1002], cuoi[1002];
void BFS(int u, int v, bool &temp){
	queue<int> q;
	q.push(u);
	kt[u] = 1;
	while(!q.empty()){
		for(int i=1; i<=v; i++){
			if(mt[q.front()][i]){
				mt[q.front()][i]=0;
				mt[i][q.front()]=0;
				if(kt[i]==1) temp=true;
				kt[i] = 1;
				q.push(i);
			}
		}
		q.pop();
	}
}
void setmt(int e){
	for(int i=1; i<=e; i++){
		mt[dau[i]][cuoi[i]] = 1;
		mt[cuoi[i]][dau[i]] = 1;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		memset(kt, 0, sizeof(kt));
		memset(mt, 0, sizeof(mt));
		memset(dau, 0, sizeof(dau));
		memset(cuoi, 0, sizeof(cuoi));
		queue<int> q;
		queue<int> kq;
		int v, e, u, x, y;
		cin >> v >> e;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			dau[i] = x;
			cuoi[i] = y;
			mt[x][y] = 1;
			mt[y][x] = 1;
		}
		bool temp = false;
		for(int u=1; u<v; u++){
			memset(kt, 0, sizeof(kt));
			setmt(e);
			BFS(u, v, temp);
		}
		if(temp) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
