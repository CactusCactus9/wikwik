#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stdexcept>

// class templates are useful when a class defines 
// something that is independent of the data type.
template	<typename T>
class Array{
	private:
		T				*_elements;
		unsigned int	_size;
	public:
		Array(){
			_elements = NULL;
			_size = 0;
		}
		Array(unsigned int n) : _size(n){
			this->_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++){
				this->_elements[i] = 0;
			}
		}
		Array(const Array &obj){
			this->_size = obj._size;
			this->_elements = new T[obj._size];
			for (unsigned int i = 0; i < this->_size; i++){
				this->_elements[i] = obj._elements[i];
			}
		}
		Array	operator=(const Array &other){
			if (this != &other){
				if (this->_elements)
					delete [] this->_elements;
				this->_size = other._size;
				this->_elements = new T[other._size];
				for (unsigned int i = 0; i < this->_size; i++){
				this->_elements[i] = other._elements[i];
				}
			}
			return *this;
		}
		T	operator[](unsigned int i){
			if (i >= this->_size)
				throw (std::out_of_range("Element out of range!"));
			return (this->_elements[i]);
		}
		unsigned int	size()const{
			return (this->_size);
		}
		~Array(){
			delete [] _elements;
		}
};
#endif