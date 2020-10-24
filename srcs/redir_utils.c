#include "minishell.h"

void			redir_write(char *fname, t_command *cmd)
{
	int		fd;

	if ((fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return ;
	if (!cmd->flag)
		ft_putendl_fd(cmd->content, fd);
	else
		ft_putstr_fd(cmd->content, fd);
	close(fd);
}

void			redir_append(char *fname, t_command *cmd)
{
	int		fd;

	if ((fd = open(fname, O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
		return ;
	if (!cmd->flag)
		ft_putendl_fd(cmd->content, fd);
	else
		ft_putstr_fd(cmd->content, fd);
	close(fd);
}
void			redirect(t_command *cmd, char *content)
{
	char	cwd_file[BUFSIZ];
	int		fd;

	fd = -1;
	getcwd(cwd_file, sizeof(cwd_file));
	ft_strlcat(cwd_file, "/", BUFSIZ);
	ft_strlcat(cwd_file, cmd->fname, BUFSIZ);
	if (cmd->redirection == REDIRECTION_WRITE)
		fd = open(cwd_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (cmd->redirection == REDIRECTION_APPEND)
		fd = open(cwd_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		
	if (fd < 0)
		return ;
	if (!ft_strncmp(cmd->type, "echo", 4) && cmd->flag)
		ft_putstr_fd(content, fd);
	else if (!content)
		ft_putchar_fd(0, fd);
	else
		ft_putendl_fd(content, fd);
	close(fd);
}
