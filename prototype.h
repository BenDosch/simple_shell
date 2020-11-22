#ifndef PROTOTYPE_H
#define PROTOTYPE_H

/**
 * struct builtin - struct for builtins
 * @bi: Built in name
 * @f: The function associated
 */

typedef struct bi{
	char *bi;
	int (*f)(char **commands, char *buffer);
}bi_t;


int sl_exit(char **commands, char *buffer);
int sl_env(char **commands, char *buffer);
int _strcmp(char *s1, char *s2);
size_t _strlen(char *str);
char *dircat(char *dir, char *file);
bi_t *load_builtins(void);
void free_d_ptr(char **ptr);
char **sherlock(char *str, const char *delim);
void free_d_ptr(char **ptr);
int count_delim(char *str, const char *delim);
void set_word(char *str, char **words, unsigned int word,
	      unsigned int mark,unsigned int i);
int (*runcommand(char **commands, char *buffer))(char **, char *);
char *_getenv(const char *name);
char *get_file_path(char *filename);

#endif /* PROTOYPE_H */
