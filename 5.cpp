#include<bits/stdc++.h>
using namespace std;
int dau[10020], cuoi[10020];
int main(){
	int t; cin >> t;
	while(t--){
		priority_queue <int, vector<int>, greater<int> > q[1002];
		int v, e;
		cin >> v >> e;
		int j = 0;
		for(int i=1; i<=e; i++){
			cin >> dau[i] >> cuoi[i];
			q[dau[i]].push(cuoi[i]);
		}
		int i = 1;
		while(i<=v){
			cout << i << ": ";
			while(!q[i].empty()){
				cout << q[i].top() << " ";
				q[i].pop();
			}
			i++;
			cout << "\n";
		}
	}
	return 0;
}
