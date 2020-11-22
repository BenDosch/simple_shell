# Simple Shell

Simple Shell is an educational directory for the Holberton project 0x16. C- Simple Shell.

## Compilation

Use the gcc compiler to compile all files in the repository in order to create a functional executable

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage

Run the shell using the command
```bash
./hsh
```
After which a prompt will be displayed. Current working built-ins include:
```shell
exit //no status
env
```
You can also run executable files by giving the path to the executable, i.e.:
```bash
ls
/bin/ls
```
Currently the shell is capable of handling EOF(end of file) and Ctrl+C (^C)
## Roadmap
Future built-ins currently being worked on include:
```shell
alias
help
cd
exit status
setenv
unsetenv
history
```
Furthermore work is being done to handle:
(#) comments
(;) separators
(&&) and ( || ) shell logical operators

## Known Bugs
Currently there are bugs that present when attempting to run an executable found in the current working directory or if the absolute path to executable is given. This is our current priority.

## Contributers
Though outside advice was given by fellow Holberton students, the primary contributors to this project were
Ben Dosch and Selidex Parnell.