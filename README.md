# Mini Device Monitor

## Project Introduction
### Why This Project?

It's just a little project which a beginner learning C wanna improve his programming skills but he doesn't like just solving problem sets repeatedly. It's also an attempt to experience the real-world development.
Or: I'm learning C, and I want to improve my programming skills by building practical projects instead of only solving problem sets.
## Features
- Temperature Analysis
  - Calculates the average temperature.
  - Finds the maximum and minimum temperatures.
  - Counts abnormal readings.

- Interactive Menu
  - Provides a command-line interface.

- Temperature Data Display
  - Displays all simulated temperature readings.

- Input Validation and Error Handling
  - Handles invalid menu options and EOF.
  - Checks for invalid parameters in analysis functions.

## How to run

Compile the program with Clang:

```bash
clang -std=c17 -Wall -Wextra -Wpedantic main.c monitor.c -o monitor
```

Run the program:

```bash
./monitor
```

## How to run the test

Compile the test with Clang:

```bash
clang -std=c17 -Wall -Wextra -Wpedantic test_monitor.c monitor.c -o test_monitor
```

Run the test:

```bash
./test-monitor
```

## Version
### Current version
    v0.3
### Future Updates
    To be determined.

## Version History
### v0.3
- Split the program into `main.c`, `monitor.c`, and `monitor.h`.
- Added local unit tests using `assert`.
- Added a menu option to generate a chosen number of simulated temperature readings.
- Improved menu input validation to reject entries such as `2abc`.
### v0.2
- Added an interactive menu.
- Added temperature data display.
- Improved input validation and error handling.
### v0.1
- Implemented basic temperature analysis.
