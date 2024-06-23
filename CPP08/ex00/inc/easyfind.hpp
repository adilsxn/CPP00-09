#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::const_iterator easyfind(T const & cont, const int elem){
    typename T::const_iterator it;
    it = std::find(cont.begin(), cont.end(), elem);
    if (it == cont.end())
        throw std::out_of_range("Element not found\n");
    return (it);
};


#endif // !EASYFIND_HPP
