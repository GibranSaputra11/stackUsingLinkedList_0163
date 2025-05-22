#include <iostream>
using namespace std;

//Node class representing a single node in the linked list
class Node{
    public:
        int data;
        Node* next;

        Node(){
            next = NULL;
        }
};  

// Stack class
class Stack{
    private:
        Node* top; //Pointer to the top node of the stack

    public:
        Stack(){
            top = NULL; //Initialize the stack with a null top pointer
        }
    
    // Push operator: Insert an element onto the top of the stack
    int push(int value){
        Node* newNode = new Node(); // 1. Alocate memory for the new node
        newNode->data = value; // 2. Assign value
        newNode->next = top; //3. Set the next pointer of the new node to the current top
        top = newNode; // 4. Update the top pointer to the new node
        cout << "Push Value: " << value << endl;
        return value;
    }

    // Pop opreation: Remove the topmost element from the stack
    void pop(){
        if (isEmpty()){
            cout << "Stack is empty." << endl;
        }

        Node* temp = top; // Create a temporary pointer to the top node
        top = top->next; // Update the top pointer to the next node
        cout << "Popped value: " << top->data << endl;
    }

    // Peek/Top opeeration: Retrieve the value of the topmost element without removing
    void peek(){
        if (top == NULL){
            cout << "List is empty." << endl;
        }
        else{
            Node *current = top;
            while (current != NULL){
                cout << current->data << " " << endl;
                current = current->next;
            }
            cout << endl;
        } // Retrun the valiue of the top node
    }

    // IsEmpty operation: Check if the stack is empty
    bool isEmpty(){
        return top == NULL; //Retrun true if top pointer is NULL, indicating an empty stack
    }
};

int main(){
    Stack stack;

    int choice = 0;
    int value;

    while (choice != 5){
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value); // Push the enterd value onto the stack
                break;
            case 2:
                if (!stack.isEmpty()){
                    stack.pop(); // Pop the top element from the stack
                }
                else{
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            case 3:
                if (!stack.isEmpty()){
                    stack.peek(); // Get the value of the top element 
                }
                else{
                    cout << "Stack is empty. No top value." << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
        }
    }
}