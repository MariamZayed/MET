
# 🎯 Bootstrap Task – Portfolio Styling

## 🧩 المطلوب
هتستخدم **Bootstrap** عشان تحول الـ HTML اللي عملته قبل كده إلى Portfolio شكله احترافي زي الصورة.

---

## 📦 Step 0: ربط Bootstrap

### 🟢 الطريقة 1 (CDN)
حط اللينك ده جوه `<head>`:

```html
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/css/bootstrap.min.css" rel="stylesheet">
````

---

### 🟢 الطريقة 2 (Local Folder)

لو عندك فولدر اسمه `bootstrap-5.3.5-dist` على Desktop:

1. انسخ الفولدر جوه المشروع
2. اربط الـ CSS كده:

```html
<link rel="stylesheet" href="bootstrap-5.3.5-dist/css/bootstrap.min.css">
```

---

## 🧱 Step 1: استخدام Container

📌 الهدف: تنظيم الصفحة

### المطلوب:

1. لف كل الـ body جوه div:

```html
<div class="container mt-5">
```

2. جرب كمان:

* `container-fluid` (full width)

---

## 🧭 Step 2: Navbar

📌 بدل الـ unordered list

### المطلوب:

1. اعمل Navbar باستخدام:

```html
<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
```

2. جوه الـ navbar:

* `container`
* `navbar-brand` → اسمك
* `navbar-nav` → اللينكات

3. خلي اللينكات:

* Home
* Projects
* Contact

4. استخدم:

* `nav-item`
* `nav-link`

---

## 🧍‍♂️ Step 3: Header Section

📌 تنسيق الاسم + القسم

### المطلوب:

1. لف الاسم والقسم في div:

```html
<div class="text-center my-5">
```

2. خلي:

* الاسم: `display-4`
* القسم: `lead text-muted`

---

## 🧩 Step 4: About Me Section باستخدام Grid

📌 الهدف: صورة + نص جنب بعض

### المطلوب:

1. اعمل:

```html
<div class="row align-items-center">
```

2. قسمها لعمودين:

* العمود الأول (الصورة):

```html
<div class="col-md-4 text-center">
```

* العمود الثاني (النص):

```html
<div class="col-md-8">
```

3. للصورة:

* `img-fluid`
* `rounded-circle`
* `shadow`

---

## 📦 Step 5: استخدام Cards (اختياري تحسين)

📌 لف الـ About Me في Card

### المطلوب:

1. استخدم:

```html
<div class="card p-4 shadow">
```

---

## 📬 Step 6: Contact Form Styling

📌 تحسين الفورم

### المطلوب:

1. لف الفورم:

```html
<div class="row justify-content-center">
```

2. خلي الفورم في عمود:

```html
<div class="col-md-6">
```

3. لكل input:

* استخدم `form-control`

4. لكل label:

* استخدم `form-label`

5. لف كل عنصر في:

```html
<div class="mb-3">
```

---

## 🔘 Step 7: Button Styling

📌 تحسين زرار Send

### المطلوب:

1. استخدم:

```html
<button class="btn btn-primary w-100">Send</button>
```

2. جرّب ألوان مختلفة:

* `btn-success`
* `btn-danger`
* `btn-outline-dark`

---

## 📏 Step 8: Spacing & Utilities

📌 تحسين المسافات

### المطلوب:

استخدم:

* `mt-5` → margin top
* `mb-3` → margin bottom
* `p-3` → padding
* `text-center`
* `shadow`
* `rounded`

---

## 🎯 Step 9: Final Touch

### المطلوب:

1. خلي كل section بينها مسافة
2. استخدم `<hr>` أو Bootstrap spacing بدلها
3. خلي التصميم:

* Responsive (جرب تصغر الشاشة)
* متناسق

---

## ✅ Tasks (Required)

1. Add Bootstrap using CDN or local folder
2. Wrap the page inside a container
3. Replace the list with a Bootstrap navbar
4. Style the header using Bootstrap typography classes
5. Use grid system to align image and text
6. Style the image using Bootstrap classes
7. Convert About Me section into a card
8. Style the form using Bootstrap form classes
9. Style the button with different Bootstrap styles
10. Apply spacing utilities across the page
11. Make the layout responsive

---

