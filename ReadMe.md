# Library Management System

A console-based **Library Management System** built in C++ using Object-Oriented Programming (OOP). The application allows users to manage a collection of media types (Books, Magazines, and DVDs), track inventory, calculate specific overdue fines, and compare inventory.

## 🚀 Key Features

* **Dynamic Inventory Tracking:** Add, search, view, and safely remove media assets via dedicated unique IDs.
* **Polymorphic Collection System:** Manages dynamic memory allocation of mixed derived media classes safely under a single vector utilizing `std::vector<Library*>`.
* **Custom Fine Calculation Engine:** Implements virtual overriding function parameters to enforce tiered daily fee penalty frameworks:
    * **Books:** 0.50 USD / day
    * **Magazines:** 0.20 USD / day
    * **DVDs:** 1.00 USD / day
* **Encapsulated Data Comparisons:** Uses a `friend` function configuration to read and evaluate internal data sizes between separate instantiation blocks of book pages safely.

## 🛠️ OOP Concepts Showcased

* **Inheritance:**  abstract base class tracking shared properties (`Library`) inherited down into distinct product data groups (`Book`, `Magazine`, `DVD`).
* **Polymorphism:** Utilizing `virtual` keywords, run-time override execution ways, and memory handling through proper dynamic methods (`virtual ~Library()`).
* **Encapsulation:** Protecting data states using `protected` and `private` scope restrictions.
* **Downcasting:** Implementing structured safe type conversions via `dynamic_cast` blocks to single out sub-class data cleanly during runtime loops.

## 🔧 How To Build & Run

### Prerequisites
* A C++ compiler supporting at least **C++11** or higher (`g++`, `clang`, or MSVC).