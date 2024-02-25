#include "PmergeMe.hpp"
#include <algorithm>

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
		// std::cout << "size" << pairs.size() << std::endl;
		size = pairs.size();

		std::vector<int>	firsts;
		std::vector<int>	seconds;
		std::vector<int>::iterator	it;
		//----store last element----//
		if ((ac - 1) % 2 != 0)
			temp = atoi(av[ac - 1]);

		// //----merge sort----//
		mergeSort(pairs, 0, (pairs.size() - 1));

		//----inserting----//
		//firsts
		firsts.push_back(pairs[0].second);
		firsts.push_back(pairs[0].first);
		for (size_t i = 1; i < pairs.size(); ++i)
			firsts.push_back(pairs[i].first);
		//seconds
		for (size_t i = 0; i < pairs.size(); ++i)
			seconds.push_back(pairs[i].second);
		for (size_t i = 0; i < firsts.size(); ++i)
			std::cout << "firdst-----" << firsts[i] << std::endl;
		fsize = firsts.size();
		for (size_t i = 0; i < seconds.size(); ++i)
			std::cout << "seconds----" << seconds[i]<< std::endl;
		std::vector<int>	js = jacobsthal_index(seconds.size());
		for (size_t i = 0; i < seconds.size(); ++i)
			std::cout << "jacobs----" << js[i]<< std::endl;
			int	n_j = js[1];
			int	o_j = 1;
		for(size_t i = 1; i < seconds.size(); ++i){
			std::cout << "jacob:***** " << js[i] << std::endl;
			if (js[i] > (int)seconds.size()){
				n_j = seconds[(int)seconds.size() + 1];
			std::cout << "NEW jacob:***** " << n_j << std::endl;
			}
			else if (js[i] <= (int)seconds.size())
				n_j = js[i];
				o_j = js[i - 1];
				int	insert_size = n_j + o_j - 1;
				while (n_j > o_j){
				std::cout << "n_j >> " << n_j << " o_j>>> " << o_j << std::endl;
					it = std::lower_bound(firsts.begin(), firsts.begin() + insert_size, seconds[n_j - 1]);
					std::cout << "what to insert : " << seconds[n_j - 1] << std::endl;
					firsts.insert(it, seconds[n_j - 1]);
					n_j--;
					fsize++;
					std::cout << "size" << fsize << std::endl;
					for (int j = 0; j < fsize; ++j)
						std::cout << "final:  " << firsts[j] << std::endl;
				}
			// }
		}
			puts("IIIII");
		// for (size_t i = 0; i < firsts.size(); ++i) {
        // std::cout << "Pair " << i + 1 << ": "
        //           << firsts[i] << std::endl;}
	}
	catch(const char *e){
		std::cout << e << std::endl;
	}
}
