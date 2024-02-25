#ifndef PMERGEME_H
#define PMERGEME_H
#include <vector>
#include <iostream>
typedef std::pair<int, int> Pair;
void	check_args(std::string str);
void     merge(std::vector<Pair> &vec, int left, int mid, int right);
void	mergeSort(std::vector<Pair> &vec, int left, int right);
std::vector<int>	jacobsthal_index(int n);
// std::vector<std::pair<int, int> >	ft_vector_pairs(int n1, int n2);
#endif