
#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArrayToLinkList(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i ++){
        
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
        
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* insertAtk(Node* head, int k, int elem){
    if(head == NULL){
        if(k == 1){
            Node* temp = new Node(elem);
            return temp;
        }else{
            return NULL;
        }
    }
    if(k == 1){
        Node* temp = new Node(elem);
        temp -> next = head;
        return temp;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            Node* x = new Node(elem);
            x -> next = temp -> next;
            temp -> next = x;
            break;
        }
            temp = temp -> next;
        
    }
    return head;
    
}

Node* insertVal(Node* head,int elem, int val){
    if(head == NULL) return NULL;
    
    if(head -> data == val){
        Node* temp = new Node(elem);
        temp -> next = head;
        return temp;
    }
    Node* temp = head;
    while(temp){
        if(temp -> next -> data == val){
            Node* x = new Node(elem);
            x -> next = temp -> next;
            temp -> next = x;
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
    head = insertAtk(head,3,6);
    print(head);
    head = insertVal(head,8,9);
    print(head);
    
    return 0;
}