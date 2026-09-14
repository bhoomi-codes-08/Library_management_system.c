# Library Management System

A console-based Library Management System implemented in C, designed to manage book inventory through persistent file storage — no external database required.

## Overview

This project demonstrates core systems programming concepts including structured data modeling, file I/O, and safe data mutation patterns in C. Book records are persisted to disk in a flat-file format and manipulated using a read-modify-write strategy to ensure data integrity across operations.

## Features

- **Add Book** — Register new books with metadata (name, author, ID, price)
- **Display Catalog** — List all books with real-time availability status
- **Search by ID** — Look up a specific book record by its ID
- **Issue Book** — Mark a book as issued, updating its status persistently
- **Return Book** — Revert issued status back to available

## Technical Highlights

- Custom `struct`-based data model for book records
- File-based persistence using `fopen`/`fscanf`/`fprintf`
- Safe update pattern: records are read from the existing file and written to a temporary file, which is then swapped in via `rename()` — avoiding partial writes or data loss during update operations
- Input parsing with bounded string reads (`%99s`) to prevent buffer overflow

## Tech Stack

- **Language:** C
- **Storage:** Flat-file (`.txt`) persistence

## Getting Started

### Prerequisites
- GCC (or any standard C compiler)

### Build & Run
```bash
gcc library.c -o library
./library
```

### Usage
On running the program, you'll see a menu:
```
----Library Management System----
1. Add Book
2. Display Books
3. Search by ID
4. Issue Book
5. Return Book
6. Exit
```
Enter the number corresponding to the action you want to perform, and follow the prompts.

## Project Structure
```
.
├── library.c       # Main source file
├── Library.txt     # Data file (auto-created on first run)
└── README.md
```

## Future Improvements

- Replace fixed-width text parsing with a structured format (CSV/JSON)
- Add input validation and duplicate ID checks
- Support multi-word book titles and author names (currently single-word only)
- Migrate to dynamic memory allocation for in-memory record handling

## License

This project is open source and available under the [MIT License](LICENSE).

#Author :- Bhoomi Mahajan
Linkdin profile:- https://www.linkedin.com/in/bhoomi-mahajan-4308a0428/
