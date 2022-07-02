#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LList{
    Node *head;
    Node *tail;
    
public:
    int count;
    LList(){
        head = NULL;
        tail = NULL;
        count = 0;
    }
    void addNode(int item);
    void addIndex(int item , int index);
    int deleteAt(int pos);
    bool deleteItem(int item);
    int indexOf(int item);
    void display();
};

//add end
void LList::addNode(int item){
    Node* newNode= new Node();
    newNode->data = item;
    if(head == NULL){
        head = newNode;
    }
    else{
    tail->next = newNode;
    }
    tail = newNode;
    count++;
}

//add give index
void LList :: addIndex(int item, int index){
    if(index < 0 || index > count+1) {
        return;
    }
    Node *newNode = new Node();
    newNode->data = item;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        if(index == 0){
            newNode->next = head;
            head = newNode;
        }
        else if(index == count+1){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            Node *temp = head;
            while(index-1 > 0){
            temp=temp->next;
            index--;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    count++;
    }
}

//delete a node at give index
int LList :: deleteAt(int pos){
    if(pos < 0 || pos > count+1) return -1;
    int dataRemoved = -1;
    Node *prev = new Node;
    Node *curr = head;
    while(pos > 0){
        prev = curr;
        curr = curr->next;
        pos--;
    }
    if(count>1){
        if(curr != head && curr->next != NULL){
            dataRemoved = curr->data;
            prev->next = curr->next;
            delete curr;
        }
        else if(curr == head){
            dataRemoved = curr->data;
            head = curr->next;
            delete curr;
        }
        else if(curr->next == NULL){
            dataRemoved = curr->data;
            prev->next = NULL;
            tail = prev;
            delete curr;
        }
    }
    else{
        dataRemoved = curr->data;
        delete curr;
        delete head;
        delete tail;
    }
    count--;
    return dataRemoved;
}

//delete a node when given a item
bool LList :: deleteItem(int item){
    bool ans = false;
    int idx = 0;
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == item){
            deleteAt(idx);
            ans = true;
        }
        idx++;
        curr = curr->next;
    }
    return ans;
}

int LList::indexOf(int item){
    int pivot=0;
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == item){
            return pivot;
        }
        curr = curr->next;
        ++pivot;
    }
    return -1;
}
//display a list
 void LList :: display(){
     if(head==NULL){
         return;
     }
     else{
         Node *curr = head;
         while(curr != NULL){
             cout<<curr->data<<"->";
             curr=curr->next;
         }
         if(curr == NULL){
             cout<<"NULL"<<endl;
         }
     }
 }

int main() {
    // insert code here...
    LList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.display();
    //cout<<endl;
    list.addIndex(5,2);
    //list.deleteAt(4);
    //list.deleteItem(5);
    list.display();
    cout<<list.indexOf(5);
    cout<<endl;
    cout<<list.count<<endl;
    return 0;
}
