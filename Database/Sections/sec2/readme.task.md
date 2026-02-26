- For those how doesn't own laptop, insert these quiries into the online sql editor then do your task
- Then start task from number 2
<pre>
    CREATE TABLE Staff (
    staffNo VARCHAR(5) PRIMARY KEY,
    fName VARCHAR(20),
    lName VARCHAR(20),
    city VARCHAR(20),
    position VARCHAR(20),
    salary INT,
    branchNo VARCHAR(5)
);
</pre>

<pre>
INSERT INTO Staff VALUES
('s1','Gad','Ahmed','Tanta','Manager',60000,'B02'),
('s2','Samy','Tamer','Cairo','Assistant',30000,'B02'),
('s3','Samy','Ahmed','Tanta','Supervisor',50000,'B01'),
('s4','Tamer','Samir','Giza','Manager',40000,'B03');
</pre>
<hr> <br> <br>

<h1>Week one Task:</h1>

**1.** Create DB named ```met``` with table named ```staff```, and insert the following data
<img width="620" height="401" alt="db" src="https://github.com/user-attachments/assets/ec965cc9-ebf3-4c9c-8d7e-fdc9a51b852d" />


---

**2.** Write an SQL query to retrieve all columns and all rows from the `Staff` table **without using `*`**.

---

**3.** Write an SQL query to display only the following columns:
`staffNo`, `fName`, `position`, and `salary`.

---

**4.** Write an SQL query to list all unique cities where staff members live.

---

**5.** Write an SQL query to display:

* `staffNo`
* `fName`
* `lName`
* yearly salary increased by 10%

Name the calculated column `increasedSalary`.

---

**6.** The `SELECT` statement automatically removes duplicate rows unless `ALL` is specified.
(   ) True
(   ) False

---

**7.** Which clause is used to remove duplicate rows?
A) WHERE
B) GROUP BY
C) DISTINCT
D) ORDER BY

---

**8.** What will be the output column name in this query (if no alias is used)?

```sql
SELECT salary/12
FROM Staff;
```
A) salary
B) monthlySalary
C) col4 (or system-generated name)
D) 12

---
**9.** Can you write a query includes ```distinct city``` beside other columns? and state why not. 
<hr>
