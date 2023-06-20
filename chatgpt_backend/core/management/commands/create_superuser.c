Converting Django Python code to C is not directly possible, as Django is a web framework specifically designed for Python. However, I can provide you with a simple C program that demonstrates creating a user struct and checking if a user exists.

```c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
} User;

bool user_exists(User users[], int num_users, const char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    User users[10];
    int num_users = 0;

    strcpy(users[num_users].username, "admin");
    strcpy(users[num_users].password, "admin");
    num_users++;

    const char *new_username = "admin";

    if (!user_exists(users, num_users, new_username)) {
        strcpy(users[num_users].username, new_username);
        strcpy(users[num_users].password, "admin");
        num_users++;
        printf("Successfully created a user\n");
    } else {
        printf("User already exists\n");
    }

    return 0;
}
```

This C code creates a simple user struct and checks if a user with a given username already exists in the users array. If not, it adds the user to the array. Note that this is a very basic example and does not cover many features of the original Django code.