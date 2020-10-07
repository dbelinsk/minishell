#include "minishell.h"
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
 ** TODO - INFINITE LOOP UNTIL EOF or ERROR
 ** TODO - EACH GET FUNCTION HAS TO RECIVE &line ###
 ** TODO - GET THE VALUE OF &line and modify &line for next get call
 ** TODO - PUSH BACK TO comandline struct chain
 ** Initializes the comandline struct chain
 */
int		init(t_command **cmd, char *line)
{
	t_command		tmp;

	tmp.type = get_type();
	tmp.path = get_path();
	tmp.content = get_content();
	tmp.flag = get_flag();
	tmp.sep = get_sep();
	tmp.exe = get_exe(tmp);

	tmp.exe(tmp);
	return (0);
}
