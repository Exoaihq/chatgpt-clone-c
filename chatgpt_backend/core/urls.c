It's not possible to directly convert this Django Python code to C, as Django is a web framework specifically designed for Python. However, I can provide you with a simple example of a C program that uses a web server library to achieve similar functionality.

To achieve this, you can use the `libmongoose` library. First, download and include the `mongoose.h` header file in your project. Then, you can use the following code as a starting point:

```c
#include <stdio.h>
#include "mongoose.h"

static void handle_request(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  if (ev == MG_EV_HTTP_MSG) {
    struct mg_http_message *hm = (struct mg_http_message *) ev_data;
    if (mg_http_match_uri(hm, "/chats")) {
      mg_printf(c, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
      mg_printf(c, "Chat history endpoint");
    } else if (mg_http_match_uri(hm, "/chats/:chat_id")) {
      mg_printf(c, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n");
      mg_printf(c, "Chat messages endpoint");
    } else {
      mg_http_reply(c, 404, "", "Not Found");
    }
  }
}

int main(void) {
  struct mg_mgr mgr;
  mg_mgr_init(&mgr);
  mg_http_listen(&mgr, "http://localhost:8000", handle_request, NULL);

  printf("Starting web server on http://localhost:8000\n");
  for (;;) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}
```

This code sets up a simple web server using the `libmongoose` library and listens for requests on the `/chats` and `/chats/:chat_id` endpoints. Note that this is just a starting point and you'll need to implement the actual functionality for the chat history and chat messages.