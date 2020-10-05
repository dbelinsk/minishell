#include<stdio.h>
#include <termios.h>
#include<sys/wait.h>
#include<signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ft_getchar(int fd)
{
	char buf[BUFSIZ];
	char *bufp;
	int i;

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
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (i > 0)
		return ret;
	else
		return NULL;
}

int ft_getchar2(int fd)
{
	char buf[BUFSIZ];
	printf("%d\n", fd);
	if (read(fd, buf, 1) > 0)
		return (1);
	return (0);
}

int main()
{
	pid_t	pid = fork();
	char	*p;
	int		fd, fd2;
	if (pid == 0)
	{
		while (1)
		{
			/*int fds[2];
			pipe(fds);
			fds[0] = dup(STDOUT_FILENO);*/
			//dup2(fds[1], STDIN_FILENO);
			//read(fds[0], buf, buf_sz);
			if (!ft_getchar2(fds[0]))
			{
				printf("yes\n");
			}
			else
			{
				printf("NO\n");
			}
			//dup2(fd, STDIN_FILENO);
			//close(fds);
			sleep(1);
		}
	}
	else if (pid > 0)
	{
		//parrent;
		while (1);
	}
	else
		printf("ERROR\n");

/*
	while (1)
	{
	};*/
    return 0;
}
