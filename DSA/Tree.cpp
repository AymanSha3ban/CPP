#include <iostream>
using namespace std ;
struct Node{
	int data ;
	Node * right;
	Node * left;
};
void insert(Node *&root , int x){
	if(root == NULL){
		Node *t=new Node();
		t->data=x;
		t->left=NULL; 
		t->right=NULL;
		root=t; 
	}
	else if (x <= root->data){
		insert(root->left,x);
	}
	else{
		insert(root->right,x);
	}
}
bool search(Node *&root , int target){
	bool found = false;
	if(root==NULL){
		return found=false ;	
	}
	else if (root->data==target){
		return found=true;
	}
	else{
		if(target<=root->data){
			search(root->left,target) ;
		}
		else {
			search(root->right,target);
		}			
	}
}
int count(Node *& root){
	if(root==NULL){
		return 0;
	}
	else{
		return 1+count(root->left) +count(root->right);
	}
}
void min(Node *&root){
	if (root== NULL){
		cout<<"is empty\n";
		return ;
	}
	else if (root->left==NULL){
		cout<<"min = "<<root->data<<endl;
		return;
	}else{
		return min(root->left);
	}
}
void max(Node *&root){
	if (root== NULL){
		cout<<"is empty\n";
		return ;
	}
	else if (root->right==NULL){
		cout<<"max = "<<root->data<<endl;
		return;
	}else{
		return max(root->right);
	}
}
void print(Node *& root){
	if(root==NULL){
		return;
	}
	else{
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}
int main() {
	Node *root =NULL;
	insert(root,10);
	insert(root,8);
	insert(root,12);
	insert(root,5);
	insert(root,6);
	insert(root,20);
	if(search(root,7)){
		cout<<"found \n";
	}else{
		cout<<"not found \n";
	}
	if(search(root,20)){
		cout<<"found \n";
	}else{
		cout<<"not found \n";
	}
	cout<<"tne count = "<<count(root) <<endl;
	min(root);
	max(root);
	printf("The element of tree :\n");
	print(root);
	return 0;
}