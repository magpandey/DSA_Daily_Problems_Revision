
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

Node* removeHead(Node* head){
    if(head == NULL) return NULL;
    
    Node* temp = head;
    head = head -> next;
    if(head == NULL){
        delete(temp);
        return NULL;
    }
    delete(temp);
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL) return NULL;
    if(head -> next == NULL){
        delete(head);
        return NULL;
    }
    Node* temp = head;
    while(temp ->next  != NULL){
        temp = temp -> next;
    }
    Node* prev = temp -> before;
    prev -> next = nullptr;
    delete(temp);
    
    return head;
}

Node* removeKth(Node* head, int k){
    if(head == NULL) return NULL;
    Node* temp = head;
    
    int cnt = 0;
    while(temp != NULL){
        cnt ++;
        if(cnt == k){
          Node* prev = temp -> before;
          Node* front = temp -> next;
          if(prev == NULL && front == NULL){
              delete(temp);
              return NULL;
          }else if(prev == NULL){
              return removeHead(temp);
          }else if(front == NULL){
              return removeTail(head);
          }
          prev -> next = temp -> next;
          front -> before = temp -> before;
          temp -> before = nullptr;
          temp -> next = nullptr;
          delete(temp);
          break;
          
        }
        temp = temp -> next;
    }
    return head;
}

int main() {
    vector<int>arr = {1,3,9,4,2};
    
    Node* head = convertArrayToLinkList(arr);
    print(head);
    head = removeKth(head,5);
    print(head);
    
    return 0;
}