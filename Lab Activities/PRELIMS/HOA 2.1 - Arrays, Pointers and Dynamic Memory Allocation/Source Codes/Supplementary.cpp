#include <iostream>
#include <string>

// base class for fruit and vegetable to inherit from
class foodType {
    protected:
        std::string name;
        int price;
        int quantity;

    public:
        foodType(std::string giveName, int givePrice, int giveAmount) { // constructor!
            name = giveName;
            price = givePrice;
            quantity = giveAmount;
        }
    
    virtual ~foodType() {} // dynamic destructor for newly created pointer to the created object

    virtual void showContents() = 0;
    
    int findSum() { // total price when we have more than one to buy
        return price * quantity;
    }
    
    std::string getName() { // getter function to give name
        return name;
    }
};



// Inheritence (fruit and veggie classes - PROBLEM 1)

class Fruit : public foodType {
    
public: 
    // Constructor
    Fruit(std::string giveName = "Null Fruit", int givePrice = 0, int giveAmount = 0) // default
    : foodType(giveName, givePrice, giveAmount) { // this line calls the base class constructor first
    std::cout << "Fruit Constructor Called: " << name << std::endl;
    }

    // Destructor
    ~Fruit() override {
        std::cout << "Fruit Destructor Called: " << name << std::endl;
    }

    // Copy Constructor
    Fruit(const Fruit &copyFruit) : foodType(copyFruit.name, copyFruit.price, copyFruit.quantity) {
        std::cout << "Fruit Copy Constructor Called: " << name << std::endl;
    }

    // Copy Assignmnent Operator
    Fruit& operator=(const Fruit &assignFruit) {
        std::cout << "Fruit Copy Assignment Operator Called for: " << assignFruit.name << std::endl;
        if (this != &assignFruit) { // check if self-assignment and skips the unnesscesarry-ness
            name = assignFruit.name;
            price = assignFruit.price;
            quantity = assignFruit.quantity;
        }
        return *this;
    }

    void showContents() override {
        std::cout << "[Fruit] " << name << " || Price: PHP " << price << " || Qty: x" << quantity << " || Subtotal: PHP " << findSum() << std::endl;
    }
};

class Vegetable : public foodType { // I just copy and pasted my fruit class and just changed the fruits in here
public:
    // Constructor
    Vegetable(std::string newName = "Null Veggie", int newPrice = 0, int newQuantity = 0) 
        : foodType(newName, newPrice, newQuantity) {
        std::cout << "Vegetable Constructor Called: " << name << std::endl;
    }

    // Destructor
    ~Vegetable() override {
        std::cout << "Vegetable Destructor Called: " << name << std::endl;
    }

    // Copy Constructor
    Vegetable(const Vegetable &copyVeg) : foodType(copyVeg.name, copyVeg.price, copyVeg.quantity) {
        std::cout << "Vegetable Copy Constructor Called: " << name << std::endl;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable &assignVeg) {
        std::cout << "Vegetable Copy Assignment Operator Called: " << assignVeg.name << std::endl;
        if (this != &assignVeg) {
            name = assignVeg.name;
            price = assignVeg.price;
            quantity = assignVeg.quantity;
        }
        return *this;
    }

    void showContents() override {
        std::cout << "[Vegetable] " << name << " || Price: PHP " << price << " || Qty: x" << quantity << " || Subtotal: PHP " << findSum() << std::endl;
    }
};

// Function prototype/s
void totalPrice(foodType* list[], int size);


// MAIN
int main() {
    std::cout << "Jenna's Grocery List\n";
    // creating the array
    const int size = 4;
    foodType* itemList[size];

    itemList[0] = new Fruit("Apple", 10, 7);
    itemList[1] = new Fruit("Banana", 10, 8);
    itemList[2] = new Vegetable("Broccoli", 60, 12);
    itemList[3] = new Vegetable("Lettuce", 50, 10);

    // using a for-loop to display the items
    std::cout << "\nItems: \n";
    for (int i = 0; i < size; i++) {
        if (itemList[i] != nullptr) {
            itemList[i]->showContents();
        }
    }

    // function call from problem 3
    totalPrice(itemList, size);

    // delete lettuce and destroy it (PROBLEM 4)
    std::cout << "\nRemoving lettuce...\n";
    for (int i = 0; i < size; i++) {
        if (itemList[i] != nullptr && itemList[i]->getName() == "Lettuce") {
            delete itemList[i];     // D
            itemList[i] = nullptr;  // NU!
            std::cout << "Lettuce is gone, reduced to atoms.\n";
        }
    }

    // check after lettuce destruction
    std::cout << std::endl; // spacing
    totalPrice(itemList, size);

    // finally, deallocating
    std::cout << "\nCleaning up. Thank you for your time.\n";
    for (int i = 0; i < size; i++) {
        if (itemList[i] != nullptr) {
            delete itemList[i];
        }
    }

    return 0;
}

// Function definition/s (PROBLEM 3)
void totalPrice(foodType* list[], int size) { // basically, accepts an array of pointers to our base class, foodType and number of elements in the array
    int total = 0; // start at 0 alwayss
    for (int i = 0; i < size; i++) { // use a for loop to cycle through the array for every pointer present
        if (list[i] != nullptr) { // check if its actually a pointer to an actual object (prevents crashes, learned the hard way)
            total += list[i]->findSum(); // makes sure quantity comes into play
        }
    }
    std::cout << "Total Price: PHP " << total << std::endl;
}