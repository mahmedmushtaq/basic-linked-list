#include <iostream>
using namespace std;

class node{
  public:
      int data;
      node *next;
    
};

class FloatList{
  node *head;
  node *tail;
  node *newNode;
  int count = 0;

public:
  FloatList(){
    head = NULL;
    tail = NULL;

  }

  void insertAtHead(int value){
   
    newNode = new node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
   
    

  }

  void appendNode(int value){
    newNode = new node();
    newNode->data = value;
 
   if(isEmpty()){
      // if list is empty then insert data at head
      head = newNode;
    }else{
        
       tail = head;
      while(tail->next != NULL){
         tail = tail->next;
       }
       tail->next = newNode; 
    }

    

  };

   bool isEmpty(){
    return head == NULL;
  }

  void displayList(){
    tail  = head;
    while(tail){
      cout << tail->data <<endl;
      tail = tail->next;
    }
  }


  int countList(){
    tail = head;
    int count  = 0;
    while(tail){
      count ++;
      tail=tail->next;
    }
     return count;
  }


  void insertAtLocation(int position, int newValue){
   
    tail = head;
    int i = 0;
    while(tail->next){
     if(++i == position){
      
      newNode = new node();
      newNode->data = newValue;
      newNode->next = tail->next;
      tail->next = newNode;
       
       
     }else 
     tail = tail->next;
    }
  };

  void deleteNodeByValue(int value){
   node *nodePtr, *previousNode;
// If the list is empty, do nothing.
    if (!head)
    return;

    if(head->data == value){
      nodePtr = head->next;
      delete head;
      head = nodePtr;
    }else {
      // Initialize nodePtr to head of list
      nodePtr = head;
      // Skip all nodes whose value member is not equal to num.
      while (nodePtr != NULL && nodePtr->data != value)
      {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
      }
      // Link the previous node to the node after nodePtr, then delete
       
      previousNode->next = nodePtr->next;
      delete nodePtr;
    } 


   }



 
  
};

int main() {
    FloatList list;
    list.insertAtHead(3);
    list.insertAtHead(4);
    list.insertAtHead(7);
    
    list.insertAtLocation(2,22);
    list.deleteNodeByValue(7);
    list.displayList();

    cout << "size is = "<< list.countList();
    return 0;
}