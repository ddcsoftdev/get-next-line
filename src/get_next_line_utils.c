/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:42:00 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/21 12:11:35 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_line(char *text, int end, int start)
{
	char	*line;
	int		i;
	
	line = malloc((end - start) * sizeof(char) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (start < end)
	{
		line[i] = text[start];
		i++;
		start++;
	}
	line[i] = '\0';
	return (line);
}