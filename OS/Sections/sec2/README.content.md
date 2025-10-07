# Session 1 — Introduction to Linux (Beginners)

> **Goal:** Introduce students to Linux fundamentals in a simple and hands-on way, helping them gain confidence using the command line.

## 1. Topics Covered

1. What is an Operating System and why Linux? (Basic comparison with Windows)
2. Linux Distributions: Ubuntu – Debian – Fedora
3. Difference between a File and a Folder
4. Filesystem Hierarchy Overview

   * `/` — root directory
   * `/home` — user home directories
   * `/etc` — system configuration files
   * `/bin` — essential user binaries
   * `/var` — logs and variable files
5. Creating Files and Folders using commands

   * `pwd`, `ls`, `cd`
   * `mkdir`, `rmdir`
   * `touch`, `echo`, `cat`
6. Viewing File Content

   * `cat` — display full file content
   * `head` — view first 10 or 20 lines
   * `tail` — view last 10 or 20 lines
   * `less` — scroll through long files
7. Basic File Permissions

   * `ls -l`, `chmod`
8. Practical Demo and Mini Exercises


## 2. In-class Command Practice

```bash
# Display current directory
pwd

# Create a new folder and move into it
mkdir linux_lab && cd linux_lab

# Create text files in different ways
touch file1.txt
echo "Hello Linux" > file2.txt
cat > file3.txt   # (type text then press Ctrl+D)

# Display files with permissions
ls -l

# Change permissions to read-only
chmod 444 file2.txt
ls -l file2.txt

# Display first or last 20 lines of a file
head -20 file3.txt
tail -20 file3.txt
```

## 3. Try youself

* Try using `less` to view large text files.
* Read about the difference between the `root` user and a normal user.
* Prepare one question or interesting command you discovered for next session.


# 4. Tasks
### **Task 1 — Create Your Own Workspace**

1. Inside the `linux_lab` directory, create a new folder named after your first name.
2. Move into that folder using `cd`.
3. Inside it, create **three text files** using different methods (`touch`, `echo`, and `cat`).
4. Verify that the files were created using `ls -l`.

### **Task 2 — Explore File Viewing Commands**

1. Open one of your text files and add **at least 25 lines** of content (you can copy and paste repeated lines).
2. Use the command `head -10 filename.txt` to show the first 10 lines.
3. Then use `tail -10 filename.txt` to show the last 10 lines.
4. Finally, use `less filename.txt` to navigate up and down inside the file.

### **Task 3 — Modify and Check Permissions**

1. Pick one of your created files.
2. Change its permissions using `chmod 755 filename.txt`.
3. Run `ls -l` to check the new permissions.
4. Explain to your partner (or write in notes) what the numbers mean (rwxr-xr-x).

