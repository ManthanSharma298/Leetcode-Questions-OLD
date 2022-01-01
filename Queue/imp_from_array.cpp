#include <bits/stdc++.h>
using namespace std;
const int sz = 4e5;

class Queue{
private:
	int a[sz];
	int f,r;
public:
	// constructor
	Queue(){
		f=-1, r=-1;
	}
	bool isEmpty(){
		return f == -1 && r == -1;
	}
	bool isFull(){
		return (r+1)%sz == f;
	}
	void push(int x){
		if(isFull()){
			cout<<"Error: queue is full\n";
		}
		else{
			if(isEmpty()){
				f=0, r=0;
			}
			else{
				r = (r+1)%sz;
			}
			a[r] = x;
		}
	}
	int front(){
		if(isEmpty()){
			cout<<"Error: Queue is empty\n";
			return -1;
		}
		return a[f];
	}
	void pop(){
		if(isFull()){
			cout<<"Error: queue is full\n";
		}
		else{
			if(isEmpty()){
				cout<<"Error: Queue is empty\n";
			}
			else{	// when only single element is there
				if(f == r){
					f=-1, r=-1;	// make queue empty
				}
				else{
					f = (f+1)%sz;
				}
			}
		}
	}
	// wrong function but just to check as array is large, we didn't consider circular array in this 
	void print(){
		for(int i=f; i<=r; ++i){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
};

int main(){
	Queue q = Queue();
	q.push(2);
	q.push(3);
	q.push(4);
	q.print();
	q.pop();
	q.pop();
	q.print();
	cout<<(q.isEmpty() ? "empty\n" : "not_empty\n");
	q.push(5);
	q.print();


	return 0;
}