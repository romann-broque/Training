
#include "mini_lem_in.h"

void	get_inst(const char *line)
{
	int		i;
	bool	(*is_inst[])(const char *) = {is_start_inst,
											 is_end_inst,
											 is_link_inst};
	int		(*inst[])(const char *) = {start, end, link};

	i = 0;
	while (i < NBOF_COM)
	{
		if (is_inst[i](line) == true)
		{
			inst[i](line);
			break ;
		}
		++i;
	}
}

static int	start(const char *command)
{

}

static int	end(const char *command)
{

}

static int	link(const char *command)
{

}
