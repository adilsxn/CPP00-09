#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

template<typename T, typename F>
void iter(T* arr, int size, F function){
     for(int i = 0; i < size; i++)
            function(arr[i]);
      return ;
};

template<typename T>
void multbytwo(T& elem){
     elem  *= 2;
     return ;
};

template<typename T>
void printArray(T* arr, int size){
    std::cout<<"[";
   for(int i = 0; i < size; i++)
       std::cout<<arr[i]<<" ";
   std::cout<<"]";
   std::cout << std::endl;
};
#endif
