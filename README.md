
# 🏨 Hostel Allocation System – README

## 📌 Overview

The **Hostel Allocation System** is a simple C++ console-based application designed to manage hostel room allocation for students.

The system allows users to:

* Register students
* Register hostel rooms
* Allocate rooms based on **gender and priority**
* Display room allocations
* Display a waitlist for unallocated students

The allocation process ensures:

* Students are assigned to rooms matching their gender.
* Students with higher priority (lower number = higher priority) are allocated first.
* Students are placed on a waitlist if no suitable room is available.

---

## ⚙️ Features

### 1️⃣ Student Registration

Each student record includes:

* **ID**
* **Name**
* **Gender (M/F)**
* **Priority (1–3)**

  * `1` = Highest priority
  * `3` = Lowest priority

---

### 2️⃣ Room Registration

Each room includes:

* **Room Number**
* **Gender Block (M/F)**
* **Capacity**
* List of assigned occupants

---

### 3️⃣ Room Allocation

When allocation is executed:

* Students are sorted by priority (ascending order).
* The system checks:

  * If the room matches the student's gender
  * If the room has available space
* If both conditions are met → student is assigned.
* If not → student is added to the **waitlist**.

---

### 4️⃣ Display Allocation

The system displays:

* Each room with its occupants
* A waitlist of students who were not allocated

---

## 🖥️ How to Compile and Run

### 🔹 Step 1: Save the file

Save the program as:

```
hostel_allocation.cpp
```

### 🔹 Step 2: Compile (Using g++)

```bash
g++ hostel_allocation.cpp -o hostel
```

### 🔹 Step 3: Run

```bash
./hostel
```

On Windows:

```bash
hostel.exe
```

---

## 📋 How to Use the Program

After running, the system will display a menu:

```
HOSTEL ALLOCATION SYSTEM
1. Register Student
2. Register Room
3. Allocate Rooms
4. Display Allocation Lists
0. Exit
```

---

### ✅ Option 1: Register Student

Enter:

* Student ID
* Name
* Gender (M/F)
* Priority (1–3)

Example:

```
Enter ID: 101
Enter Name: John
Enter Gender (M/F): M
Enter Priority (1-3): 1
```

---

### ✅ Option 2: Register Room

Enter:

* Room Number
* Gender Block (M/F)
* Capacity

Example:

```
Enter Room Number: 12
Enter Gender Block (M/F): M
Enter Capacity: 4
```

---

### ✅ Option 3: Allocate Rooms

* Sorts students by priority
* Assigns rooms automatically
* Adds unallocated students to waitlist

---

### ✅ Option 4: Display Allocation Lists

Shows:

```
--- ROOM ALLOCATIONS ---
Room 12 (M):
  John (Priority 1)

--- WAITLIST ---
Mary (F, Priority 2)
```

---

## 🧠 Allocation Logic Summary

| Condition                      | Action           |
| ------------------------------ | ---------------- |
| Gender matches & room not full | Allocate student |
| Room full or no matching room  | Add to waitlist  |

---

## ⚠️ Limitations

* Names with spaces are not supported (e.g., "John Doe" will not work correctly).
* No data persistence (data is lost when program exits).
* No duplicate ID checking.
* No room reallocation or removal functionality.
* Waitlist is not cleared before re-allocation (may duplicate entries if allocation is run multiple times).

---

## 🚀 Possible Improvements

You can enhance the system by adding:

* File storage (save/load data)
* Search student by ID
* Remove student
* Edit student details
* Clear waitlist before re-allocation
* Support full names using `getline()`
* Admin login system
* Graphical User Interface (GUI)

---

## 📚 Technologies Used

* C++
* STL (`vector`, `algorithm`)
* Sorting with custom comparator
* Structured programming

---

## 👨‍💻 Author

Developed as a console-based academic project for demonstrating:

* Structures
* Vectors
* Sorting
* Basic allocation algorithms

---

If you'd like, I can also create:

* A more professional GitHub-ready README
* A system flowchart
* A system documentation report (for submission)
* Improved version of the code with fixes and enhancements
