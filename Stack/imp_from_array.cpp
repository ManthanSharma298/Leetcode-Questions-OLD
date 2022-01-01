#include <bits/stdc++.h>

using namespace std;
#define sz 2005

class stk{
	int a[sz];
	int tp = -1;
public:
	void push(int x){
		if(tp == sz-1){
			cout<<"Error: stack Overflow";
		}
		else{
			a[++tp] = x;
		}
	}
	void top(){
		cout<<a[tp]<<"\n";
	}
	void pop(){
		tp--;
	}
	void print(){
		for(int i=0; i<=tp; ++i){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
};

int main(){
	stk s;
	s.push(2);
	s.push(3);
	s.print();
	s.pop();
	s.top();
	s.push(50);
	s.print();

	return 0;
}