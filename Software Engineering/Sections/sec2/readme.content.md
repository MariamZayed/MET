# Gantt Chart in Microsoft Excel  

## Example
 <img src="./../../images/img2-1.png" alt="alt text" width="500">

## 1. Understanding and Calculating Precedence (Earliest Start Time)

### What Does "Precedence" Mean?
In project management, **Precedence** refers to task dependencies (الأسبقية أو المهام السابقة المعتمد عليها). 
* In the dependency definition, it defines which predecessor tasks must finish before an activity can start.
* In the Gantt data table, the numeric value represents the **Earliest Start Time ($ES$)** of the task measured in days from project kick-off.

### The Calculation Rules
$$\text{End Time} = \text{Start Time} + \text{Duration}$$

$$\text{Start Time (Precedence)} = \max(\text{End Times of all immediate predecessor tasks})$$

If an activity has no predecessors (`NONE`), its start time is $0$.

---

### Step-by-Step Breakdown for Activities A–J

| Activity | Dependencies | Calculation Formula / Rule | Start Time (`Precedence`) | Duration (`Time`) | End Time |
| :---: | :---: | :--- | :---: | :---: | :---: |
| **A** | NONE | Starts at day $0$ | **$0$** | 40 | $0 + 40 = 40$ |
| **B** | NONE | Starts at day $0$ | **$0$** | 20 | $0 + 20 = 20$ |
| **C** | A, B | $\max(\text{End}_A, \text{End}_B) = \max(40, 20)$ | **$40$** | 15 | $40 + 15 = 55$ |
| **D** | A | $\text{End}_A = 40$ | **$40$** | 25 | $40 + 25 = 65$ |
| **E** | C | $\text{End}_C = 55$ | **$55$** | 15 | $55 + 15 = 70$ |
| **F** | A, B | $\max(\text{End}_A, \text{End}_B) = \max(40, 20)$ | **$40$** | 25 | $40 + 25 = 65$ |
| **G** | F | $\text{End}_F = 65$ | **$65$** | 10 | $65 + 10 = 75$ |
| **H** | G | $\text{End}_G = 75$ | **$75$** | 15 | $75 + 15 = 90$ |
| **I** | G | $\text{End}_G = 75$ | **$75$** | 10 | $75 + 10 = 85$ |
| **J** | I | $\text{End}_I = 85$ | **$85$** | 15 | $85 + 15 = 100$ |

 <img src="./../../images/img2-3.png" alt="alt text" width="500">

---

## 2. Prepare Your Excel Table

Organize your data in Excel into three columns using the calculated values:

| Activities | Precedence | Time |
| :---: | :---: | :---: |
| A | 0 | 40 |
| B | 0 | 20 |
| C | 40 | 15 |
| D | 40 | 25 |
| E | 55 | 15 |
| F | 40 | 25 |
| G | 65 | 10 |
| H | 75 | 15 |
| I | 75 | 10 |
| J | 85 | 15 |

---

## 3. Insert the Stacked Bar Chart

1. Select only the **Precedence** values with their header.
2. Go to the **Insert** tab on the Excel ribbon.
3. In the **Charts** group, click on **Bar**.
4. Choose **Stacked Bar** (the second option under **2-D Bar**).

---

## 4. Add Duration (`Time`) and Assign Task Labels

1. Right-click anywhere inside the chart area and select **Select Data...**.

### A. Add Duration Data
2. Under **Legend Entries (Series)** on the left side, click **Add**:
   * **Series name:** Click cell header `Time` (or enter `"Time"`).
   * **Series values:** Select the numeric cells in the **Time** column (`40` down to `15`).
   * Click **OK**.

### B. Map Task Labels (Fixing the 1, 2, 3... Issue)
3. Under **Horizontal (Category) Axis Labels** on the right side, click **Edit**:
   * **Axis label range:** Select the cells containing task names (`A` through `J`, omitting the header).
   * Click **OK**.
4. Click **OK** again to exit the dialog.

---

## 5. Make the Precedence Bars Transparent

1. Left-click once on the first set of bars (the **Precedence** bars) to select all of them.
2. Right-click on the selected bars and choose **Format Data Series...**.
3. In the formatting pane/window:
   * Go to **Fill** $\rightarrow$ select **No fill**.
   * Go to **Border Color** $\rightarrow$ select **No line**.
4. *(Optional)* Click on the remaining **Time** bars, navigate to **Fill**, select **Solid fill**, and pick your preferred color (e.g., Brick Red).

---

## 6. Adjust the Axes to Match the Layout

### A. Reverse the Task Order (A at top, J at bottom)
1. Right-click the **Vertical Axis** (the activity letters A–J) and click **Format Axis...**.
2. Under **Axis Options**, check **Categories in reverse order**.

### B. Set Axis Direction and Step Intervals
1. Right-click the **Horizontal Axis** (the numeric timeline axis) and select **Format Axis...**.
2. Check **Values in reverse order** *(to match layouts where the timeline counts right-to-left starting at 0 on the right)*.
3. Under **Axis Options**:
   * Set **Minimum** to `0`.
   * Set **Maximum** to `120` (or `100`).
   * Set **Major unit** to `20` to display intervals of 20 units ($0, 20, 40, 60, \dots$).
4. Close the dialog.

---

## Troubleshooting

### Why does the vertical axis display numbers (1, 2, 3...) instead of task names (A, B, C...)?
By default, Excel assigns sequential row indices if the category axis range is omitted.
* **Fix:** Right-click chart $\rightarrow$ **Select Data** $\rightarrow$ Under **Horizontal (Category) Axis Labels**, click **Edit** $\rightarrow$ Select cells `A` through `J` $\rightarrow$ Click **OK**.

## Output 
 <img src="./../../images/img2-2.png" alt="alt text" width="500">
