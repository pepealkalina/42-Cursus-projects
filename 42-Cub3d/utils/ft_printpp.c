/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:17:20 by paescano          #+#    #+#             */
/*   Updated: 2023/11/20 18:33:55 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	ft_printpp(char **pp)
{
	int	j;

	j = 0;
	if (pp != NULL)
	{
		while (pp[j])
		{
			printf("pp[%d]: %s|\n", j, pp[j]);
			j++;
		}
	}
}