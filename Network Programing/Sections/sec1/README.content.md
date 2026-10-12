Here is the updated guide with the **Constructors** section fully written in English and embedded directly into the lesson flow (between `this` and `Object Instantiation`), with the return-type explanation kept clean, focused, and concise:

---

# Session 01: Class Fundamentals & Syntax in C#

## 1. The Core Mental Model Shift: C++ vs. C#

| Concept | C++ | C# |
| --- | --- | --- |
| **File Structure** | Separate declaration (`.h`) and implementation (`.cpp`) | Single unified source file (`.cs`) |
| **Functions & Scope** | Free/Global functions can exist anywhere | **Forbidden**; every function must live inside a `class` or `struct` |
| **Memory Allocation** | Objects can live on the Stack (`Account a;`) or Heap (`new Account`) | Classes are **Reference Types**; objects are **always** allocated on the Heap via `new` |
| **Memory Management** | Manual via pointers (`*`, `->`) and `delete` | Automated via managed references and the **Garbage Collector (GC)** |
| **Console Output** | `std::cout << x << std::endl;` | `Console.WriteLine($"Value: {x}");` (String Interpolation) |

---

## 2. Variables and Methods

### A. Local Variables

Syntax matches C++ for primary primitive types, with the addition of `decimal` for financial accuracy:

```csharp
int age = 25;
string name = "Mariam";
double rate = 4.5;
bool isActive = true;
decimal salary = 5000.75m; // The 'm' suffix denotes the high-precision decimal type

```

### B. Methods

General syntax:

`[Access Modifier] [Return Type] [MethodName]([Parameters])`

```csharp
public class Calculator
{
    // Standard method returning a value
    public int Add(int a, int b)
    {
        return a + b;
    }

    // Void method performing an action
    public void DisplayMessage(string message)
    {
        Console.WriteLine(message);
    }

    // Expression-bodied method (shorthand for single-line return statements)
    public int Multiply(int a, int b) => a * b;
}

```

---

## 3. Class Header & Access Modifiers

```csharp
public class BankAccount
{
    // Class members
}

```

### A. Class-Level Access Modifiers

* **`public class`**: Accessible from any project/assembly in the solution.
* **`internal class`**: Accessible only within the current compiled project/assembly (Default if omitted).
* **Can a class be declared `private`?**
* **Top-level class:** **No.** The compiler forbids it because an inaccessible top-level type serves no purpose.
* **Nested class (a class inside another class):** **Yes.** It is accessible only by its enclosing outer class.



### B. Member-Level Access Modifiers

Unlike C++ block headers (`public:`, `private:`), in C# **each individual member defines its own modifier**:

* `public`: Accessible from anywhere.
* `private`: Accessible only inside the declaring class (Default for class members if omitted).

---

## 4. Fields vs. Properties

### A. What is a Field?

A field is a raw storage location in memory. Following naming conventions, private fields are typically prefixed with an underscore `_`:

```csharp
private double _gpa;

```

### B. What is a Property?

In C++, protecting a private field requires two separate functions:

```cpp
// C++ approach
double getGpa() {
    return gpa;
}
void setGpa(double val) {
    if (val >= 0) gpa = val;
}

```

In C#, a **Property** merges these two functions into a single idiomatic construct:

* Externally, it looks and behaves like a regular variable (`s.Gpa = 3.8;`).
* Internally, it executes underlying code blocks to safeguard data integrity.

```
                  +-----------------------------------+
                  |         Property: Gpa             |
                  |                                   |
s.Gpa = 3.8;  ──> |  set { if(value >= 0) _gpa = v; } | ──> Writes to: private double _gpa
                  |                                   |
print(s.Gpa); <── |  get { return _gpa; }             | <── Reads from:  private double _gpa
                  +-----------------------------------+

```

---

## 5. Properties Syntax Explained

### A. Full Property (Used when custom validation is required)

Uses an explicit private backing field with `get` and `set` accessors:

```csharp
public class Student
{
    private double _gpa; // Backing Field

    public double Gpa
    {
        get 
        { 
            return _gpa; // Executes upon reading
        }
        set 
        { 
            // The contextual keyword 'value' holds the incoming data assigned via '='
            if (value >= 0.0 && value <= 4.0)
            {
                _gpa = value;
            }
        }
    }
}

```

### B. Auto-Implemented Properties (Shorthand Syntax)

When no custom validation rules are needed, the compiler creates a hidden backing field automatically:

```csharp
// Read & Write: accessible externally
public string Name { get; set; }

// Public read, mutation restricted to class methods
public decimal Balance { get; private set; }

// Read-Only Property: can only be assigned during instantiation in a Constructor
public int Id { get; }

```

