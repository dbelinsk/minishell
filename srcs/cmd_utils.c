#include "minishell.h"

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get TYPE and leave line[0] on first printable character
 ** TODO - return TYPE on success, NULL on fail
 */
char		*get_type()
{
	return ("echo");
}

/**
 ** TODO - modify parameters to recive (char *type)
 ** TODO - get PATH based on recived type
 ** TODO - return PATH on success, NULL on fail
 */
char		*get_path()
{
	return ("/bin/echo");
}

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get CONTENT and leave line[0] on first printable character
 ** TODO - return CONTENT on success, NULL on fail
 */
char		*get_content()
{
	return ("Hola Mundo!");
}

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get FLAGS and leave line[0] on first printable character
 ** TODO - return 1 if FLAG found, 0 no FLAG, -1 on fail
 */
int			get_flag()
{
	return (NONE);
}

/**
 ** TODO - modify parameters to recive (char **line)
 ** TODO - trim *line from whitespaces
 ** TODO - get SEPARATOR and leave line[0] on first printable character
 **			if exists
 ** TODO - return 2 on PIPE found, 1 on NEW CMD, 0 no SEP, -1 on fail
  */
int			get_sep()
{
	return (NONE);
}

/**
 ** TODO - modify parameters to recive (char *type)
 ** TODO - get EXECUTABLE function based on recived cmd (or type)
 ** TODO - return EXECUTABLE function on success, NULL on fail
 */
void		*get_exe(t_command cmd)
{
	return (&execute);
}
