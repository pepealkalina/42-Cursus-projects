/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:20:24 by preina-g          #+#    #+#             */
/*   Updated: 2024/04/24 09:35:47 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool is_number(const char *num)
{
    unsigned int it = 0;
    while (it < std::strlen(num) && std::isdigit(num[it])) 
        it++;
    return num != NULL && it == std::strlen(num);
}

bool checkArgs(const char **argv)
{
    int i = 0;
    // check if every element is a number
    while (argv[i])
    {
        if (!is_number(argv[i]))
            return (false);
        i++;
    }
    return (true);
}

void mergeSortVec(std::vector<int> &src)
{
    if (src.size() < 2)
        return ;
    
    //create the pair of lists for separate
    std::vector<int> right;
    std::vector<int> left;

    //set the len for divide that  is src.size() / 2
    int mid = src.size() / 2;
    
    // set an iterator for iterate the src list
    std::vector<int>::iterator it = src.begin();
    //add the elements to each array
    for (int i = 0; i < mid; i++)
        left.push_back(*it++);
    for (unsigned int i = mid; i < src.size(); i++)
        right.push_back(*it++);

    //separate it recursively
    mergeSortVec(left);
    mergeSortVec(right);

    //merge vectors
    std::merge(left.begin(), left.end(), right.begin(), right.end(), src.begin());
}

void mergeSortLst(std::list<int> &src)
{
    if (src.size() < 2)
        return ;
    
    //create the pair of lists for separate
    std::list<int> right;
    std::list<int> left;

    //set the len for divide that  is src.size() / 2
    int mid = src.size() / 2;
    
    // set an iterator for iterate the src list
    std::list<int>::iterator it = src.begin();
    //add the elements to each array
    for (int i = 0; i < mid; i++)
        left.push_back(*it++);
    for (unsigned int i = mid; i < src.size(); i++)
        right.push_back(*it++);

    //separate it recursively
    mergeSortLst(left);
    mergeSortLst(right);
    
    //merge left to right list
    left.merge(right);
    
    //set src to left
    src = left;
}

static void print(std::list<int> &src)
{
    std::list<int>::iterator it;

    for (it = src.begin(); it != src.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe(const char **argv)
{
    std::list<int> lst;
    std::vector<int> vec;
    
    // set precision for print time to fixed point

    //check if arguments are correct
    if (!checkArgs(argv))
    {
        std::cerr << "Error: Wrong arguments" << std::endl;
        return;
    }
    
    //add the elements to vector and list
    for (int i = 0; argv[i]; i++)
    {
        lst.push_back(std::atoi(argv[i]));
        vec.push_back(std::atoi(argv[i]));
    }

    // print the list
    print(lst);
    std::cout << std::endl;
    
    // SORT LIST
    //take the time to do the difference
    std::cout << std::fixed << std::setprecision(9);
    std::clock_t time = clock();
    
    //sort the vector
    mergeSortLst(lst);
    
    //print ordered list
    print(lst);
    
    //update time
    double lstTime = (std::clock() - time) / (double)(CLOCKS_PER_SEC * 1000);
    //print the output required for subject
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list<int> : " << lstTime << " us" << std::endl;

    
    // SORT LIST
    // take the time to do the difference
    time = clock();
    
    //sort the vector
    mergeSortVec(vec);
    
    //update time
    double vecTime = (std::clock() - time) / (double)(CLOCKS_PER_SEC * 1000);
    //print the output required for subject
    std::cout << "Time to process a range of " << lst.size() << " elements with std::vector<int> : " << vecTime << " us" << std::endl;
}