#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iterator>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <iterator>
// #include <vector>
#include <iostream>
#include <deque>


PmergeMe::PmergeMe(const char *av){
    long  nb;
    std::string tmp;
    std::stringstream ss;
    std::set<int>dupControl;
    _hasStraggler = false;
    ss << av;

    while(std::getline(ss, tmp, ' '))
    {
        nb =  std::atol(tmp.c_str());
        if (nb > INT_MAX || nb < INT_MIN)
            throw std::runtime_error("Only integers are valid\n");
        if(!dupControl.insert(static_cast<int>(nb)).second)
            throw std::runtime_error("Error: duplicate number detected\n");
       this->_inputDeq.push_back(static_cast<int>(nb));
        // this->_inputVec.push_back(static_cast<int>(nb));
    }
    std::cout<<_inputDeq.size();
    _sortDeq();
    // for(std::size_t i = 0; i != _inputDeq.size(); i++)
        // std::cout<<_inputDeq[i]<<" ";
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
    for(it = _inputDeq.begin(); it != _inputDeq.end(); it += 1){
        if (*it < *(it += 1))
            std::iter_swap(it, it += 1);
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
    //Iterator for position of insetion on main chain
    std::deque<int>::iterator insertionPos;
    //iterator for pend element to insert in main chain
    std::deque<int>::iterator pendIt;
    for(int i = 0; ; i++){
        size_t pos = _posDeq[i];
        pendIt = _pendDeq.begin();
        std::advance(pendIt, pos);
        if (pendIt == _pendDeq.end())
            break;
        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(),
                *pendIt);
        _mainDeq.insert(insertionPos, *pendIt);
    }
    if (pendIt != _pendDeq.end()){
        for(pendIt = _pendDeq.begin(); pendIt != _pendDeq.end(); pendIt++){
        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(), 
                *pendIt);
        _mainDeq.insert(insertionPos, *pendIt);
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
    for(it = _inputDeq.begin(); it != _inputDeq.end(); it++)
        std::cout<<*it<<" ";
    makePairsFromDeq();
    sortPairsFromDeq();

    std::deque<std::pair<int, int> >::iterator it2;
    for(it2 = _deqPair.begin(); it2 != _deqPair.end(); it2++){
        _mainDeq.push_back(it2->first);
        _pendDeq.push_back(it2->second);
    }
    _mainDeq.insert(_mainDeq.begin(), _pendDeq.front());
    buildInsertionDeq();
    makeSortedDeq();
    std::cout <<"After: \n";
    for(it = _mainDeq.begin(); it != _mainDeq.end(); it++)
        std::cout<<*it<<" ";
}


