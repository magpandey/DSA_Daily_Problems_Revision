
#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* before;
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        before = nullptr;
    }
    Node(int data1,Node* next1, Node* before1){
        data = data1;
        next = next1;
        before = before1;
    }
};
Node* convertArrayToLinkList(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i ++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){
   Node* temp = head;
   while(temp != NULL){
       cout << temp -> data << "  ";
       temp = temp -> next;
   }
   cout << endl;
}

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val,head,nullptr);
    head -> before = newHead;
    return newHead;
}
Node* insertBeforeTail(Node* head, int val){
    if(head -> next == NULL){
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* prev = tail -> before;
    Node* newNode = new Node(val,tail,prev);
    prev -> next = newNode;
    tail -> before = newNode;
    return head;
}

int main() {
    vector<int>arr = {1,3,9,4,2};
    
    Node* head = convertArrayToLinkList(arr);
    head = insertBeforeTail(head,6);
    print(head);
    
    
    return 0;
}