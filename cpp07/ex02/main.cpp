#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    try
    {
        Array<int> arr1(10);

        for (int i = 0; i < 10; i++){
            arr1[i] = i * 3;
        } 
        std::cout << "array 1: " ;
        for (int i = 0; i < 10; i++){
           std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        const Array<int> arr2(arr1);

        std::cout << "array 2: " ;
        for (int i = 0; i < 10; i++){
           std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << arr2[-2] << std::endl;
        // arr2[3] = 45;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
    return 0;
}