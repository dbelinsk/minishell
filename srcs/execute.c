#include "minishell.h"

int				s_exit(t_command **cmd, char **envp, int is_pipe )
{
	int		ret = 0;

	if (is_pipe)
		return (1);
	if ((*cmd)->sep == PIPE)
		ret = 1;
	return (ret);
}

int				s_echo(t_command *cmd, char **envp)
{
	pid_t	child;
	char	*args[4];
	int		i;

	i = 0;
	args[i++] = cmd->type;
	if (cmd->flag)
		args[i++] = "-n";
	args[i++] = cmd->content;
	args[i++] = (char*)0;
	if ((child= fork()) == 0)
	{
		if (cmd->sep != PIPE)
			execve (cmd->path, args, NULL);
	}
	else if (child > 0)
		wait(&child);
	else
		return (0);
	return (1);
}

int				s_cd(t_command *cmd, char **envp)
{
	DIR			*dir;
	char		*path;

	if (!ft_strlen(cmd->content))
			path = ft_getenv(envp, "HOME");
	else
			path = cmd->content;
	if (!(dir = opendir(path)))
	{
		m_error(cmd->type, cmd->content, DIR_ERROR);
		return (1);
	}
	closedir(dir);
	if (cmd->sep != PIPE)
	{
		if (!ft_strlen(cmd->content))
			chdir(ft_getenv(envp, "HOME"));
		else
			chdir(cmd->content);
	}
	return (1);
}

int				s_pwd(t_command *cmd, char **envp)
{
	pid_t	child;
	char	*args[2];

	args[0] = cmd->type;
	args[1] = (char*)0;
	if ((child= fork()) == 0)
	{
		if (cmd->sep != PIPE)
			execve(cmd->path, args, NULL);
	}
	else if (child > 0)
		wait(&child);
	else
		return (0);
	return (1);
}

int				s_env(t_command *cmd, char **envp)
{
	pid_t	child;
	char	*args[4];

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = "env";
	args[3] = (char*)0;
	if ((child= fork()) == 0)
	{
		if (cmd->sep != PIPE)
			execve(args[0], args, envp);
	}
	else if (child > 0)
		wait(&child);
	else
		return (0);
	return (1);
}

int			s_export(t_command *cmd, char **envp)
{
	printf("hello from export\n");
	return (1);
}

int			s_unset(t_command *cmd, char **envp)
{
	printf("hello from uset\n");
	return (1);
}


/**
 ** HERE COMES TO DO LIST FOR MINISHELL
 */
int				execute(t_command **cmd, char **envp)
{
	int				ret;
	int				is_pipe;
	t_command		*aux;

/*	printf("type = [%s]\n", (*cmd)->type);
	printf("path = [%s]\n", (*cmd)->path);
	printf("content = [%s]\n", (*cmd)->content);
	printf("flag = [%d]\n", (*cmd)->flag);
	printf("sep = [%d]\n", (*cmd)->sep);*/
	ret = 1;
	is_pipe = 0;
	while ((*cmd))
	{
		if ((*cmd)->sep == PIPE)
			is_pipe = 1;
		if ((*cmd)->sep == SEMCOL)
			is_pipe = 0;
		if ((*cmd)->exe || !ft_strncmp((*cmd)->type, "export", 6)
						|| !ft_strncmp((*cmd)->type, "unset", 5))
			ret = (*cmd)->exe(*cmd, envp, is_pipe);
		else
			m_error((*cmd)->type, NULL, COMMAND_ERR);
		aux = (*cmd)->next;
		clean_cmd(cmd);
		*cmd = aux;
	}
	return (ret);
}
