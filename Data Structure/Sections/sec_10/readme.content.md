<p dir="rtl">
  
# Session 10 - Graphs – Terminology & Traversal

## 1. What is a Graph?
الجراف **Graph** هو تمثيل رياضي/تصويري لعلاقات بين عناصر.

- **V (Vertices / Nodes)**
  
كل نقطة بنسميها **vertex** أو **node**.

- **E (Edges / Arcs)**
  
مجموعة الروابط بين الـ vertices، كل رابط اسمه **edge** أو **arc**.

بالتالي:
> Graph G = (V, E)

---

## 2. Types of Graphs

### 2.1 Directed Graph (Di-Graph)
فيه الـ **edges** ليها اتجاه  
يتم تمثيلها كده: `(u, v)`
- `u` → origin  
- `v` → destination  

### 2.2 Undirected Graph
الـ **edge** ملوش اتجاه  
`{u, v}` معناها الرابط رايح جاي بين الاتنين.

### 2.3 Mixed Graph
فيه **directed edges** و **undirected edges** مع بعض.

---

## 3. Basic Graph Terminology

**End-vertices**:
- هما الطرفين بتوع الـ **edge**.

**Adjacent vertices**:
- نقطتين بينهم **edge** مباشر،. خلي بالك صفة ال Adjacent مش بتستخدم إلا لل nodes.

**Incident (ملامسة) edge**:
- الـ edge بتكون incident (ملامسة) على verte، وخلي بالك صفة ال Incident إلا لل edges.

**Outgoing edges**:
- في الـ directed graph: الـ edges الخارجة من الـ vertex.

**Incoming edges**:
- في الـ directed graph: الـ edges الداخلة للـ vertex.

---

## 4. Degree Concepts

**Degree – deg(v)**
- عدد الـ edges المتصلة بـ vertex v.

https://i0.wp.com/www.mathbootcamps.com/wp-content/uploads/graph-with-labelled-vertices-showing-all-vertex-degrees-2.png?w=602&ssl=1

**Out-degree – outdeg(v)**  
- عدد الـ edges الخارجه من النود، وده في الديريكتيد جراف.

**In-degree – indeg(v)**  
- عدد الـ edges الي داخله لنود، وده في الديريكتيد جراف.

---

## 5. Special Edge Types

**Parallel edges (Multiple edges)**  
- أكتر من edge بين نفس الـ vertices.

**Self-loop**
- الـ edge راجعة لنفس الـ vertex.

**Simple Graph**  
مفيهوش:
  - parallel edges  
  - self-loops  

---

## 6. Important Properties

### 6.1 Undirected Graph
لو الجراف فيه `m` edges:
- Σ deg(v) = 2m

### 6.2 Directed Graph
لو فيه `m` edges:
- Σ indeg(v) = m Σ outdeg(v) = m

### 6.3 Maximum Number of Edges (Simple Graph)
- Directed:

m ≤ n(n − 1)

- Undirected:

m ≤ n(n − 1) / 2

يعني:
> A simple graph has O(n²) edges at most.

---

## 7. Paths & Connectivity

**Path**  
- تسلسل vertices متصلة ببعض.

**Simple Path**  
- مفيش vertex بتتكرر.

**Cycle**
- الـ path بيبدأ وينتهي بنفس vertex.

**Directed Path / Cycle**  
- كل الـ edges فيه directed.

**Subgraph**  
- جزء من الجراف.

**Spanning Subgraph**
- الـ subgraph فيه كل الـ vertices.

---

## 8. Connected Graphs

**Connected Graph**  
- أي vertex يوصل لأي vertex تاني بـ path.

**Connected Component**  
- أكبر جزء connected داخل graph مش connected بالكامل.

---

## 9. Trees & Forests

**Forest**
- الـ graph من غير cycles.

**Tree**  
- الـ connected forest.

**Spanning Tree**  
- الـ tree يحتوي كل vertices الجراف.

### Properties:
لو `n` vertices و `m` edges:

- Connected graph → `m ≥ n − 1`
- Tree → `m = n − 1`
- Forest → `m ≤ n − 1`

---

## 10. Graph Traversal

### 10.1 Depth First Search (DFS)
الـ DFS بيمشي **deep** الأول  
ويستخدم **Stack**

**Idea:**
- نغوص في الجراف على الآخر، ولما نقف نرجع خطوة خطوة.

**Rules (DFS):**
1. Visit an unvisited adjacent vertex, mark it visited, push it to stack.
2. If no adjacent unvisited vertex, pop from stack.
3. Repeat until stack is empty.

---

### 10.2 Breadth First Search (BFS)
الـ BFS بيمشي **level by level**  
ويستخدم **Queue**

**Idea :**
نمشي عرضي، نزور كل الجيران الأول قبل ما نغوص.

**Rules (BFS):**
1. Visit an unvisited adjacent vertex, mark it visited, enqueue it.
2. If no adjacent unvisited vertex, dequeue.
3. Repeat until queue is empty.

---

## 11. DFS vs BFS (Quick Comparison)

| Feature | DFS | BFS |
|------|----|----|
| Data Structure | Stack | Queue |
| Strategy | Depth first | Level order |
| Use Case | Detect cycles, paths | Shortest path (unweighted) |

---

## Tasks

1. Define Graph, Vertex, and Edge in your own words.
2. Draw a simple undirected graph with 5 vertices and label all degrees.
3. Convert an undirected graph into a directed graph and compute indeg & outdeg.
4. Given a graph, identify if it is a tree or not and justify.
5. Trace DFS order starting from vertex A.
6. Trace BFS order starting from the same vertex.

 </p>
