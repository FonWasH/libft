/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:32:54 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 03:04:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/* INCLUDES                                                                   */
/* ************************************************************************** */

# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

# define B02 "01"
# define B08 "01234567"
# define B10 "0123456789"
# define B16 "0123456789abcdef"
# define B32 "0123456789abcdefghijklmnopqrstuv"
# define B64 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# define BYTE		8
# define PI			3.14159265358979323846
# define _1E30F		1000000015047466219876688855040.0
# define FLT_MAX	3.402823466e+38F

/* ************************************************************************** */
/* STRUCT                                                                     */
/* ************************************************************************** */

typedef struct s_list
{
	void			*data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/* ************************************************************************** */
/* CHARACTER FUNCTIONS                                                        */
/* ************************************************************************** */

/**
 * @brief Checks if the character is alphanumeric.
 * @param c The character to check.
 * @return true if alphanumeric, false otherwise.
 */
bool	ft_isalnum(int c);

/**
 * @brief Checks if the character is alphabetic.
 * @param c The character to check.
 * @return true if alphabetic, false otherwise.
 */
bool	ft_isalpha(int c);

/**
 * @brief Checks if the character is an ASCII character.
 * @param c The character to check.
 * @return true if ASCII, false otherwise.
 */
bool	ft_isascii(int c);

/**
 * @brief Checks if the character is a digit (0-9).
 * @param c The character to check.
 * @return true if digit, false otherwise.
 */
bool	ft_isdigit(int c);

/**
 * @brief Checks if the character is printable.
 * @param c The character to check.
 * @return true if printable, false otherwise.
 */
bool	ft_isprint(int c);

/**
 * @brief Checks if the character is a whitespace.
 * @param c The character to check.
 * @return true if whitespace, false otherwise.
 */
bool	ft_isspace(int c);

/**
 * @brief Converts an uppercase character to lowercase.
 * @param c The character to convert.
 * @return The lowercase version or original if not applicable.
 */
int		ft_tolower(int c);

/**
 * @brief Converts a lowercase character to uppercase.
 * @param c The character to convert.
 * @return The uppercase version or original if not applicable.
 */
int		ft_toupper(int c);

/* ************************************************************************** */
/* LINKED LIST FUNCTIONS                                                      */
/* ************************************************************************** */

/**
 * @brief Adds a new node to the back of the list.
 * @param lst Address of pointer to list.
 * @param new Node to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Adds a new node to the front of the list.
 * @param lst Address of pointer to list.
 * @param new Node to add.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees all nodes of the list.
 * @param lst Address of pointer to list.
 * @param del Function to delete node content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Removes a specific node from the list.
 * @param lst Address of pointer to list.
 * @param node Node to remove.
 * @return Pointer to previous node or next node if not existing.
 */
t_list	*ft_lstdelnode(t_list **lst, t_list *node);

/**
 * @brief Deletes a single node using the given function.
 * @param lst Node to delete.
 * @param del Function to delete node content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Returns the first node of the list.
 * @param lst Pointer to list.
 * @return Pointer to first node or NULL.
 */
t_list	*ft_lstfirst(t_list *lst);

/**
 * @brief Iterates over the list and applies a function.
 * @param lst List to iterate.
 * @param f Function to apply.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Returns the last node of the list.
 * @param lst Pointer to list.
 * @return Pointer to last node or NULL.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Applies function to content of each node and creates a new list.
 * @param lst List to iterate.
 * @param f Function to apply to each node's content.
 * @param del Function to delete content on error.
 * @return New list or NULL on error.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Creates a new list node.
 * @param data Pointer to data to store.
 * @return Pointer to new node or NULL on error.
 */
t_list	*ft_lstnew(void *data);

/**
 * @brief Returns the number of elements in the list.
 * @param lst Pointer to list.
 * @return Number of nodes.
 */
size_t	ft_lstsize(t_list *lst);

/* ************************************************************************** */
/* MEMORY FUNCTIONS                                                           */
/* ************************************************************************** */

/**
 * @brief Sets memory to zero.
 * @param s Pointer to memory block.
 * @param n Number of bytes to zero.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Searches memory for a byte value.
 * @param s Pointer to memory block.
 * @param c Byte to search for.
 * @param n Number of bytes to search.
 * @return Pointer to first match or NULL.
 */
void	*ft_memchr(void *s, int c, size_t n);

/**
 * @brief Compares two memory blocks.
 * @param s1 Pointer to first block.
 * @param s2 Pointer to second block.
 * @param n Number of bytes to compare.
 * @return 0 if equal, >0 or <0 depending on comparison.
 */
int		ft_memcmp(void *s1, void *s2, size_t n);

/**
 * @brief Copies memory from source to destination.
 * @param d Destination buffer.
 * @param s Source buffer.
 * @param n Number of bytes.
 * @return Pointer to destination.
 */
void	*ft_memcpy(void *d, void *s, size_t n);

/**
 * @brief Safely copies overlapping memory blocks.
 * @param d Destination buffer.
 * @param s Source buffer.
 * @param n Number of bytes.
 * @return Pointer to destination.
 */
void	*ft_memmove(void *d, void *s, size_t n);

/**
 * @brief Fills memory with a constant byte.
 * @param s Memory block to fill.
 * @param c Byte value to set.
 * @param n Number of bytes.
 * @return Pointer to memory block.
 */
void	*ft_memset(void *s, int c, size_t n);

/* ************************************************************************** */
/* MEMORY ALLOCATION FUNCTIONS                                                */
/* ************************************************************************** */

/**
 * @brief Allocates zero-initialized memory.
 * @param e Number of elements.
 * @param n Size of each element.
 * @return Pointer to allocated memory or NULL on error.
 */
void	*ft_calloc(size_t e, size_t n);

/**
 * @brief Frees a 2D array of pointers.
 * @param tab The array of pointers.
 * @param n Number of elements in the array.
 */
void	ft_mfree(void **tab, size_t n);

/**
 * @brief Reallocates memory with a new size.
 * @param p Pointer to old memory block.
 * @param old Old size in bytes.
 * @param new New size in bytes.
 * @return Pointer to new memory block or NULL on error.
 */
void	*ft_realloc(void *p, size_t old, size_t new);

/* ************************************************************************** */
/* NUMBER FUNCTIONS                                                           */
/* ************************************************************************** */

/**
 * @brief Returns absolute value.
 * @param n The number.
 * @return Absolute value.
 */
size_t	ft_abs(ssize_t n);

/**
 * @brief Converts string to long (ssize_t).
 * @param s String to convert.
 * @return Converted number.
 */
ssize_t	ft_atol(char *s);

/**
 * @brief Converts string in arbitrary base to long.
 * @param s String to convert.
 * @param base Characters used as base.
 * @return Converted number.
 */
ssize_t	ft_atol_base(char *s, char *base);

/**
 * @brief Converts number to string.
 * @param n Number to convert.
 * @return String representation, or NULL on error.
 */
char	*ft_ltoa(ssize_t n);

/**
 * @brief Converts number to string in base.
 * @param n Number to convert.
 * @param base Characters used as base.
 * @return String representation, or NULL on error.
 */
char	*ft_ltoa_base(ssize_t n, char *base);

/**
 * @brief Checks if number is duplicated in array.
 * @param tab Array of numbers.
 * @param size Size of array.
 * @param n Number to check.
 * @return true if duplicate found.
 */
bool	ft_nisdup(int *tab, size_t size, int n);

/**
 * @brief Calculates the number of characters needed to represent a signed
 * integer in a given base.
 * 
 * Includes space for a negative sign if needed.
 * 
 * @param n The signed integer value.
 * @param base_size The numerical base.
 * @return The number of characters needed to represent the value.
 */
size_t	ft_snlen(ssize_t n, size_t base_size);

/**
 * @brief Converts an unsigned long integer to string in base.
 * 
 * @param n The unsigned long integer to convert.
 * @param base Characters used as base.
 * @return String representation, or NULL on error.
 */
char	*ft_ultoa_base(size_t n, char *base);

/**
 * @brief Calculates the number of digits needed to represent an unsigned
 * integer in a given base.
 * 
 * @param n The unsigned integer value.
 * @param base_size The numerical base.
 * @return The number of digits needed to represent the value.
 */
size_t	ft_unlen(size_t n, size_t base_size);

/* ************************************************************************** */
/* STRING FUNCTIONS                                                           */
/* ************************************************************************** */

/**
 * @brief Gets the length of a NULL-terminated string array.
 * @param ms Array of strings.
 * @return Number of strings.
 */
size_t	ft_mstrlen(char **ms);

/**
 * @brief Sorts array of strings alphabetically.
 * @param ms Array of strings.
 */
void	ft_sortmstr(char **ms);

/**
 * @brief Splits string by delimiter character.
 * @param s String to split.
 * @param c Delimiter.
 * @return NULL-terminated array of strings.
 */
char	**ft_split(char *s, char c);

/**
 * @brief Appends a character to the start and end of a string.
 * @param s Original string.
 * @param c Character to append.
 * @return New string with character added, or NULL on error.
 */
char	*ft_straddchr(char *s, char c);

/**
 * @brief Finds first occurrence of character in string.
 * @param s The string.
 * @param c Character to find.
 * @return Pointer to character or NULL.
 */
char	*ft_strchr(char *s, int c);

/**
 * @brief Compares two strings.
 * @param s1 First string.
 * @param s2 Second string.
 * @return Difference between characters or 0.
 */
int		ft_strcmp(char *s1, char *s2);

/**
 * @brief Counts how many times c appears in the string.
 * @param s The string.
 * @param c Character to count.
 * @return Number of occurrences.
 */
size_t	ft_strcount(char *s, int c);

/**
 * @brief Duplicates a string.
 * @param s Source string.
 * @return Copy of string.
 */
char	*ft_strdup(char *s);

/**
 * @brief Checks if a string only contains digits.
 * @param s The string to check.
 * @return true if all digits, false otherwise.
 */
bool	ft_strisdigit(char *s);

/**
 * @brief Applies function to each character (in-place).
 * @param s Source string.
 * @param f Function to apply.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Joins two strings into one.
 * @param s1 First string.
 * @param s2 Second string.
 * @return Concatenated string.
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief Joins two strings and optionally frees s1/s2.
 * @param s1 First string.
 * @param s2 Second string.
 * @param f Flags: 1=free s1, 2=free s2, 3=free both.
 * @return Joined string.
 */
char	*ft_strjoin_free(char *s1, char *s2, int f);

/**
 * @brief Appends string to destination within buffer size.
 * @param d Destination string.
 * @param s Source string.
 * @param n Total buffer size.
 * @return Total length of string tried to create.
 */
size_t	ft_strlcat(char *d, char *s, size_t n);

/**
 * @brief Copies a string into another with buffer size.
 * @param d Destination buffer.
 * @param s Source string.
 * @param n Buffer size.
 * @return Length of source string.
 */
size_t	ft_strlcpy(char *d, char *s, size_t n);

/**
 * @brief Duplicates the first n characters of a string.
 * @param s Source string.
 * @param n Number of characters.
 * @return New string.
 */
char	*ft_strldup(char *s, size_t n);

/**
 * @brief Gets the length of a string.
 * @param s The string.
 * @return Length of the string.
 */
size_t	ft_strlen(char *s);

/**
 * @brief Gets the length of string up to character c.
 * @param s The string.
 * @param c Character to stop at.
 * @return Length up to c or full length.
 */
size_t	ft_strllen(char *s, int c);

/**
 * @brief Applies function to each character of string.
 * @param s Source string.
 * @param f Function to apply.
 * @return New mapped string.
 */
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));

