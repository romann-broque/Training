/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 01:42:18 by romannbroqu       #+#    #+#             */
/*   Updated: 2023/11/18 21:00:04 by rbroque          ###   ########.fr       */
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
	bool has_pipe = cmd[i] != NULL && is_pipe(cmd[i]);
	int	fd[2];
	int	pid;
	int	status;

	if (has_pipe && pipe(fd) == -1)
	{
		error("error pipe\n");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid != 0)
	{
		cmd[i] = NULL;
		if (has_pipe
			&& (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			error("dup or close error!\n");
		else
		{
			execve(*cmd, cmd, env);
			error("error!\n");
		}
		return (EXIT_FAILURE);
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], STDIN_FILENO) == -1
			|| close(fd[0]) == -1 || close(fd[1]) == -1))
		error("dup or close error!\n");
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

static int	execute_cd(char **av)
{
	if (av[0] != NULL && (av[1] == NULL || is_pipe(av[1]) || is_semicolon(av[1])))
	{
		if (chdir(av[0]) == 0)
			return (EXIT_SUCCESS);
		else
			error("error chdir\n");
	}
	else
		error("cd: too many arguments\n");
	return (EXIT_FAILURE);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	status;

	if (ac == 1)
		return (EXIT_SUCCESS);
	status = EXIT_SUCCESS;
	i = 0;
	while (av[i] != NULL && av[i + 1] != NULL)
	{
		av += i + 1;
		i = 0;
		while (av[i] != NULL
			&& is_pipe(av[i]) == false && is_semicolon(av[i]) == false)
		{
			++i;
		}
		if (*av != NULL && strcmp("cd", *av) == 0)
			status = execute_cd(av + 1);
		else if (i > 0)
			status = execute_cmd(av, env, i);
	}
	return (status);
}
