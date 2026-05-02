#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>

int	errorOut(std::string msg) {
	std::cout << "Error: " << msg << std::endl;
	return (1);
}

int	main(int ac, char **av) {
	if (ac != 4)
		errorOut("you need to provide a file, a target word and a replacement word!");

	std::string	filename = av[1];
	std::string	target = av[2];
	std::string	replacement = av[3];

	if (filename.empty() || target.empty())
		errorOut("filename and Target can't be empty strings!");

	std::ifstream	inFile(filename.c_str());
	std::ofstream	outFile((filename + ".replace").c_str());
	std::string		line;
	size_t			targetSize = target.length();

	if (!inFile)
		errorOut("could not open input file.");

	if (!outFile)
		errorOut("could not create output file.");

	while (std::getline(inFile, line))
	{
		size_t	pos = 0;
		size_t	match;

		while ((match = line.find(target, pos)) != std::string::npos )
		{
			outFile << line.substr(pos, match - pos);
			outFile << replacement;
			pos = match + targetSize;
		}

		outFile << line.substr(pos);

		if (!inFile.eof())
			outFile << '\n';
	}
}
