#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe(const char **av);
    PmergeMe(const PmergeMe &);
    PmergeMe &operator=(const PmergeMe &);
    ~PmergeMe(void);

    //Deque methods
    
    void makePairsFromDeq(void);
    void sortPairsFromDeq(void);
    void buildInsertionDeq(void);
    void makeSortedDeq(void);
    void _sortDeq(void);

    //Vector methods
    void makePairsFromVec(void);
    void sortPairsFromVec(void);
    void buildInsertionVec(void);
    void makeSortedVec(void);
    void _sortVec(void);

private:
    bool _hasStraggler;
    int _straggler;
    std::vector<int>_inputVec;
    std::vector<int>_posVec;
    std::vector<std::pair<int, int> >_vecPair;
    std::vector<int>_mainVec;
    std::vector<int>_pendVec;
    std::vector<int>_jacobVec;

    std::deque<int>_inputDeq;
    std::deque<int>_posDeq;
    std::deque<std::pair<int, int> >_deqPair;
    std::deque<int>_mainDeq;
    std::deque<int>_pendDeq;
    std::deque<int>_jacobDeq;

};


#endif // !PMERGEME_HPP
