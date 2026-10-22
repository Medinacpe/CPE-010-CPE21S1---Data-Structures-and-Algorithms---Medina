#include <iostream>


// class name should follow PascalCase
class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        //constructor
        Triangle(double A, double B, double C);

        //methods
        void setAngles(double A, double B, double C);

        //validation
        const bool validateTriangle();
};

int main(){
    // Variable Declaration
    int x, y, z;

    //driver code
    std::cout << "Triangle Verifier\n\nInput the first angle: ";
    std::cin >> x;
    std::cout << "Input the second angle: ";
    std::cin >> y;
    std::cout << "Input the third angle: ";
    std::cin >> z;
    Triangle set1(x,y,z);
    if(set1.validateTriangle()){
        std::cout<<"\nThe shape is a valid Triangle"<<std::endl;
    } else{
        std::cout<<"\nThe shape is NOT a valid triangle. \n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB= B;
    angleC = C;
    totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB= B;
    angleC = C;
    totalAngle = A+B+C;
}

const bool Triangle::validateTriangle(){
    // makes sure angles are positive and sum up to exactly 180 degrees
    if (angleA > 0 && angleB > 0 && angleC > 0 && totalAngle == 180) {
        return true;
    }
    return false;
}



