#include "PmergeMe.hpp"
#include <utility>
#include <vector>
#include <iostream>

//std::pair class template is available and can be used to store a pair of values of different types
void	check_args(std::string str){
	size_t  index = str.find_first_not_of("0123456789 ");//.
	if (index != std::string::npos)
		throw ("invalid input!");
}


void	merge(std::vector<std::pair<int, int> > vec, int mid, int right, int left){
	int	n1 = mid  - left + 1;
	int	n2 = right - mid;

	std::vector<std::pair<int, int> >	r_part(n1);
	std::vector<std::pair<int, int> >	l_part(n2);

	for (int i = 0; i < n1; i++){
		l_part
	}

}