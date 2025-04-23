#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
class Linkedlist {
    public:
    Node* head;
    Linkedlist(){
        head=NULL;
    }
    bool isempty(){
        return (head==NULL) ;
    }
    void insert(int newV){
        Node* newN = new Node;
		newN->data = newV;
        if(isempty()){
            newN->next=NULL;
            head=newN;
        }
        else{
            newN->next=head;
            head=newN;
        }
    }
    void print(){
        Node* temp;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void count(){
        Node* temp;
        temp=head;
        int k=0;
        while(temp!=NULL){
            k++;
            temp=temp->next;
        }
        cout<<"the number of items = "<<k<<endl;
    }
    bool isfound(int item){
        Node* temp;
        temp=head;
        bool f=false;
        while(temp!=NULL){
            if(temp->data==item){
            	f=true;
			}
            temp=temp->next;
        }
        return f;
    }
};

int main(){
    Linkedlist obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.print();
    obj.count();
    if(obj.isfound(4)){
    	cout<<"found!\n";	
	}
	else 
	cout<<"Not found!\n";
return 0;
}