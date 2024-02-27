#include "PmergeMe.hpp"

int	main(int ac, char **av){
	std::vector<Pair>	pairs;
	std::vector<int>	sorted;
	clock_t				start;
	double				v_duration;
	char				*endptr;
	long				value;
	int	temp = 0;
	std::deque<Pair>	pr;
	std::deque<int>		ordered;
	clock_t				beginning;
	double				d_duration;
	int	tmp = 0;
	
	//----vectors----//
	{
		try{
			//----parsing----//
			start = clock();
			if (ac < 2)
				throw ("Error! Not enough arguments!");
			for (int i = 1; i < ac; i++){
				check_args(av[i]);
				value = std::strtol(av[i], &endptr, 10);
				if (value > INT_MAX)
					throw("Error! Number too big!");
			}
				
			
			// ----make pairs----//
			for (int i = 1; (i < ac - 1 && i + 1 < ac); i+=2){
				if (atoi(av[i]) > atoi(av[i + 1]))
					pairs.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
				else	
					pairs.push_back(std::make_pair(atoi(av[i + 1]), atoi(av[i])));
			}
			//----Last odd element----//
			if (((ac - 1) % 2) != 0){
				temp = atoi(av[ac - 1]);
				check_args(av[ac - 1]);
			}
			if (ac > 2){
				//----merge sort----//
				v_mergeSort(pairs, 0, (pairs.size() - 1));
				
				//----inserting----//
				sorted = v_insert_pend(pairs, temp);
				v_duration = ((clock() - start) * 1000000 /  CLOCKS_PER_SEC);
			}
			std::cout << "Before: ";
			for (int i = 1; i < ac ; i++)
				std::cout << av[i] << " ";
			std::cout << std::endl;
			if (!std::is_sorted(sorted.begin(), sorted.end()))
				throw ("Not sorted!");
			std::cout << "After :";
			if (ac > 2){
				for (size_t i = 0; i < sorted.size(); ++i){
					std::cout << sorted[i] << " ";
				}
				std::cout << std::endl;
			}
			else if ( ac == 2)
				std::cout << av[1] << std::endl;
		}
		catch(const char *e){
			std::cout << e << std::endl;
		}
	}
	//----Deques----//
	{
		try{
			//----parsing----//
			beginning = clock();
			if (ac < 2)
				throw ("Error! Not enough arguments!");
			for (int i = 1; i < ac; i++){
				check_args(av[i]);
				value = std::strtol(av[i], &endptr, 10);
				if (value > INT_MAX)
					throw("Error! Number too big!");
			}
				
			
			// ----make pairs----//
			for (int i = 1; (i < ac - 1 && i + 1 < ac); i+=2){
				if (atoi(av[i]) > atoi(av[i + 1]))
					pr.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
				else	
					pr.push_back(std::make_pair(atoi(av[i + 1]), atoi(av[i])));
			}
			//----Last odd element----//
			if (((ac - 1) % 2) != 0){
				tmp = atoi(av[ac - 1]);
				check_args(av[ac - 1]);
			}
			if (ac > 2){
				//----merge sort----//
				d_mergeSort(pr, 0, (pr.size() - 1));
				
				//----inserting----//
				ordered = d_insert_pend(pr, tmp);
				d_duration = ((clock() - beginning) * 1000000 /  CLOCKS_PER_SEC);
			}
			std::cout << "Before: ";
			for (int i = 1; i < ac ; i++)
				std::cout << av[i] << " ";
			std::cout << std::endl;
			if (!std::is_sorted(ordered.begin(), ordered.end()))
				throw ("Not ordered!");
			std::cout << "After :";
			if (ac > 2){
				for (size_t i = 0; i < ordered.size(); ++i){
					std::cout << ordered[i] << " ";
				}
				std::cout << std::endl;
			}
			else if ( ac == 2)
				std::cout << av[1] << std::endl;
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << v_duration << " us" << std::endl;
			std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << d_duration << " us" << std::endl;
		}
		catch(const char *e){
			std::cout << e << std::endl;
		}
	}
}
