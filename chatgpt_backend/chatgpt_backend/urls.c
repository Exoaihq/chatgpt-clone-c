Unfortunately, it's not possible to directly convert this Django Python code to C, as Django is a web framework specifically designed for Python, and C does not have an equivalent web framework. However, you can create a simple HTTP server in C using the following code:

```c
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

static const int PORT = 8080;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[30000] = {0};
        read(new_socket, buffer, 30000);
        printf("%s\n", buffer);

        char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
        write(new_socket, response, sizeof(response) - 1);
        close(new_socket);
    }

    return 0;
}
```

This code creates a simple HTTP server in C that listens on port 8080 and responds with "Hello world!" to every request. Note that this is not a direct conversion of the Django code, but a simple example of a web server in C.