#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002], kq[1002];
void DFS(int u, int v, int k){
	kt[u]=1;
	for(int i=1; i<=v; i++){
		if(kt[i]==0 && mt[u][i]==1){
			kq[i] = u;
			kt[i] = 1;
			if(i!=k) DFS(i, v, k);
			else break;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int v, e, u, k;
		cin >> v >> e >> u >> k;
		int x, y;
		bool ok = false;
		stack<int> s;
		memset(kq, 0, sizeof(kq));
		memset(kt, 0, sizeof(kt));
		memset(mt, 0, sizeof(mt));
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y] = 1;
		}
		kq[u] = 0;
		DFS(u, v, k);
		int temp = k;
		while(temp!=u && kq[temp]!=0){
			s.push(temp);
			temp = kq[temp];
			if(temp==u) ok = true;
		}
		if(ok){
			s.push(temp);
			while(!s.empty()){
				cout << s.top() << " ";
				s.pop();
			}
		}
		else cout << -1;
		cout << endl;
	}
	return 0;
}
