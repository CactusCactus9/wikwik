#ifndef PMERGEME_H
#define PMERGEME_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <deque>
#include <utility>

void				check_args(std::string str);
//----vector----//
typedef std::pair<int, int> Pair;
void				v_merge(std::vector<Pair> &vec, int left, int mid, int right);
void				v_mergeSort(std::vector<Pair> &vec, int left, int right);
std::vector<size_t>	v_jacobsthal_index(int n);
std::vector<int>	v_insert_pend(std::vector<Pair> pairs, int temp);

//----deque----//
typedef std::pair<int, int> Paired;
void				d_merge(std::deque<Paired> &deq, int left, int mid, int right);
void				d_mergeSort(std::deque<Paired> &deq, int left, int right);
std::deque<size_t>	d_jacobsthal_index(int n);
std::deque<int>	    d_insert_pend(std::deque<Paired> pairs, int temp);
#endif