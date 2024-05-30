/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pplen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:46:02 by paescano          #+#    #+#             */
/*   Updated: 2023/11/08 12:58:36 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	ft_pplen(char **pp)
{
	int	i;

	if (!pp)
		return (0);
	i = 0;
	while (pp[i])
		i++;
	return (i);
}