> **Why does `this.Id = id;` work in the constructor?**
> `public int Id { get; }` declares a read-only property with no `set` accessor. The compiler generates an invisible `readonly` field under the hood. C# explicitly allows assignment to this field **only inside constructors**. Once constructor execution completes, the property becomes completely immutable.

---

## 6. The `this` Keyword

In C++, `this` is an explicit pointer (`this->name`). In C#, `this` is a **reference** to the current instance accessed via the dot operator (`this.name`).

**Primary Uses:**

1. **Disambiguation:** Resolving conflicts when a parameter name matches a property or field name:

```csharp
this.Name = name;

```

2. **Constructor Chaining:** Invoking one constructor from another to avoid code duplication using `: this(...)`.

---

## 7. Constructors

### A. Role of a Constructor

A constructor is a special method automatically invoked by the runtime when creating an instance of a class. Its primary role is to initialize object state and enforce valid preconditions before exposing the object.

```csharp
public class Student
{
    // Default / Parameterless Constructor
    public Student()
    {
        Name = "Unknown";
    }

    // Parameterized Constructor
    public Student(int id, string name)
    {
        this.Id = id;
        this.Name = name;
    }
}

```

### B. Compiler Defaults

* **No constructors written:** The C# compiler injects a parameterless default constructor that zero-initializes fields (`0`, `null`, `false`).
* **Any constructor defined:** The compiler suppresses the automatic parameterless constructor. If you still need `new Student()`, you must explicitly declare it.

### C. Constructor Chaining (`: this`)

To adhere to DRY (Don't Repeat Yourself), overload constructors can forward initialization logic to a master constructor using `: this(...)`:

```csharp
public class Student
{
    public int Id { get; }
    public string Name { get; set; }
    public double Gpa { get; set; }

    // Master Constructor
    public Student(int id, string name, double gpa)
    {
        this.Id = id;
        this.Name = name;
        this.Gpa = gpa;
    }

    // Chained Constructor: passes default GPA to the Master Constructor
    public Student(int id, string name) : this(id, name, 0.0)
    {
    }
}

```

### D. Why Doesn't a Constructor Have a Return Type?

1. **Disambiguation from Regular Methods:**
If constructors permitted a return type (even `void`), the compiler could not differentiate between a constructor and a regular instance method that happens to share the class name:
```csharp
// Is this an initializer, or a standard method returning nothing?
public void Student() { }

```


Omitting the return type is the explicit syntactic rule that identifies the member as a constructor.
2. **The Constructor Does Not Return the Instance:**
In `Student s = new Student();`, the caller receives the newly allocated reference from the `new` operator, not from the constructor itself. The constructor's sole responsibility is initializing the newly allocated memory (`this`).

---

## 8. Object Instantiation

Because classes are Reference Types, instantiation always utilizes `new` on the Heap:

```csharp
// 1. Explicit type declaration
Student s1 = new Student(101, "Mariam", 3.9);

// 2. Type inference via 'var'
var s2 = new Student(102, "Ahmed", 3.5);

// 3. Target-typed new (Modern C#)
Student s3 = new(103, "Sara", 3.8);

// 4. Object Initializer syntax (populates public setters post-instantiation)
Student s4 = new Student(104, "Omar", 3.2)
{
    Name = "Omar Farooq"
};

```

---

## 9. Complete Working Example

```csharp
using System;

namespace OopBasics
{
    public class Student
    {
        // 1. Backing Field
        private double _gpa;

        // 2. Read-Only Auto-Property (Assignable only inside Constructors)
        public int Id { get; }

        // 3. Auto-Implemented Property
        public string Name { get; set; }

        // 4. Full Property with validation
        public double Gpa
        {
            get => _gpa;
            set
            {
                if (value >= 0.0 && value <= 4.0)
                    _gpa = value;
            }
        }

        // 5. Overloaded Constructor (chains to Master Constructor with default GPA 0.0)
        public Student(int id, string name) : this(id, name, 0.0)
        {
        }

        // 6. Master Constructor
        public Student(int id, string name, double gpa)
        {
            // Allowed: Read-only auto-property assigned inside the constructor
            this.Id = id;

            // Auto-property assignment
            this.Name = name;

            // Runs through the validation logic in the 'set' block
            this.Gpa = gpa;
        }

        // 7. Instance Method
        public void PrintStudentCard()
        {
            Console.WriteLine($"[ID: {this.Id}] Name: {this.Name}, GPA: {this.Gpa}");
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            // Instantiate an object on the Heap
            Student student = new Student(101, "Mariam", 3.9);

            student.PrintStudentCard();

            // Valid modification
            student.Name = "Mariam Zayed";

            // Invalid modification (Rejected by validation logic; remains 3.9)
            student.Gpa = 4.8;

            // student.Id = 200; 
            // COMPILE ERROR: Property 'Id' cannot be assigned to -- it is read-only.

            student.PrintStudentCard();
        }
    }
}

```