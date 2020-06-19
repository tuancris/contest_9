#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002], kq[1002];
bool kTra(int u, int k){
	int temp1 = u, temp2 = k;
	while(temp1!=0 && temp2!=0){
		if(temp1>temp2)  swap(temp1, temp2);
		if(temp1==temp2) return true;
		if(mt[temp1][temp2]==1) return true;
		else temp2 = kq[temp2];
	}
	return false;
}
void BFS(int v){
	stack<int> s;
	queue<int> q;
	for(int u=1; u<=v; u++){
		if(kt[u]==0){
			q.push(u);
			kq[u] = 0;
			kt[u] = 1;
			while(!q.empty()){
				for(int i=1; i<=v; i++){
					if(kt[i]==0 && mt[q.front()][i]){
						kt[i] = 1;
						q.push(i);
						kq[i] = q.front();
					}
				}
				q.pop();
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		memset(mt, 0, sizeof(mt));
		memset(kq, 0, sizeof(kq));
		memset(kt, 0, sizeof(kt));
		int v, e, u, x, y, k;
		cin >> v >> e;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y] = 1;
			mt[y][x] = 1;
		}
		BFS(v);
		int Q; cin >> Q;
		while(Q--){
			cin >> u >> k;
			if(kTra(u, k)) cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}
	return 0;
}
