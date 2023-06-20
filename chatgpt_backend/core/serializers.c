Unfortunately, it's not possible to directly convert this Python code to C, as the code is using Django Rest Framework, which is a Python-specific library. However, I can provide you with a simple example of a C structure that represents a chat message. This won't have the same functionality as the provided Python code, but it will give you an idea of how to represent a chat message in C.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

typedef struct {
    uuid_t chat_id;
    char *message;
} ChatMessage;

ChatMessage *create_chat_message(const char *message) {
    ChatMessage *chat_message = (ChatMessage *)malloc(sizeof(ChatMessage));
    if (chat_message == NULL) {
        return NULL;
    }

    uuid_generate(chat_message->chat_id);

    chat_message->message = (char *)malloc(strlen(message) + 1);
    if (chat_message->message == NULL) {
        free(chat_message);
        return NULL;
    }

    strcpy(chat_message->message, message);

    return chat_message;
}

void free_chat_message(ChatMessage *chat_message) {
    if (chat_message != NULL) {
        if (chat_message->message != NULL) {
            free(chat_message->message);
        }
        free(chat_message);
    }
}

int main() {
    ChatMessage *chat_message = create_chat_message("Hello, World!");
    if (chat_message == NULL) {
        printf("Failed to create chat message\n");
        return 1;
    }

    char chat_id_str[37];
    uuid_unparse(chat_message->chat_id, chat_id_str);
    printf("Chat ID: %s\n", chat_id_str);
    printf("Message: %s\n", chat_message->message);

    free_chat_message(chat_message);

    return 0;
}
```

This example uses the `uuid` library for generating UUIDs. To compile this code, you may need to install the `uuid-dev` package and link against the `uuid` library:

```
gcc chat_message.c -o chat_message -luuid
```