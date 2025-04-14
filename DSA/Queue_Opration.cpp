#include <iostream>
using namespace std;
const int Max=100;
//Stack to reverse
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
//Q one : 
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
// Q two :
void rem_ele(Queue &q , int pos){
	Queue t ;
	init(t);
	int x ; bool empty=false;
	while(!empty){
		remove(q,x,empty);
		if(x==pos){
			continue;
		}
		add(t,x);
	}
	empty=false;
	while(!empty){
		remove(t,x,empty);
		add(q,x);
	}
	cout<<"the elemnt in position deleted well!\n";
}
// Q three :
void swap_f2ele(Queue &q){
	int f,s;
	Queue t ;
	init(t);
	int x ; bool empty=false;
	remove(q,f,empty);
	remove(q,s,empty);
	while(q.front < q.rear - 1){
		remove(q,x,empty);
		add(t,x);
	}
	int l2, l1;
	remove(q, l2, empty); 
	remove(q, l1, empty);
	add(q,l1);
	add(q,l2);
	empty=false;
	while(!empty){
		remove(t,x,empty);
		add(q,x);
	}
	add(q,f);
	add(q,s);
	cout<<"swap done!\n";
}
int main() {
	Queue o;
	init(o);
	add(o,1);
	add(o,2);
	add(o,3);
	add(o,4);
	add(o,5);
	add(o,6);
	add(o,7);
	print(o);
	reverse(o);
	print(o);
	reverse(o);
	rem_ele(o,3);
	print(o);
	swap_f2ele(o);
	print(o);
	return 0;
}