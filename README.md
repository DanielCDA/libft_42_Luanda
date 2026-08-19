*This project has been created as part of the 42 curriculum by danagost.*

# Libft

## Description

O **libft** é uma biblioteca em C que reimplementa um conjunto de funções da `libc` (como `strlen`, `memcpy`, `atoi`, etc.), seguidas por um conjunto de funções adicionais úteis (manipulação de strings, conversões, funções para file descriptors) e, por fim, um conjunto de funções para manipular listas ligadas (`t_list`).

O objetivo é compreender, de dentro para fora, como as funções da biblioteca padrão de C funcionam, ao mesmo tempo que se constrói uma "caixa de ferramentas" própria que será reutilizada nos próximos projetos do currículo da 42.

A biblioteca está organizada em três partes:

- **Parte 1 — Funções da libc**: reimplementação de funções padrão (`isalpha`, `isdigit`, `memset`, `strlcpy`, `strncmp`, `atoi`, `calloc`, `strdup`, etc.), mantendo o mesmo protótipo e comportamento das originais.
- **Parte 2 — Funções adicionais**: funções que não existem na `libc` ou existem de forma diferente (`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`).
- **Parte 3 — Lista ligada**: implementação de uma estrutura `t_list` e das funções para a criar, percorrer, transformar e libertar (`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`).

## Instructions

### Compilação

Para compilar a biblioteca estática `libft.a`:

```bash
make
```

Isto gera o ficheiro `libft.a` na raiz do repositório, a partir dos ficheiros `ft_*.c`, com as flags `-Wall -Wextra -Werror`.

Outras regras disponíveis no `Makefile`:

```bash
make clean   # remove os ficheiros objeto (.o)
make fclean  # remove os .o e o libft.a
make re      # fclean + all (recompila tudo do zero)
```

### Utilização num projeto

Para usar a biblioteca noutro projeto:

1. Copia a pasta do `libft` (ou os ficheiros necessários) para o teu projeto.
2. No teu `Makefile`, compila o `libft.a` primeiro e depois faz o link:

```makefile
libft/libft.a:
	make -C libft

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) -Lft -lft -Llibft -o $(NAME)
```

3. Inclui o cabeçalho no teu código:

```c
#include "libft.h"
```

## Resources

- Manual pages do POSIX/BSD (`man strlen`, `man memcpy`, `man strlcpy`, `man calloc`, etc.) — usadas como referência principal para garantir que o comportamento (valor de retorno, edge cases) das funções reimplementadas corresponde exatamente ao das originais.
- Documentação da BSD `<bsd/string.h>` para `strlcpy`/`strlcat`, funções que não existem por omissão na glibc.
- **Uso de IA (Claude, Anthropic)**: a IA foi usada, após a implementação das funções, para:
  - Rever o código já escrito e verificar conformidade com o enunciado (comparação função a função com a tabela de protótipos do subject).
  - Correr o `norminette` sobre todos os ficheiros para confirmar conformidade com a Norma.
  - Escrever e correr testes funcionais comparando o comportamento de funções como `ft_strlcpy`, `ft_strlcat`, `ft_itoa` (caso `INT_MIN`), `ft_split`, `ft_substr` e `ft_strtrim` com as versões da libc do sistema, incluindo casos-limite (strings vazias, delimitadores repetidos, `start`/`len` fora dos limites).
  - Identificar um pequeno problema de limpeza de código: includes desnecessários (`<stdio.h>`, `<string.h>`) em `ft_strlcat.c`, que foram removidos.
  - Redigir este ficheiro `README.md`.
  A lógica e a escrita de todas as funções da biblioteca foram feitas pelo autor; a IA não foi usada para gerar código de resolução do projeto, apenas para revisão, testes e verificação de norma e auxiliar na traduçao do manual e a descricao das funcoes.

## Descrição detalhada da biblioteca

