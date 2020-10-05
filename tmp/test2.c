#include<stdio.h>
#include <termios.h>
#include<sys/wait.h>
#include<signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void			put_promt()
{
	char *dir;

	dir = NULL;
	dir = getcwd(dir, 0);
	write(STDOUT_FILENO, dir, strlen(dir));
	write(STDOUT_FILENO, "\n$ ", 3);
	free(dir);
}

void			signal_handler(int sig)
{


	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\033[2D\033[J\n", 8);
		put_promt();
	}
	if (sig == SIGQUIT)
	{
		write(STDOUT_FILENO, "\033[2D\033[J", 7);
	}
}

int ft_getchar(int fd)
{
	static char buf[BUFSIZ];
	static char *bufp;
	static int i;

	bufp = buf;
	i = 0;
	if (!i)
	{
		i = read(fd, buf, 1);
		bufp = buf;
	}
	if ( --i >= 0 )
		return  *bufp++;
	return EOF;
}

char			*ft_fgets(int size)
{
	char		*ret;
	int			c;
	int			i = 0;

	ret = malloc(sizeof(*ret) * (size + 1));
	if (size <= 0)
		return (ret);
	int	fd = dup(STDOUT_FILENO);
	while (i < size - 1 && ((c = ft_getchar(fd)) != EOF))
	{
		ret[i++] = c;
		if (c == '\n')
			break;
	}
	ret[i] = '\0';
	close(fd);
	if (i > 0)
		return ret;
	else
		return NULL;
}

int main() {
char my_string[1500];
    int n = 0;
    char *p, *p2 = NULL;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	put_promt();

	char buf[1];
	while (1)
	{
		if (!(p = ft_fgets(3)))
		{
			write(STDOUT_FILENO, "logout\n", 7);
			break ;
		}
		else
		{
			write(STDOUT_FILENO, "\033[K", 3);
			free(p);
		}
	}
}


