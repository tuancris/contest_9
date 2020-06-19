#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002];

void DFS(int u, int v){
	cout << u << " ";
	kt[u] = 1;
	for(int i=1; i<=v; i++){
		if(kt[i]==0 && mt[u][i]==1){
			kt[i] = 1;
			DFS(i, v);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int v, e, u;
		cin >> v >> e >> u;
		int x, y;
		memset(kt, 0, sizeof(kt));
		memset(mt, 0, sizeof(mt));
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y]=1;
		}
		DFS(u, v);
		cout << endl;
	}
	return 0;
}
