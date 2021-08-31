#include <iostream>

using namespace std;

template <class T>
class Node {
public:
    T info;
    Node<T> *next;

    Node(T data) {
        next = NULL;
        info = data;
    }

};

template <class T>
class LinkedList {
private:
    Node<T> *start;
public: 

    LinkedList(){
        start = NULL;
    }

    void print(){

        Node<T> *curr = start;
        while (curr != NULL)
        {
            cout<<curr->info<<" ";
            curr = curr -> next;
        }
        cout<<endl;
    }

    void insertToFront(T data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = start;
        start = newNode;
    }

    void insertToEnd(T data) {
        Node<T> *newNode = new Node<T>(data);
        if(start == NULL)
        {
            start = newNode;   
        }
        else {
            Node<T> *curr = start;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void insertOrdered(T data) {
        if(start == NULL) {
            start = new Node<T>(data);
        }

        else {

            Node<T>  *newNode = new Node<T>(data);
            Node<T> *curr = start;
            Node<T> *prev = NULL;
            while (curr != NULL && data > curr->info)
            {
                prev = curr;
                curr = curr -> next;
            }

            if(prev == NULL) {
                newNode -> next = start;
                start = newNode;
            }

            else if(curr == NULL) {
                prev->next = newNode;
            }
            else {
                prev->next = newNode;
                newNode -> next = curr ;
            }

        }
    }

    bool deleteItem(T data) {
        if(start == NULL)
            return false;

        else {
            Node<T> *curr = start;
            Node<T> *prev = NULL;
            while (curr != NULL && curr->info != data)
            {
                prev = curr;
                curr = curr -> next;
            }

            if(curr == NULL)
                return false;

            else if(prev == NULL) {
                start = start -> next;
                delete curr;
                return true;
            }
            else {
                prev->next = curr -> next;
                delete curr;
                return true;
            }
        }
    }
   void  buildFromTexFile(char *fname){

    }
    LinkedList<T> countNegative(){
        Node<T> *curr=start;
        Node<T> *newlist;
        int count=0;
        while(curr->next!=NULL){
            if(curr->info<0){
                newlist->info=curr->info;
            }
            curr=curr->next;
            newlist=newlist->next;
        }
        return *newlist;

    }
};

int main() {
    LinkedList<int> list;

    list.insertOrdered(5);
    list.insertOrdered(-15);
    list.insertOrdered(8);
    list.insertOrdered(25);
    list.insertOrdered(-1);
    list.insertOrdered(13);

    //list.deleteItem(1);
    //list.deleteItem(8);
    //list.deleteItem(25);

    list.print();
    LinkedList<int> list1;
    list1=list.countNegative();
   return 0;
}