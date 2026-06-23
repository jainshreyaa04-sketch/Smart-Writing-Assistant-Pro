# 📝 Smart Writing Assistant Pro

A C++ based Smart Writing Assistant that provides **spell checking**, **Trie-based auto-complete**, **custom dictionary management**, **search history**, and **writing analytics** using efficient data structures and algorithms.

---

## 🚀 Features

* ✅ Spell Checking
* ✅ Trie-based Auto Complete
* ✅ Intelligent Word Suggestions
* ✅ Levenshtein Distance Algorithm
* ✅ Custom Dictionary Support
* ✅ Search History
* ✅ Dictionary Import & Export
* ✅ Writing Analytics
* ✅ Object-Oriented Design
* ✅ File Handling for Persistent Data

---

## 🛠️ Tech Stack

* **Language:** C++
* **Data Structure:** Trie
* **Algorithm:** Levenshtein Distance (Dynamic Programming)
* **Concepts Used:**

  * Object-Oriented Programming (OOP)
  * File Handling
  * STL (Vector, Unordered Map, String)
  * Dynamic Programming
  * Modular Programming

---

## 📂 Project Structure

```text
Smart-Writing-Assistant-Pro/
│
├── src/
│   ├── main.cpp
│   ├── Trie.cpp
│   ├── Trie.h
│   ├── SpellChecker.cpp
│   ├── SpellChecker.h
│   ├── Dictionary.cpp
│   ├── Dictionary.h
│   ├── History.cpp
│   ├── History.h
│   ├── Levenshtein.cpp
│   ├── Levenshtein.h
│   ├── UI.cpp
│   └── UI.h
│
├── data/
│   ├── dictionary.txt
│   ├── custom_dictionary.txt
│   ├── history.txt
│   └── frequency.txt
│
├── screenshots/
├── assets/
├── output/
├── README.md
└── .gitignore
```

---

## ⚙️ How to Run

### Clone the repository

```bash
git clone https://github.com/YOUR_USERNAME/Smart-Writing-Assistant-Pro.git
```

### Go to the project folder

```bash
cd Smart-Writing-Assistant-Pro/src
```

### Compile

```bash
g++ *.cpp -o SmartWritingAssistant.exe
```

### Run

```bash
./SmartWritingAssistant.exe
```

For Windows PowerShell:

```powershell
.\SmartWritingAssistant.exe
```

---

## 📸 Screenshots

Add screenshots here after uploading them.

* Home Screen
* Spell Check
* Auto Complete
* Search History
* Dictionary Statistics
* Writing Analytics

---

## 📊 Algorithms Used

### Trie

Used for:

* Fast word insertion
* Word search
* Prefix search
* Auto-complete suggestions

### Levenshtein Distance

Used to calculate edit distance between two words and generate ranked spelling suggestions.

Time Complexity:

* Trie Search → **O(L)**
* Trie Insert → **O(L)**
* Auto Complete → **O(P + K)**
* Levenshtein Distance → **O(M × N)**

where:

* **L** = Length of word
* **P** = Prefix length
* **K** = Number of matching words
* **M, N** = Lengths of compared words

---

## 🎯 Learning Outcomes

Through this project I learned:

* Efficient text searching using Trie
* Dynamic Programming with Levenshtein Distance
* Object-Oriented Design
* File Handling in C++
* STL Containers
* Modular software development

---

## 🔮 Future Improvements

* GUI using Qt
* Dark Mode Interface
* Multi-language Dictionary
* Grammar Checking
* Voice Input
* AI-powered Suggestions

---

## 👩‍💻 Author

**Shreya Jain**

Computer Science Engineering Student

GitHub: https://github.com/YOUR_USERNAME

LinkedIn: https://www.linkedin.com/in/YOUR_LINKEDIN/

---

## ⭐ If you found this project interesting, consider giving it a star!
