#include "minishell.h"

char		*ft_getenv(const char *var)
{
	extern char **environ;
	int			i;
	int			len;

	i = 0;
	len = strlen(var);
	while (environ[i])
	{
		if (!strncmp(environ[i], var, len) && environ[i][len] == '=')
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

int			ft_unsetenv(const char *name)
{
	return 0;
}

int			ft_putenv(char *str)
{
	return (0);
}

int			ft_setenv(const char *name, const char *value, int overwrite)
{
	char	*env;

	/*ft_strcpy(env, name);
	ft_strcat(env, "=");
	ft_strcat(env, value);*/
	return (ft_putenv(env) != 0) ? -1 : 0;
}



