# UML Sequence Diagrams & System Architecture

A comprehensive 60-minute practical workshop designed for teaching UML Sequence Diagrams using a multi-tier Web Authentication flow as a real-world case study.

---

## 1. Theoretical Overview

### What is a Sequence Diagram?
A **Sequence Diagram** is an Interaction/Behavioral UML diagram that models how processes or objects collaborate over time. It visually represents the temporal order of messages exchanged between different actors and components to complete a specific system workflow.

### Core Notations

* **Lifeline:** Depicted as a vertical dashed line extending downward from a participant box. It represents the existence and lifecycle of a component during the interaction.
* **Execution Specification (Activation Bar):** A vertical rectangle placed on a lifeline indicating that the component is actively executing an operation or waiting for a response.
* **Synchronous Message (`—►`):** A solid line with a filled arrowhead. The caller halts execution and waits for the operation to complete before proceeding.
* **Reply / Return Message (`- - ->`):** A dashed line with an open arrowhead returning control and optional data back to the caller.
* **Self-Message:** A nested loop message originating and terminating on the same lifeline, indicating an internal method execution (e.g., data validation, hashing).
* **Combined Fragment (`alt`):** An interaction frame representing conditional branching (`if / else`). It is split into operands by a horizontal dashed line, where only the operand satisfying the guard condition `[condition]` executes.

---

## 2. Case Study: User Authentication Flow

This scenario illustrates an end-to-end authentication workflow spanning four core system layers: **User**, **Frontend**, **Backend**, and **Database**.




### Flow Execution Breakdown

1. **Submission:** The `User` submits credentials via a form (`Submit Form(Email, Pass)`).
2. **Dispatch:** The `Frontend` sends an HTTP payload to the `Backend` via `Post(data)`.
3. **Branching (`alt` frame):** The backend interacts with the database depending on record existence:
   * **Success Path (`[Valid Cred]`):**
     * The `Backend` queries the store via `findUserByEmail(email)`.
     * The `Database` returns the record containing the stored password hash: `userData(hashed_pass)`.
     * The `Backend` verifies the supplied plain password against the stored hash via an internal method `verifyHash()`.
     * Upon verification, the `Backend` dispatches an HTTP `200 Ok` status code containing the auth token to the `Frontend`.
     * The `Frontend` transitions the user interface (`Redirect to Profile`).
   * **Failure Path (`[Invalid Cred]`):**
     * The `Database` returns an empty set or a `Not found` state.
     * The `Backend` responds with an HTTP `401 Unauthorized` code.
     * The `Frontend` triggers a client-side error notification (`Wrong Pass or Email`).

---

## 3. Step-by-Step Implementation in Software Ideas Modeler

Follow these concrete steps to replicate the architecture diagram:

### Step 1: Placing System Lifelines
1. From the **Sequence Diagram** panel on the left toolbox, select the **Lifeline** element.
2. Click four times on the canvas to instantiate four entities horizontally.
3. Label them consecutively:
   * `User`
   * `Frontend`
   * `Backend`
   * `Database`

### Step 2: Defining Initial Request Calls
1. Select **Call Message** from the toolbox.
2. Drag from the `User` lifeline to the `Frontend` lifeline; assign the name: `Submit Form(Email, Pass)`.
3. Select another **Call Message** and drag from `Frontend` to `Backend`; assign the name: `Post(data)`.

### Step 3: Configuring the `alt` Combined Fragment
1. Locate **Combined Fragment** under the interaction tools and draw a boundary covering the canvas below the initial POST message across all lifelines.
2. Click the drawn fragment to select it and press **F5** (or right-click and choose **Element Properties...**).
3. Under the **Fragment** tab:
   * Confirm that **Interaction Operator** is set to `alt`.
   * Under the **Interaction Operands** list, click **Add**.
   * Set **Guard condition** to `Valid Cred` and confirm with **OK**.
   * Click **Add** a second time.
   * Set **Guard condition** to `Invalid Cred` and confirm with **OK**.
4. Click **OK** to close the Properties dialog. The fragment will now render split horizontally with a dashed line.

### Step 4: Routing Messages inside the Upper Operand (`[Valid Cred]`)
1. **Database Lookup:** Select **Call Message** and route from `Backend` to `Database` labeled `findUserByEmail(email)`.
2. **Data Return:** Select **Reply Message** (dashed arrow) and route from `Database` back to `Backend` labeled `userData(hashed_pass)`.
3. **Internal Hash Check:** Select **Self Message** on the `Backend` lifeline and label it `verifyHash()`.
4. **Success Response:** Select **Reply Message** from `Backend` to `Frontend` labeled `200 Ok`.
5. **UI Transition:** Select **Reply Message** from `Frontend` to `User` labeled `Redirect to Profile`.

### Step 5: Routing Messages inside the Lower Operand (`[Invalid Cred]`)
1. **Missed Record Return:** Select **Reply Message** from `Database` back to `Backend` labeled `Not found`.
2. **Error Response:** Select **Reply Message** from `Backend` to `Frontend` labeled `401 Unauthorized`.
3. **Client Notification:** Select **Reply Message** from `Frontend` to `User` labeled `Wrong Pass or Email`.
