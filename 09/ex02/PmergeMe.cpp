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
}

void	mergeSort(std::vector<Pair> &vec, int left, int right){
	if (left < right){
		int	mid = left + (right - left) / 2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

std::vector<size_t>	jacobsthal_index(int n){
	std::vector<size_t>	vec(n);

	vec[0] = 1;
	vec[1] = 3;
	for(int i = 2; i < n; ++i){
		vec[i] =  vec[i - 1] + 2 * vec[i - 2];
	}
	return vec;
}

std::vector<int>	insert_pend(std::vector<Pair> pairs, int temp){
	std::vector<int>::iterator	it;
	std::vector<int>			firsts;
	std::vector<int>			seconds;
	// int							fsize;

	//firsts
	firsts.push_back(pairs[0].second);
	firsts.push_back(pairs[0].first);
	for (size_t i = 1; i < pairs.size(); ++i)
		firsts.push_back(pairs[i].first);
	//seconds
	for (size_t i = 0; i < pairs.size(); ++i)
		seconds.push_back(pairs[i].second);
	// fsize = firsts.size();
	std::vector<size_t>	js = jacobsthal_index(seconds.size());
	size_t	n_j = js[1];
	size_t	o_j = 1;
	for(size_t i = 1; i < seconds.size(); ++i){
		if (js[i] > seconds.size())
			n_j = seconds.size();
		else
			n_j = js[i];
		o_j = js[i - 1];
		size_t	insert_size = n_j + o_j - 1;
		// std::cout << n_j << "   " << js[i - 1] << std::endl;
		while (n_j > o_j){
			it = firsts.begin() + insert_size;
			// std::cout << *it << std::endl;
			it = std::lower_bound(firsts.begin(), firsts.begin() + insert_size++, seconds[n_j - 1]);
			firsts.insert(it, seconds[n_j - 1]);
			n_j--;
			// fsize++;
		}
	}
	if (std::is_sorted(firsts.begin(), firsts.end()))
		std::cout << "sorted\n";
	if (temp){
		it = std::lower_bound(firsts.begin(), firsts.end(), temp);
		firsts.insert(it, temp);
	}
	return (firsts);
}
