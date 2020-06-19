#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002];
void DFS(int u, int v){
	kt[u] = 1;
	for(int i=1; i<=v; i++){
		if(kt[i]==0 && mt[u][i]){
			kt[i] = 1;
			DFS(i, v);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int v, e, x, y;
		cin >> v >> e;
		memset(mt, 0, sizeof(mt));
		memset(kt, 0, sizeof(kt));
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y] = 1;
			mt[y][x] = 1;
		}
		int count = 0;
		for(int j=1; j<=v; j++){
			if(kt[j]==0){
				DFS(j, v);
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}
