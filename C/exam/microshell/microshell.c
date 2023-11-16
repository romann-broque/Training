/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:42:18 by romannbroque      #+#    #+#             */
/*   Updated: 2023/11/16 10:19:51 by romannbroque     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static size_t	ft_strlen(const char *const str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

static void	error(const char *const str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

static bool	is_pipe(const char *const str)
{
	return (str[0] == '|' && str[1] == '\0');
}

static bool	is_semicolon(const char *const str)
{
	return (str[0] == ';' && str[1] == '\0');
}

static int	execute_cmd(
	char **const cmd,
	char *const *const env,
	const int i
	)
{
	//int has_pipe = cmd[i] != NULL && is_pipe(cmd[i]);
	int	pid;
	int	status;

	pid = fork();
	if (pid != 0)
	{
		cmd[i] = NULL;
		status = execve(*cmd, cmd, env);
		error("error!\n");
		return (EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	return (WIFEXITED(status) && WEXITSTATUS(status));

}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	status;

	if (ac == 1)
		return (EXIT_SUCCESS);
	--ac;
	++av;
	i = 0;
	while (av[i] != NULL)
	{
		av += i;
		i = 0;
		while (av[i] != NULL
			&& is_pipe(av[i]) == false && is_semicolon(av[i]) == false)
			++i;
		if (i > 0)
			status = execute_cmd(av, env, i);
	}
	return (status);
}
