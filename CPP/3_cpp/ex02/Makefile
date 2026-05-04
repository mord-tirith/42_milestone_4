#######################
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#######################

# Basic Variables:
NAME		= repetitiveWork
PNAME		= Repetitive Work
INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= .obj/

# File Variables:
SRC_FILES	= ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

# Compiler Variables:
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

# Makefile Variables:
MAKEFLAGS	+=	--no-print-directory
STAMP		=	$(OBJ_DIR).build-stamp

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

.PHONY: all clean fclean re testOutput

all: $(NAME)
	@if test -e $(STAMP) && test $(STAMP) -nt $(NAME); then \
		echo "${BLUE}${PNAME} already up to date${RESET}"; \
	fi
	@touch $(STAMP)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "${BLUE}${PNAME} installed${RESET}"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "${CYAN}Compiled $@${RESET}"

clean:
	@removed=0; \
	if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf "$(OBJ_DIR)"; \
		removed=1; \
	fi; \
	if [ "$$removed" -eq 1 ]; then \
		echo "${YELLOW}.o files removed${RESET}"; \
	else \
		echo "${RED}Error: no .o files to remove${RESET}"; \
	fi

fclean: clean
	@removed=0; \
	if test -e ${NAME}; then \
		rm -f "${NAME}"; \
		removed=1; \
	fi; \
	if [ "$$removed" -eq 0 ]; then \
		echo "${RED}Error: ${PNAME} isn't currently installed${RESET}"; \
	else \
		echo "${YELLOW}"All ${PNAME} versions uninstalled"${RESET}"; \
	fi

re: fclean all

testOutput:
	@echo "Default constructor called" > testOutput
	@echo "Copy constructor called" >> testOutput
	@echo "Copy assignment operator called" >> testOutput
	@echo "getRawBits member function called" >> testOutput
	@echo "Default constructor called" >> testOutput
	@echo "Copy assignment operator called" >> testOutput
	@echo "getRawBits member function called" >> testOutput
	@echo "getRawBits member function called" >> testOutput
	@echo "0" >> testOutput
	@echo "getRawBits member function called" >> testOutput
	@echo "0" >> testOutput
	@echo "getRawBits member function called" >> testOutput
	@echo "0" >> testOutput
	@echo "Destructor called" >> testOutput
	@echo "Destructor called" >> testOutput
	@echo "Destructor called" >> testOutput

