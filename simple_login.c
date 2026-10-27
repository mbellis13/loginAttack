#include <stdio.h>
#include <string.h>


void exploitCode(void) {
    for (int frame = 0; frame < 40; frame++) {
        /* Clear the screen and move the cursor to the top. */
        printf("\033[2J\033[H");

        printf("XXXXXXX__exploited__XXXXXXXX\n");
        printf("X**************************X\n");
        printf("X**************************X\n");
        printf("X*****     ______     *****X\n");
        printf("X****   .-'      `-.   ****X\n");
        printf("X****  /            \\  ****X\n");
        printf("X**** |,  .-.  .-.  ,| ****X\n");
        printf("X**** | )(_o/  \\o_)( | ****X\n");
        printf("X**** |/     /\\     \\| ****X\n");
        printf("X**** (_     ^^     _) ****X\n");

        if (frame % 2 == 0) {
            /* Open mouth. */
            printf("X****  \\__|IIIIII|__/  ****X\n");
            printf("X****   |          |   ****X\n");
            printf("X****   |  IIIIII  |   ****X\n");
            printf("X*****   `--------`   *****X\n");
        } else {
            /* Closed mouth. */
            printf("X****  \\__|IIIIII|__/  ****X\n");
            printf("X****   | \\IIIIII/ |   ****X\n");
            printf("X****   \\__________/   ****X\n");
            printf("X*****                *****X\n");
        }

        printf("X**************************X\n");
        printf("X**************************X\n");
        printf("XXXXXXX__exploited__XXXXXXXX\n");

        fflush(stdout);
        usleep(250000);  /* 250,000 microseconds = 0.25 seconds */
    }

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



int main(int argc, char *argv[]){
    int allow_login = 0;
    char inputPwd[25];
    unsigned long correctHash = 1684334466543687429;
    printf("*********************************************************\n");
    printf("Simple Login Program.  Try to guess the password\n");
    printf("run with argument show-address to show variable locations\n");
    printf("*********************************************************\n");

    if(argc > 1){
        if(strcmp(argv[1],"show-address")==0){
            printf("\n******variable locations******\n");
            printf("allow_login: %d @ %p\n", allow_login, (void*)&allow_login);
            printf("inputPwd: %s @ %p\n", inputPwd, (void*)&inputPwd);
            printf("correctHash: %ld @ %p\n\n", correctHash, (void*)&correctHash);  
        }
    }
      

    printf("enter password: ");
    gets(inputPwd);
    if(hash_string(inputPwd) == correctHash)
        allow_login = 1;
    
    if(argc > 1){
        if(strcmp(argv[1],"show-address")==0){
            printf("\n******variable locations******\n");
            printf("allow_login: %d @ %p\n", allow_login, (void*)&allow_login);
            printf("inputPwd: %s @ %p\n", inputPwd, (void*)&inputPwd);
            printf("correctHash: %ld @ %p\n\n", correctHash, (void*)&correctHash);  
        }
    } 

    if(allow_login == 0)
        printf("\nXXXXXXXXXX  Login request REJECTED!!    XXXXXXXXXXXX\n");
    else
        printf("\n**********  Login request ALLOWED!!!!  *************\n");
}
