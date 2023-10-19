#include <iostream>
using namespace std;

struct Node{
    int     data;
    Node    *next;

    Node(){
        this->next = NULL
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next=NULL){
        this->data = data;
        this->next = next;
    }
}
template<class T>
class List{
public:
    int     count;
    Node    *head;
    Node    *tail;

    List(){
        count = 0;
        head = NULL;
        tail = NULL;
    }
    void Create(){
        count = 0;
        head = NULL;
        tail = NULL;
    }
    void add(const &T e){
        Node pNew = new Node(e);
        if(tail==NULL){
            head = tail = pNew;
        } else {
            tail->next = pNew;
            tail = pNew;
        }
        count++;
    }

    void add(int index, const &T e){
        if(index <0 || index >= count){
            throw out_of_range("Index out of bound");
        if(index == count){
            add(e);
        } else if (index == 0){
            Node pNew = new Node(e);
            head->next = pNew;
            head = pNew;
            count++;
        } else {
            Node pCur= head;
            for(int i=1; i<index; i++){    
                pCur = pCur->next;
            }
            Node pNew = new Node(e, pCur->next);

            //Node pNew = new Node(e);
            //pNew->next = pCur->next;
            pCur->next = pNew;
            count++;
        }
    }
    int size(){
        return count;
    }
}

int main(){
    List<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
        list.add(index);
    }

    cout << list.toString();
}