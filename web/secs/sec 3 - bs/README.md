# 1-  مقدمة عن Bootstrap

## إيه هو Bootstrap؟  
**Bootstrap** هو إطار عمل (**Framework**) مبني على **HTML، CSS، JavaScript**، بيساعدك في تصميم واجهات المستخدم بشكل أسرع وأسهل.  
بدل ما تكتب **CSS** من الصفر، Bootstrap بيوفر لك **كلاسات جاهزة** تقدر تستخدمها مباشرة لتنسيق العناصر.

## ليه نستخدم Bootstrap؟  
- ✅ **يوفر الوقت**: مش محتاج تكتب كود CSS كتير.  
- ✅ **سهل الاستخدام**: كل اللي عليك تضيف الكلاسات المناسبة للعنصر.  
- ✅ **تصميم متجاوب (Responsive)**: بيتكيف تلقائيًا مع أي شاشة (موبايل، تابلت، كمبيوتر).  
- ✅ **متوافق مع المتصفحات**: شغال على كل المتصفحات الحديثة بدون مشاكل.  
- ✅ **يدعم الجافاسكريبت**: فيه مكونات تفاعلية جاهزة زي الـ **Navbar، الـ Modal، الـ Carousel...**  

<br><br>
# 2- إزاي شغال Bootstrap؟  
ببساطة، بيعتمد على **نظام الشبكة (Grid System)** و **كلاسات CSS جاهزة** عشان تقدر تنسق الصفحة بسرعة.  

### 🔸 **بدون Bootstrap (لازم تكتب CSS بنفسك)**
```html
<button style="background-color: blue; color: white; padding: 10px 20px; border: none;">
    اضغط هنا
</button>
```

### 🔹 **باستخدام Bootstrap (كلاس جاهز)**
```html
<button class="btn btn-primary">اضغط هنا</button>
```

## إيه اللي بيقدمه Bootstrap؟  
1. 🎯 **نظام الشبكة (Grid System)**: لتقسيم الصفحة لأعمدة وصفوف بسهولة.  
2. 🎯 **عناصر جاهزة (Components)**: زي الأزرار، الكروت، القوائم، التنبيهات...  
3. 🎯 **تصميم مرن (Utilities)**: زي تغيير الألوان، التباعد، المحاذاة...  

---

## 🔥 ملخص سريع  
✅ Bootstrap = إطار عمل CSS جاهز  
✅ بيوفر عليك كتابة أكواد CSS كتير  
✅ بيدعم التصميم المتجاوب  
✅ فيه عناصر جاهزة بتسهل الشغل  

<br><br>

# 3- إزاي نبدأ؟ (Setup & Installation)

## 1️⃣ تحميل Bootstrap واستخدامه  
فيه 3 طرق تقدر تبدأ بيها مع **Bootstrap**:  

## 🔹 الطريقة الأولى: استخدام CDN (الأسهل والأسرع)  
دي أسهل طريقة لأنك مش محتاج تنزل أي ملفات، كل اللي عليك تضيف الأكواد الجاهزة في ملف **HTML**.  

### **خطوات الاستخدام:**  
1. افتح ملف `index.html`  
2. ضيف أكواد Bootstrap في `<head>` و `<body>` كالتالي:  

```html
<!DOCTYPE html>
<html lang="ar">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bootstrap Setup</title>
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet"> <!-- السطر ده هنا-->
</head>
<body>

    <h1 class="text-center text-primary">مرحبًا بك في Bootstrap!</h1>

    <!-- Bootstrap JavaScript -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"> هنشرح ده قدام</script>
</body>
</html>
```

✅ **مميزات الطريقة دي**:  
- مش هتحتاج تحمل أي ملفات على جهازك.  
- **Bootstrap دايمًا مُحدث**، لأنك بتاخده من الإنترنت مباشرة.  

❌ **عيوبها**:  
- محتاج إنترنت عشان الصفحة تظهر بتنسيق Bootstrap.  

---

