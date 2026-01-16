
NAME = megaphone

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): megaphone.cpp
	c++ megaphone.cpp -Wall -Wextra -Werror -std=c++98 -o megaphone

clean:
	rm -rf megaphone

fclean: clean

re: fclean all
