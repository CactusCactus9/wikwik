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


void	merge(std::vector<Pair> &vec, int left, int mid, int right){
	int	size1 = mid  - left + 1;
	int	size2 = right - mid;

	std::vector<Pair>	l_part(size1);
	std::vector<Pair>	r_part(size2);

	for (int i = 0; i < size1; ++i){
		l_part[i] = vec[left + i];
	}
	for (int j = 0; j < size2; ++j)
		r_part[j] = vec[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < size1 && j < size2){
		if (l_part[i].first <= r_part[j].first)
			vec[k++] = l_part[i++];
		else
			vec[k++] = r_part[j++];
	}
	while (i < size1)
		vec[k++] = l_part[i++];
	while (j < size2)
		vec[k++] = r_part[j++];
	// for (int i = 0; i < vec.size(); ++i) {
	// std::cout << "Pair " << i + 1 << ": "
    //               << vec[i].first << ", " << vec[i].second << std::endl;}
}

//----Mege sort----//
// void	mergeSort(std::vector<Pair> vec, int left, int right){
// 	if (left < right){
// 		int	mid = left + (right - left) / 2;
// 		mergeSort(vec, left, mid);
// 		mergeSort(vec, mid + 1, right);
// 		merge(vec, left, mid, right);
// 	}
// }
std::vector<int>	jacobsthal_index(int n){
	std::vector<int>	vec(n);

	vec[0] = 1;
	vec[1] = 3;
	for(int i = 2; i < n; ++i){
		vec[i] =  vec[i - 1] + 2 * vec[i - 2];
	}
	return vec;
}

// std::vector<int>	ft_inset(std::vector<int> main, std::vector<int> pend, int size){
// 	std::vector<int>	js = jacobsthal_index(size);
// 	for (int i = 3; i < size; ++i){
		
// 	}
// }
// Merge sort function for pairs
// void mergeSort(std::vector<Pair>& vec, int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;

//         mergeSort(vec, left, mid);
//         mergeSort(vec, mid + 1, right);

//         merge(vec, left, mid, right);
//     }
// }