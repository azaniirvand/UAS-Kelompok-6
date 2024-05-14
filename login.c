#include <stdlib.h>
#include <string.h>
#include "header.h"
// Fungsi untuk login
int login(Login loginInfo[], int *jumlahLogin) {
    char username[50], password[50];
    printf("Masukkan username: ");
    scanf(" %s", username);
    printf("Masukkan password: ");
    scanf("%s", password);
    
    for (int i = 0; i < *jumlahLogin; i++) {
        if (strcmp(username, loginInfo[i].username) == 0 && strcmp(password, loginInfo[i].password) == 0)
            return 1;
    }
    return 0;
}
