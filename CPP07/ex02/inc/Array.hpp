#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T = int>
class Array {

public:
    class OutOfBoundsException: public std::exception{
        public:
            virtual const char * what(void) const throw(){
                return "Index out of bounds\n";
            }
    };

    Array(void): _arr(NULL), _size(0){};
    Array(unsigned int n): _arr(new T[n]), _size(n){};
    Array(const Array & src): _arr(new T[src._size]), _size(src._size){
        for (unsigned int i = 0; i < src._size; i++) {
            this->_arr[i] = src._arr[i];
        }
    };

    Array &operator=(const Array & rhs){
        if(this != &rhs){
            delete[] this->_arr;
            this->_size(rhs._size);
            this->_arr(new T[rhs._size]);
            for (unsigned int i = 0; i < rhs._size; i++) {
               this->_arr[i] = rhs._arr[i];
            }
        }
        return *this;
    };

    T& operator[](unsigned int index){
        if (index >= this->_size)
            throw OutOfBoundsException();
        return this->_arr[index];
    }

    unsigned int size(void) const{
        return this->_size;
    };

    ~Array(void){ delete[] _arr;};

private:
    T* _arr;
    unsigned int _size;
};

#endif // !ARRAY_HPP
