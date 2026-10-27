# Context and Use Case Diagram

## Part 1: Context Diagram (DFD Level 0)

### 1. Architectural Concept

* **Definition:** The highest abstraction level of a system using structured analysis.
* **The Black Box Principle:** The entire system is represented as a single central process (bubble `0`). Internal logic, sub-processes, and internal databases (**Data Stores**) are **strictly prohibited** at this level.
* **Core Elements:**
* **System Process:** The central bubble (named `Multi-Vendor Marketplace System`).
* **External Entities (Terminators):** External parties or external systems exchanging data across the system boundary.
* **Data Flows:** Directed arrows labeled strictly with **data nouns** (never verbs or actions).
---

### 2. Multi-Vendor Marketplace Specification (Context Level)

#### External Entities

1. **Customers**
2. **Vendor**
3. **Platform Admin**
4. *(Optional External System)* **Payment Gateway**

#### Data Flows Breakdown

<h1>imgggggggggggggggggggg</h1>

* **Customers $\longleftrightarrow$ System:**
* *Inputs (Inflows):* `Search Queries`, `Order Data`, `Payment Info`, `Shipping Address`.
* *Outputs (Outflows):* `Product Catalog`, `Order Status`, `Invoice / Receipt`.


* **Vendor $\longleftrightarrow$ System:**
* *Inputs (Inflows):* `Product Listings`, `Inventory Updates`, `Fulfillment Status`.
* *Outputs (Outflows):* `Order Alerts`, `Sales Analytics`, `Payout Statements`.


* **Platform Admin $\longleftrightarrow$ System:**
* *Inputs (Inflows):* `Vendor Approvals`, `Commission Rates`, `Platform Policies`.
* *Outputs (Outflows):* `Platform Analytics`, `Commission Reports`, `Audit Logs`.



---

## Part 2: Use Case Diagram (UML)

### 1. Architectural Concept

* **Definition:** A behavioral diagram capturing functional requirements from the perspective of external actors.
* **Core Question:** *"What business value does the system deliver to each actor?"*
* **Core Elements:**
* **Actors:** Roles played by human users or external systems (placed **outside** the boundary).
* **Use Cases:** Discrete, end-to-end units of business functionality (represented as horizontal ellipses, labeled with `Verb + Noun`).
* **System Boundary:** A rectangle enclosing all use cases.

---

### 2. Multi-Vendor Marketplace Specification (Use Case Level)

#### Actors Definition

* **Customers (Primary Actor):** Browses products, places orders, and reviews vendors.
* **Vendor (Primary Actor):** Manages a virtual storefront, lists items, and processes customer fulfillment.
* **Platform Admin (Primary Actor):** Governs platform integrity, verifies vendors, manages global categories, and audits revenue commissions.

#### Use Case Breakdown

<h1>imgggggggggggggggggggg</h1>

##### Customer

* `Search & Filter Products`
* `Add Item to Cart`
* `Checkout Order`
* `Add Review`

##### Vendor

* `Register Shop Profile`
* `Manage Product Catalog` (Create, Update, Remove listings)
* `Track Shop Orders`
* `View Payout Dashboard`

##### Platform Admin

* `Approve / Suspend Vendor Account`
* `Manage Platform Commission Fees`
* `Monitor Financial Audits`
* `Moderate Reported Products`


---

### Step-by-Step Guide: Context Diagram (DFD Level 0)

1. **Define the System Scope & Boundary**
* Identify the target system as a single central entity.
* Draw one central circle/bubble labeled with the system name and zero prefix (e.g., `0. Multi-Vendor Marketplace System`).


2. **Identify External Entities (Terminators)**
* Determine all external individuals, organizations, or third-party systems that interact directly with the platform.
* Draw rectangles around the central system for each entity (e.g., `Customer`, `Vendor`, `Platform Admin`, and `Payment Gateway`).


3. **Map Inflows (Inputs to the System)**
* Trace the primary data items sent from each external entity into the system.
* Draw directional arrows pointing from each entity to the central bubble.
* Label arrows with data nouns (e.g., `Order Data / Shipping Address`, `Product Listings`, `Vendor Approvals`).


4. **Map Outflows (Outputs from the System)**
* Trace the data, notifications, or receipts returned by the system to each entity.
* Draw directional arrows pointing from the central bubble to the corresponding entities.
* Label arrows with data nouns (e.g., `Invoice / Receipt`, `Sales Analytics`, `Payment Status`).


5. **Validate Diagram Constraints (Sanity Check)**
* Verify that **no internal data stores (databases)** appear at this level.
* Ensure **no direct arrows exist between external entities** (all communication must pass through the central process).
* Confirm that all labels are formatted as **nouns** rather than verbs.


---

### Step-by-Step Guide: Use Case Diagram (UML)

1. **Draw the System Boundary**
* Place a large rectangular box representing the boundaries of the application.
* Label the box at the top with the system name (e.g., `Online Store - Multi Vendor`).


2. **Identify and Place Actors**
* Determine who requires value or triggers interactions within the system.
* Draw stick figures **outside** the system boundary (e.g., `Customer`, `Vendor` on the left; `Platform Admin`, `Payment Gateway` on the right or bottom).


3. **Identify Core Use Cases**
* List the primary goals and functional actions each actor performs.
* Draw horizontal ellipses **inside** the system boundary.
* Label each use case using a `Verb + Noun` naming convention (e.g., `Search & Filter Products`, `Manage Product Catalog`, `Approve Vendor`).


4. **Establish Associations**
* Draw solid, undirected lines linking each actor to the specific use cases they trigger or participate in.

## Notices
1. **Verbs on Data Flow Arrows:**
* *Wrong:* Labeling an arrow `Submit Order` or `Pay Money` in DFD.
* *Correct:* Labeling it `Order Details` or `Payment Credentials`.

2. **Placing Internal Databases in the Context Diagram:**
* Databases (Data Stores) must only appear starting from **DFD Level 1** onward.


3. **Drawing Interactions Between External Entities:**
* External entities never exchange data directly in a Context Diagram; every arrow must either originate from or terminate at the central system.