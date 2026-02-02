# 📝 C++ Console Task Manager

![C++](https://img.shields.io/badge/Language-C++17-blue.svg?style=flat&logo=c%2B%2B)
![OOP](https://img.shields.io/badge/Paradigm-OOP-green.svg)
![Status](https://img.shields.io/badge/Status-Completed-success.svg)

A robust, console-based Task Management system built with **C++** to demonstrate Object-Oriented Programming principles and efficient memory management using STL.

The application allows users to create, read, update, and delete (CRUD) tasks, with automatic persistence to a text file.

---

## ⚙️ Key Technical Features

This project focuses on clean architecture and advanced C++ features:

* **Object-Oriented Design:** Strong separation of concerns with `Task` (Data Model) and `TaskManager` (Controller) classes.
* **Operator Overloading:** Custom implementation of `operator==`, `operator!=`, and the subscript `operator[]` for intuitive object manipulation.
* **Data Persistence:** Automatic saving and loading of tasks using `std::fstream` (File I/O) upon program initialization and termination.
* **STL Integration:** Utilization of `std::vector` for dynamic array management.
* **Modular Architecture:** Code split into Header (`.hpp`) and Implementation (`.cpp`) files within a custom `namespace hd`.
* **Documentation:** Full Doxygen-style comments for code maintainability.

---

## 🚀 Functionalities

1.  **Add Task:** Create new entries dynamically.
2.  **Edit Task:** Modify descriptions of existing tasks.
3.  **Delete Task:** Remove tasks from the vector.
4.  **Mark as Done:** Toggle task status.
5.  **Data Persistence:** Tasks are saved to `ListOfTasks.txt` automatically when the program exits.

---

## 🛠️ Code Structure

* `Task.hpp/cpp`: Represents a single unit of work. Contains description, status, and comparison operators.
* `TaskManager.hpp/cpp`: Manages the lifecycle of tasks, file I/O operations, and user interaction logic.
* `main.cpp`: Entry point, initializes the manager and launches the menu loop.
* `ListOfTasks.txt`: Database file for storing task history.

---

## 💻 How to Compile & Run

You can compile this project using any standard C++ compiler (like g++).

**Using Terminal (g++):**

```bash
# 1. Compile all source files
g++ main.cpp TaskImplementation.cpp TaskManagerImplementation.cpp -o task_manager

# 2. Run the application
./task_manager  # On Linux/Mac
task_manager.exe # On Windows
