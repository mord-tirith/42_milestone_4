#######################
#        ▘  ▌ ▜       #
#  ▌▌▀▌▛▘▌▀▌▛▌▐ █▌▛▘  #
#  ▚▘█▌▌ ▌█▌▙▌▐▖▙▖▄▌  #
#######################

# Basic Variables:
NAME		= phonebook
VAL_NAME	= prebuilt_phonebook
PNAME		= PhoneBook
INC_DIR		= inc/
SRC_DIR		= src/
OBJ_DIR		= .obj/
VAL_OBJ_DIR	= .valgrind-objects/

# File Variables:
SRC_FILES	= Card.cpp Contact.cpp PhoneBook.cpp main.cpp
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:= $(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

VAL_FILES	= Card.cpp Contact.cpp PhoneBook.cpp grindMain.cpp
VAL_SRC		= $(addprefix $(SRC_DIR), $(VAL_FILES))
VAL_OBJ		:= $(patsubst $(SRC_DIR)%.cpp, $(VAL_OBJ_DIR)%.o, $(VAL_SRC))

# Compiler Variables:
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

# Makefile Variables:
MAKEFLAGS	+=	--no-print-directory
STAMP		=	$(OBJ_DIR).build-stamp
VAL_STAMPP	=	$(VAL_OBJ_DIR).build-stamp

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

.PHONY: all clean fclean re top_call

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
	if [ -d "$(VAL_OBJ_DIR)" ]; then \
		rm -rf "$(VAL_OBJ_DIR)"; \
		removed=1; \
	fi; \
	if [ "$$removed" -eq 1 ]; then \
		echo "${YELLOW}.o files removed${RESET}"; \
	else \
		echo "${RED}Error: no .o files to remove${RESET}"; \
	fi

fclean: clean
	@removed_normal=0; \
	removed_valgrind=0; \
	if test -e ${NAME}; then \
		rm -f "${NAME}"; \
		removed_normal=1; \
	fi; \
	if test -e $(VAL_NAME); then \
		rm -f "${VAL_NAME}"; \
		removed_valgrind=1; \
	fi; \
	if [ "$$removed_valgrind" -eq 0 ] && [ "$$removed_normal" -eq 0 ]; then \
		echo "${RED}Error: ${PNAME} isn't currently installed${RESET}"; \
	elif [ "$$removed_valgrind" -eq 1 ] && [ "$$removed_normal" -eq 0 ]; then \
		echo "${YELLOW}${VAL_NAME} uninstalled${RESET}"; \
	elif [ "$$removed_valgrind" -eq 0 ] && [ "$$removed_normal" -eq 1 ]; then \
		echo "${YELLOW}${NAME} uninstalled${RESET}"; \
	else \
		echo "${YELLOW}"All ${PNAME} versions uninstalled"${RESET}"; \
	fi

re: fclean all

valgrind: $(VAL_NAME)
	@if test -e $(VAL_STAMPP) && test $(VAL_STAMPP) -nt $(VAL_NAME); then \
		echo "${BLUE}Pre-built phonebook already installed${RESET}"; \
	fi
	@touch $(VAL_STAMPP)

$(VAL_NAME): $(VAL_OBJ)
	@$(CC) $(CFLAGS) $(VAL_OBJ) -o $(VAL_NAME)
	@echo "${BLUE}${VAL_NAME} installed${RESET}"

$(VAL_OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "${CYAN}Compiled $@${RESET}"


