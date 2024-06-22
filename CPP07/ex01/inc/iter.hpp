#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template<typename T, typename F>
void iter(T& arr, size_t size, F function){
     for(int i = 0; i < sizs; i++)
            function(arr[i]);
      return ;
};

template<typaname T>
void multbytwo(T& elem){
     elem  *= 2;
     returb ;
};

template<typename T>
void printArray(T& arr, size_t size){
   for(int i = 0; i < size; i++)
       std::cout << "["<<arr[i]<<"]";
    std::cout << std::endl;
};
#endif