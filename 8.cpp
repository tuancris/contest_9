#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002];
void BFS(int u, int v){
	queue<int> kq;
	queue<int> q;
	q.push(u);
	kq.push(u);
	kt[u]=1;
	while(!q.empty()){
		for(int i=1; i<=v; i++){
			if(kt[i]==0 && mt[q.front()][i]){
				kt[i]=1;
				q.push(i);
				kq.push(i);
			}
		}
		q.pop();
	}
	while(!kq.empty()){
		cout << kq.front() << " ";
		kq.pop();
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		memset(kt, 0, sizeof(kt));
		memset(mt, 0, sizeof(mt));
		queue<int> q;
		queue<int> kq;
		int v, e, u, x, y;
		cin >> v >> e >> u;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y]=1;
			mt[y][x]=1;
		}
		BFS(u, v);
		cout << endl;
	}
	return 0;
}
