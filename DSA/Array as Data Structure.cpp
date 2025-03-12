#include <iostream>
using namespace std;
class Array {
    int length;
    int size;
    int* items;
public:
    Array(int Asize) {
        length = 0;
        size = Asize;
        items = new int[Asize];
    }
    int getLength() { return length; }
    int getSize() { return size; }
    void Fill() {
        int n;
        cout << "Enter no of items : ";
        cin >> n;
        if (n > size) {
            cout << "greater than size try again!\n";
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << "item number " << i + 1 << " : ";
                cin >> items[i];
                length++;
            }

        }
    }
    void Display() {
        cout << "Array = { ";
        for (int i = 0; i < length; i++) {
            cout << items[i] << " ";
        }
        cout << "} .\n";
    }
    void Append(int newitem) {
        if (length < size) {
            items[length] = newitem;
            length++;
        }
        else {
            cout << "Array is full! no append.\n";
        }
    }
    void insert(int index, int item1) {
        if (index != 0 && length < size ) {
            //Shifting 
            for (int i = length; i > index; i--) {
                items[i] = items[i - 1];
            }
            items[index] = item1;
            length++;
        }
    }
    void Searsh(int key) {
        bool isfound=false;
        int index=0;
        for (int i = 0; i < length; i++) {
            if (items[i] == key) {
                isfound = true;
                index++;
            }
        }
        if (isfound == true) {
            cout << "this number have found in index = " <<index<< endl;
        }
        else {
            cout << "there is no this number !\n";
        }
        

    }
    void Delete(int place) {
        if (place > size || length == size) {
            cout << "it's impossible process!\n";
        }
        else {
            for (int i = place; i < length;i++) {
                items[i] = items[i + 1];
            }
            length--;
        }

    }
     
    void Enlarge(int new_size) {
        int large = size + new_size;
        size = large;
        int* old = items;
        items = new int[size];
        for (int i = 0; i < size; i++) {
            items[i] = old[i];
        }
        delete old;

        cout << "Now size of Array = " << getSize() << endl;
    }
    void Merge(Array &other) {
        int nSize = size + other.getSize();
        size = nSize;
        int* old = items;
        items = new int[size];
        int i;
        for (i = 0; i < length;i++) {
            items[i] = old[i];
        }
        delete old;
        int j = i;
        for (i = 0; i < other.getLength();i++) {
            items[j++] = other.items[i];
            length++;
        }

        cout << "Done (*_*)!\n";
    }

};
int main() {
    int s;
    cout << "Enter the size of arry \n";
    cin >> s;
    Array arr(s);
    arr.Fill();
    arr.Display();
    int x;
    cout << "Enter a num that u wann Append it : ";
    cin >> x;
    arr.Append(x);
    arr.Display();
    arr.insert(2, 10);
    arr.Display();
    arr.Searsh(2);
    arr.Delete(0);
    arr.Display();
    arr.Enlarge(15);
    Array obj2(3);
    obj2.Fill();

    arr.Merge(obj2);
    arr.Display();

    return 0;
}
