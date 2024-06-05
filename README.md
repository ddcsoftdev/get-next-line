
# Get Next Line

Get Next Line is a project focused on creating a function in C that reads a line from a file descriptor. This project demonstrates the use of file I/O operations and dynamic memory allocation in C.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Get Next Line project involves writing a function that returns a line read from a file descriptor. The function handles multiple file descriptors and reads efficiently even from very large files or slow I/O sources.

## Features

- Reads a line from a file descriptor.
- Handles multiple file descriptors simultaneously.
- Efficient memory usage.
- Manages buffer sizes dynamically.

## Requirements

To build and run Get Next Line, you need:
- A UNIX-like operating system (Linux, macOS, etc.)
- `gcc` compiler
- `make` utility

## Installation

Clone the repository to your local machine:

```sh
git clone https://github.com/ddcsoftdev/get-next-line.git
cd get-next-line
```

Build the project using `make`:

```sh
make
```

## Usage

### Including the Function

To use the `get_next_line` function in your project, include the header file and link the compiled library.

```c
#include "get_next_line.h"
```

### Function Prototype

```c
char *get_next_line(int fd);
```

### Example

Here is an example of how to use the `get_next_line` function:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s
", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

### Compilation

Compile your program with the `get_next_line` implementation:

```sh
gcc -o example example.c get_next_line.c
```

### Running the Program

Run the compiled program:

```sh
./example
```

This will read and print lines from `example.txt`.

## Contributing

Contributions are welcome! Please fork the repository and open a pull request to add new features, fix bugs, or improve documentation.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
