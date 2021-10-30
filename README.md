# Pechkin
![logo](pechkin.jpg)
Pechkin is a universal lightweight messaging library

## For what?
Message exchange in the understanding of Pechkin is a convenient way to exchange data between different units of code: functions, objects (if you work in C++), etc.
Initially, I decided to write Pechkin because I was not satisfied with the number of user arguments that can be passed to callback functions in GTK, but you can use sending messages for more prosaic purposes.

## How to use?
Pechkin is a very simple library it consists of a very small set of functions:
+ `void pl_send(char *name, void *value, size_t size)` - allows you to send a message
  - `name` - message name
  - `value` - message content
  - `size` - message content size

+ `void *pl_read(char *msg_name)` - accept message
  - `msg_name` - message name

+ `void pl_free()` - delete all messages
+ `void pl_remove(char *msg_name)` - delete a message
  - `msg_name` - message name

+ `pl_is_exist(char *msg_name)` - check if such a message exists
  - `msg_name` - message name

+ `pl_get_msg_list()` - get a pointer to a list of messages
+ `pl_set_msg_list(list *new_msg_list)` - change the pointer to the message list

## How do I add it to my project?
1. To start, run the following command:

```
git clone --recursive https://github.com/Centrix14/pechkin.git
```

2. Next, include the header file in the project:

```
#include "pechkin/pl.h"
```

3. After that, add the `pechkin/pl.c` file to the source list
4. That's it, enjoy the library!

---
by Centrix14 19.03.2021
