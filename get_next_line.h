#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*join(char *s1, char *s2);
int		len(char *str);
char	*root(int fd, char *buf, int bytes_read, int *i);
char	*help_with_endl1(int idx, char *buf);
char	*help_with_root(int *i, char *temp, char *sub_str[], int fd);
char	*help_with_endl2(int idx, char *buf);
int		check_endl(char *buf);
#endif
