/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:28:23 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/18 10:03:01 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.hpp"

void	replace_file(std::string file, std::string s1, std::string s2){
	std::string	line;
	size_t	index;
	int		i;
	
	index = 0;
	i = 0;
	std::fstream	infile(file);
	if (!infile.is_open()){
		std::cerr << "file not open" << std::endl;
		return;
	}
	std::fstream	outfile(file +  ".replace", std::ios::out | std::ios::trunc);
	if (!outfile.is_open()){
		std::cerr << "couldn't open this file" << std::endl;
		return;
	}
	if (s1 == "")
	{
		while (std::getline(infile, line))
			outfile << line <<std::endl;;
		outfile.close();
		return ;
	}
	while (std::getline(infile, line))
	{
		index = line.find(s1);
		while (index != (std::string::npos))
		{
			outfile << line.substr(0, index) << s2;
			line = line.substr(index + s1.length());
			index = line.find(s1);
		}
		outfile << line;
		outfile<<std::endl;
	}
	infile.close();
	outfile.close();
	}
