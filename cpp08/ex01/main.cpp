#include "Span.hpp"

int main() {
    try {
		Span mySpan(11);

		mySpan.addNumber(6);
		mySpan.addNumber(3);
		mySpan.addNumber(17);
		mySpan.addNumber(9);
		mySpan.addNumber(11);


        std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;

        std::vector<int> test;
        test.push_back(43);
        test.push_back(75);
        test.push_back(51);
        test.push_back(15);
        test.push_back(63);
        test.push_back(69);
        mySpan.addSpan(test);
        
        std::vector<int>* test2 = mySpan.getLst();
        for (size_t i = 0; i < (test2)->size(); i++){
            std::cout << (*test2)[i] << std::endl;
        }

        std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}