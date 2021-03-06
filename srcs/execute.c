#include "minishell.h"

void			tmp_print_item(t_command *item)
{
	printf("type = [%s]\n", item->type);
	printf("path = [%s]\n", item->path);
	printf("content = [%s]\n", item->content);
	printf("flag = [%s]\n", item->flag);
	printf("sep = [%d]\n", item->sep);
	printf("err = [%d]\n", item->err);
	if (item->prev)
	{
		printf("prev->type = [%s]\n", item->prev->type);
		printf("prev->path = [%s]\n", item->prev->path);
		printf("prev->content = [%s]\n", item->prev->content);
		printf("prev->flag = [%s]\n", item->prev->flag);
		printf("prev->sep = [%d]\n", item->prev->sep);
		printf("prev->err = [%d]\n", item->prev->err);
	}
	if (item->next)
	{
		printf("next->type = [%s]\n", item->next->type);
		printf("next->path = [%s]\n", item->next->path);
		printf("next->content = [%s]\n", item->next->content);
		printf("next->flag = [%s]\n", item->next->flag);
		printf("next->sep = [%d]\n", item->next->sep);
		printf("next->err = [%d]\n", item->next->err);
	}

}

void			print_all_items(t_command *tmp)
{
	while (tmp)
	{
		if (tmp->prev)
				printf("prev type = %s\n", tmp->prev->type);
		else
				printf("tmp->prev = NULL\n");
		printf("tmp type = %s\n", tmp->type);
		if (tmp->next)
			printf("next type = %s\n", tmp->next->type);
		else
				printf("tmp->next = NULL\n");
		printf("*******************\n");
		tmp = tmp->next;
	}
}

int				s_exit(t_command *cmd)
{
	if (cmd->redirection)
			redirect(cmd, NULL);
	if (cmd->prev)
		if (cmd->prev->sep == PIPE ||
			(cmd->prev->sep == AND && cmd->prev->err))
			return (1);
	if (cmd->sep == PIPE)
		return (1);
	return (0);
}



int				s_echo(t_command *cmd)
{
	pid_t	child;
	char	*args[4];
	int		i;

	i = 0;
	args[i++] = cmd->type;
	args[i++] = cmd->flag;
	args[i++] = cmd->content;
	args[i++] = (char*)0;
	/*if (cmd->flag)
		ft_putstr_fd(cmd->content, 1);
	else
		ft_putendl_fd(cmd->content, 1);*/

	if ((child= fork()) == 0)
	{
		if (cmd->prev)
			if (cmd->prev->err && cmd->prev->sep != PIPE)
				return (-1);
		if ((cmd->sep != PIPE))
		{
			if (cmd->prev && cmd->prev->sep != PIPE && cmd->prev->err)
				return (1);
			else
			{
				if (cmd->redirection)
					redirect(cmd, cmd->content);
				else
					execve(cmd->path, args, NULL);
			}
		}
	}
	else if (child > 0)
		wait(&child);
	else
		return (0);
	return (1);
}

int				s_cd(t_command *cmd)
{
	DIR			*dir;
	char		*path;
	char		*tmp;

	tmp = ft_strtrim(cmd->content, " ");
	free(cmd->content);
	cmd->content = tmp;
	if (!ft_strlen(cmd->content))
			path = ft_getenv("HOME");
	else
			path = cmd->content;
	if (!(dir = opendir(path)))
	{
		m_error(cmd->type, cmd->content, DIR_ERROR);
		return (-1);
	}
	closedir(dir);
	if (cmd->sep != PIPE)
	{
		if (cmd->prev)
			if (cmd->prev->err)
				return (-1);
		if (cmd->redirection)
			redirect(cmd, NULL);
		chdir(path);
	}
	return (1);
}

int				s_pwd(t_command *cmd)
{
	char	cwd[BUFSIZ];
	pid_t	child;
	char	*args[2];

	args[0] = cmd->type;
	args[1] = (char*)0;
	if ((child= fork()) == 0)
	{
		if (cmd->prev)
			if (cmd->prev->err)
				return (-1);
		if (cmd->sep != PIPE)
		{
			if (cmd->redirection)
			{
				getcwd(cwd, sizeof(cwd));
				redirect(cmd, cwd);
			}
			else
				if (execve(cmd->path, args, NULL) == -1)
					printf("bash: %s: %s\n",cmd->path, strerror(errno));
				//execve(cmd->path, args, NULL);
		}
	}
	else if (child > 0)
		wait(&child);
	else
		return (0);
	return (1);
}

int				s_env(t_command *cmd)
{
	extern char		**environ;
	pid_t			child;
	char			*args[4];

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = "env";
	args[3] = (char*)0;
	if ((child= fork()) == 0)
	{
		if (cmd->prev)
			if (cmd->prev->err && cmd->prev->sep != PIPE)
				return (-1);
		if (cmd->sep != PIPE)
		{
			if (cmd->redirection)
			{
				redirect(cmd, NULL);
			}
			else
				execve(args[0], args, environ);
		}
	}
	else if (child > 0)
		wait(&child);
	else
		return (0);
	return (1);
}

int			s_export(t_command *cmd)
{
	char		*name;
	char		*val;
	int			eq;

	if (!(val = ft_strchr(cmd->content, '=')))
		return (1);
	name = cmd->content;
	eq = (int)(val - cmd->content);
	name[eq] = 0;
	val++;
	if (cmd->prev)
		if (cmd->prev->sep == PIPE)
			return (1);
	if (cmd->sep == PIPE)
		return (1);
	if (cmd->redirection)
			redirect(cmd, NULL);
	if (ft_setenv(name, val, 1) < 0)
		m_error(cmd->type, val, IDENTIFYER_ERROR);
	return (1);
}

int			s_unset(t_command *cmd)
{
	if (cmd->redirection)
			redirect(cmd, NULL);
	ft_unsetenv(cmd->content);
	return (1);
}

void		universal(t_command *cmd)
{
	char	cwd[BUFSIZ];
	pid_t	child;
	char	*args[2];

	args[0] = cmd->type;
	args[1] = (char*)0;
	if ((child= fork()) == 0)
	{
		if (execve(cmd->path, args, NULL) == -1)
			printf("bash: %s: %s\n",cmd->path, strerror(errno));
	}
	else if (child > 0)
		wait(&child);
	else
		return ;
	return ;
}

/**
 ** HERE COMES TO DO LIST FOR MINISHELL
 */
int				execute(t_command **cmd)
{
	int				ret;
	t_command		*aux;

	ret = 1;
	aux = *cmd;
	while (aux)
	{
		//tmp_print_item(aux);
		if (aux->exe)
		{
			if ((ret = aux->exe(aux)) < 0)
				aux->err = 1;
		}
		else
			m_error(aux->type, NULL, COMMAND_ERR);
		aux = aux->next;
	}
	clean_cmd(cmd);
	return (ret);
}
