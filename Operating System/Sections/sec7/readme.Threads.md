<p dir="rtl">

# 📘 **Session 7 – Multithreading Session**

## Table of Contents

* يعني إيه Thread
* مميزات الـ Multithreading
* الـ Multicore Challenges
* Models المختلفة
* Thread Libraries
* مشاكل الـ Threads
---

## **1. Introduction to Multithreading**

الـ **Thread** هو أصغر وحدة تنفيذ داخل الـ **Process**.
الـ Process ممكن يحتوي كذا Thread كلهم بيشاركوا نفس الـ **address space** ونفس الـ **resources**، وده بيسمح بتنفيذ **parallelism** و **concurrency**.

ليه بنحتاج الـ Threads؟
لأن فيه تطبيقات كتير محتاجة تنفّذ أكتر من مهمة في نفس الوقت، زي:

* السيرفرات
* تطبيقات الـ GUI
* الألعاب
* أنظمة الـ Real-Time

---
## **2. Benefits of Multithreading**

### **2.1.1 Why Threads Are Better Than Processes**

رغم إن الـ **Processes** قوية ومستقلة، لكن الـ **Threads** أحسن في حاجات كتير:

* التواصل بين الـ Threads أسهل وأسرع لأنها بتشارك نفس الـ **address space**، لكن الـ Processes بتحتاج **IPC (Inter-Process Communication)** وده أبطأ ومعقد.
* الـ Process ليه **PCB (Process Control Block)** كبير فيه كل حاجة تخصه، بينما الـ Thread ليه TCB صغير وخفيف، فالتعامل معاه أسرع.
* الـ Context Switching بين Threads أخف من الـ Switching بين Processes.

### **2.1 Responsiveness**

وجود أكتر من Thread بيخلي الواجهة (UI) تفضل شغالة حتى لو فيه Thread تاني بيعمل شغل تقيل.
مثال: اللابتوب ما بيهنّجش وهو بيعمل Download لأن المهام موزعة على Threads.

---

### **2.2 Resource Sharing**

الـ Threads داخل نفس الـ Process بيشاركوا:

* نفس الـ memory
* نفس الـ code
* نفس الـ data

وده بيخلّي تبادل البيانات أسهل من الـ **Processes** اللي بتحتاج **IPC – Inter-Process Communication**.

---

### **2.3 Economy (Lightweight Execution)**

إنشاء Thread أرخص بكتير من إنشاء Process لأن الـ Thread مش بيعمل:

* new memory allocation
* copying PCB
* ومش بيعمل إنشاء address space جديدة

عشان كده بنقول إن الـ Threads **Lightweight**.

---

### **2.3.1 Why Threads Don’t Allocate New Address Space**

الـ **Thread** جزء من الـ **Process**، مش كيان مستقل.
وعشان كده:

* كل Threads جوه نفس الـ Process بيستخدموا **نفس الـ address space** اللي اتعملت للـ Process الأصلي.
* لو كل Thread كان هيعمل address space لوحده، يبقى هو كده Process جديد مش Thread.
* هدف الـ Thread أصلاً إنه يكون "lightweight" ويشارك الـ resources بدل ما يعيد تكوينها.

فالمعالج ما بيخصصلوش Memory جديدة… بياخد من نفس مساحة الـ Process.

---
### **2.4 Utilization of Multiprocessor Architectures**

الـ Multicore CPU بيقدر يشغّل أكتر من Thread في نفس الوقت على Cores مختلفة → أداء أعلى بكتير.


#### إيه الفرق بين Multicore vs Multiprocessor؟

النقطة دي موجودة لأنها بتشرح **أكبر فائدة للـ Multithreading**:
إنك تقدر تستغل كل Core في المعالج بدل ما تنفّذ كل حاجة بالتسلسل.

المعالج اللي فيه أكتر من Core يقدر يشغّل أكتر من Thread **في نفس اللحظة** (Parallelism).
وده أهم سبب نعمل Multithreading أصلاً.

| المصطلح                   | المعنى                                              | مثال                        |
| ------------------------- | --------------------------------------------------- | --------------------------- |
| **Multicore Processor**   | معالج واحد فيه **أكتر من Core** كله في شريحة واحدة  | Core i7 Quad-Core           |
| **Multiprocessor System** | جهاز فيه **أكتر من معالج مستقل** (أكتر من CPU فعلي) | Servers فيها 2 أو 4 معالجات |

**باختصار:**
Multicore = Processor واحد بكذا Core
Multiprocessor = جهاز فيه أكثر من Processor

والـ Threads تشتغل على الاتنين، بس الـ Multicore هو اللي منتشر في اللابتوبات.

---

## **3. Multicore Programming**

### **3.1 What Multicore Means**

