/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:42:01 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/23 12:46:55 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <chrono>
# include <iomanip>

bool checkArgs(const char **argv);

void mergeSortVec(std::vector<int> &src);
void mergeSortLst(std::list<int> &src);

void PmergeMe(const char **argv);
#endif