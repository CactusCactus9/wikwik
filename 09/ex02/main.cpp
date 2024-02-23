#include "PmergeMe.hpp"
#include <algorithm>

typedef std::pair<int, int> Pair;

struct CompareFirst {
    bool operator()(const Pair& a, const Pair& b) const {
        return a.first < b.first;
    }
};

int	main(int ac, char **av){
	std::vector<std::pair<int, int> >	pairs;
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
			//----store last element----//
			if ((ac - 1) % 2 != 0)
				temp = atoi(av[ac - 1]);
			//----merge sort----//
			std::stable_sort(pairs.begin(), pairs.end(), CompareFirst());
			 for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "Pair " << i + 1 << ": "
                  << pairs[i].first << ", " << pairs[i].second << std::endl;}
	}
	catch(const char *e){
		std::cout << e << std::endl;
	}
}
