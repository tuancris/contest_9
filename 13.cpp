#include<bits/stdc++.h>
using namespace std;
int mt[1002][1002], kt[1002], kq[1002];
void BFS(int u, int v, int k){
	memset(kq, 0, sizeof(kq));
	stack<int> s;
	queue<int> q;
	q.push(u);
	kq[u]=0;
	kt[u]=1;
	while(!q.empty()){
		for(int i=1; i<=v; i++){
			if(kt[i]==0 && mt[q.front()][i]){
				kt[i]=1;
				q.push(i);
				kq[i] = q.front();
			}
		}
		q.pop();
	}
	int temp = k;
	bool ok = false;
	while(temp!=0 && kq[temp]!=0){
		s.push(temp);
		temp = kq[temp];
		if(temp==u) ok = true;
	}
	s.push(temp);
	if(ok){
		while(!s.empty()){
			cout << s.top() << " ";
			s.pop();
		}
	}
	else cout << -1;
}
int main(){
	int t; cin >> t;
	while(t--){
		memset(kt, 0, sizeof(kt));
		memset(mt, 0, sizeof(mt));
		queue<int> q;
		queue<int> kq;
		int v, e, u, x, y, k;
		cin >> v >> e >> u >> k;
		for(int i=1; i<=e; i++){
			cin >> x >> y;
			mt[x][y] = 1;
		}
		BFS(u, v, k);
		cout << endl;
	}
	return 0;
}
