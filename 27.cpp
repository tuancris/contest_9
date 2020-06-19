#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002], dau[1002], cuoi[1002];
void DFS(int u, int v, bool &temp, int const k){
	kt[u] = 1;
	for(int i=1; i<=v; i++){
		if(mt[u][i]==1){
			if(i==k) temp=true;
			mt[u][i] = 0;
			DFS(i, v, temp, k);
		}
	}
}
void setmt(int e){
	for(int i=1; i<=e; i++){
		mt[dau[i]][cuoi[i]] = 1;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int v, e, x, y;
		cin >> v >> e;
		memset(mt, 0, sizeof(mt));
		memset(kt, 0, sizeof(kt));
		memset(dau, 0, sizeof(dau));
		memset(cuoi, 0, sizeof(cuoi));
		bool temp = false;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			dau[i] = x;
			cuoi[i] = y;
		}
		for(int j=1; j<=v; j++){
			memset(kt, 0, sizeof(kt));
			memset(mt, 0, sizeof(mt));
			setmt(e);
			DFS(j, v, temp, j);
		}
		if(temp) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}
	return 0;
}
