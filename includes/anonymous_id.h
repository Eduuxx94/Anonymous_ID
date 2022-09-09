#ifndef ANONYMOUS_ID_H
# define ANONYMOUS_ID_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include <string.h>

typedef struct s_data {
	int		lineid;
	int		file_out;
	int		fd;
	char	*current_line;
	char	*path_file;
	char	*new_file;
}			t_data;

// Main Functions
void	ft_put_anonynous( char *current_line);
void	ft_open_file(t_data *data);
void	ft_exit(t_data *data, char *str, int error);
int		main(int argc, char **argv);

#endif