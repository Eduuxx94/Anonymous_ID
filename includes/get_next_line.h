/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:57:12 by ede-alme          #+#    #+#             */
/*   Updated: 2022/09/09 13:57:13 by ede-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //for printf main tester
# include <unistd.h> //for open and close functions main terster

typedef struct s_vars {
	int		i;
	int		j;
	char	*temp;
	int		i_line;
	int		i_buffer;
}		t_vars;

//Main Function
char	*get_next_line(int fd);

//Utils Functions
char	*ft_get_buff(char *line, char *buffer, t_vars var);

#endif