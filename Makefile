CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wmissing-prototypes -Wstrict-prototypes -std=c11 -Iinclude

# -Wall: Enable all common warnings to catch typical mistakes early.
# -Wextra: Turn on additional, more aggressive warnings for cleaner code.
# -Werror: Treat all warnings as errors so nothing slips through unnoticed.
# -Wmissing-prototypes: Force every function to have a proper prototype in a header.
# -Wstrict-prototypes: Require exact function signatures and forbid old-style declarations.

SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)

TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

