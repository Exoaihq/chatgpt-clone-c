Converting Django models to C is not a direct translation, as Django is a web framework specifically designed for Python. However, I can provide you with a C structure equivalent to the models you provided. Keep in mind that this will not have the same functionality as the Django models.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <uuid/uuid.h>

typedef struct Chat {
    uuid_t id;
    time_t created_at;
} Chat;

typedef struct Message {
    enum RoleChoices { USER, ASSISTANT } role;
    uuid_t id;
    char *content;
    time_t timestamp;
    Chat *chat;
} Message;

Chat *create_chat() {
    Chat *new_chat = (Chat *)malloc(sizeof(Chat));
    uuid_generate(new_chat->id);
    new_chat->created_at = time(NULL);
    return new_chat;
}

Message *create_message(enum RoleChoices role, char *content, Chat *chat) {
    Message *new_message = (Message *)malloc(sizeof(Message));
    uuid_generate(new_message->id);
    new_message->content = content;
    new_message->role = role;
    new_message->timestamp = time(NULL);
    new_message->chat = chat;
    return new_message;
}
```

This code provides basic C structures for Chat and Message, as well as functions to create new instances of these structures. Note that this code does not include any database interaction or other functionality provided by Django models.