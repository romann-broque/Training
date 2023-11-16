/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:42:18 by romannbroque      #+#    #+#             */
/*   Updated: 2023/11/16 02:38:58 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static bool	is_pipe(const char *const str)
{
	return (str[0] == '|' && str[1] == '\0');
}

static bool	is_semicolon(const char *const str)
{
	return (str[0] == ';' && str[1] == '\0');
}

static int	execute_cmd(
	const char *const cmd,
	char *const *const arg,
	char *const *const env
	)
{
	return (execve(cmd, arg, env));
}

static size_t	get_count_arg(char **av)
{
	size_t	i;

	i = 0;
	while (av[i] != NULL
	&& is_pipe(av[i]) == false && is_semicolon(av[i]) == false)
		++i;
	return (i);
}

static size_t	add_cmd_to_lst(
	t_command *const cmd,
	char **args,
	char **env
	)
{
	const size_t	count_arg = get_count_arg(args);
	size_t			i;

	cmd->cmd = args[0];
	cmd->env = env;
	cmd->arg = malloc(sizeof(char *) * (count_arg + 1));
	i = 0;
	while (i < count_arg)
	{
		cmd->arg[i] = args[i];
		++i;
	}
	cmd->arg[i] = NULL;
	return (count_arg);
}

static void	fill_cmd_lst(
	t_command *const cmd_lst,
	char **args,
	char **env
	)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (is_pipe(args[i]))
		{
			cmd_lst[i].type = E_PIPE;
			cmd_lst[i].cmd = "|";
		}
		else if (is_semicolon(args[i]))
		{
			cmd_lst[i].type = E_SEMICOLON;
			cmd_lst[i].cmd = ";";
		}
		else
		{
			cmd_lst[i].type = E_CMD;
			i += add_cmd_to_lst(cmd_lst + i, args, env);
		}
		++i;
	}
	cmd_lst[i].cmd = NULL;
}

static t_command	*init_cmd_lst(const int size, char **args, char **env)
{
	t_command	*cmd_lst;

	cmd_lst = (t_command *)malloc((size + 1) * sizeof(t_command));
	if (cmd_lst == NULL)
		return (NULL);
	fill_cmd_lst(cmd_lst, args, env);
	return (cmd_lst);
}

static void	print_cmd_lst(t_command *const cmd_lst)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cmd_lst[i].cmd != NULL)
	{
		printf("(");
		if (cmd_lst[i].type == E_PIPE)
			printf("PIPE");
		else if (cmd_lst[i].type == E_SEMICOLON)
			printf("SEMICOLON");
		else
		{
			printf("cmd -> [%s]\n", cmd_lst[i].cmd);
			printf("(args:\n");
			j = 0;
			while (cmd_lst[i].arg[j] != NULL)
			{
				printf("[%s]", cmd_lst[i].arg[j]);
				++j;
			}
			printf(")");
		}
		printf("-");
		++i;
	}
	printf("\n");
}

int	main(int ac, char **av, char **env)
{
	t_command	*cmd_lst;

	++av;
	--ac;
	cmd_lst = init_cmd_lst(ac, av, env);	
	print_cmd_lst(cmd_lst);
	return (0);
}
