# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 19:33:24 by mbourdel          #+#    #+#              #
#    Updated: 2015/01/17 14:38:21 by mbourdel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./

SRC = fdf.c ft_get_the_map.c get_next_line.c
SRC += ft_set_pt3d.c ft_set_pt2d.c ft_make_the_taff.c
SRC += ft_mlx_stuff.c ft_map.c ft_img.c ft_pixel_put_img.c
SRC += ft_draw.c ft_octants.c ft_color.c ft_print_hud.c
SRC += ft_set_env.c ft_altitude.c ft_set2_pt3d.c
SRC += ft_set2_pt2d.c ft_set3_pt2d.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

MLX = -L/usr/X11/lib -lmlx -lXext -lX11

FLAG = -Wall -Werror -Wextra

RED = \x1B[0;31m

GREEN = \x1B[0;32m

YELLOW = \x1B[1;33m

NC = \x1B[0m

all: $(NAME)

$(NAME):
	@cd $(LIBFT_PATH); $(MAKE) -f Makefile
	@gcc $(FLAG) $(SRC_PATH)$(SRC) -o $(NAME) $(LIBFT_PATH)libft.a $(MLX)
	@echo "${GREEN}"
	@echo "     ████████╗██╗  ██╗██╗███████╗    ██╗███████╗"
	@echo "     ╚══██╔══╝██║  ██║██║██╔════╝    ██║██╔════╝"
	@echo "        ██║   ███████║██║███████╗    ██║███████╗"
	@echo "        ██║   ██╔══██║██║╚════██║    ██║╚════██║"
	@echo "        ██║   ██║  ██║██║███████║    ██║███████║"
	@echo "        ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝    ╚═╝╚══════╝"
	@echo "${YELLOW}"
	@echo "                                                               "
	@echo "FFFFFFFFFFFFFFFFFFFFFFDDDDDDDDDDDDD      FFFFFFFFFFFFFFFFFFFFFF"
	@echo "F::::::::::::::::::::FD::::::::::::DDD   F::::::::::::::::::::F"
	@echo "F::::::::::::::::::::FD:::::::::::::::DD F::::::::::::::::::::F"
	@echo "FF::::::FFFFFFFFF::::FDDD:::::DDDDD:::::DFF::::::FFFFFFFFF::::F"
	@echo "  F:::::F       FFFFFF  D:::::D    D:::::D F:::::F       FFFFFF"
	@echo "  F:::::F               D:::::D     D:::::DF:::::F             "
	@echo "  F::::::FFFFFFFFFF     D:::::D     D:::::DF::::::FFFFFFFFFF   "
	@echo "  F:::::::::::::::F     D:::::D     D:::::DF:::::::::::::::F   "
	@echo "  F:::::::::::::::F     D:::::D     D:::::DF:::::::::::::::F   "
	@echo "  F::::::FFFFFFFFFF     D:::::D     D:::::DF::::::FFFFFFFFFF   "
	@echo "  F:::::F               D:::::D     D:::::DF:::::F             "
	@echo "  F:::::F               D:::::D    D:::::D F:::::F             "
	@echo "FF:::::::FF           DDD:::::DDDDD:::::DFF:::::::FF           "
	@echo "F::::::::FF           D:::::::::::::::DD F::::::::FF           "
	@echo "F::::::::FF           D::::::::::::DDD   F::::::::FF           "
	@echo "FFFFFFFFFFF           DDDDDDDDDDDDD      FFFFFFFFFFF           "
	@echo "${NC}"

clean:
	@rm -rf $(OBJ)
	@echo "${RED}"
	@echo "▓█████▄ ▓█████   ██████ ▄▄▄█████▓ ██▀███   █    ██  ▄████▄  ▄▄▄█████▓ ██▓ ▒█████   ███▄    █ "
	@echo "▒██▀ ██▌▓█   ▀ ▒██    ▒ ▓  ██▒ ▓▒▓██ ▒ ██▒ ██  ▓██▒▒██▀ ▀█  ▓  ██▒ ▓▒▓██▒▒██▒  ██▒ ██ ▀█   █ "
	@echo "░██   █▌▒███   ░ ▓██▄   ▒ ▓██░ ▒░▓██ ░▄█ ▒▓██  ▒██░▒▓█    ▄ ▒ ▓██░ ▒░▒██▒▒██░  ██▒▓██  ▀█ ██▒"
	@echo "░▓█▄   ▌▒▓█  ▄   ▒   ██▒░ ▓██▓ ░ ▒██▀▀█▄  ▓▓█  ░██░▒▓▓▄ ▄██▒░ ▓██▓ ░ ░██░▒██   ██░▓██▒  ▐▌██▒"
	@echo "░▒████▓ ░▒████▒▒██████▒▒  ▒██▒ ░ ░██▓ ▒██▒▒▒█████▓ ▒ ▓███▀ ░  ▒██▒ ░ ░██░░ ████▓▒░▒██░   ▓██░"
	@echo " ▒▒▓  ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒▓ ░▒▓░░▒▓▒ ▒ ▒ ░ ░▒ ▒  ░  ▒ ░░   ░▓  ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ "
	@echo " ░ ▒  ▒  ░ ░  ░░ ░▒  ░ ░    ░      ░▒ ░ ▒░░░▒░ ░ ░   ░  ▒       ░     ▒ ░  ░ ▒ ▒░ ░ ░░   ░ ▒░"
	@echo " ░ ░  ░    ░   ░  ░  ░    ░        ░░   ░  ░░░ ░ ░ ░          ░       ▒ ░░ ░ ░ ▒     ░   ░ ░ "
	@echo "   ░       ░  ░      ░              ░        ░     ░ ░                ░      ░ ░           ░ "
	@echo " ░                                                 ░                                         "
	@echo " ▄████▄   ▒█████   ███▄    █   █████▒██▓ ██▀███   ███▄ ▄███▓▓█████ ▓█████▄                   "
	@echo "▒██▀ ▀█  ▒██▒  ██▒ ██ ▀█   █ ▓██   ▒▓██▒▓██ ▒ ██▒▓██▒▀█▀ ██▒▓█   ▀ ▒██▀ ██▌                  "
	@echo "▒▓█    ▄ ▒██░  ██▒▓██  ▀█ ██▒▒████ ░▒██▒▓██ ░▄█ ▒▓██    ▓██░▒███   ░██   █▌                  "
	@echo "▒▓▓▄ ▄██▒▒██   ██░▓██▒  ▐▌██▒░▓█▒  ░░██░▒██▀▀█▄  ▒██    ▒██ ▒▓█  ▄ ░▓█▄   ▌                  "
	@echo "▒ ▓███▀ ░░ ████▓▒░▒██░   ▓██░░▒█░   ░██░░██▓ ▒██▒▒██▒   ░██▒░▒████▒░▒████▓                   "
	@echo "░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ▒ ▒  ▒ ░   ░▓  ░ ▒▓ ░▒▓░░ ▒░   ░  ░░░ ▒░ ░ ▒▒▓  ▒                   "
	@echo "  ░  ▒     ░ ▒ ▒░ ░ ░░   ░ ▒░ ░      ▒ ░  ░▒ ░ ▒░░  ░      ░ ░ ░  ░ ░ ▒  ▒                   "
	@echo "░        ░ ░ ░ ▒     ░   ░ ░  ░ ░    ▒ ░  ░░   ░ ░      ░      ░    ░ ░  ░                   "
	@echo "░ ░          ░ ░           ░         ░     ░            ░      ░  ░   ░                      "
	@echo "░                                                                   ░                        "
	@echo "${NC}"


fclean: clean
	@rm -rf $(NAME)

re: fclean all

deslib:
	@cd $(LIBFT_PATH); $(MAKE) fclean -f Makefile

total: deslib re

