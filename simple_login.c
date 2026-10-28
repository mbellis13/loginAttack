#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>




void exploitCode(void)
{


	printf("XXXXXXX__EXPLOITED__XXXXXXXX\n");
	printf("X**************************X\n");
	printf("X**************************X\n");
	printf("X*****     ______     *****X\n");
	printf("X****   .-'      `-.   ****X\n");
	printf("X****  /            \\  ****X\n");
	printf("X**** |,  .-.  .-.  ,| ****X\n");
	printf("X**** | )(_o/  \\o_)( | ****X\n");
	printf("X**** |/     /\\     \\| ****X\n");
	printf("X**** (_     ^^     _) ****X\n");
	printf("X****  \\__|IIIIII|__/  ****X\n");
	printf("X****   | \\IIIIII/ |   ****X\n");
	printf("X****   \\__________/   ****X\n");
	printf("X*****                *****X\n");
        printf("X**************************X\n");
        printf("X**************************X\n");
        printf("XXXXXXX__EXPLOITED__XXXXXXXX\n");
	exit(0);
}

unsigned long hash_string(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main(int argc, char *argv[]) {
    int allow_login = 0;
    char inputPwd[25] = "";
    unsigned long correctHash = 1684334466543687429UL;

    printf("*********************************************************\n");
    printf("Simple Login Program.  Try to guess the password\n");
    printf("run with argument show-address to show variable locations\n");
    printf("*********************************************************\n");

    if (argc > 1) {
        if (strcmp(argv[1], "show-address") == 0) {
            printf("\n******variable locations******\n");
            printf("allow_login: %d @ %p\n",
                   allow_login, (void *)&allow_login);
            printf("inputPwd: %s @ %p\n",
                   inputPwd, (void *)inputPwd);
            printf("correctHash: %lu @ %p\n\n",
                   correctHash, (void *)&correctHash);
        }
    }

    printf("enter password: ");
    fflush(stdout);

    /* Intentionally unsafe for the classroom overflow demo. */
    gets(inputPwd);

    if (hash_string(inputPwd) == correctHash) {
        allow_login = 1;
    }

    if (argc > 1) {
        if (strcmp(argv[1], "show-address") == 0) {
            printf("\n******variable locations******\n");
            printf("allow_login: %d @ %p\n",
                   allow_login, (void *)&allow_login);
            printf("inputPwd: %s @ %p\n",
                   inputPwd, (void *)inputPwd);
            printf("correctHash: %lu @ %p\n\n",
                   correctHash, (void *)&correctHash);
        }
    }

    if (allow_login == 0) {
        printf("\nXXXXXXXXXX  Login request REJECTED!!    XXXXXXXXXXXX\n");
    } else {
        printf("\n**********  Login request ALLOWED!!!!  *************\n");
    }

    return 0;
}
