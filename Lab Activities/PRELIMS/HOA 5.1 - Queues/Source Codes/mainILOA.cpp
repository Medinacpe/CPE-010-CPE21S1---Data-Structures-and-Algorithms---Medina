#include <iostream>
#include <queue>

// prototype
void display(std::queue<char> r);


int main() {
    std::queue<char> q;

    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');

    //display queue
    std::cout<<"Displaying the queue:";
    display(q);

    //empty
    if(q.empty()){
        std::cout<<"Queue is empty!\n";
    } else {
        std::cout<<"Queue has elements.\n";
    }

    //size
    std::cout<<"The amount of elements in the queue is "<<q.size()<<".\n";

    //front
    std::cout<<"Element at the front: "<<q.front()<<"\n";

    //back
    std::cout<<"Element at the back: "<<q.back()<<"\n";

    //pop
    std::cout<<"Popping...\n";
    q.pop();

    //display queue
    std::cout<<"Displaying the queue:";
    display(q);

    //push
    std::cout<<"Pushing...\n";
    q.push('Z');

    //display queue
    std::cout<<"Displaying the queue:";
    display(q);


    // ### CHALLENGE
    std::cout<<std::endl; // spacing

    // Removing the queue!
    std::cout<<"Destroying the queue!\n";
    while(!q.empty()){
        q.pop();
    }

    // should be empty two checks; displaying the queue and if empty
    //display queue
    std::cout<<"Displaying the queue:";
    display(q);

    //empty
    if(q.empty()){
        std::cout<<"Queue is empty!\n";
    } else {
        std::cout<<"Queue has elements.\n";
    }

    return 0;
}

//function definitions
void display(std::queue<char> r){
    //create a copy of the queue
    std::queue<char> c = r;

    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();
    }

    std::cout<<"\n";
}