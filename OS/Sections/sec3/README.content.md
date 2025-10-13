
# Session 2: File Permissions & Ownership in Linux

## 1. Overview
In this session, we’ll dive deeper into how Linux controls **access to files and directories**.  
Students will learn how permissions work, how to view them, and how to modify them using commands.

---

## 2. Topics Covered
- Understanding File Ownership
  - The concepts of **user**, **group**, and **others**
  - File types in permission notation (e.g., `-`, `d`, `l`)
- Understanding File Permissions
  - Read (`r`), Write (`w`), Execute (`x`)
  - Permissions for files vs. directories
- Viewing Permissions
  - Using `ls -l` to display permissions
  - Breaking down each section of the output
- Changing Permissions
  - Using `chmod` (symbolic and numeric modes)
  - Common examples and practical exercises
- Changing Ownership
  - Using `chown` and `chgrp`
  - Understanding why root privileges are sometimes required
- Permission Denied Errors
  - How to interpret and solve them

---

## 3. Live Demonstrations
1. Display file permissions using `ls -l`
2. Modify file permissions:
   - Example: `chmod u+x script.sh`
   - Example: `chmod 755 myfolder`
3. Change file ownership (for demonstration):
   - `sudo chown user2 file.txt`
4. Explain what happens when a user doesn’t have permission to execute or write to a file.

---

## 4. Commands Summary
| Command | Description |
|----------|--------------|
| `ls -l` | List files with detailed information including permissions |
| `chmod` | Change file or directory permissions |
| `chown` | Change file owner |
| `chgrp` | Change file’s group owner |
| `whoami` | Display the current user |
| `id` | Display user and group information |

---

## 5. Tasks

### **Task 1: Viewing Permissions**
Create three files (`file1.txt`, `file2.txt`, `file3.txt`) and one directory (`mydir`).
Use `ls -l` to list them and write down:
- Which ones are files vs. directories  
- What their default permissions are  
- Who owns them  

---

### **Task 2: Modifying Permissions**
Change permissions using both symbolic and numeric methods:
1. Give the owner execute permission on `file1.txt`
2. Remove write permission from the group on `file2.txt`
3. Set `mydir` to full access (read, write, execute) for everyone

---

### **Task 3: Ownership and Access**
1. Create a new user (demonstration or explanation only if not possible locally)  
2. Change the owner of one file using `sudo chown`  
3. Try accessing the file from another user and observe the permission error  
4. Fix the error by changing ownership or permissions appropriately

---
