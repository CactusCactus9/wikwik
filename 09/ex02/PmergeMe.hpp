#ifndef PMERGEME_H
#define PMERGEME_H
#include <vector>
#include <iostream>
typedef std::pair<int, int> Pair;
void				check_args(std::string str);
void				merge(std::vector<Pair> &vec, int left, int mid, int right);
void				mergeSort(std::vector<Pair> &vec, int left, int right);
std::vector<size_t>	jacobsthal_index(int n);
std::vector<int>	insert_pend(std::vector<Pair> pairs, int temp);
#endif