/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:12:18 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/21 12:09:08 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*text;
	static int		end;
	int				start;

	if (fd < 0)
		return (NULL);
	if (!text)
	{
		text = malloc(BUFFER_SIZE * sizeof(char) + 1);
		if (text)
			read(fd, text, BUFFER_SIZE);
		end = 0;
	}
		start = end;
	while (text[end] && text[start] != '\n')
		end++;
	end++;
	line = get_line(text, end, start);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}*/
