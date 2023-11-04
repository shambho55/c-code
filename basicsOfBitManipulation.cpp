#include<bits/stdc++.h>
using namespace std;

void func1(int n,int i){
	int mask = (1<<i);
	cout << (n | mask) << "\n";
}

void func2(int n,int j){
	int mask = (1<<j);
	cout << (n & ~(mask)) << "\n";
}

void func3(int n,int k){
	int mask = (1<<k);
	cout << (n ^ mask) << "\n";
}

void func4(int n,int m){
	int mask = (1<<m);
	if(n & mask == 0) cout <<  "false" << "\n";
	else cout << "true" << "\n";
}

int main(){
int n,i,j,k,m;
cin >> n >> i >> j >> k >> m;
func1(n,i);
func2(n,j);
func3(n,k);
func4(n,m);
}
