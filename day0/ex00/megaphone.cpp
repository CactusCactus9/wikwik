/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkace <abelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:45:18 by abelkace          #+#    #+#             */
/*   Updated: 2023/11/10 17:47:22 by abelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				std::cout<<(char)toupper(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout<<std::endl;
	}
	else
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
}
