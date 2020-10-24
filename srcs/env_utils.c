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
	extern char **environ;
	char 		**ep;
	char		**sp;
	size_t		len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	len = ft_strlen(name);
	ep = environ;
	while (*ep)
	{
		if (!ft_strncmp(*ep, name, len) && (*ep)[len] == '=')
		{
			sp = ep;
			while (*sp)
			{
				*sp = *(sp + 1);
				sp++;
			}
		}
		else
			ep++;
	}
	return 0;
}

int			ft_putenv(char *str)
{
	putenv(str);
/*	extern char	**environ;
	char		**ep;
	char		**new_env;
	char		**aux;
	int			size;
	ep = environ;
	size = 0;
	while (*ep)
	{
		size++;
		ep++;
	}
	if (!(new_env = malloc(sizeof(char**) * (size + 2))))
	{
		errno = ESRCH;
		return (-1);
	}
	aux = new_env;
	ep = environ;
	while (*ep)
		*(aux++) = *(ep++);
	*(aux++) = str;
	*aux = NULL;
	free(environ);
	environ = new_env;*/
	return (0);
}

int			ft_setenv(const char *name, const char *value, int overwrite)
{
	char	*env;
	char	*tmp;
	int		ret;

	if (!name || name[0] == 0 || ft_strchr(name, '=')  || !value)
	{
		errno = EINVAL;
		return -1;
	}
	if (ft_getenv(name) && overwrite == 0)
		return 0;
	ft_unsetenv(name);
	tmp = ft_strjoin(name, "=");
	env = ft_strjoin(tmp, value);
	free(tmp);
	//ret = ft_putenv(env);
	return (ft_putenv(env) != 0 ? -1 : 0);
}