## 🔹 الطريقة الثانية: تحميل Bootstrap يدويًا  
1. روح للموقع الرسمي:  
   **[https://getbootstrap.com](https://getbootstrap.com)**  
2. حمّل الملفات المضغوطة (`bootstrap.zip`).  
3. فك الضغط، هتلاقي فولدر فيه:  
   - **css/** → ملفات التنسيق  
   - **js/** → ملفات الجافاسكريبت  
4. اربط الملفات يدويًا في HTML:  

```html
<link rel="stylesheet" href="css/bootstrap.min.css">
<script src="js/bootstrap.bundle.min.js"></script>
```

✅ **مميزاتها**:  
- هتشتغل أوفلاين بدون إنترنت.  
❌ **عيوبها**:  
- محتاج تحمل الملفات يدويًا وتحدثها بنفسك لما ينزل إصدار جديد.  

---

## 🔹 الطريقة الثالثة: استخدام npm (للمطورين المحترفين)  
لو بتشتغل على مشروع كبير باستخدام **Node.js**، تقدر تثبت Bootstrap بالأمر ده:  

```sh
npm install bootstrap
```
وبعدها تستدعي ملف CSS و JS في الكود بتاعك.  

---

## 🔥 ملخص سريع 🚀  
✅ **أسرع طريقة؟** → استخدم **CDN**.  
✅ **محتاجه أوفلاين؟** → حمل الملفات يدويًا.  
✅ **بتشتغل بـ Node.js؟** → استخدم **npm**.  

---

كده انت جاهز تبدأ تشتغل بـ **Bootstrap**! 🎉  

<br>
<br>

# 4- 📌 شرح الـ Grid System في Bootstrap (أهم حاجة!)

### 🔹 ما هو الـ Grid System؟
الـ **Grid System** في Bootstrap هو **نظام شبكي** يساعدك في **تنظيم العناصر في الصفحة بطريقة متجاوبة**. بيعتمد على **صفوف (Rows) وأعمدة (Columns)** لتقسيم الصفحة.

🎯 **هدفه؟**
- يخليك تقدر تقسم التصميم بسهولة بدون كتابة CSS معقد.
- يكون **متجاوب تلقائيًا** مع جميع أحجام الشاشات.

---

### 🔹 مكونات الـ Grid System

#### 1️⃣ `container` أو `container-fluid` (الغلاف الأساسي)
🔹 كل **Grid** لازم يكون جوه عنصر **`container`** أو **`container-fluid`** عشان يكون متناسق مع عرض الصفحة.

```html
<div class="container">  <!-- أو container-fluid -->
    <!-- هنا نحط الـ Rows و Columns -->
</div>
```
✅ **`container`**: بيحافظ على هوامش على الجوانب.  
✅ **`container-fluid`**: بياخد العرض بالكامل.  

---

#### 2️⃣ `row` (الصفوف)
🔹 كل مجموعة من الأعمدة لازم تكون جوه **`row`**، وده بيضمن أن الأعمدة تتعامل مع بعض كوحدة واحدة.

```html
<div class="row">
    <!-- الأعمدة هتتحط هنا -->
</div>
```

---

#### 3️⃣ `col` (الأعمدة)
🔹 بنستخدم **`col`** عشان نقسم الصف لعدد معين من الأعمدة.
- الـ **Bootstrap Grid** مقسّم لـ **12 عمود**، يعني أي تقسيمة لازم مجموعها = **12**.

```html
<div class="row">
    <div class="col-6 bg-primary text-white">عمود 1 (نصف العرض)</div>
    <div class="col-6 bg-success text-white">عمود 2 (نصف العرض)</div>
</div>
```
✅ `col-6` → يعني كل عمود **يأخذ 6 من أصل 12** (يعني نصف الصفحة).  

---

### 🔹 تقسيم الأعمدة (Columns)

| **التقسيمة** | **الشرح** |
|------------|---------|
| `col-12` | عمود واحد يأخذ العرض بالكامل |
| `col-6 + col-6` | عمودين متساويين (كل واحد يأخذ نصف العرض) |
| `col-4 + col-4 + col-4` | 3 أعمدة متساوية (كل واحد يأخذ ثلث العرض) |
| `col-3 + col-3 + col-3 + col-3` | 4 أعمدة متساوية (كل واحد يأخذ ربع العرض) |

🔹 **مثال عملي على تقسيمات مختلفة:**
```html
<div class="container">
    <div class="row">
        <div class="col-4 bg-primary text-white">عمود 1</div>
        <div class="col-4 bg-success text-white">عمود 2</div>
        <div class="col-4 bg-danger text-white">عمود 3</div>
    </div>
</div>
```

---

### 🔹 الـ Grid والاستجابة للشاشات المختلفة
🔹 Bootstrap بيوفر **كلاسات مخصصة** لكل نوع من الشاشات، بحيث تقدر تتحكم في عدد الأعمدة بناءً على حجم الجهاز:  

| **الحجم** | **الكلاس المستخدم** | **وصف** |
|------------|-----------------|-----------|
| Extra Small | `col-` | الموبايلات (أقل من 576px) |
| Small | `col-sm-` | الشاشات الصغيرة (≥576px) |
| Medium | `col-md-` | التابلت (≥768px) |
| Large | `col-lg-` | اللابتوب (≥992px) |
| Extra Large | `col-xl-` | الشاشات الكبيرة (≥1200px) |

🔹 **مثال على تصميم متجاوب:**
```html
<div class="container">
    <div class="row">
        <div class="col-sm-12 col-md-6 col-lg-4 bg-primary text-white">عمود متجاوب</div>
        <div class="col-sm-12 col-md-6 col-lg-4 bg-success text-white">عمود متجاوب</div>
        <div class="col-sm-12 col-md-6 col-lg-4 bg-danger text-white">عمود متجاوب</div>
    </div>
</div>
```

---

### 🔹 محاذاة الأعمدة (Alignment)
Bootstrap بيوفر كلاسات للمحاذاة الرأسية والأفقية للأعمدة داخل الصف.

#### 📌 المحاذاة الأفقية (`justify-content-`)
🔹 للتحكم في **المسافات بين الأعمدة أفقيًا**:

| **الكلاس** | **المعنى** |
|------------|------------|
| `justify-content-start` | محاذاة على اليسار (افتراضي) |
| `justify-content-center` | محاذاة في المنتصف |
| `justify-content-end` | محاذاة على اليمين |
| `justify-content-between` | توزيع الأعمدة مع وجود مسافات متساوية بينها |
| `justify-content-around` | توزيع الأعمدة مع وجود مسافات على الأطراف |

🔹 **مثال عملي**:
```html
<div class="container">
    <div class="row justify-content-center">
        <div class="col-4 bg-primary text-white">عمود في المنتصف</div>
    </div>
</div>
```

---

#### 📌 المحاذاة الرأسية (`align-items-`)
🔹 للتحكم في **المسافات بين الأعمدة رأسيًا**:

| **الكلاس** | **المعنى** |
|------------|------------|
| `align-items-start` | محاذاة في الأعلى |
| `align-items-center` | محاذاة في المنتصف |
| `align-items-end` | محاذاة في الأسفل |

🔹 **مثال عملي**:
```html
<div class="container">
    <div class="row align-items-center" style="height: 200px;">
        <div class="col-4 bg-primary text-white">وسط الصف</div>
    </div>
</div>
```

---

### 🎯 خلاصة الـ Grid System
✔ الـ **Grid** بيتكون من **Container** → فيه **Rows** → وكل Row فيه **Columns**.  
✔ الصفحة مقسمة لـ **12 عمود**، ولازم أي تقسيمة تحترم العدد ده.  
✔ **الكلاسات (`col-sm-`, `col-md-`, `col-lg-`... إلخ)** بتساعد في جعل التصميم **متجاوب مع جميع الشاشات**.  
✔ المحاذاة (`justify-content-` و `align-items-`) تساعد في ترتيب العناصر داخل الشبكة.

<br>
<br>

## أهم الـ Components في Bootstrap

الـ Components في Bootstrap عبارة عن عناصر جاهزة بتوفر لك وظائف وتصميمات جاهزة من غير ما تكتب كود CSS أو JavaScript بنفسك. ودي من أقوى مميزات Bootstrap لأنها بتسهل الشغل جدًا. هنشرح أهم الـ Components اللي هتحتاجها:

### 1. الأزرار (Buttons)
الأزرار في Bootstrap جاهزة بتنسيقات مختلفة، وعشان تعمل زرار، استخدم كلاس `btn` مع ألوان مختلفة زي:

```html
<button class="btn btn-primary">زر رئيسي</button>
<button class="btn btn-secondary">زر ثانوي</button>
<button class="btn btn-success">زر نجاح</button>
<button class="btn btn-danger">زر تحذير</button>
<button class="btn btn-warning">زر تنبيه</button>
<button class="btn btn-info">زر معلومات</button>
<button class="btn btn-light">زر فاتح</button>
<button class="btn btn-dark">زر داكن</button>
```

تقدر تخلي الزرار أكبر باستخدام `btn-lg` أو أصغر باستخدام `btn-sm`.

---

### 2. الأيقونات والتنبيهات (Alerts)
التنبيهات بتستخدم لإظهار رسائل للمستخدم بشكل واضح:

```html
<div class="alert alert-success">عملية ناجحة!</div>
<div class="alert alert-danger">حدث خطأ ما!</div>
<div class="alert alert-warning">تحذير: انتبه لهذا الأمر.</div>
<div class="alert alert-info">معلومة جديدة لك.</div>
```

ممكن كمان تخلي التنبيه قابل للإغلاق:

```html
<div class="alert alert-warning alert-dismissible fade show" role="alert">
    تحذير: هذا إشعار مهم!
    <button type="button" class="btn-close" data-bs-dismiss="alert" aria-label="Close"></button>
</div>
```

---

### 3. الكروت (Cards)
الكروت بتساعدك في عرض المحتوى داخل صندوق منسق بشكل احترافي:

```html
<div class="card" style="width: 18rem;">
    <img src="https://via.placeholder.com/150" class="card-img-top" alt="صورة">
    <div class="card-body">
        <h5 class="card-title">عنوان الكارت</h5>
        <p class="card-text">هذا نص داخل الكارت.</p>
        <a href="#" class="btn btn-primary">اضغط هنا</a>
    </div>
</div>
```

ممكن تضيف `card-header` أو `card-footer` لتنسيق أعلى وأسفل الكارت.

---

### 4. القوائم المنسدلة (Dropdowns)
القوائم المنسدلة بتسمح بعرض خيارات عند الضغط على زر معين:

```html
<div class="dropdown">
    <button class="btn btn-secondary dropdown-toggle" type="button" data-bs-toggle="dropdown">
        القائمة المنسدلة
    </button>
    <ul class="dropdown-menu">
        <li><a class="dropdown-item" href="#">الخيار الأول</a></li>
        <li><a class="dropdown-item" href="#">الخيار الثاني</a></li>
        <li><a class="dropdown-item" href="#">الخيار الثالث</a></li>
    </ul>
</div>
```

---

### 5. المودال (Modal) - النوافذ المنبثقة
المودال بيسمح لك بعرض نافذة منبثقة عند الضغط على زر معين:

```html
<!-- زر يفتح المودال -->
<button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#exampleModal">
    افتح النافذة
</button>

<!-- المودال نفسه -->
<div class="modal fade" id="exampleModal" aria-labelledby="exampleModalLabel" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title" id="exampleModalLabel">عنوان المودال</h5>
                <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="إغلاق"></button>
            </div>
            <div class="modal-body">
                هذا هو محتوى المودال.
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">إغلاق</button>
                <button type="button" class="btn btn-primary">حفظ التغييرات</button>
            </div>
        </div>
    </div>
</div>
```

---

### 6. الـ Navbar (الشريط العلوي للتنقل)
لو عايز تعمل قائمة تنقل احترافية، استخدم الـ Navbar:

```html
<nav class="navbar navbar-expand-lg navbar-light bg-light">
    <div class="container-fluid">
        <a class="navbar-brand" href="#">موقعي</a>
        <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
            <ul class="navbar-nav">
                <li class="nav-item"><a class="nav-link active" href="#">الرئيسية</a></li>
                <li class="nav-item"><a class="nav-link" href="#">حول</a></li>
                <li class="nav-item"><a class="nav-link" href="#">خدمات</a></li>
                <li class="nav-item"><a class="nav-link" href="#">اتصل بنا</a></li>
            </ul>
        </div>
    </div>
</nav>
```

---

### 7. الـ Accordion (القوائم القابلة للطي)
مفيدة لو عندك محتوى طويل وتريد عرضه بطريقة منظمة:

```html
<div class="accordion" id="accordionExample">
    <div class="accordion-item">
        <h2 class="accordion-header">
            <button class="accordion-button" type="button" data-bs-toggle="collapse" data-bs-target="#collapseOne">
                عنوان القسم الأول
            </button>
        </h2>
        <div id="collapseOne" class="accordion-collapse collapse show" data-bs-parent="#accordionExample">
            <div class="accordion-body">
                محتوى القسم الأول.
            </div>
        </div>
    </div>
</div>
```

---

## الخلاصة
- **الأزرار (`btn`)**
- **التنبيهات (`alert`)**
- **الكروت (`card`)**
- **القوائم المنسدلة (`dropdown`)**
- **المودال (النوافذ المنبثقة) (`modal`)**
- **شريط التنقل (`Navbar`) (`navbar`)**
- **القوائم القابلة للطي (`Accordion`) (`accordion`)**

دي أهم الـ Components اللي هتحتاجها، طبعًا Bootstrap فيه مكونات أكتر بكتير، لكن دي الأساسية اللي لازم تع 