| Ficheiro | Função | Descrição |
|---|---|---|
| `ft_isalpha.c` | `ft_isalpha` | Testa se o carácter é uma letra |
| `ft_isdigit.c` | `ft_isdigit` | Testa se o carácter é um dígito |
| `ft_isalnum.c` | `ft_isalnum` | Testa se o carácter é alfanumérico |
| `ft_isascii.c` | `ft_isascii` | Testa se o carácter pertence ao conjunto ASCII |
| `ft_isprint.c` | `ft_isprint` | Testa se o carácter é imprimível |
| `ft_strlen.c` | `ft_strlen` | Calcula o comprimento de uma string |
| `ft_memset.c` | `ft_memset` | Preenche uma zona de memória com um byte |
| `ft_bzero.c` | `ft_bzero` | Preenche uma zona de memória com zeros |
| `ft_memcpy.c` | `ft_memcpy` | Copia uma zona de memória (sem sobreposição) |
| `ft_memmove.c` | `ft_memmove` | Copia uma zona de memória (com sobreposição) |
| `ft_strlcpy.c` | `ft_strlcpy` | Copia uma string de forma segura, com limite de tamanho |
| `ft_strlcat.c` | `ft_strlcat` | Concatena uma string de forma segura, com limite de tamanho |
| `ft_toupper.c` | `ft_toupper` | Converte um carácter para maiúscula |
| `ft_tolower.c` | `ft_tolower` | Converte um carácter para minúscula |
| `ft_strchr.c` | `ft_strchr` | Procura a primeira ocorrência de um carácter numa string |
| `ft_strrchr.c` | `ft_strrchr` | Procura a última ocorrência de um carácter numa string |
| `ft_strncmp.c` | `ft_strncmp` | Compara os primeiros `n` caracteres de duas strings |
| `ft_memchr.c` | `ft_memchr` | Procura um byte numa zona de memória |
| `ft_memcmp.c` | `ft_memcmp` | Compara duas zonas de memória |
| `ft_strnstr.c` | `ft_strnstr` | Procura uma substring dentro de um limite de caracteres |
| `ft_atoi.c` | `ft_atoi` | Converte uma string para inteiro |
| `ft_calloc.c` | `ft_calloc` | Aloca e zera memória |
| `ft_strdup.c` | `ft_strdup` | Duplica uma string |
| `ft_substr.c` | `ft_substr` | Extrai uma substring |
| `ft_strjoin.c` | `ft_strjoin` | Concatena duas strings numa nova string alocada |
| `ft_strtrim.c` | `ft_strtrim` | Remove caracteres do início e do fim de uma string |
| `ft_split.c` | `ft_split` | Divide uma string num array de strings, segundo um delimitador |
| `ft_itoa.c` | `ft_itoa` | Converte um inteiro para string |
| `ft_strmapi.c` | `ft_strmapi` | Aplica uma função a cada carácter e devolve uma nova string |
| `ft_striteri.c` | `ft_striteri` | Aplica uma função a cada carácter, in-place |
| `ft_putchar_fd.c` | `ft_putchar_fd` | Escreve um carácter num file descriptor |
| `ft_putstr_fd.c` | `ft_putstr_fd` | Escreve uma string num file descriptor |
| `ft_putendl_fd.c` | `ft_putendl_fd` | Escreve uma string seguida de newline num file descriptor |
| `ft_putnbr_fd.c` | `ft_putnbr_fd` | Escreve um inteiro num file descriptor |
| `ft_lstnew.c` | `ft_lstnew` | Cria um novo nó de lista |
| `ft_lstadd_front.c` | `ft_lstadd_front` | Adiciona um nó no início da lista |
| `ft_lstadd_back.c` | `ft_lstadd_back` | Adiciona um nó no fim da lista |
| `ft_lstsize.c` | `ft_lstsize` | Conta o número de nós da lista |
| `ft_lstlast.c` | `ft_lstlast` | Devolve o último nó da lista |
| `ft_lstdelone.c` | `ft_lstdelone` | Liberta um nó e o seu conteúdo |
| `ft_lstclear.c` | `ft_lstclear` | Liberta a lista inteira |
| `ft_lstiter.c` | `ft_lstiter` | Aplica uma função ao conteúdo de cada nó |
| `ft_lstmap.c` | `ft_lstmap` | Cria uma nova lista aplicando uma função a cada conteúdo |
