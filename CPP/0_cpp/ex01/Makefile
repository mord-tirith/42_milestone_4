#######################
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#######################

# Basic Variables:
NAME		= phonebook
PNAME		= Phonebook
INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= .obj/

# File Variables:
SRC_FILES	= PhoneBook.cpp main.cpp
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

# Compiler Variables:
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

# Makefile Variables:
MAKEFLAGS	+= --no-print-directory
STAMP		=	$(OBJ_DIR).build-stamp

# Valgrind Variables:
VLOG		= valgrind.log
VFLAGS		= --leak-check=full --log-file=$(VLOG)

####################
#      ▜   ▗ ▗     #
#  ▛▌▀▌▐ █▌▜▘▜▘█▌  #
#  ▙▌█▌▐▖▙▖▐▖▐▖▙▖  #
#  ▌               #
####################

CYAN		:= $(shell tput setaf 87)
BLUE		:= $(shell tput setaf 111)
RED			:= $(shell tput setaf 160)
PINK		:= $(shell tput setaf 200)
YELLOW		:= $(shell tput setaf 220)
RESET		:= $(shell tput sgr0)

################
#      ▜       #
#  ▛▘▌▌▐ █▌▛▘  #
#  ▌ ▙▌▐▖▙▖▄▌  #
################

.PHONY: all clean fclean re clean_install banner valgrind

all: $(NAME)
	@if test -e $(STAMP) && test $(STAMP) -nt $(NAME); then \
		echo "${BLUE}${PNAME} already up to date${RESET}"; \
	fi
	@touch $(STAMP)

$(NAME): $(OBJ)
	@make banner
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${BLUE}${PNAME} installed${RESET}"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@if test -e $(OBJ_DIR); then \
		rm -rf $(OBJ_DIR); \
		echo "${YELLOW}.o files removed${RESET}"; \
	else \
		echo "${RED}Error: no .o files to remove${RESET}"; \
	fi

fclean: clean
	@if test -e $(NAME); then \
		rm -f $(NAME) $(VLOG) \
		echo "${YELLOW}${PNAME} uninstalled${RESET}"; \
	else \
		echo "${RED}Error: ${PNAME} isn't currently installed${RESET}"; \
	fi

re: fclean all

banner:
	@echo "${PINK}░       ░░░  ░░░░  ░░░      ░░░   ░░░  ░░        ░░       ░░░░      ░░░░      ░░░  ░░░░  ░";
	@echo "▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒▒  ▒▒";
	@echo "▓       ▓▓▓        ▓▓  ▓▓▓▓  ▓▓  ▓  ▓  ▓▓      ▓▓▓▓       ▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓▓  ▓▓     ▓▓▓▓";
	@echo "█  ████████  ████  ██  ████  ██  ██    ██  ████████  ████  ██  ████  ██  ████  ██  ███  ██";
	@echo "█  ████████  ████  ███      ███  ███   ██        ██       ████      ████      ███  ████  █";
	@echo "                                                                               ${CYAN}by thenriqu${RESET}";

valgrind: $(NAME)
	@valgrind $(VFLAGS) ./$(NAME)
