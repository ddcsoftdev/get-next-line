/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:12:18 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/21 12:23:35 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	char			*line;
	static char		*text;
	static int		end;
	int				start;

//for bonus create a list with struct
//		-fd
//		-end
//		if fd != to current fd then search for it in list
//		if found end = to list end
//		if not open new entry in list for this fd and end = 0;
//		update list end at end of function
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
	if (!line || !text[end])
		free(text);
	return (line);
}

/*int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
		//printf ("%d", fd);
		printf("%s",get_next_line_bonus(fd));
		printf("%s",get_next_line_bonus(fd));
			printf("%s",get_next_line_bonus(fd));
			printf("%s",get_next_line_bonus(fd));
			printf("%s",get_next_line_bonus(fd));

	return (0);
}*/
