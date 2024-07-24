#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
// #include <vector>
#include <iostream>
#include <deque>


PmergeMe::PmergeMe(const char *av){
    long long nb;
    std::string tmp;
    std::stringstream ss;
    _hasStraggler = false;
    ss << av;

    while(std::getline(ss, tmp, ' '))
    {
        nb =  std::atoll(tmp.c_str());
        if (nb > INT_MAX || nb < INT_MIN)
            throw std::runtime_error("Only integers are valid\n");
        _inputDeq.push_back(static_cast<int>(nb));
        // this->_inputVec.push_back(static_cast<int>(nb));
        _sortDeq();
    } 
}


PmergeMe::PmergeMe(const PmergeMe & src){
    (void)src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs){
    (void)rhs;
    return *this;
}

PmergeMe::~PmergeMe(void){
    return ;
}

//insertion sort to sort collection of pairs in order of the largest

int jacobstahl(int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobstahl(n - 1) + 2 * jacobstahl(n - 2);
}

void PmergeMe::makePairsFromDeq(void){
    if (_inputDeq.size() % 2 == 0)
    {
        _hasStraggler = true;
        _straggler = _inputDeq.front();
        _inputDeq.pop_front();
    }
    std::deque<int>::iterator it;
    for(it = _inputDeq.begin(); it != _inputDeq.end(); it += 2){
        if (*it < *(it += 1))
            std::iter_swap(it, (it += 1));
        _deqPair.push_back(std::make_pair(*it, *(it += 1)));
    }
}

void PmergeMe::sortPairsFromDeq(void){
    std::deque<std::pair<int, int> >::iterator it;
    for(it = _deqPair.begin(); it != _deqPair.end(); it++){
        std::rotate(std::upper_bound(_deqPair.begin(), it, *it, std::less<std::pair<int, int> >()), it, it + 1);
    }
}

void PmergeMe::buildInsertionDeq(void){
    int jacobSeed = 3;
    int size = _inputDeq.size() / 2;
    if (size == 0)
        return ;
    for(; jacobstahl(jacobSeed) < size - 1; jacobSeed++)
        _posDeq.push_back(jacobstahl(jacobSeed));
}

void PmergeMe::makeSortedDeq(void){
    std::deque<int>::iterator insertionPos;
    for(std::size_t i = 0; i < _pendDeq.size(); i++){
        size_t pos = _posDeq[i];
        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(),
            _pendDeq[pos]);
        _mainDeq.insert(insertionPos, _pendDeq[pos]);
    }
    if (_pendDeq.size() != 0){
        for(std::size_t i = 0; i < _pendDeq.size(); i++){
        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(),
            _pendDeq[i]);
        _mainDeq.insert(insertionPos, _pendDeq[pos]);
    }
        }
    }
    if (_hasStraggler == true){

        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(),
            _straggler);
        _mainDeq.insert(insertionPos, _straggler);
    }
    
}

void PmergeMe::_sortDeq(void){
    std::cout <<"Before: \n";
    std::deque<int>::iterator it;
    for(it = _mainDeq.begin(); it != _mainDeq.end(); it++)
        std::cout<<*it<<" ";

    makePairsFromDeq();
    sortPairsFromDeq();

    std::deque<std::pair<int, int> >::iterator it2;
    for(it2 = _deqPair.begin(); it2 != _deqPair.end(); it2++){
        _mainDeq.push_back(it2->first);
        _pendDeq.push_back(it2->second);
    }
    _mainDeq.insert(_mainDeq.begin(), _mainDeq.front());
    buildInsertionDeq();
    makeSortedDeq();
    std::cout <<"Before: \n";
    for(it = _mainDeq.begin(); it != _mainDeq.end(); it++)
        std::cout<<*it<<" ";
}


