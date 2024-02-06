#include "Array.hpp"
#include <iostream>

int	main(){
	
		// Array<int>		a(3);
		// Array<float>	f(2);
		// Array<float>	b(f);

		// std::cout << a.size() << std::endl;
		// std::cout << f.size() << std::endl;
		// 	a[0] = 0;
		// 	a[1] = 1;
		// 	a[2] = 2;
		// 	std::cout << a[0] << " ";
		Array<int> emptyArray;
        std::cout << "Empty Array size: " << emptyArray.size() << std::endl;

        // Parameterized constructor (array of 5 elements initialized by default)
        Array<double> arrayWithSize(5);
        std::cout << "Array with size: " << arrayWithSize.size() << std::endl;

        // Copy constructor
        Array<int> originalArray(3);
        originalArray[0] = 1;
        originalArray[1] = 2;
        originalArray[2] = 3;

        Array<int> copiedArray(originalArray);
        std::cout << "Copied Array size: " << copiedArray.size() << std::endl;

        // Assignment operator
        Array<int> assignedArray;
        assignedArray = originalArray;
        std::cout << "Assigned Array size: " << assignedArray.size() << std::endl;

        // Accessing elements with subscript operator
        std::cout << "Original Array[1]: " << originalArray[1] << std::endl;
        std::cout << "Copied Array[2]: " << copiedArray[2] << std::endl;

}