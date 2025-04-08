#include <iostream>
using namespace std ;
const int Max= 100;
struct Stack{
	int arr[Max];
	int top;
};
void init(Stack &s){
	s.top=-1;
}
void push(Stack& s , int x){
	if(s.top>=Max-1){
		cout<<"The Stack Oferflow ! \n";
		return ;
	}
	s.arr[++s.top]=x;
}
void pop(Stack& s , int &x ,bool &empty){
	if(s.top==-1){
		cout<<"The Stack Underflow !\n";
		return ;
	}
	x=s.arr[s.top--];
	empty=(s.top==-1);
}
void print(Stack &s){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	while(!empty){
		pop(s,x,empty);
		cout<<x<<" ";
		push(t,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
}
void count(Stack &s){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	int counter=0;
	while(!empty){
		pop(s,x,empty);
		counter++;
		push(t,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
	cout<<"counter of Stack = "<<counter<<"\n";
}
void findmax(Stack &s){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	int max= INT_MIN;
	while(!empty){
		pop(s,x,empty);
		if(x>max){
			max=x;
		}
		push(t,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
	cout<<"The max of stack is "<<max<<endl;
}
void findmin(Stack &s){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	int min=INT_MAX;
	while(!empty){
		pop(s,x,empty);
		if(x<min){
			min=x;
		}
		push(t,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
	cout<<"The min of stack is "<<min<<endl;
}
int sum (Stack &s){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	int sum= 0;
	while(!empty){
		pop(s,x,empty);
		sum+=x;
		push(t,x);
	}
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
	return sum;
}
float avrage (Stack &s){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	int sum= 0;
	int i=0;
	while(!empty){
		pop(s,x,empty);
		sum+=x;
		i++;
		push(t,x);
	}
	float avrage =(float)sum/i;
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
	return avrage;
}
void remove_target(Stack &s ,int tar){
	Stack t;
	init(t);
	int x ;
	bool empty=false;
	while(!empty){
		pop(s,x,empty);
		if(x==tar)
		continue;
		push(t,x);
	}
	cout<<"\n";
	empty=false;
	while(!empty){
		pop(t,x,empty);
		push(s,x);
	}
	cout<<"target "<<tar<<" are removed!\n";
}


int main(){
	Stack obj;
	init(obj);
	push(obj,1);
	push(obj,2);
	push(obj,3);
	push(obj,4);
	push(obj,5);
	push(obj,6);
	push(obj,7);
	print(obj);
	count(obj);
	findmax(obj);
	findmin(obj);
	cout<<"the sum of elemnt of stack is "<<sum(obj)<<endl;
	cout<<"the avrage of elemnt of stack is "<<avrage(obj)<<endl;
	remove_target(obj,7);
	int x;
	bool empty=false;
	pop(obj,x,empty);
	print(obj);
	return 0; 
}