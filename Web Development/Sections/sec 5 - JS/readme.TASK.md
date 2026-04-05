# To-Do List Task

## Part 1: HTML Structure

نفّذ الخطوات دي بالترتيب:

---

### Step 1: Create File

* اعمل ملف باسم:

  * `index.html`

* اكتب basic HTML structure باستخدام:

  * `!DOCTYPE html`

---

### Step 2: Add Container

* اعمل `div`:

  * class = `container`

* جوه:

  * `h1` واكتب فيه:

    * `To-Do List`

---

### Step 3: Input Section

* اعمل `div`:

  * class = `input-section`

* جوه:

  * `input`

    * type = `text`
    * id = `taskInput`
    * placeholder = `Add a new task...`

  * `button`

    * id = `addTaskBtn`
    * text = `Add Task`

---

### Step 4: Task List

* داخل الـ container:

* اعمل:

  * `ul`

    * id = `taskList`

---

### Step 5: Extra DOM Element

* اعمل:

  * `div`

    * id = `HelloWorld`
    * class = `oldClass`
    * text = `Hello World`

* بعده:

  * `button`

    * id = `HelloWorldBtn`
    * text = `Change Class`

---

### Step 6: Link Files

* اربط الملفات:

  * CSS → `todo.css`
  * JS → `todo.js`

---

## Part 2: JavaScript Logic

اعمل ملف:

* `todo.js`

---

### Step 1: Wait for DOM

* استخدم:

  * `DOMContentLoaded`

---

### Step 2: Select Elements

* اعمل variables باستخدام:

  * `getElementById`

* للعناصر:

  * `taskInput`
  * `addTaskBtn`
  * `taskList`

---

### Step 3: Add Click Event

* على الزر:

  * `addTaskBtn`

* استخدم:

  * `addEventListener`
  * event = `click`

---

### Step 4: Get Input Value

* هات قيمة الـ input:

  * `taskInput.value`

* استخدم:

  * `trim()`

---

### Step 5: Validation

* لو القيمة فاضية:

  * اعمل:

    * `alert("Please enter a task!")`
  * واستخدم:

    * `return`

---

### Step 6: Create Task Element

* اعمل:

  * `li` باستخدام `createElement`

* جوه:

  * `span`

    * class = `task`
    * فيه النص

  * `button`

    * class = `delete-btn`
    * text = `X`

---

### Step 7: Delete Task

* اعمل:

  * `addEventListener` على زر الـ delete

* لما المستخدم يضغط:

  * احذف الـ `li` باستخدام:

    * `remove()`

---

### Step 8: Append Task

* ضيف الـ `li` جوه:

  * `taskList`

---

### Step 9: Clear Input

* بعد الإضافة:

  * خلي قيمة الـ input:

    * `""`

---

## Part 3: Class Change

---

### Step 1: Select Button

* اختار:

  * `HelloWorldBtn`

---

### Step 2: Add Click Event

* لما المستخدم يضغط على الزر:

  * استخدم:

    * `addEventListener`

---

### Step 3: Change Class

* غيّر الـ class باستخدام:

  * `setAttribute`

* خلي القيمة:

  * `newClass`

---

## Homework Tasks

1. Allow user to press **Enter** to add task
2. Add feature: mark task as **completed** (toggle class)
3. Prevent adding duplicate tasks
4. Count number of tasks and display it
5. Add "Delete All" button

---
