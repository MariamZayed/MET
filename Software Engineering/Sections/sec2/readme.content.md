# Gantt Chart in Microsoft Excel  

## Example
 <img src="./../../images/img2-1.png" alt="alt text" width="500">


## 1. Understanding & Calculating Precedence (Earliest Start Time)

### What Does "Precedence" Mean?
In project management, **Precedence** defines task dependencies (الأسبقية أو الاعتمادية بين المهام):
* **Dependency Definition:** Identifies which predecessor task(s) must complete before an activity can start.
* **Offset Value (`Precedence`):** Represents the **Earliest Start Time ($ES$)** in days from project kick-off.

### Core Calculation Formulas

$$
\text{End Time} = \text{Start Time} + \text{Duration}
$$

$$
\text{Start Time (Precedence)} = \max(\text{End Times of all immediate predecessor tasks})
$$

> *Note:* If an activity has no predecessor (`NONE`), its Start Time is set to $0$.

---

### Step-by-Step Dependency Table (Activities A–J)

| Activity | Dependencies | Calculation Logic | Start Time (`Precedence`) | Duration (`Time`) | End Time |
| :---: | :---: | :--- | :---: | :---: | :---: |
| **A** | NONE | Starts at project kickoff ($0$) | **0** | 40 | $0 + 40 = 40$ |
| **B** | NONE | Starts at project kickoff ($0$) | **0** | 20 | $0 + 20 = 20$ |
| **C** | A, B | $\max(\text{End}_A, \text{End}_B) = \max(40, 20)$ | **40** | 15 | $40 + 15 = 55$ |
| **D** | A | $\text{End}_A = 40$ | **40** | 25 | $40 + 25 = 65$ |
| **E** | C | $\text{End}_C = 55$ | **55** | 15 | $55 + 15 = 70$ |
| **F** | A, B | $\max(\text{End}_A, \text{End}_B) = \max(40, 20)$ | **40** | 25 | $40 + 25 = 65$ |
| **G** | F | $\text{End}_F = 65$ | **65** | 10 | $65 + 10 = 75$ |
| **H** | G | $\text{End}_G = 75$ | **75** | 15 | $75 + 15 = 90$ |
| **I** | G | $\text{End}_G = 75$ | **75** | 10 | $75 + 10 = 85$ |
| **J** | I | $\text{End}_I = 85$ | **85** | 15 | $85 + 15 = 100$ |

---

## 2. Prepare the Excel Data Sheet

Set up your table in Excel with three clear columns:

| Activities | Precedence | Duration |
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

## 3. Step-by-Step Implementation in Excel 2024

### Step 1: Insert the 2-D Stacked Bar Chart
1. Highlight only the **Precedence** column values along with its header (e.g., `B1:B11`).
2. Navigate to the ribbon: **Insert** $\rightarrow$ **Charts** group.
3. Click the **Insert Column or Bar Chart** icon.
4. Under the **2-D Bar** section, select **Stacked Bar** *(Do NOT select Stacked Column; Gantt charts require horizontal bars)*.

---

### Step 2: Add the Duration Series
1. Right-click anywhere in the chart area and select **Select Data...**.
2. Under **Legend Entries (Series)** on the left, click **Add**:
   * **Series name:** Click the column header cell `Duration`.
   * **Series values:** Clear any default values (`={1}`), then select the numeric values in the `Duration` column (e.g., `C2:C11`).
3. Click **OK**.

---

### Step 3: Map the Task Category Axis (A, B, C...)
*(Prevents sequential numbers 1, 2, 3... from showing on the axis)*

1. While still inside the **Select Data Source** dialog, look at the right side under **Horizontal (Category) Axis Labels**.
2. Click **Edit**.
3. In the **Axis label range** field, select the letters `A` through `J` (e.g., `A2:A11`, excluding the table header).
4. Click **OK**, then click **OK** again to close the dialog.

---

### Step 4: Hide the Precedence Bars (Float the Durations)
1. In the chart, click once on the first bar series (**Precedence**) to select all starting segments.
2. Right-click and choose **Format Data Series...** to open the side pane.
3. In the **Format Data Series** pane, select the **Fill & Line** tab (paint bucket icon):
   * Under **Fill**, select **No fill**.
   * Under **Border**, select **No line**.

---

### Step 5: Adjust Vertical & Horizontal Axes (Match Target Style)

#### A. Invert Vertical Categories (A at Top, J at Bottom)
1. Right-click on the vertical axis containing task names (`A, B, C...`) and select **Format Axis...**.
2. In the right pane under **Axis Options** (bar graph icon):
   * Check **Categories in reverse order**.

#### B. Reverse Horizontal Scale (0 on Right $\rightarrow$ 120 on Left)
1. Right-click on the numeric axis (`0, 20, 40...`) and select **Format Axis...**.
2. In the right pane under **Axis Options**:
   * Check **Values in reverse order**.
   * Under **Units**, set **Major** to `20` (to establish intervals of $0, 20, 40, \dots, 120$).
   * Under **Bounds**, set **Minimum** to `0` and **Maximum** to `120`.

---

## 4. Common Troubleshooting Tips

* **Bars are standing vertically instead of horizontally:**
  * You selected *Stacked Column* instead of *Stacked Bar*.
  * *Fix:* Right-click the chart $\rightarrow$ **Change Chart Type...** $\rightarrow$ select **Bar** $\rightarrow$ choose **Stacked Bar** $\rightarrow$ **OK**.
* **Vertical axis displays numbers (1, 2, 3...) instead of task letters:**
  * Excel defaulted to row index numbers.
  * *Fix:* Right-click chart $\rightarrow$ **Select Data** $\rightarrow$ Edit **Horizontal (Category) Axis Labels** $\rightarrow$ select your task names range (`A` to `J`).
* **Task letters appear at the bottom/top edge rather than the side:**
  * Check the **Labels** section in the **Format Axis** pane and verify that **Label Position** is set to **Next to Axis** or **High/Low** relative to reversed orientation.