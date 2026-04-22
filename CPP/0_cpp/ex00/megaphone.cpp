#include <cctype>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *";

	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			av[i][j] = std::toupper(av[i][j]);
		std::cout << av[i];
	}
	std::cout << "\n";
	return (0);
}
