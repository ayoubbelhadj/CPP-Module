#include "Span.hpp"

Span::Span(): N(0){
}

Span::Span(unsigned int n): N(n){
}

Span& Span::operator=(const Span& obj){
    if (this != &obj){
        this->N = obj.GetN();
        this->lst = obj.lst;
    }
	return *this;
}

Span::Span(const Span& obj){
    *this = obj;
}

Span::~Span(){
}

unsigned int Span::GetN() const{
    return this->N;
}

void	Span::addNumber(int nbr){
	if (lst.size() >= this->N)
        throw OutOfSize();
    lst.push_back(nbr);
}

size_t Span::shortestSpan() const{
    size_t shortSpan;
    size_t tmp;
    size_t  i;

    if (lst.size() < 2)
        throw SpanExeption();
    i = 1;
    shortSpan = INT_MAX;
    while (i < lst.size()){
        tmp = std::abs(lst[i] - lst[i - 1]);
        shortSpan = std::min(shortSpan, tmp);
        i++;
    }
    return shortSpan;
}

size_t Span::longestSpan() const{
    size_t longeSpan;
    size_t tmp;
    size_t  i;

    if (lst.size() < 2)
        throw SpanExeption();
    i = 1;
    longeSpan = 0;
    while (i < lst.size()){
        tmp = std::abs(lst[i] - lst[i - 1]);
        longeSpan = std::max(longeSpan, tmp);
        i++;
    }
    return longeSpan;
}

void    Span::addSpan(std::vector<int> vec){
    if (N - lst.size() < vec.size())
        throw OutOfSize();
    std::vector<int>::iterator itr = vec.begin();
    while(itr != vec.end()){
        addNumber(*itr);
        itr++;
    }
}

std::vector<int>* Span::getLst(){
    return &this->lst;
}