معالج فيه أكتر من **Core**.
كل Core يعتبر processor صغير مستقل، وده بيسمح بتنفيذ parallel threads.

---

### **3.2 Challenges of Multicore Programming**

#### **3.2.1 Dividing Activities**

لازم يقسم الـ tasks لجزء ينفع يتنفّذ في Thread مستقل.

#### **3.2.2 Balance**

لازم يوزّع المهام بحيث مفيش Core تبقى محمّلة زيادة عن اللزوم.

##### **3.2.2.1 Load Balancing Criteria**

التوزيع مش حسب الوقت ولا الحجم بس… هو مزيج من:

1. **Workload amount**
   كمية الشغل اللي الـ Thread محتاج يعملها (Computation).

2. **Thread priority**
   لو في Threads أهم من غيرها.

3. **Core availability**
   لو في Core فاضية أو عليها ضغط أقل.

4. **Execution time**
   لو Thread بتاخد وقت طويل، ممكن نحط معاها Thread خفيفة.

الهدف النهائي؟
ولا Core تبقى **Overloaded** والباقي فاضي.
عشان ده يسبب **performance drop**.
<br>
<br>
#### **3.2.3 Data Splitting**

البيانات المشتركة بين الـ Threads لازم تتقسّم صح.

##### **3.2.3.1 Why Data Splitting Is a Challenge**

لما Threads تشارك نفس البيانات:

* لازم تقسم البيانات بحيث كل Thread يشتغل على جزء واضح.
* ممنوع Thread تلمس Data Thread تاني من غير تنظيم.
* لو التقسيم غلط → يحصل تضارب، ويظهر **race condition**.

يعني لو عندك Array، ومش مقسماه صح:
Thread ممكن تكتب فوق بيانات Thread تاني → البرنامج يبوظ.
<br><br>

#### **3.2.4 Testing and Debugging**

البرامج اللي فيها multithreading أصعب في الاختبار وبتسبب مشاكل زي **race conditions**.
#### **3.2.4.1 Why Multithreading Makes Testing Hard**

المشاكل هنا مش بسبب الـ threads نفسها، لكن بسبب **السلوك غير المتوقع**:

1. **Race Condition**
   بيظهر بس في توقيت معين.
   ممكن يبان مرة و10 لأ → difícil جدًا تكراره.

2. **Timing Issues**
   ترتيب التنفيذ مش ثابت → كل Run مختلف.

3. **Synchronization Bugs**
   لو نسيتي Lock أو حطيتي Lock غلط → البرنامج يهنّج أو يحصل Deadlock.

4. **Interleaving**
   صعب تعرفي مين Thread نفّذ إيه الأول.

عشان كده، اختبار برامج Multithreaded بيكون أصعب بكتير من Single-threaded.

---

## **4. Multithreading Models**

### **4.1 Many-to-One Model**

كل الـ **user threads** بتتنفذ على **kernel thread** واحد.
عيوبه:

* مفيش parallelism على Multicore
* لو kernel thread اتعمله block → الكل يتوقف

---

### **4.2 One-to-One Model**

كل **user thread** يقابله **kernel thread**.
مميزاته:

* يدعم parallelism
* أداء أفضل
  عيوبه:
* مكلف من حيث الموارد

---

### **4.3 Many-to-Many Model**

عدة **user threads** ترتبط بعدد أقل أو مساوي من **kernel threads**.
ده أفضل Model لأنه:

* بيدعم parallelism
* بيدي مرونة
* بيقلل overhead

---

## **5. Thread Libraries**

### **5.1 POSIX Threads (Pthreads)**

API بتشتغل على UNIX/Linux.
بتوفر أوامر:

* create
* join
* cancel
* synchronize

---

### **5.2 Windows Threads**

جزء من Windows API.
بيدي تحكم كامل في الـ Threads على Windows OS.

---

### **5.3 Java Threads**

مبنية فوق JVM.
سهلة لأنها built-in في Java.

---

## **6. Common Threading Issues**

### **6.1 Race Condition**

يحصل لما أكتر من Thread يحاول يعدّل نفس الـ shared data في نفس الوقت.

---

### **6.2 Deadlock**

يحصل لما Thread يستنى مورد ماسكه Thread تاني، والاتنين يفضلوا واقفين.

---

### **6.3 Starvation**

Thread ما بياخدش فرصته في التنفيذ لأن scheduler دايمًا يدي غيره الأولوية.

---

## **7. Tasks**

### **Task 1:**

Explain the difference between **one-to-one** and **many-to-one** threading models.

### **Task 2:**

Give two real examples where **responsiveness** is important in multithreaded applications.

### **Task 3:**

List three challenges of **multicore programming**.

### **Task 4:**

Define **race condition** in your own words.

---
</p>
