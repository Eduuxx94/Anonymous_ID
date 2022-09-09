#include "anonymous_id.h"

int g_index = 0;

void	ft_put_anonynous( char *current_line)
{
	int	i;
	int	times;

	i = 0;
	times = 0;
	while (current_line && current_line[i] != '\0')
	{
		if (current_line[i] >= '0' && current_line[i] <= '9')
		{
			current_line[i] = '9';
			times++;
			if (times == 9)
				current_line[i] = '0';
		}
		i++;
	}
}

void	ft_write_file(t_data *data)
{
	while (1)
	{
		if (data->current_line)
			free (data->current_line);
		data->current_line = get_next_line(data->fd);
		if ((data->current_line && !strncmp(data->current_line, "    <CustomerID>", 16)) || (data->current_line && !strncmp(data->current_line,"    <CustomerTaxID>", 19)) || (data->current_line && !strncmp(data->current_line,"  <CustomerID>", 14)) || (data->current_line && !strncmp(data->current_line, "<CustomerID>", 12)) || (data->current_line && !strncmp(data->current_line, "<CustomerTaxID>", 15))) //this will search in main code if line cointains the updated date
			ft_put_anonynous(data->current_line);
		if (data->current_line && ++g_index)
			write(data->file_out, data->current_line, (strlen(data->current_line)));
		else
			break ;
		if (++data->lineid % 5000 == 0)
			printf("Line: %i\n", data->lineid);
	}
	if (data->current_line)
		free (data->current_line);
}

void	ft_open_file(t_data *data)
{
	data->fd = open(data->path_file, O_RDONLY); //Open the file
	if (data->fd < 0)
		ft_exit(data, "A Error occurred while try open path_file\n", 0);

	data->file_out = open(data->new_file, O_RDWR | O_CREAT, 0644); //This will create new file
	if (data->file_out < 0)
		ft_exit(data, "A Error occurred while creating the file_out\n", 3);

	data->current_line = NULL;
	data->lineid = 0;
	ft_write_file(data);
}


void	ft_exit(t_data *data, char *str, int error)
{
	if (str)
		printf("%s", str);
	if (error > 0)
		printf("Error code: %i\n", error);
	else if (error == -1)
	{
		printf("%s\n", data->new_file);
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		ft_exit(&data, "Please use: \n./inject_code	path_file	new_path\n", 0);
	data.path_file = argv[1];
	data.new_file = "out.txt";
	if (argc == 3)
		data.new_file = argv[2];
	ft_open_file(&data);
	printf("Data anonymization: %i times...\n", g_index);
	ft_exit(&data, "Saved file: ", -1);
	return (0);
}
