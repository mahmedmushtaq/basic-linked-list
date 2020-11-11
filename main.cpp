#include <iostream>
using namespace std;

class node{
  public:
      float data;
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
    int choice;
	bool quit = false;
	int temp;

	while (!quit) {
		cout << "\nCreate a Linked List" << endl;
		cout << "1. Insert Nodes" << endl;
    cout << "2. Insert Nodes at the Head" << endl;
		cout << "3. Insert Nodes at any location" << endl;
		cout << "4. Display the Linked List" << endl;
		cout << "5. Delete any Node from the List" << endl;
		cout << "6. Count the number of Nodes" << endl;
	 	cout << "7. Quit" << endl;
    cout << "Choice = "; 
		cin >> choice;
		if (choice == 7) break;
		switch (choice) {
    case 1:
      cout << "\nEnter an Integer Value: ";
			cin >> temp;
			list.appendNode(temp);
      break;

		case 2:

			cout << "\nEnter an Integer Value: ";
			cin >> temp;
			list.insertAtHead(temp);
			break;
		case 3:
			int pos;
			cout << "\nEnter the value and position: ";
			cin >> temp;
			cin >> pos;
			list.insertAtLocation(pos, temp);
			break;
		case 4:
			list.displayList();
			break;
		case 5:

			cout << "\nEnter the value of the node: ";
			cin >> temp;
			list.deleteNodeByValue(temp);
			cout << "\n" << temp << " was deleted from the list";
			break;
		case 6:
			cout << "\nSize of linked List: " << list.countList();
			break;
		default:
			cout << "\nInvalid";
		}

	}

    cout << "size is = "<< list.countList();
    return 0;
}
