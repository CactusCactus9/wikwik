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


// void	merge(std::vector<std::pair<int, int> > vec, int mid, int right, int left){
// 	int	size1 = mid  - left + 1;
// 	int	size2 = right - mid;

// 	std::vector<std::pair<int, int> >	r_part(size1);
// 	std::vector<std::pair<int, int> >	l_part(size2);

// 	for (int i = 0; i < size1; i++){
// 		l_part[i] = vec[left + i];
// 	}
// 	for (int j = 0; j < size2; j++)
// 		r_part[j] = vec[mid + 1 + j];
// 	int i = 0, j = 0, k = left;
// 	while (i < size1 && j < size2){
// 		if (vec)
// 	}

// }