#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct AsciiImageStruct {
    char **data;
    int rows;
} AsciiImage;

AsciiImage hackermanImage() {
    static char *lines[] = {
            " _    _          _____ _  ________ _____  __  __          _   _     _______ __  __ ",
            "| |  | |   /\\   / ____| |/ /  ____|  __ \\|  \\/  |   /\\   | \\ | |   |__   __|  \\/  |",
            "| |__| |  /  \\ | |    | ' /| |__  | |__) | \\  / |  /  \\  |  \\| |______| |  | \\  / |",
            "|  __  | / /\\ \\| |    |  < |  __| |  _  /| |\\/| | / /\\ \\ | . ` |______| |  | |\\/| |",
            "| |  | |/ ____ \\ |____| . \\| |____| | \\ \\| |  | |/ ____ \\| |\\  |      | |  | |  | |",
            "|_|  |_/_/    \\_\\_____|_|\\_\\______|_|  \\_\\_|  |_/_/    \\_\\_| \\_|      |_|  |_|  |_|"
    };
    return (AsciiImage) { lines, sizeof(lines)/sizeof(char*) };
}

void printAsciiImage(AsciiImage img) {
    int i;
    for (i=0; i<img.rows; i++) {
        printf("%s\n", img.data[i]);
    }
    printf("\n");
}

void applicationStart(void) {
    for (int i = 0; i < 4; i++)
    {
        usleep(2);
        printf("");
    }
    printf("                        ..\n");
    usleep(100000);
    printf("                      .oK0l\n");
    usleep(100000);
    printf("                     :0KKKKd.\n");
    usleep(100000);
    printf("                   .xKO0KKKKd\n");
    usleep(100000);
    printf("                  ,Od' .d0000l\n");
    usleep(100000);
    printf("                 .c;.   .'''...           ..'.\n");
    usleep(100000);
    printf("    .,:cloddxxxkkkkOOOOkkkkkkkkxxxxxxxxxkkkx:\n");
    usleep(100000);
    printf("    ;kOOOOOOOkxOkc'...',;;;;,,,'',;;:cllc:,.\n");
    usleep(100000);
    printf("     .okkkkd,.lko  .......',;:cllc:;,,'''''.\n");
    usleep(100000);
    printf("       .cdo. :xd' cd:.  ..';'',,,'',,;;;,'.\n");
    usleep(100000);
    printf("          . .ddl.;doooc'..;oc;'..';::;,'.\n");
    usleep(100000);
    printf("            coo;.oooolllllllcccc:'.  .\n");
    usleep(100000);
    printf("           .ool''lllllccccccc:::::;.\n");
    usleep(100000);
    printf("           ;lll. .':cccc:::::::;;;;'\n");
    usleep(100000);
    printf("           :lcc:'',..';::::;;;;;;;,,.\n");
    usleep(100000);
    printf("           :cccc::::;...';;;;;,,,,,,.\n");
    usleep(100000);
    printf("           ,::::::;;;,'.  ..',,,,'''.\n");
    usleep(100000);
    printf("            ........          ......\n");
    usleep(100000);
    printf("            ```\n\n");
    usleep(400000);
    printAsciiImage(hackermanImage());
    usleep(100000);
    printf("\nThank you for your ongoing support, welcome to HACKERMAN windows edition.\n");
    sleep(1);
    printf("Who would you like to hack today? (Q to exit)\n");
    usleep(100000);
}

void randomHackTime(char target[40]) {
    float total = 50000.0;
    int i = 0;
    float percent = 0;
    while (i < total) {
        if (i != 0) {
            percent = 100 * (i / total);
        }
        printf("\n%s %.2f%% hacked...", target, percent);
        int sleeptime = rand();
        if (i + sleeptime > total) {
            sleeptime = total - i;
        }
        i = i + sleeptime;
       sleep(sleeptime / 2000);
    }
    printf("\n\n%s 100%% pwned!\n\n", target);
}

_Noreturn void startHacking(void) {
    int targets_hacked = 0;
    while (true) {
        printf("Awaiting target... > ");
        char target[40];
        scanf("%39s", target);
        if (strcmp(target, "Q") == 0 || strcmp(target, "q") == 0) {
            printf("\nThanks for hacking with us today!\n");
            if (targets_hacked == 1) {
                printf("You have successfully hacked %d person.\n\n", targets_hacked);
            }
            else {
                printf("You have successfully hacked %d people.\n\n", targets_hacked);
            }
            printf("Goodbye.");
            sleep(5);
            exit(0);
        }
        printf("\nHacking %s, hold on to your butt!\n", target);
        randomHackTime(target);
        targets_hacked += 1;
        printf("Who else do you want to hack? (Q to exit)\n");
    }
}

int main(void) {
    srand(time(0));
    applicationStart();
    startHacking();
}