/**
 * @brief Compares up to n characters of two strings.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Max number of characters.
 * @return Difference or 0 if equal.
 */
int		ft_strncmp(char *s1, char *s2, size_t n);

/**
 * @brief Finds a substring within a limited length.
 * @param s1 Haystack string.
 * @param s2 Needle string.
 * @param n Max length to search.
 * @return Pointer to start of found substring or NULL.
 */
char	*ft_strnstr(char *s1, char *s2, size_t n);

/**
 * @brief Finds last occurrence of character in string.
 * @param s The string.
 * @param c Character to find.
 * @return Pointer to character or NULL.
 */
char	*ft_strrchr(char *s, int c);

/**
 * @brief Replaces part of a string with another.
 * @param s1 Original string.
 * @param s2 Replacement string.
 * @param start Start index.
 * @param end End index.
 * @return New string.
 */
char	*ft_strreplace(char *s1, char *s2, size_t start, size_t end);

/**
 * @brief Converts a string to lowercase.
 * @param s The string.
 * @return New string in lowercase.
 */
char	*ft_strtolower(char *s);

/**
 * @brief Converts a string to uppercase.
 * @param s The string.
 * @return New string in uppercase.
 */
char	*ft_strtoupper(char *s);

/**
 * @brief Trims characters from beginning and end.
 * @param s1 String to trim.
 * @param s2 Characters to trim.
 * @return New trimmed string.
 */
