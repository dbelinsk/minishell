#include "minishell.h"

void		clean_cmd(t_command **cmd)
{
	t_command		*tmp;

	while ((*cmd))
	{
		free((*cmd)->type);
		free((*cmd)->content);
		free((*cmd)->path);
		free((*cmd)->fname);
		tmp = (*cmd)->next;
		free(*cmd);
		*cmd = tmp;
	}
}
/*
** Creates new comandline struct item
** Return - pointer to item
*/
t_command	*new_cmd_item(t_command item_cmd)
{
	t_command		*cmd;

	if (!(cmd = (t_command*)malloc(sizeof(*cmd))))
		return (NULL);
	cmd->type = item_cmd.type;
	cmd->path = item_cmd.path;
	cmd->content = item_cmd.content;
	cmd->flag = item_cmd.flag;
	cmd->redirection = item_cmd.redirection;
	cmd->fname = item_cmd.fname;
	cmd->sep = item_cmd.sep;
	cmd->err = 0;
	cmd->exe = item_cmd.exe;
	cmd->next = NULL;
	return (cmd);
}

/**
 ** Pushes back to the list of comandlines the new item
 */
void	cmd_push_back(t_command **cmd, t_command cmd_item)
{
	t_command		*tmp;

	if (!*cmd)
	{
		*cmd = new_cmd_item(cmd_item);
		(*cmd)->prev = NULL;
		return ;
	}
	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd_item(cmd_item);
	tmp->next->prev = tmp;
}

/** ---- MODIFY REQUIRED ---
 ** TODO - LOOP UNTIL @param line length > 0
 ** TODO - PUSH BACK TO comandline struct chain
 ** --- IMPORTANT ---
 ** type, content, path are reservated in memory
 ** Initializes the comandline struct chain
 */
int		init(t_command **cmd, char *line)
{
	t_command		item;
	char			*paths;

	if (!line || !cmd)
		return -1;
	paths = ft_getenv("PATH");
	while (ft_strlen(line))
	{
		item.type = get_type(&line);
		item.flag = get_flag(&line);
		item.content = get_content(&line);
		item.redirection = get_redirection(&line);
		if (item.redirection)
			item.fname = get_content(&line);
		else
			item.fname = NULL;
		if ((item.sep = get_sep(&line)) < 0)
			return (-1);
		item.path = get_path(item.type, paths);
		item.exe = get_exe(item.type);
		cmd_push_back(cmd, item);
	}
	return (0);
}
