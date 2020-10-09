#include "minishell.h"

void		clean_cmd(t_command **cmd)
{
	t_command		*tmp;

	while (*cmd)
	{
		free((*cmd)->type);
		free((*cmd)->content);
		free((*cmd)->path);
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
	cmd->sep = item_cmd.sep;
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
		return ;
	}
	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_cmd_item(cmd_item);
}

/** ---- MODIFY REQUIRED ---
 ** TODO - LOOP UNTIL @param line length > 0
 ** TODO - PUSH BACK TO comandline struct chain
 ** --- IMPORTANT ---
 ** type, content, path are reservated in memory
 ** Initializes the comandline struct chain
 */
void		init(t_command **cmd, char *line, char *paths)
{
	t_command		item;

	if (!line || !cmd || !ft_strlen(paths))
		return ;
	while (ft_strlen(line))
	{
		item.type = get_type(&line);
		item.flag = get_flag(&line);
		item.content = get_content(&line);
		item.sep = get_sep(&line);
		item.path = get_path(item.type, paths);
		item.exe = get_exe(item.type);
		cmd_push_back(cmd, item);
	}
}
