#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#define LEN 512

int ft_getchar2()
{
	char buf[BUFSIZ];
	int br;

	buf[0] = 0;
	br = read(STDOUT_FILENO, buf, BUFSIZ);
	if (br > 0)
		return (1);
	return (0);
}

int main()
{

	while (1)
	{
		/*char	buf[1];
		int		p[2];

		if (pipe(p) < 0)
			break ;
		int br = read(STDOUT_FILENO, buf, sizeof(buf));
		if (br > 0)
			buf[br] = 0;
		//printf("--->%d\n", br);
		write(p[1], buf, strlen(buf));*/
		//int	fd = dup(STDOUT_FILENO);
		if (!ft_getchar2())
		{
			//printf("-yes\n");
			write(STDOUT_FILENO, "\033[K", 3);
		}
		else
		{
			//printf("-no\n");
			write(STDOUT_FILENO, "\033[K", 3);
		}
		//dup2(fd, STDOUT_FILENO);
		//close(fd);
	}
	return 0;
}
