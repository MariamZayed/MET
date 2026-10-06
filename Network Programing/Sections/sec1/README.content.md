# OOP & Classes in C#


## 1. Procedural vs. OOP 

### Problem with Procedural Code
In procedural programming, state (data variables, structs) and behavior (functions/procedures) are kept separate:
- Functions from anywhere in the codebase can access and mutate data directly.
- Maintaining invariants and business validation rules becomes error-prone as the application scales.
- Lack of ownership: there is no single entity responsible for maintaining data integrity.

### The OOP Solution
OOP binds **Data (State)** and **Functions (Behavior)** together into cohesive, self-contained building blocks called **Classes**.
- A class dictates *how* its data can be read or modified.
- External code interacts via a public interface, preventing invalid state.

### Class vs. Object (Stack vs. Heap Memory)
- **Class (Blueprint):** A user-defined data type and template. Declaring a class does not allocate object memory at runtime.
- **Object (Instance):** A concrete instance allocated in memory at runtime via the `new` keyword.


```csharp
BankAccount acc1 = new BankAccount("Mariam", 500);
BankAccount acc2 = acc1; // Copies reference only; points to the exact same heap memory.

```

---

## 2. Class & Data Protection 

### Access Modifiers

* `private`: Accessible only within the body of the class (default for class members).
* `public`: Accessible from any code in the assembly or consuming projects.
* **Core Rule:** Never expose fields as `public`. Expose operations and validated properties instead.

###  C# Properties

#### Traditional Approach (Java-Style)

```csharp
public class Account
{
    private decimal _balance;

    public decimal GetBalance() => _balance;

    public void SetBalance(decimal value)
    {
        if (value >= 0)
        {
            _balance = value;
        }
    }
}

```

#### Full Property with Validation (C# Idiomatic)

```csharp
public class Account
{
    private decimal _balance;

    public decimal Balance
    {
        get { return _balance; }
        private set 
        { 
            if (value >= 0)
                _balance = value; 
        }
    }
}

```

#### Auto-Implemented Properties

Used when no immediate custom validation is required. The compiler generates an anonymous backing field under the hood:

```csharp
public string OwnerName { get; set; }
public int AccountNumber { get; } // Read-only property (settable only via constructor)

```

---

## 3. Object Lifecycle: Constructors & `this` (25 mins)

### Constructors

* Special methods invoked at instantiation time (`new`).
* Guarantee that an object starts in a valid, fully initialized state.
* If no constructor is defined, the C# compiler supplies an empty default parameterless constructor.

### Constructor Overloading & Constructor Chaining (`: this(...)`)

Overloading allows multiple ways to initialize an object. Chaining prevents code duplication by delegating initialization to a central constructor:

```csharp
public class BankAccount
{
    public int AccountNumber { get; }
    public string OwnerName { get; set; }
    public decimal Balance { get; private set; }

    // Constructor 1: Default balance = 0
    public BankAccount(string ownerName) : this(ownerName, 0)
    {
        // Delegates work to Constructor 2
    }

    // Constructor 2: Master constructor
    public BankAccount(string ownerName, decimal initialBalance)
    {
        OwnerName = ownerName;
        if (initialBalance > 0)
        {
            Balance = initialBalance;
        }
    }
}

```

### Constructor vs. Object Initializer Syntax

* **Constructor:** Enforces mandatory parameters at creation time.
* **Object Initializer:** Populates public mutable properties immediately after instantiation:

```csharp
// Object Initializer
var student = new Student { Name = "Zeyad", Age = 21 };

```

---

## 4. Behavior: Methods & Static Members (20 mins)

### Instance Methods

Operations that operate on the specific data of the invoking object (`this`):

```csharp
public void Deposit(decimal amount)
{
    if (amount <= 0) return;
    Balance += amount;
}

public bool Withdraw(decimal amount)
{
    if (amount <= 0 || amount > Balance) return false;
    Balance -= amount;
    return true;
}

```

### Instance vs. Static Members

| Feature | Instance Member | Static Member |
| --- | --- | --- |
| **Belongs to** | Individual Object (Instance) | The Class Type itself |
| **Memory Allocation** | Allocated per instance on the Heap | Single shared allocation in Type metadata |
| **Invocation** | `instanceName.Member()` | `ClassName.Member()` |
| **Use Case** | Data/behavior unique to each object | Shared state, constants, utility functions |

#### Example: Shared Static ID Counter

```csharp
public class BankAccount
{
    // Shared counter across all instances
    private static int _lastAssignedId = 1000;

    public int AccountNumber { get; }

    public BankAccount()
    {
        AccountNumber = ++_lastAssignedId;
    }

    public static int GetTotalAccountsCreated() => _lastAssignedId - 1000;
}

```

---

## 5. Live Coding Demo & Practical Exercise (15 mins)

### Complete Code Example

```csharp
using System;

namespace OopFundamentals
{
    public class BankAccount
    {
        // Static Member: Shared counter across all accounts
        private static int _lastAssignedId = 1000;

        // Encapsulated Properties
        public int AccountNumber { get; }
        public string OwnerName { get; set; }
        public decimal Balance { get; private set; }

        // Constructors with Chaining
        public BankAccount(string ownerName) : this(ownerName, 0)
        {
        }

        public BankAccount(string ownerName, decimal initialBalance)
        {
            AccountNumber = ++_lastAssignedId;
            OwnerName = ownerName;

            if (initialBalance > 0)
            {
                Balance = initialBalance;
            }
        }

        // Instance Methods
        public void Deposit(decimal amount)
        {
            if (amount <= 0)
                throw new ArgumentException("Deposit amount must be positive.");

            Balance += amount;
        }

        public bool Withdraw(decimal amount)
        {
            if (amount <= 0 || amount > Balance)
                return false;

            Balance -= amount;
            return true;
        }

        // Static Utility Method
        public static int GetTotalAccountsCreated()
        {
            return _lastAssignedId - 1000;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            BankAccount acc1 = new BankAccount("Mariam", 500);
            BankAccount acc2 = new BankAccount("Omar");

            acc1.Deposit(250);
            bool isSuccess = acc1.Withdraw(100);

            Console.WriteLine($"Acc 1 -> ID: {acc1.AccountNumber}, Owner: {acc1.OwnerName}, Balance: {acc1.Balance:C}");
            Console.WriteLine($"Acc 2 -> ID: {acc2.AccountNumber}, Owner: {acc2.OwnerName}, Balance: {acc2.Balance:C}");
            Console.WriteLine($"Total accounts created: {BankAccount.GetTotalAccountsCreated()}");
        }
    }
}

```

---

## In-Class Mini Task (5-7 mins)

**Objective:** Implement an inter-account transfer method on the `BankAccount` class.

**Requirements:**

1. Method signature: `public bool TransferTo(BankAccount targetAccount, decimal amount)`
2. Ensure `targetAccount` is not `null`.
3. Ensure `amount` is greater than 0 and does not exceed the sender's balance.
4. If successful, deduct the amount from the current account, add it to `targetAccount`, and return `true`; otherwise return `false`.

```

```