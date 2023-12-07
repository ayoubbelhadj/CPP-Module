#ifndef APAN_HPP
#define APAN_HPP

#include <vector>
#include <iostream>
class Span
{
private:
	Span();
    std::vector<int> lst;
	unsigned int	N;
public:
    Span(unsigned int n);
    Span(const Span& obj);
    Span& operator=(const Span& obj);
    ~Span();
    unsigned int GetN() const;
    void    addNumber(int nbr);
    void    addSpan(std::vector<int> vec);
    size_t shortestSpan() const;
    size_t longestSpan() const;
    std::vector<int>* getLst();
    class   OutOfSize : public std::exception{
        virtual const char *what() const throw(){
            return ("The Span is full.");
        }
    };
    class   SpanExeption : public std::exception{
        virtual const char *what() const throw(){
            return ("Not enough numbers to find a span.");
        }
    };
};

#endif