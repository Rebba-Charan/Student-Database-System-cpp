# Student Database System (C++)

A simple **Student Database System** built using **C++**, **OOPs concepts**, and **Binary File Handling**.

This project was created to practice:

* Object-Oriented Programming (OOPs)
* File Handling in C++
* Binary Files
* Random Access using `seekg()` and `seekp()`
* CRUD operations (Create, Read, Update, Delete)

---

## 🚀 Features

* Add Student
* View All Students
* View One Student by Index
* Update Student Record
* Delete Student Record

---

## 🛠 Concepts Used

### OOPs

* Class and Objects
* Encapsulation of student data

### File Handling

* `ofstream`
* `ifstream`
* `fstream`

### Binary File Concepts

* `write()`
* `read()`
* `ios::binary`
* `ios::app`
* `ios::in`
* `ios::out`

### File Pointer Control

* `seekg()` → move read pointer
* `seekp()` → move write pointer

---

## 📂 File Structure

* `studentdata.bin` → stores student records
* `main.cpp` → source code

---

## 📌 Student Record Structure

Each student record contains:

* Roll Number
* Name

---

## ▶️ How to Run

### 1. Compile

```bash
g++ main.cpp -o main
```

### 2. Run

```bash
./main
```

(For Windows)

```bash
main.exe
```

---

## 📋 Menu Options

The program supports the following operations:

1. Add Student
2. View All Students
3. View One Student
4. Update Student
5. Delete Student
6. Exit

---

## 💡 Why I Built This Project

I built this project to strengthen my understanding of:

* practical OOPs
* converting concepts into code
* file handling beyond basic text files
* how binary files and random access work internally

This project helped me understand how simple database-like systems can be built using core C++ concepts.

---

## 🔥 Learning Outcomes

From this project, I learned:

* how to store objects in binary files
* how to retrieve specific records using file pointers
* how to update data without rewriting the entire file
* how delete operations are handled using a temporary file
* how real-world CRUD systems work at a basic level

---

## 📈 Future Improvements

Possible improvements for this project:

* Search student by Roll Number
* Prevent duplicate Roll Numbers
* Add Age / Branch / CGPA fields
* Better menu-driven UI
* Password/Admin authentication
* Sorting student records
* Export records to text/CSV format

---

## 👨‍💻 Author

**Charan**

B.Tech Student | Learning C++ | Exploring OOPs, DSA, and Problem Solving

---
