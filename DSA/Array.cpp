#include <iostream>
using namespace std ;
class Array{
	int length;
	int size ;
	int* items;
	public:
		Array(int Asize){
			length=0;
			size=Asize;
			items = new int[size];
		}
		int getsize(){
			return size ;
		}
		int getlength(){
			return length ;
		}
		void Fill(){
			int l;
			cout<<"Enter the number element of Array : \n";
			cin>>l;
			if(l>size||l==0){
				cout<<"Error plz check ur number !\n";
				return ;
			}
			else{
				cout<<"Enter the element of array : \n";
				for(int i=0; i<l; i++){
					cout<<"Element "<<i+1<<" : ";
					cin>>items[i];
					cout<<"\n";
					length++;
				}
				cout<<"Array are filled !\n";
			}
		}
		void Display(){
			cout<<"Array = { ";
			for(int i=0; i<length;i++){
				cout<<items[i]<<" ";
			}
			cout<<"}\n";
		}
		void Insert(int index , int nv){
			if(index < 0|| index > length ){
				cout<<"Error!\n";
				return ;
			}
			else {
				//shifting 
				for(int i=length; i>index; i--){
					items[i]=items[i-1];
				}
				items[index]=nv;
				cout<<"new val are inserted \n";
				length++;
			}
		}
		void Delete(int index ){
			if(index<0||index>size){
				cout<<"Error!\n";
				return ;	
			}
			else{
				for(int i=index; i<length; i++){
					items[i]=items[i+1];
				}
				length--;
				cout<<"the number of index "<<index<<" are deleted \n";
			}
		}
		void Append(int num){
			if(length<size){
				items[length]=num;
				length++;
				cout<<"the number are appended!\n";
			}
			else{
				cout<<"Array are full!\n";
			}
		}
		void Search(int k){
			if(k<0||k>size){
				cout<<"Error NOT FOUND!\n";
				return ;
			}
			else{
				bool found=false;
				int ind=0;
				for(int i=0; i<length; i++){
					if(items[i]==k){
						found=true;
						ind=i;	
					}
				}
				if(found){
					cout<<"the key is founded element number "<<ind+1<<" in array\n";
				}
				else{
					cout<<"Error NOT FOUND!\n";
				}
			}
		}
		void Update(int in ,int uv){
			if(in<0||in>size||in>length){
				cout<<"Error NOT FOUND!\n";
				return ;
			}
			else{
				items[in]=uv;
				cout<<"The index are Ubdated !\n";
			}	
		}
		void Merge(Array& o){
			int newsize= size +o.getsize();
			size=newsize;
			int* old =items;
			items=new int[newsize];
			int i;
			for(i=0;i<length;i++){
				items[i]=old[i];
			}
			delete[]  old ;
			int j=i;
			for(i=0;i<o.getlength();i++){
				items[j++]=o.items[i];
				length++;
			}
			cout<<"Merge is Done (*_*)\n";
		}
		void sortArray(){
			for(int i=0;i<length-1;i++){
				for(int j=0;j<length-i-1;j++){
				if(items[j]>items[j+1]){
					int temp = items[j];
					items[j]=items[j+1];
					items[j+1]=temp ;
				}
			}
			}
		}		
};

int main(){
	Array obj(20);
	obj.Fill();
	obj.Display();
	obj.Insert(5,6);
	obj.Display();
	obj.Append(7);
	obj.Display();
	obj.Delete(3);
	obj.Display();
	obj.Insert(3,4);
	obj.Display();
	obj.Search(4);
	obj.Display();
	Array obj1(10);
	obj1.Fill();
	obj1.Display();
	obj.Merge(obj1);
	obj.Display();
	obj.sortArray();
	obj.Display();
	return 0; 
}