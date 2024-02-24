#include "PmergeMe.hpp"
#include <algorithm>


void	mergeSort(std::vector<Pair> &vec, int left, int right){
	if (left < right){
		int	mid = left + (right - left) / 2;
		mergeSort(vec, left, mid);
		mergeSort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

int	main(int ac, char **av){
	std::vector<std::pair<int, int> >	pairs;
	int	size;
	int	fsize;
	int	temp;//if odd, temp to save last element 
	try{
		if (ac <= 2)
			throw ("Error!");
		for (int i = 1; (i < ac - 1 && i + 1 < ac); i+=2){
			check_args(av[i]);
			//--make pairs----//
			if (atoi(av[i]) > atoi(av[i + 1]))
				pairs.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
			else	
				pairs.push_back(std::make_pair(atoi(av[i + 1]), atoi(av[i])));
		}
		std::cout << "size" << pairs.size() << std::endl;
		size = pairs.size();

		std::vector<int>	firsts;
		std::vector<int>	seconds;
		std::vector<int>::iterator	it;
		fsize = firsts.size();
		//----store last element----//
		if ((ac - 1) % 2 != 0)
			temp = atoi(av[ac - 1]);

		// //----merge sort----//
		mergeSort(pairs, 0, (pairs.size() - 1));
		firsts.push_back(pairs[0].second);
		firsts.push_back(pairs[0].first);
		for (size_t i = 2; i < pairs.size(); ++i)
			firsts.push_back(pairs[i].first);
		for (size_t i = 0; i < pairs.size(); ++i)
			seconds.push_back(pairs[i].second);
		for (size_t i = 0; i < firsts.size(); ++i)
			std::cout << "firdst-----" << firsts[i] << std::endl;
		for (size_t i = 0; i < seconds.size(); ++i)
			std::cout << "seconds----" << seconds[i]<< std::endl;
		std::vector<int>	js = jacobsthal_index(seconds.size());
		for(size_t i = 1; i <seconds.size(); ++i){
			// insert(seconds[js[i] - 1])
			it = std::lower_bound(firsts.begin(), firsts.begin() + fsize, seconds[js[i] - 1]);
			firsts.insert(it, seconds[js[i] - 1]);
			puts("IIIII");
		}
		for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "Pair " << i + 1 << ": "
                  << pairs[i].first << ", " << pairs[i].second  << std::endl;}
	}
	catch(const char *e){
		std::cout << e << std::endl;
	}
}
