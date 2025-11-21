#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next_ptr;
};

class Stack {
private:
    Node* head; 
    int size;
    int capacity;

public:
    Stack(int maxCapacity) {
        head = nullptr;
        size = 0;
        capacity = maxCapacity;
    }

    ~Stack() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next_ptr;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    void push(std::string value) {
        if (isFull()) {
            std::cout << "Stack overflow! cannot push: " << value << "\n";
            return;
        }
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_ptr = head; 
        head = newNode;            
        size++;
        std::cout << "\nPushed: " << value << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow! Cannot pop\n";
            return;
        }
        std::string popped = head->data;
        Node* temp = head; 
        head = head->next_ptr; 
        delete temp; 
        size--;
        std::cout << "\nPopped value: " << popped << std::endl;
    }

    void peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!\n";
            return;
        }
        std::cout << "\nTop element: " << head->data << std::endl;
    }
    
    // Check if the stack is full
    bool isFull() {
        return size >= capacity;
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "\nStack is empty!" << std::endl;
            return;
        }
        std::cout << "\nStack elements (Top to Bottom): \n";
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next_ptr;
        }
        std::cout << std::endl;
    }

    int getCurrentSize() {
        return size;
    }

    int getMaxSize() {
        return capacity;
    }
};

int main() {
    int stack_size;
    int option = 0; 
    std::string value;

    std::cout << "Enter Stack size: ";
    while (!(std::cin >> stack_size) || stack_size <= 0) {
        std::cout << "Invalid input. Enter a positive integer for Stack size: ";
        std::cin.clear(); 
        std::cin.ignore(10000, '\n'); 
    }

    Stack myStack(stack_size);
    
    while (option != 7) {
        std::cout << "\n--- Stack Operations ---\n";
        std::cout << "1. Push\n2. Pop\n3. Peek\n4. Check if stack is full\n5. Check if stack is empty\n6. Display Stack\n7. EXIT\nEnter option: ";
        
        if (!(std::cin >> option)) {
            std::cout << "\nInvalid input. Please enter a number from 1 to 7.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue; 
        }

        switch (option) {
            case 1:
                std::cout << "Enter value to push: ";
                if (std::cin >> value) {
                    myStack.push(value);
                } else {
                    std::cout << "\nInvalid input for value.\n";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.peek();
                break;
            case 4:
                if (myStack.isFull()) {
                    std::cout << "\nStack is FULL";
                } else {
                    std::cout << "\nStack is NOT FULL";
                }
                std::cout << "\nCurrent Size: " << myStack.getCurrentSize() << " Max Capacity: " << myStack.getMaxSize() << std::endl;
                break;
            case 5:
                if (myStack.isEmpty()) {
                    std::cout << "\nStack is EMPTY";
                } else {
                    std::cout << "\nStack is NOT empty";
                }
                std::cout << "\nCurrent Size: " << myStack.getCurrentSize() << " Max Capacity: " << myStack.getMaxSize() << std::endl;
                break;
            case 6:
                myStack.display();
                break;
            case 7:
                std::cout << "\nExiting program.\n";
                break;
            default:
                std::cout << "\nInvalid option. Please enter a number from 1 to 7.\n";
                break;
        }
    } 
    return 0;
}