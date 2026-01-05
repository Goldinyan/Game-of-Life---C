
# Conway’s Game of Life (Terminal Version)

This project is a minimalistic, fast implementation of **Conway’s Game of Life** in C.  
The grid is rendered in the terminal, including an interactive selection phase where individual cells can be set.

---

## Build

Requirement: a C compiler (e.g., `gcc`) and `make`.

```sh
make
```

This produces the executable:

```
./program
```

---

## Running

```sh
./program
```

## Controls

### Selection Mode (setting cells)

| Key | Action |
|------|--------|
| **w** | Move cursor up |
| **s** | Move cursor down |
| **a** | Move cursor left |
| **d** | Move cursor right |
| **g** | Toggle cell (alive/dead) |
| **f** | Confirm selection → start simulation |
| **q** | Quit program |

The cursor is highlighted in green.

### Simulation Mode

After pressing **f**, the Game‑of‑Life simulation begins:

- The grid updates continuously  
- The rules are applied correctly  
- The simulation runs until you close the terminal  

---

## Game of Life Rules (Short Version)

- A living cell with 2 or 3 neighbors → stays alive  
- A living cell with <2 or >3 neighbors → dies  
- A dead cell with exactly 3 neighbors → becomes alive  

---

## Git Workflow

### Clone repository

```sh
git clone https://github.com/Goldinyan/Game-of-Life---C.git
cd game_of_life
```

### Pull changes

```sh
git pull
```

---

## License

MIT License – see LICENSE file.

