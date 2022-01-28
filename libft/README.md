# LIBFT - my own library
___

## Table of contents
1. [About](#about)
2. [CTYPE](#ctype)
3. [STRINGS](#strings-mem-functions)
4. [PUT-FUNCTIONS](#put-functions)
5. [STDLIB](#stdlib)
6. [STRING](#string)
7. [LIST-FUNCTIONS](#list-functions)
8. [EXTRA-FUNCTIONS](#extra-functions)
9. [FT_PRINTF](#ft_printf)
10. [GET_NEXT_LINE](#get_next_line)
11. [ADDED-FUNCTIONS](#added-functions)

## About

libft is the first project at 42. It is about creating your first library and recoding some functions from libc. 42 only allows some low-level functions like write, read, malloc or free. If you want to use *high-level* functions you have to code them yourself. In some of the following projects 42-students are allowed to reuse functions from libft. Most of the functions are from librarys like ctype.h or string.h. Functions that are not part of the c-standard will be explicitly named in the description of the different parts.

**How the tables work:**
| Prototype                     | Description | Used functions |
| :---                          | :---        | :---           |   
| shows the prototype of the function. To save space the keyword *const* remains unused | a really shot description. for a longer description please read the manual | external functions used like free or malloc |

> Description of the library the real function are from

**How to use:**

Clone the repository:
```bash
git clone https://github.com/ayeCaptainJack/libft.git
```
go to the repository and run make
```bash
make
```
copy libft.a and libft.h into your directory and include libft.h in your files
```c
#include "libft.h"
```
compile your files with libft.a
```bash
gcc yourfile_01.c yourfile_02.c libft.a
```
use clean to delete all object files, fclean to remove all object files and libft.a and re to recompile the library 
```bash
make clean / make clean / make re 
```

## CTYPE

> The ctype.h header file of the C Standard Library declares several functions that are useful for
> testing and mapping characters.


| Prototype                     | Description | Used functions     |
| :---                          |    :----                                                 | :---  |
| ```int ft_isalpha(int c)```   | returns wether an integer is a letter or not             | none  |
| ```int ft_isalnum(int c)```   | returns wether an integer is aplhanummerical or not      | none  |
| ```int ft_isascii(int c)```   | returns wether an integer is an ascii-value or not       | none  |
| ```int ft_isprint(int c)```   | returns wether an integer is printable or not            | none  |
| ```int ft_isdigit(int c)```   | returns wether an integer is a digit or not              | none  |
| ```int ft_tolower(int c)```   | returns an uppercase letter as a lowercase letter        | none  |
| ```int ft_toupper(int c)```   | returns a lowercase letter as an uppercase letter        | none  |

## STRINGS (mem-functions)


> The strings.h header file of the C Standard Library declares several functions that are useful for
> manipulating any type of arrays or pointers.


| Prototype                                                     | Description                                            | Used functions |
| :---                                                          | :----                                                  | :---           |
| ```void ft_bzero(void *s, size_t n)```                        | sets n bytes of s to 0                                 | none           |
| ```void *ft_memccpy(void *dst, void *src, int c, size_t n)``` | copys n bytes from src to dst until it hits c          | none           |
| ```void *ft_memchr(const void *s, int c, size_t n)```         | finds c in n bytes of s                                | none           |
| ```int ft_memcmp(const void *s1, void *s2, size_t n)```       | returns the first difference between s1 and s2         | none           |
| ```void *ft_memcpy(void *dst, void *src, size_t n)```         | copies n bytes from src to dst                         | none           |
| ```void *ft_memmove(void *dst, void *src, size_t n)```        | same as memcpy but handles overlaps                    | none           |
| ```void *ft_memset(void *s, int c, size_t n)```               | set n bytes of s to c                                  | none           |

## PUT-FUNCTIONS


> The put-functions are useful to write to different filedescriptors and therefore into files.
> These functions are not part of libc and are part of the second part of the task.

| Prototype                                  | Description                          | Used functions |
| :---                                       |    :----                             | :---           |
| ```void ft_putchar_fd(char c, int fd)```   | writes a char to fd                  | write          |
| ```void ft_putstr_fd(char *s, int fd)```   | writes a string to fd                | write          |
| ```void ft_putendl_fd(char *s, int fd)```  | writes a string and a new line to fd | write          |
| ```void ft_putnbr_fd(int n, int fd)```     | writes an integer to fd              | write          |

## STDLIB


> The stdlib.h header defines four variable types, several macros, and various functions for performing general functions.


| Prototype                                         | Description                                                        | Used functions |
| :---                                              |    :----                                                           | :---           |
| ```int ft_atoi(const char *str)```                | returns a string as an integer                                     | none           |
| ```void *ft_calloc(size_t count, size_t size))``` | returns an allocated pointer of size count * len and sets mem to 0 | malloc         |

[//]: <| I recommend adding realloc here | realloc gives a pointer more memory withpout loosing its value               | malloc, free | high |> 


## STRING


>The string.h header defines one variable type, one macro, and various functions for manipulating arrays of characters.


| Prototype               | Description | Used functions     |
| :---                    |    :----    |          :---      |
| ```char *ft_strchr(const char *s, int c)```                   | finds c in s, returns first accurance of c as a pointer, returns 0 if nothing is found                               | none   |
| ```char *ft_strrchr(const char *s, int c)```                  | finds c in s, returns last accurance of c as a pointer, returns 0 if nothing is found           | none   |
| ```char *ft_strdup(const char *src)```                        | duplicates src.                                                       | malloc |
| ```size_t ft_strlcat(char *dst, char *src, size_t dstsize)``` | adds dstzie - strlen(dstzie) - 1 chars to dst from src                | none   |
| ```size_t ft_strlcpy(char *dst, char *src, size_t dstsize)``` | copys dstzie - 1 chars from dst to src                                | none   |
| ```int ft_strncmp(const char *s1, const char *s2, size_t n)``` | returns the first difference of src and dst (0 if no difference accured) in the first n bytes| none   |
| ```size_t ft_strlen(const char *s)```                         | returns the length of a string s                                      | none   |
| ```char *ft_strnstr(const char *haystack, char *needle, size_t len)```| finds the needle in the haystack                              | none   |

## LIST-FUNCTIONS

> The lst-funtcions allow you to manipulate and use lists. Lists are quiet useful if you dont know the final length of an array because you can just append as many nodes as you want until you run out of memory. 

```c
typedef struct		s_list
{
	void		*content;
	struct s_list	*next;
}	       		t_list;
```

| Prototype               | Description | Used functions     |
| :---                    |    :----    |          :---      |
| ```void ft_lstadd_back(t_list **lst, t_list *new)```          | adds node new to the end of list lst                                     | none   |
| ```void ft_lstadd_front(t_list **lst, t_list *new)```              | adds node new to the front of list lst                                | none   |
| ```void ft_lstclear(t_list **lst, void (*del)(void*))```           | deletes and frees every node of list lst                                   | free   |
| ```void ft_lstdelone(t_list *lst, void (*del)(void*))```            | deletes and frees node lst                                            | free   |
| ```void ft_lstiter(t_list *lst, void (*f)(void *))```               | applies function f on the content of every node                       | none   |
| ```t_list *ft_lstlast(t_list *lst)```                               | returns the last node of list lst                                     | none   |
| ```t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))``` | creates a new list out of application of f on content of list lst  | free, malloc   |
| ```t_list *ft_lstnew(void *content)```                              | creates a new node and gives the paramter to its content              | malloc |
| ```int ft_lstsize(t_list *lst)```                                   | returns the size of list lst                                             | none   |

## EXTRA-FUNCTIONS

> These are some extra functions which are not part of the libc standard.

| Prototype               | Description | Used functions     |
| :---                    |    :----    |          :---      |
| ```char *ft_substr(char *s, unsigned int start, size_t len)```| creates a substring of s from start to start + len                    | malloc |
| ```char *ft_strtrim(char *s1, char *set)```                   | creates a trimmed substring of s1 with all chars from set cut from the end & the beginning                 | malloc |
| ```char *ft_strmapi(char *s, char (*f)(unsigned int, char)``` | applies function f on every char of s                                | none   |
| ```char *ft_strjoin(char *s1, char *s2)```                    | creates a new string out of concatination of s1 and s2               | malloc |
| ```char *ft_itoa(int n)```                                    | returns an integer as a string                                       | malloc |
| ```char **ft_split(char *str, char c)```                      | returns an array of string out of the splited str by char c          | malloc (free) |

## FT_PRINTF

> ft_printf is a function which mimics the printf of stdio.h. It doesnt mimic everything but some standard conversions are working. For more info look into the doccumentaion of ft_printf

| Prototype               | Description | Used functions     |
| :---                    |    :----    |          :---      |
| ```int ft_printf(char *format, ...)``` | mimic of printf | malloc, free, write, functions of stdarg.h|

## GET_NEXT_LINE

> get_next_line is a function to get the next line of a file or from standard output/ standard input/ standard error. For more information look at the get_next_line repository. (For the purpose of this project BUFFER_SIZE is predefined as 100)

| Prototype               | Description | Used functions     |
| :---                    |    :----    |          :---      |
| ```int get_next_line(int fd, char **line)``` | puts the next line of fd into \*line | malloc, free, read|
 
## ADDED-FUNCTIONS

> these are some functions I added my self. This list will probably keep growing during my time at 42.

| Prototype               | Description | Used functions     |
| :---                    |    :----    |          :---      |
| ```ft_utoa(unsigned int n)``` | returns a string out of an unsigned integer n | malloc |
| ```char	*ft_strcpy(char *dst, char *src)``` | copies src to dst including the NULL-terminator | none |
