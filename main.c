/*
Compiler: C99
Project:  Library system management
Author:   Kennedy Musyoka
Date:     July, 2021
License:  MIT
*/

// name
//member id
//tel
//status
//is_staff

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//structs for data storage

struct user{
    char name[100];
    char member_id[20];
    char tel[13];
    int status;
    int is_staff;

};
// Function prototype
void execute_action(int action);
void close();
int menu();
void add_user();


int main()
{
    int action;
    while(1) {
        action = menu ();
        execute_action(action);
        Sleep(5000);
    }
    return 0;
}


// Function definitions

void execute_action(int action) {
    switch(action) {
    case 1:
        add_user();
        break;
    case 2:
        printf("adding a book\n");
        break;
    case 3:
        close();
        break;
    default:
        printf("Unrecognized action\n");
    }
}

void close() {
    printf("Thank you for using the system\nByeBye\n");
    Sleep(5000);
    exit(0);
}

int menu() {
    int action;
    system("cls");

    // navigation menu
    do {
        printf("\tLibrary Management System!\n");
        printf("Welcome Musyokaa\n");
        printf("1. Add user\n");
        printf("2. Add book\n");
        printf("3. Exit\n");
        printf("Action(1-3): ");
        scanf("%d", &action);

        if(action < 1 || action > 3) {
            printf("Invalid action. Try again\n");
            sleep(3000);
            system("cls");
        }
    }while(action < 1 || action > 3);

    return action;
}

void add_user() {
    struct user u;
    FILE *fp;
    fp = fopen("user","ab");
    if(!fp) {
        printf("Unable to open file");
        exit (0);
    }
    u.is_staff = 0;
    u.status = 1;
    printf("Enter phone number: ");
    getchar();
    gets(u.name);
    printf("Enter phone number: ");
    scanf("s",&u.tel);
    printf("Enter Member id: ");
    scanf("%s",&u.member_id);

    fwrite(&u, sizeof(struct user), 1, fp);
    fclose(fp);
    printf("Welcome %s\n",u.name);
}
