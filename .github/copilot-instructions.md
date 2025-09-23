# Copilot Instructions - Info1SerieO (Linked Lists Exercises)

This is an educational C project for Informática I (Computer Science I) course focusing on singly linked list data structures and algorithms. The project structure follows specific academic conventions.

## Project Structure & Architecture

- **`Act1/`**: Activity 1 containing linked list exercises
  - `comun.h`: Common type definitions and includes - **START HERE** when understanding the data model
  - `main.c`: Main program with test cases and partially implemented functions
  - `listasFunc.h`: Function prototypes (currently empty, needs population)
  - `listasFunc.c`: Implementation of linked list functions (partially implemented)
- **`Serie O (listas).pdf`**: Exercise specifications in Spanish (use `pdftotext` to read)

## Key Data Structures

```c
// Core data payload (from comun.h)
typedef struct {
    int x, y;           // Coordinates for comparison operations
    char str[SZ_ARR];   // String data (SZ_ARR = 128)
} data_t;

// Singly linked list node
typedef struct lista {
    data_t xy;          // Data payload
    struct lista *sig;  // Next pointer (Spanish: "siguiente")
} lista_t;
```

## Project-Specific Conventions

### Memory Management
- **CRITICAL**: "Asegurarse en todos los casos de no dejar memoria tomada" (ensure no memory leaks)
- Always `free()` dynamically allocated nodes
- **No global variables permitted** ("está prohibido el uso de variables globales")

### Naming Conventions
- Spanish identifiers: `sig` (siguiente = next), `xy` (coordinates)
- Function names in Spanish/English mix: `crtNode`, `pushList`, `invList`
- Struct suffixes: `_t` for type definitions

### Duplicate Element Definition
Elements are considered duplicates when **both** `x` and `y` coordinates match:
```c
// These are duplicates
data_t a = {5, 7, "first"};
data_t b = {5, 7, "second"};
```

### List Operations Patterns
- Functions should return counts/sizes when possible (e.g., `invList()` returns `size_t`)
- In-place modifications preferred over creating new lists
- List head management: some functions use dummy head nodes

## Current Implementation Status

- `main.c`: Contains incomplete `pushList()` function with infinite loop
- `listasFunc.c`: Only stub for `invList()` function exists
- `listasFunc.h`: Empty - needs function prototypes

## Exercise Requirements (from PDF)

1. **List Inversion**: Reverse list without additional memory/new list
2. **Count Duplicates**: Return count of unique duplicate coordinate pairs
3. **Remove Duplicates**: Remove duplicates, return count of removed elements  
4. **Transfer Duplicates**: Move duplicates to second list

## Development Workflow

```bash
# Compile and test
gcc -o main Act1/main.c Act1/listasFunc.c -I Act1/

# Debug with gdb
gdb ./main
```

## Key Implementation Notes

- Incomplete `pushList()` in `main.c` has infinite loop - needs proper linked list traversal
- Functions should be declared in `listasFunc.h` before implementation
- Test cases in `main()` show expected usage patterns
- Focus on pointer manipulation and proper memory cleanup