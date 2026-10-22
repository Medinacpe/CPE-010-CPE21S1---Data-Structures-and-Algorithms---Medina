#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData;

void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void display();

int main() {
    int choice;
    std::cout<<"Enter the number of max elements for the new stack: ";
    std::cin>>i;
    
    while(true){
        std::cout<<"---Stack Operations---" << std::endl;
        std::cout<<"1. PUSH\n2. POP\n3. TOP\n4. isEMPTY\n5. Display\n";
        std::cin>>choice;
        std::cout<<std::endl;
        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<< isEmpty() <<std::endl;
            break;
            case 5: display();
            break;
            default: std::cout<< "Invalid choice!\n";
        }
    }
    
    return 0;
}

bool isEmpty(){
    // create a condition to check whether the top element is equal to -1
    if(top == -1) return true;
    return false;
}

bool isFull(){
    // check if we reach the maximum capacity of the array
    if(top >= i-1) return true;
    return false;
}

void push(){
    // check if full -> if yes, return error
    if(isFull()){
        std::cout<<"Stack overflow!\n";
        return;
    }

    std::cout << "New value to add into the stack: ";
    std::cin >> newData;
    // increment the top (index by 1) then assign the new data
    stack[++top] = newData;
    std::cout<<std::endl;
}

void Top(){
    // check if the stack is empty
    if(isEmpty()){
        std::cout<<"Stack underflow.\n"<<std::endl;
    }

    std::cout<<"The element on the top of the stack is " << stack[top]<<std::endl;
}

void pop(){
    if(isEmpty()){
        std::cout<<"Stack underflow.\n"<<std::endl;
    }

    //display the top value
    std::cout<<"Popping: " << stack[top];
    //decrement the top vaue from the stack
    top--;
}

void display(){
    if(isEmpty()){
        std::cout << "Stack underflow.\n";
        return;
    }
    std::cout << "Stack (top to bottom): ";
    for(int j = top; j >= 0; j--){
        std::cout << stack[j] << " ";
    }
    std::cout << std::endl;
}