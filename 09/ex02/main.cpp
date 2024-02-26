#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>



int	main(int ac, char **av){
	std::vector<Pair>	pairs;
	std::vector<int>	sorted;
	int					size;
	clock_t				start;
	double				duration;

	
	int	temp = 0;
	try{
		if (ac <= 2)
			throw ("Error!");
		std::cout << "Before: ";
		for (int i = 1; (i < ac - 1 && i + 1 < ac); i+=2){
			std::cout << av[i] << " " << av[i + 1] << " ";
			check_args(av[i]);
			//--make pairs----//
			if (atoi(av[i]) > atoi(av[i + 1]))
				pairs.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
			else	
				pairs.push_back(std::make_pair(atoi(av[i + 1]), atoi(av[i])));
		}
		std::cout << std::endl;
		size = pairs.size();
		
		//----store last element----//
		if ((ac - 1) % 2 != 0)
			temp = atoi(av[ac - 1]);
		start = clock();
		// //----merge sort----//
		mergeSort(pairs, 0, (pairs.size() - 1));
		
		//----inserting----//
		sorted = insert_pend(pairs, temp);
		duration = ((clock() - start) * 1000000 /  CLOCKS_PER_SEC);
		std::cout << "After :";
		for (size_t i = 0; i < sorted.size(); ++i){
			std::cout << sorted[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << size * 2 << " elements with std::vector : " << duration << " us" << std::endl;
	}
	catch(const char *e){
		std::cout << e << std::endl;
	}
}
