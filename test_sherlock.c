#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *str = "Hello World!";
	char **wordbyword;
	int i = 0;

	wordbyword = sherlock(str, " ");
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);

	str = "Hello World!";
	wordbyword = sherlock(str, "cc");
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);

	/*Should fail to complie */
	/*str = "Hello World!";
	wordbyword = sherlock(str, NULL);
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);*/

	/*should fail to complie*/
	/*str = "Hello World!";
	wordbyword = sherlock(str, NULL);
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);*/

	str = NULL;
	wordbyword = sherlock(str, " ");
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);

	str = "Hello World! Again!";
	wordbyword = sherlock(str, " ");
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);

	str = "HelloccWorld!";
	wordbyword = sherlock(str, "cc");
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);

	str = "Hello  World!"
	wordbyword = sherlock(str, " ");
	while (wordbyword[i])
	{
		printf("%s\n", wordbyword[i]);
		i++;
	}
	free_d_ptr(wordbyword);

	return (0);
}
