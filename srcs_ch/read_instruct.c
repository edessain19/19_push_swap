# include "../include/push_swap.h"

char	*get_line(void)
{
	char	buf[2];
	char	*tmp;
	char	*line;
	int		ret;

	line = NULL;
	ft_memset(buf, 2);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
	{
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
		ft_memset(buf, 2);
	}
	return (line);
}