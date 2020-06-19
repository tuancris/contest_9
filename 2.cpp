#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	queue<int> ke[1002];
	cin>>n;
	cin.ignore();
	int i=1;
	while(i<=n){
		string s;
		getline(cin, s);
		int j=0;
		int k=0;
		while(j<=s.length()){
			if(s[j]!=' '&&j<s.length()){
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
	i=1;
	while(i<=n){
		while(!ke[i].empty()){
			if(i<ke[i].front())cout<<i<<" "<<ke[i].front()<<endl;
			ke[i].pop();
		}
		i++;
	}
	return 0;
}
