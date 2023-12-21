
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <sys/time.h>


template <typename container>
class PmergeMe
{
public:
	typedef typename container::value_type      v_type;
    typedef std::pair <v_type, v_type>			p_type;
private:
	container	data;
	container	pend;
	container	seqnbr;
	double		time;

	bool 	isnbr(std::string str);
	void	generate(size_t size, container &seqnbr);

	std::vector< p_type >	pairs;
	PmergeMe(void);

public:
	PmergeMe(char **av);
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator=(const PmergeMe& obj);
	~PmergeMe(void);

	void	DataDisplay(void);
	void	TimeDisplay(std::string ctype);
	void	sort(void);
};


template <typename container>
PmergeMe<container>::PmergeMe(){
}

template <typename container>
PmergeMe<container>::PmergeMe(const PmergeMe& obj){
	*this = obj;
}
template <typename container>
PmergeMe<container>& PmergeMe<container>::operator=(const PmergeMe& obj){
	if (this != &obj){
		data = obj.data;
		pend = obj.pend;
		seqnbr = obj.seqnbr;
		time = obj.time;
	}
	return *this;
}

template <typename container>
PmergeMe<container>::PmergeMe(char **av){
	time = 0;
	for(size_t i = 1; av[i]; i++){
		if (!isnbr(av[i]))
			throw std::invalid_argument("Error.");
		data.push_back(std::strtod(av[i], NULL));
	}
	if (data.size() == 1)
		throw std::invalid_argument("You have one number nothing to sort.");
	
	// step 5
	generate(data.size(), seqnbr);
}


template <typename container>
PmergeMe<container>::~PmergeMe(){
}

template <typename container>
void PmergeMe<container>::TimeDisplay(std::string ctype){
	std::cout << "Time to process a range of " << data.size();
	std::cout << " elements with " << ctype << " : ";
	std::cout << std::fixed << time << " us";
	std::cout << std::endl;
}


template <typename container>
void PmergeMe<container>:: generate(size_t size, container &seqnbr){
	int tab[] = {0,1,1,3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923};
	int	lastnb = 2;
	for (int i = 2; i < 16; i++){
		if (seqnbr.size() >= size)
			break;
		if ( i != 2)
			seqnbr.push_back(tab[i]);
		for (int j = tab[i] - 1; j > lastnb; j--)
			seqnbr.push_back(j);
		lastnb = tab[i];
	}
}



template <typename container>
bool PmergeMe<container>::isnbr(std::string str){
	char* endPtr;

	if (str.empty() || str[0] == '-')
		return false;

    strtol(str.c_str(), &endPtr, 10);
    if (*endPtr != '\0' || endPtr == str.c_str())
        return false;
		
	return true;
}

template <typename container>
void	PmergeMe<container>::DataDisplay(void){
	for(size_t i = 0; i < data.size(); i++)
		std::cout << data[i] << " ";
	std::cout << std::endl;
}


template <typename container>
void	PmergeMe<container>::sort(void){
	std::clock_t c_start;
	std::clock_t c_end;
	v_type	tmpLast;
	int	flag = 0;
	int	index;

	c_start = std::clock();
	if (data.size() == 0)
		throw std::invalid_argument("Error: Nothing to sort.");

	// step 1
	if (data.size() % 2 != 0){
		flag = 1;
		tmpLast = data.back();
		data.pop_back();
	}

	// step 2
	for (size_t i = 0; i < data.size(); i+=2){
		if (data[i] < data[i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.push_back(std::make_pair(data[i], data[i + 1]));
	}

	// step 3
	std::sort(pairs.begin(), pairs.end());
	
	// step 4
	data.clear();
	data.push_back(pairs[0].second);

	for (size_t i = 0; i < pairs.size(); i++)
		data.push_back(pairs[i].first);
	
	
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	// step 6
	for (size_t i = 0; i < seqnbr.size(); i++){
		if (seqnbr[i] - 1 >= int(pairs.size()))
			continue ;
		index = std::lower_bound(data.begin(), data.end(), pend[seqnbr[i] - 1]) - data.begin();
		data.insert(data.begin() + index, pend[seqnbr[i] - 1]);
	}

	// step 7
	if (flag){
		index = std::lower_bound(data.begin(), data.end(), tmpLast) - data.begin();
		data.insert(data.begin() + index, tmpLast);
	}
	c_end = std::clock();
	time = static_cast<double>(c_end - c_start) / CLOCKS_PER_SEC;
}


#endif