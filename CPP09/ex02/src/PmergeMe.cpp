#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iterator>
#include <ostream>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <iterator>
#include <iostream>
#include <deque>
#include <vector>


PmergeMe::PmergeMe(const char **av){
    long  nb;
    std::set<int>dupControl;
    _hasStraggler = false;

    for(int i = 1; av[i] != NULL; i++)
    {
        std::string arg = av[i];
        if (arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::runtime_error("Invalid argument(s) detected");
        nb =  std::atoi(av[i]);
        if (nb > INT_MAX || nb < INT_MIN)
            throw std::runtime_error("Only integers are valid\n");
        if(!dupControl.insert(static_cast<int>(nb)).second)
            throw std::runtime_error("Error: duplicate number detected\n");
       this->_inputDeq.push_back(static_cast<int>(nb));
       this->_inputVec.push_back(static_cast<int>(nb));
    }
    if (_inputVec.size() == 1 || _inputDeq.size() == 1)
        throw std::runtime_error("Error: two or more values are needed");
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

int jacobstahl(int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobstahl(n - 1) + 2 * jacobstahl(n - 2);
}

//Deque
void PmergeMe::makePairsFromDeq(void){

    if (_inputDeq.size() % 2 != 0)
    {
        _hasStraggler = true;
        _straggler = _inputDeq.back();
        _inputDeq.pop_back();
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
        // std::cout <<"{"<<it->first<<" "<<it->second<<"}"<<std::endl;
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
        _posDeq.push_back(jacobstahl(jacobSeed));
    }
}

void PmergeMe::makeSortedDeq(void){
    //Iterator for position of insetion on main chain
    std::deque<int>::iterator insertionPos;
    //iterator for pend element to insert in main chain
    std::deque<int>::iterator pendIt;
    for(std::size_t i = 0; _posDeq.size() > 0; i++){
        if (i >= _posDeq.size())
            break;
        size_t pos = _posDeq.at(i);
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
    std::cout<<"Before:\t";
    std::deque<int>::iterator it;
    for(it = _inputDeq.begin(); it != _inputDeq.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
    clock_t timeDeq = clock();
    makePairsFromDeq();
    sortPairsFromDeq();
    buildInsertionDeq();
    makeSortedDeq();
    timeDeq = clock() - timeDeq;
    std::cout<<"\nAfter:\t";
    for(it = _mainDeq.begin(); it != _mainDeq.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout <<"Time elapsed to sort  "<<_inputDeq.size()
        <<" elements with std::deque: "
        <<(float)timeDeq * 1000 / CLOCKS_PER_SEC <<"ms\n";
}

//Vector
void PmergeMe::makePairsFromVec(void){

    if (_inputVec.size() % 2 != 0)
    {
        _hasStraggler = true;
        _straggler = _inputVec.back();
        _inputVec.pop_back();
    }
    std::vector<int>::iterator it;
    for(it = _inputVec.begin(); it != _inputVec.end(); it += 2){
        if ((it + 1) == _inputVec.end())
            break;
        if (*it < *(it + 1))
            std::iter_swap(it, it + 1);
        _vecPair.push_back(std::make_pair(*it, *(it + 1)));
    }
}

void PmergeMe::sortPairsFromVec(void){
    std::vector<std::pair<int, int> >::iterator it;
    for(it = _vecPair.begin(); it != _vecPair.end(); it++){
        std::rotate(std::upper_bound(_vecPair.begin(), it, *it,
                    std::less<std::pair<int, int> >()), it, it + 1);
    }
    for(it = _vecPair.begin(); it != _vecPair.end(); it++){
        // std::cout <<"{"<<it->first<<" "<<it->second<<"}"<<std::endl;
        _mainVec.push_back(it->first);
        _pendVec.push_back(it->second);
    }
    _mainVec.insert(_mainVec.begin(), _pendVec.front());
    _pendVec.erase(_pendVec.begin());
}

void PmergeMe::buildInsertionVec(void){
    int jacobSeed = 3;
    int size = _pendVec.size();
    if (size == 0)
        return ;
    for(; jacobstahl(jacobSeed) < size - 1; jacobSeed++){
        _posVec.push_back(jacobstahl(jacobSeed));
    }
}

void PmergeMe::makeSortedVec(void){
    //Iterator for position of insetion on main chain
    std::vector<int>::iterator insertionPos;
    //iterator for pend element to insert in main chain
    std::vector<int>::iterator pendIt;
    for(std::size_t i = 0; _posVec.size() > 0; i++){
        if (i >= _posVec.size())
            break;
        size_t pos = _posVec.at(i);
        if (pendIt == _pendVec.end() || pos > _pendVec.size())
            break;
        pendIt = _pendVec.begin();
        std::advance(pendIt, pos);
        insertionPos = std::upper_bound(_mainVec.begin(), _mainVec.end(),
                    *pendIt);
        _mainVec.insert(insertionPos, *pendIt);
        _pendVec.erase(pendIt);
    }
    if (pendIt != _pendVec.end()){
        for(pendIt = _pendVec.begin(); pendIt != _pendVec.end(); pendIt++){
        insertionPos = std::upper_bound(_mainVec.begin(), _mainVec.end(), 
                *pendIt);
        _mainVec.insert(insertionPos, *pendIt);
        }
    }
    if (_hasStraggler == true){
        _hasStraggler = false;
        insertionPos = std::upper_bound(_mainVec.begin(), _mainVec.end(),
            _straggler);
        _mainVec.insert(insertionPos, _straggler);
    }
}

void PmergeMe::_sortVec(void){
    // std::cout<<"\n\t\t::::VECTOR::::\nBefore: \n";
    // std::vector<int>::iterator it;
    // for(it = _inputVec.begin(); it != _inputVec.end(); it++)
        // std::cout<<*it<<" ";
    // std::cout<<std::endl;
    clock_t timeVec = clock();
    makePairsFromVec();
    sortPairsFromVec();
    buildInsertionVec();
    makeSortedVec();
    timeVec = clock() - timeVec;
    // std::cout<<"\nAfter: \n";
    // for(it = _mainVec.begin(); it != _mainVec.end(); it++)
    //     std::cout<<*it<<" ";
    // std::cout<<std::endl;
    std::cout <<"Time elapsed to sort "<<_inputVec.size()
        <<" elements with std::vector: "
        <<(float)timeVec * 1000 / CLOCKS_PER_SEC <<"ms\n";
}

