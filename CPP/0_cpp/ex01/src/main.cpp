#include "Contact.hpp"
#include <iostream>

int	main()
{
	Contact test("John", "Doe", "Jhonny", "333", "Crazy little thing called love I just can't handle it this thing");

	std::cout << test.getCard() << std::endl;
	return (0);
}