char	*ft_strtrim(char *s1, char *s2);

/**
 * @brief Extracts substring from string.
 * @param s Source string.
 * @param start Starting index.
 * @param n Length of substring.
 * @return New substring.
 */
char	*ft_substr(char *s, size_t start, size_t n);

/* ************************************************************************** */
/* PUT FUNCTIONS                                                              */
/* ************************************************************************** */

/**
 * @brief Writes a character to a file descriptor.
 * @param c Character to write.
 * @param fd File descriptor.
 * @return Bytes written or -1 on error.
 */
ssize_t	ft_putchar(char c, int fd);

/**
 * @brief Writes a string followed by newline.
 * @param s String to write.
 * @param fd File descriptor.
 * @return Bytes written or -1 on error.
 */
ssize_t	ft_putendl(char *s, int fd);

/**
 * @brief Writes a limited-length string.
 * @param s String to write.
 * @param fd File descriptor.
 * @param n Number of characters.
 * @return Bytes written or -1 on error.
 */
ssize_t	ft_putlstr(char *s, int fd, size_t n);

/**
 * @brief Writes a number as string.
 * @param n Number to write.
 * @param fd File descriptor.
 * @return Bytes written or -1 on error.
 */
ssize_t	ft_putnbr(ssize_t n, int fd);

/**
 * @brief Writes a character multiple times.
 * @param c Character to write.
 * @param fd File descriptor.
 * @param n Number of times to write.
 * @return Bytes written or -1 on error.
 */
ssize_t	ft_putnchar(char c, int fd, size_t n);

/**
 * @brief Writes a string to a file descriptor.
 * @param s String to write.
 * @param fd File descriptor.
 * @return Bytes written or -1 on error.
 */
ssize_t	ft_putstr(char *s, int fd);

/* ************************************************************************** */
/* FT_PRINTF                                                                  */
/* ************************************************************************** */

/**
 * @brief A formatted output function similar to printf.
 * 
 * Supports most standard format specifiers: %c %s %d %i %u %x %X %p %%
 * 
 * @param format Format string.
 * @param ... Additional arguments to format.
 * @return Number of characters printed.
 */
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

/* ************************************************************************** */
/* GET_NEXT_LINE                                                              */
/* ************************************************************************** */
/**
 * @brief Reads a line from a file descriptor.
 * @param fd File descriptor to read from.
 * @return Allocated string (line) or NULL on EOF/error.
 */
char	*get_next_line(int fd);

#endif
