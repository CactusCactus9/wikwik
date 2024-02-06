#include "iter.hpp"
#include <iostream>

template <typename T>
void	ft_print(T &i){
	std::cout << i << std::endl;
}

// int main(){
//     //array of int
// 	int array[] = {1, 2, 3};
//     int size = sizeof(array) / sizeof(int);
//     std::cout << "Array of int : " <<std::endl;
// 	iter(array, size, ft_print<int>);
//     //array of string
//     std::string array_str[] = {"48", "49", "50"};
//     size_t size_str = sizeof(array_str) / sizeof(std::string);
//     std::cout << "Array of string : " <<std::endl;
// 	iter(array_str, size_str, ft_print<std::string>);
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}