#include <iostream>
using namespace std;
const int Max=100;
//Stack
struct Stack{
	int arr[Max];
	int top;
};
void ini(Stack &s){
	s.top=-1;
}
void push(Stack &s , int x ){
	if(s.top>=Max-1){
		cout<<"th estack overflow!\n";
		return;
	}
	s.arr[++s.top]=x;
}
void pop(Stack &s , int &x , bool &empty){
	if(s.top==-1){
		cout<<"the stack Underflow!\n";
		empty=true;
		return ;
	}
	x=s.arr[s.top--];
	empty=(s.top==-1) ;
}

//Queue
struct Queue {
	int arr[Max];
	int rear , front ;
};
void init(Queue &q){
	q.front=-1;
	q.rear=-1;
}
void add(Queue &q , int x ){
	if(q.rear>=Max-1){
		cout<<"the Quee Overflow!\n";
		return ;
	}
	if(q.front==-1)
		q.front=0;
	q.arr[++q.rear]=x;
}
void remove(Queue &q , int &x , bool &empty){
	if(q.front==-1|| q.front > q.rear){
		cout<<"the Queue Underflow!\n";
		empty=true;
		return ;
	}
	x=q.arr[q.front++];
	empty=(q.front > q.rear) ;
}
void print(Queue &q){
	Queue t ;
	init(t);
	int x ; bool empty=false;
	while(!empty){
		remove(q,x,empty);
		cout<<x<<" ";
		add(t,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		remove(t,x,empty);
		add(q,x);
	}
}
void reverse(Queue &q){
	Queue t ;
	init(t);
	Stack obj;
	ini(obj);
	int x ; bool empty=false;
	while(!empty){
		remove(q,x,empty);
		push(obj,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		pop(obj,x,empty);
		add(q,x);
	}
	cout<<"reverse is done (*_*)!\n";
}

int main() {
	Queue o;
	init(o);
	add(o,1);
	add(o,2);
	add(o,3);
	add(o,4);
	add(o,5);
	print(o);
	reverse(o);
	print(o);
	
	return 0;
}