#include <iostream>
#include "add.h" // Include the header file for the add function

int main() {
    int num1 = 5;
    int num2 = 7;
    
    // Call the add function from the add.cpp file
    int result = add(num1, num2);
    
    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl;
    
    return 0;
}