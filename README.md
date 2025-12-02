# get_next_line
My implementation of get_next_line for 42 School. Reads a file descriptor line by line, supports multiple file descriptors (bonus), and manages internal buffers efficiently. Includes all bonus functionality.
# 🌊 get_next_line — 42 Project

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Bonus-Included-ff69b4?style=for-the-badge" />
</p>

---

## 📘 Overview

`get_next_line` is a function that reads **one line at a time** from a file descriptor.
It is used to process files or input streams efficiently and **preserves the remainder between calls**.

This version includes **bonus functionality**, allowing **simultaneous reading from multiple file descriptors**.

---



- `get_next_line.c` — main line-reading function
- `get_next_line_utils*.c` — helper functions for string manipulation
- `get_next_line_bonus.c` — extended functionality for multiple FDs
- `get_next_line_bonus.h` — bonus header definitions

---

## ⚙️ Compilation

Compile your program like this:

```bash
	gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
```
Or for bonus:
```
	gcc main.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=42
```

*You can alter BUFFER_SIZE to your liking or compile without it being that it has a default size.*

🧪 Example Usage

```
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
*Remember to free each line after use to prevent memory leaks.*

🧠 Key Concepts

- Persistent static buffers

- Reading with read() only once per buffer size

- Handling multiple file descriptors independently (bonus)

- Manual string manipulation (no strtok or external libraries)

⭐ Bonus Features

- Multiple file descriptors

- Independent buffer for each file

- Correct handling of \n

- No memory leaks

🧑‍💻 Author

Emanuel Tchipoque

🔗 LinkedIn: [Emanuel Tchipoque](https://www.linkedin.com/in/emanuel-tchipoque-820894198?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=ios_app)
