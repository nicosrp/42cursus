
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int j;
	int l;
	int p;

	if (argc != 3)
		return (0);
	i = 0;

	while (argv[1][i])
	{
		p = 0;
		j = 0;
		while (argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
			{
				l = i;
				while (l > 0)
				{
					if (argv[1][i] == argv[1][l])
					{
						p = 0;
						break;
					}
				}
			}
			j ++;
		}
		if (p == 0)
			write(1, &argv[1][i], 1);
		i ++;
	}

}
