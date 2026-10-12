## OOP and File Streaming

### 1. Object-Oriented Programming (OOP) in C#

#### Abstract vs. Virtual

* **`abstract` Method:**
* Has **no body** and ends with a semicolon.
* The parent class declares it to force every child class to implement its own logic.
* The child class **must** use the keyword `override`.


* **`virtual` Method:**
* Has an **actual body** (default code written in the parent class).
* The child class can choose to keep it as is, or modify it using the keyword `override`.



```csharp
// Parent Class
public abstract class Animal
{
    // Every child MUST implement this
    public abstract void MakeSound();

    // Every child CAN use this or override it
    public virtual void Sleep()
    {
        Console.WriteLine("Animal is sleeping.");
    }
}

// Child Class
public class Dog : Animal
{
    // Required: MUST write override for abstract methods
    public override void MakeSound()
    {
        Console.WriteLine("Dog barks.");
    }

    // Optional: overriding virtual method
    public override void Sleep()
    {
        Console.WriteLine("Dog sleeps quietly.");
    }
}

```

---

#### Default Property Value (`= "text"`)

You can assign a default value to an auto-property right after the braces. When an object is created, it takes that initial value automatically.

```csharp
public class User
{
    public string Role { get; set; } = "Guest";
    public int Age { get; set; } = 18;
}

```

---

#### The `base` Keyword

The keyword `base` refers to the parent class. Its primary role is calling the parent constructor or accessing parent methods.

```csharp
public class Person
{
    public string Name { get; set; }

    // Parent constructor requires a name
    public Person(string name)
    {
        Name = name;
    }
}

public class Student : Person
{
    public int Level { get; set; }

    // base(name) sends the name value up to the Person constructor
    public Student(string name, int level) : base(name)
    {
        Level = level;
    }
}

```

---

### 2. File Streaming (StreamWriter & StreamReader)

A **Stream** handles data chunk by chunk instead of reading or writing the whole file into RAM at once.

#### Does `StreamWriter` create a new file or append?

* `new StreamWriter("data.txt")`
* If the file does **not** exist: It creates a new file.
* If the file already exists: It **deletes the old content** and writes fresh text (Overwrite).


* `new StreamWriter("data.txt", true)`
* Setting the second parameter to `true` means **Append**.
* It keeps existing text and adds new lines at the bottom.



#### The `using` Statement

```csharp
using (StreamWriter writer = new StreamWriter("data.txt"))
{
    // code
}

```

* Locks the file while you work.
* Automatically calls `.Close()` and `.Dispose()` at the end of `{ }`, releasing the file back to the OS so other processes can use it.

---

### Complete Simple Demo (OOP + Streaming)

This example avoids generic lists or complex syntax. It writes two student objects to a file and reads them line by line.

```csharp
using System;
using System.IO;

public class Person
{
    public string Name { get; set; }

    public Person(string name)
    {
        Name = name;
    }

    public virtual void ShowInfo()
    {
        Console.WriteLine("Person: " + Name);
    }
}

public class Student : Person
{
    // Property with a default value
    public string Status { get; set; } = "Active";

    // Calling the parent constructor using base
    public Student(string name) : base(name)
    {
    }

    // Overriding the virtual method
    public override void ShowInfo()
    {
        Console.WriteLine("Student: " + Name + " | Status: " + Status);
    }
}

class Program
{
    static void Main()
    {
        string filePath = "students.txt";

        Student s1 = new Student("Mariam");
        Student s2 = new Student("Sarah");

        // 1. WRITING: Append mode (true) keeps old data and adds new rows
        using (StreamWriter writer = new StreamWriter(filePath, true))
        {
            writer.WriteLine(s1.Name);
            writer.WriteLine(s2.Name);
        }

        Console.WriteLine("Data written to file successfully.");
        Console.WriteLine("Reading file line by line:");

        // 2. READING: Read line by line until reaching the end (null)
        using (StreamReader reader = new StreamReader(filePath))
        {
            string line;
            while ((line = reader.ReadLine()) != null)
            {
                // Reconstruct a Student object for each line read
                Student s = new Student(line);
                s.ShowInfo();
            }
        }
    }
}

```