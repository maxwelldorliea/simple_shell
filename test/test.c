#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{

	char buf[256];
	size_t buflen = 256;
	ssize_t n;

	do {
		fprintf(stderr, "$ ");
		if (n == 0)
			fflush(0);
		n = read(0, buf, buflen);
		printf("%d\n%s",(int)n, buf);
	} while(1);

	return (0);
}
