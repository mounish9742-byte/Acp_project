![image alt](https://github.com/mounish9742-byte/ACP_project/blob/0026d8163d4ad9398fe3bda255499c49fd38949b/Mounish.B%20Resume.png)

 # 2D Graphics Editor in C

## Project Description

This project is a simple 2D Graphics Editor implemented in C using a 2D character array. The editor allows users to create and manipulate basic geometric shapes on a text-based canvas.

### Features

* Draw Rectangle
* Draw Line
* Draw Triangle
* Draw Circle
* Delete Objects
* Modify Objects
* Display Canvas
* Clear Canvas
* Menu-Driven Interface

## Technologies Used

* C Programming Language
* GCC Compiler
* Visual Studio Code

---

## Project Structure

```
ACP_PROJECT-1/
│
├── graphics_editor.c
├── README.md
└── graphics_editor.exe (generated after compilation)
```

---

## How to Compile

### Using GCC

Open a terminal in the project directory and run:

```bash
gcc graphics_editor.c -o graphics_editor -lm
```

### Explanation

* `gcc` → GNU C Compiler
* `graphics_editor.c` → Source code file
* `-o graphics_editor` → Creates executable named graphics_editor
* `-lm` → Links the math library required for circle calculations

---

## How to Run

### Windows (PowerShell)

```powershell
.\graphics_editor.exe
```

### Windows (Command Prompt)

```cmd
graphics_editor.exe
```

### Linux / macOS

```bash
./graphics_editor
```

---

## Menu Options

```
1. Draw Rectangle
2. Draw Line
3. Draw Triangle
4. Draw Circle
5. Delete Area
6. Modify Rectangle
7. Display Picture
8. Clear Canvas
9. Exit
```

---

## Example Usage

### Draw Rectangle

```
Enter Choice: 1
Enter x y width height:
5 5 10 4
```

### Draw Line

```
Enter Choice: 2
Enter x1 y1 x2 y2:
1 2 20 10
```

### Display Canvas

```
Enter Choice: 7
```

---

## Git Commands Used

### Initialize Repository

```bash
git init
```

### Add Files

```bash
git add .
```

### Commit Changes

```bash
git commit -m "Initial Commit"
```

### Connect to GitHub Repository

```bash
git remote add origin <repository-url>
```

### Push Code

```bash
git push -u origin main
```

### Daily Updates

```bash
git add .
git commit -m "Updated project"
git push
```

---

## Learning Outcomes

* Working with 2D arrays in C
* Function-based program design
* Drawing algorithms for basic shapes
* Menu-driven programming
* Git and GitHub version control

---

## Author

Mounish B

Academic Project – 2D Graphics Editor using C
