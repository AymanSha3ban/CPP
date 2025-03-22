#include <iostream>
using namespace std ;

//Q1 : 
const int Max= 100 ;
struct Stack{
	int arr[Max];
	int top;
};
void initialize(Stack &s){
	s.top=-1 ;
}
void push(Stack &s, int x ){
	if(s.top==Max-1){
		cout<<"The Stack is Overflow!\n" ;
		return  ;
	}
	s.arr[++s.top]=x ; 
}
void pop(Stack &s, int &x ,bool &empty){
	if(s.top==-1){
		cout<<"The stack is Underflow!\n" ;
		empty=true;
		return ;
	}
	x=s.arr[s.top--];
	empty=(s.top==-1);
}
void print(Stack &s){
	if (s.top == -1) {  
	    cout << "Stack is empty!\n";
        return;
    }
	Stack t ;
	initialize(t);
	bool empty=false;
	int x;
	while(!empty){
		pop(s,x,empty);
		cout<<x<<" ";
		push(t,x);
	}
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
}
void insert(Stack &s, int index, int newval) {
    if (index > s.top + 1 || index < 0 || s.top == Max - 1) {
        cout << "Invalid index or stack overflow!\n";
        return;
    }
    
    for (int i = s.top + 1; i > index; i--) {
        s.arr[i] = s.arr[i - 1];
    }

    s.arr[index] = newval;
    s.top++;
}
//Q2:
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void is_prime(Stack &s){
	if (s.top == -1) { 
	    cout << "Stack is empty!\n";
        return;
    }
	Stack t ;
	initialize(t);
	bool empty=false;
	int x;
	int i=1 ;
	while(!empty){
		pop(s,x,empty);
		if(isPrime(x)){
			cout<<"element "<<i++<<" is prime = "<<x<<" \n";
		}
		else{
			cout<<"element "<<i++<<" not prime!\n";	
		}
		push(t,x);
	}
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
}
int main() {
	cout<<"Q1 : Insert an element X in a Sorted Stack : \n";
	Stack obj;
	initialize(obj);
	push(obj,10);
	push(obj,20);
	push(obj,30);
	push(obj,40);
	push(obj,50);
	cout<<"Original element in Stack : \n ";
	print(obj);
	cout<<"\nAfter pop : \n ";
	int x ; bool empty=false;
	pop(obj,x,empty);
	print(obj) ;
	cout<<"\nAfter insert 35  : \n ";
	insert(obj,3,35);
	print(obj) ;
	cout<<"\nQ2 : Check about a prime numbers : \n";
	is_prime(obj) ;
	cout<<"\ninsert a prime number (19) : \n";
	insert(obj,1,19);
	print(obj) ;
	cout<<"\nNow Check about a prime numbers : \n";
	is_prime(obj) ;
	cout<<"\nI think that everything is fine :)!";
	return 0;
}


