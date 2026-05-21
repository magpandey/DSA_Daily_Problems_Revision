#include <iostream>
#include <vector>
#include <string>

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
Node* convertArraytolink(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i ++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}
void printLinkList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}
Node* removeHead(Node* head){
if(head  == NULL) return head;

Node* temp = head;
head = head -> next;
delete(temp);
return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL) return head;
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete(temp -> next);
    temp -> next = NULL;
    return head;
}

//algorithm for removing k ;
Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    
    if(k == 1){
        
        if(head -> next == NULL){
            delete(head);
            return NULL;
        }
        Node* temp = head;
        head = head -> next;
        delete(temp);
        return head;
    }
        int cnt = 1;
        Node* prev = NULL;
        Node* temp = head;
        while(temp != NULL){
            if(cnt == k){
                prev -> next = prev -> next -> next;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
            cnt ++;
        }
    return head;
}
Node* removeElem(Node* head, int elem){
    if(head == NULL) return head;
    
    if(head -> data == elem){
        
        if(head -> next == NULL){
            delete(head);
            return NULL;
        }
        Node* temp = head;
        head = head -> next;
        delete(temp);
        return head;
    }
        Node* prev = NULL;
        Node* temp = head;
        while(temp != NULL){
            if(temp -> data == elem){
                prev -> next = prev -> next -> next;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
    return head;
}
int main(){
    vector<int>arr = {1,2,3,4};
    Node* head = convertArraytolink(arr);
    printLinkList(head);
    //Here you can do all your functions and check on this lInked list
    printLinkList(head);
   
}