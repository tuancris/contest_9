#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002];
void DFS(int u, int v, int &count){
	kt[u] = 1;
	for(int i=1; i<=v; i++){
		if(kt[i]==0 && mt[u][i]){
			kt[i] = 1;
			count++;
			DFS(i, v, count);
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
		int temp = 0;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y] = 1;
			mt[y][x] = 1;
		}
		int count = 1;
		DFS(1, v, count);
		if(count==v){
			for(int i=1; i<=v; i++){
				int c = 0;
				for(int j=1; j<=v; j++){
					if(mt[i][j]==1) c++;
				}
				if(c%2==1){
					temp++;
				}
			}
			if(temp==0) cout << 2;
			else {
				if(temp<=2) cout << 1;
				else cout << 0;
			}
		}
		else cout << 0;
		cout << "\n";
	}
	return 0;
}
