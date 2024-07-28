#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
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

    if (_inputDeq.size() % 2 != 0)
    {
        _hasStraggler = true;
        _straggler = _inputDeq.front();
        _inputDeq.pop_front();
    }
    std::deque<int>::iterator it;
    for(it = _inputDeq.begin(); it != _inputDeq.end(); it += 2){
        if ((it + 1) == _inputDeq.end())
            break;
        if (*it < *(it + 1))
            std::iter_swap(it, it + 1);
        _deqPair.push_back(std::make_pair(*it, *(it + 1)));
    }
}

void PmergeMe::sortPairsFromDeq(void){
    std::deque<std::pair<int, int> >::iterator it;
    for(it = _deqPair.begin(); it != _deqPair.end(); it++){
        std::rotate(std::upper_bound(_deqPair.begin(), it, *it,
                    std::less<std::pair<int, int> >()), it, it + 1);
    }
    for(it = _deqPair.begin(); it != _deqPair.end(); it++){
        std::cout <<"{"<<it->first<<" "<<it->second<<"}"<<std::endl;
        _mainDeq.push_back(it->first);
        _pendDeq.push_back(it->second);
    }
    _mainDeq.insert(_mainDeq.begin(), _pendDeq.front());
    _pendDeq.erase(_pendDeq.begin());
}

void PmergeMe::buildInsertionDeq(void){
    int jacobSeed = 3;
    int size = _pendDeq.size();
    if (size == 0)
        return ;
    for(; jacobstahl(jacobSeed) < size - 1; jacobSeed++){
        std::cout <<jacobstahl(jacobSeed);
        _posDeq.push_back(jacobstahl(jacobSeed));
    }
}

void PmergeMe::makeSortedDeq(void){
    //Iterator for position of insetion on main chain
    std::deque<int>::iterator insertionPos;
    //iterator for pend element to insert in main chain
    std::deque<int>::iterator pendIt;
    for(std::size_t i = 0; _posDeq.size() > 0; i++){
        size_t pos = _posDeq[i];
        if (pendIt == _pendDeq.end() || pos > _pendDeq.size())
            break;
        pendIt = _pendDeq.begin();
        std::advance(pendIt, pos);
        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(),
                    *pendIt);
        _mainDeq.insert(insertionPos, *pendIt);
        _pendDeq.erase(pendIt);
    }
    if (pendIt != _pendDeq.end()){
        for(pendIt = _pendDeq.begin(); pendIt != _pendDeq.end(); pendIt++){
        insertionPos = std::upper_bound(_mainDeq.begin(), _mainDeq.end(), 
                *pendIt);
        _mainDeq.insert(insertionPos, *pendIt);
        }
    }
    if (_hasStraggler == true){
        _hasStraggler = false;
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
    std::cout<<std::endl;
    std::clock_t start = std::clock();
    makePairsFromDeq();
    sortPairsFromDeq();
    buildInsertionDeq();
    makeSortedDeq();
    std::clock_t end = std::clock();
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout <<"\nAfter: \n";
    for(it = _mainDeq.begin(); it != _mainDeq.end(); it++)
        std::cout<<*it<<" ";
    std::cout <<"\nTime elapse: "<<duration;
    std::cout<<std::endl;
}


