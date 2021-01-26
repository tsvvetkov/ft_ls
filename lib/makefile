.PHONY: clean fclean re all

# COLORS
BLUE = "\e[38;5;69m"
EOC = "\e[0m"

# COMPILER
CC = clang
CFLAGS = -Wall -Wextra -Werror -Wunused

# LIBNAME
NAME := lib.a

DH = include

# LIBFT, GET_NEXT_LINE ---------------------------------------------------------
H_LIB = libft get_next_line
H_LIB := $(addprefix $(DH)/, $(addsuffix .h, $(H_LIB)))

D_LIB = libft
DS_LIB = $(D_LIB)/src
DO_LIB = $(D_LIB)/obj

S_LIB = \
memset bzero memcpy memccpy memmove memchr memcmp memalloc memdel \
atoi itoa itoa_base\
isalpha isdigit isalnum isascii isprint toupper tolower isnumber isnumber_int\
strlen strdup strcpy strncpy strcat strncat strlcat strchr strrchr \
strstr strnstr strcmp strncmp strnew strdel strclr striter striteri \
strmap strmapi strequ strnequ strsub strjoin strtrim strsplit \
putchar putstr putendl putnbr putchar_fd putstr_fd putendl_fd putnbr_fd \
numlen strnew_size arrdel
S_LIB := $(addprefix ft_, $(addsuffix .c, $(S_LIB)))
S_GNL = get_next_line
S_GNL := $(addsuffix .c, $(S_GNL))

# PRINTF -----------------------------------------------------------------------
H_PRINTF = ft_printf
H_PRINTF := $(addprefix $(DH)/, $(addsuffix .h, $(H_PRINTF)))

D_PRINTF := printf
DS_PRINTF := $(D_PRINTF)/src
DO_PRINTF := $(D_PRINTF)/obj

S_PRINTF = \
ft_printf ft_itoabasex ft_str_sym_cmp \
ft_cast_size_di ft_cast_size_poxu ft_cast_size_float \
parse_chr parse_str parse_per parse_bit parse_bcolor parse_bdollar parse_float parse_dipoxu \
parse_num_spec parse_dipoxu_spec_cases parse_num parse_float_number parse_float_flag \
parse_specifiers parse_output is_specifers \
record_chr record_str record_bit record_per record_float \
init_spec_struct ft_clean_mult \
ld_util ft_smbu long_m_str long_math ft_array_mantisa
S_PRINTF := $(addsuffix .c, $(S_PRINTF))

# AV_PARSE ---------------------------------------------------------------------
H_AV = av_parse_args
H_AV := $(addprefix $(DH)/, $(addsuffix .h, $(H_AV)))

D_AV := av_parse_args
DS_AV := $(D_AV)/src
DO_AV := $(D_AV)/obj

S_AV = av_parse_args av_parse_args_extra
S_AV := $(addsuffix .c, $(S_AV))

# FILE PATH --------------------------------------------------------------------
SS_LIB := $(addprefix $(DS_LIB)/, $(S_LIB) $(S_GNL))
O_LIB := $(addprefix $(DO_LIB)/, $(S_LIB:.c=.o) $(S_GNL:.c=.o))

SS_PRINTF := $(addprefix $(DS_PRINTF)/, $(S_PRINTF))
O_PRINTF := $(addprefix $(DO_PRINTF)/, $(S_PRINTF:.c=.o))

SS_AV := $(addprefix $(DS_AV)/, $(S_AV))
O_AV := $(addprefix $(DO_AV)/, $(S_AV:.c=.o))

SS_ALL := $(SS_LIB) $(SS_PRINTF) $(SS_AV)
O_ALL := $(O_LIB) $(O_PRINTF) $(O_AV)
H_ALL := $(H_LIB) $(H_PRINTF) $(H_AV)

all: $(NAME)

$(DO_LIB)/%.o: $(DS_LIB)/%.c $(H_LIB)
	@mkdir -p $(DO_LIB) 
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DH) -fPIE

$(DO_PRINTF)/%.o: $(DS_PRINTF)/%.c $(H_PRINTF) $(H_LIB)
	@mkdir -p $(DO_PRINTF)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DH) -fPIE

$(DO_AV)/%.o: $(DS_AV)/%.c $(H_AV)
	@mkdir -p $(DO_AV) 
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DH) -fPIE

$(NAME): $(SS_ALL) $(O_ALL) $(H_ALL)
	@ar rcs $(NAME) $(O_ALL)
	@echo $(BLUE)"LIB COMPILED"$(EOC)

clean:
	@rm -rf $(DO_LIB)
	@rm -rf $(DO_PRINTF)
	@rm -rf $(DO_AV)

fclean: clean
	@rm -f $(NAME)

re: fclean all
