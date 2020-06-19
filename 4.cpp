#include<bits/stdc++.h>
using namespace std;
int main(){
	queue<int> ke[1002];
	int n; cin >> n;
	cin.ignore();
	int i = 1;
	while(i<=n){
		string s; getline(cin, s);
		int j=0, k=0;
		while(j<=s.length()){
			if(s[j]!=' ' && j<s.length()){
				k=k*10+(int)s[j]-48;
			}
			else{
				ke[i].push(k);
				k=0;
			}
			j++;
		}
		i++;
	}
	for(int x=1; x<=n; x++){
		for(int y=1; y<=n; y++){
			if(ke[x].front()==y){
				cout << 1 << " ";
				ke[x].pop();
			}
			else cout << 0 << " ";
		}
		cout << endl;
	}
	return 0;
}
