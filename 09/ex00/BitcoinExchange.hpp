#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <map>

void	read_file(char **av);
std::map<std::string, std::string>	split_data();
int		ft_leap(int	year);
#endif