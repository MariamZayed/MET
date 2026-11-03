### 1. What are ERD and Activity Diagrams?

* **Entity-Relationship Diagram (ERD):** A structural blueprint of a database. It visualizes the tables (entities) in a system, their attributes (columns), and how they relate to one another (e.g., One Customer can place Many Orders).
* **Activity Diagram:** A behavioral UML diagram that maps out the procedural flow of actions, control logic, and decisions within a specific operation or use case (step-by-step execution path).

---

### 2. Application on the Online Store Example

* **ERD Perspective:** Defines the static data architecture. For an online store, it structures entities like **Customer**, **Vendor**, **Product**, **Order**, **OrderItem**, and **Payment**, establishing primary and foreign key relationships between them.
* **Activity Diagram Perspective:** Focuses on the dynamic execution of a specific operation, such as the **Checkout Order** process. It tracks how a customer views their cart, enters a shipping address, and provides payment, while the system validates details, processes payment, updates stock, and generates orders.

---

### 3. How to Create Both in Software Ideas Modeler 


#### **Part A: How to Create an Activity Diagram**

<img width="412" height="558" alt="activity" src="https://github.com/user-attachments/assets/d7c61f84-eb88-4985-a3c8-ba168e372982" />


* **Step 1: Set Up Swimlanes**
* Create a new project and select `Activity Diagram`.
* Add two vertical partitions: name the first **Customer** and the second **System**.


* **Step 2: Map Customer Actions**
* Place an **Initial Node** (solid black circle) in the Customer lane.
* Drop **Action** shapes for: `View Cart & Checkout`, `Enter/Confirm Shipping Address`, and `Select & Provide Payment Details`.


* **Step 3: Map System Processing & Decision**
* Connect the flow to the System lane for `Process Payment`.
* Place a **Decision Node** (diamond shape) labeled `Payment Successful?`.


* **Step 4: Branch the Flow (Yes / No)**
* **For "Success":** Connect `Yes` to: `Deduct Stock` $\rightarrow$ `Generate Order` $\rightarrow$ `Send Notifications`, ending with a **Final Node**.
* **For "Failure":** Route `No` back across to the Customer lane to `Re-enter Payment Details`.



#### **Part B: How to Create an ERD (Entity-Relationship Diagram)**

<img width="504" height="775" alt="erd" src="https://github.com/user-attachments/assets/13ff5d1d-9bb7-4e85-a453-f8342fe58af5" />



* **Step 1: Create a New ERD Project**
* Open Software Ideas Modeler, click `New Project`, and select **Entity-Relationship Diagram (ERD)**.


* **Step 2: Add Entities (Tables)**
* Drag and drop **Entity** shapes onto the workspace for core tables: `Customer`, `Product`, `Order`, and `Payment`.


* **Step 3: Define Attributes & Keys**
* Double-click each entity to add attributes (columns).
* Mark primary keys as **PK** (e.g., `CustomerID (PK)`, `ProductID (PK)`) and foreign keys as **FK** (e.g., `CustomerID (FK)`).


* **Step 4: Establish Relationships**
* Use the **Relationship / Association** tool to connect related entities (e.g., connect `Customer` to `Order` with a `1-to-Many` cardinality line to show that one customer can place multiple orders).
