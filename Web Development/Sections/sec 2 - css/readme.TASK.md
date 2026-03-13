# Task: Styling the Academic Portfolio with External CSS

## Objective

Create an external CSS file (`style.css`) to style the HTML portfolio page 

You must **not use inline styles or internal styles**. <br> 
All styling must be written in the external CSS file.

---

# Requirements

## 1. General Page Styling (body)

Apply the following styles body (to the whole page):

* Set a **background color or gradient** for the page.
* Change the **default font family**.
* specify styling for each p in the body

Body Properties:

* `font-family` 
    - choose whatever fonts you like
* `background-color`<br>
    use one neutral color like 
    <ul style="list-style-type:square;">
        <li>  rgb(255, 230, 230) for girls </li>
        <li>  rgb(230, 230, 255) for men </li>
        <li>  background: linear-gradient(to right, #eef2f3, #d9e2ec) Or use this</li>
    </ul>
* `line-height`
    - make it 1.6
* `text-align`
    - make it center
<br><br>
* for each p tag
    - make color #555
    - font-size 18px
---

## 2. h1 Styling

Style the name and title section in h1.

Requirements:

* Make the `<h1>` larger and more bold.
* Change the color of the title.
* Add **text-shadow** to the main heading.
* Add spacing between letters.

Properties to use:

* `font-size`
* `color`
* `text-shadow`
* `margin`
    - make it margin-top: 30px
* `letter-spacing`
    - make it 2px

---

## 3. Navigation Bar Styling

Convert the `<ul>` navigation into a horizontal menu.

Requirements:

* Remove default list styling.
* Display menu items horizontally.
* Add different background color to navigation.
* Add hover effect.

Properties to use:

* `list-style`
    - make list-style none
* `margin`
    - make margin auto and 20px, to make more space for the nav bar
    - `margin: 20px auto;`
* `padding`
    - make it 0, cause there is a little padding left 
* `background-color`
    - change the color to the same h1 color
* `width`
    - make it for example `60%`
* `border-radius`
    - make it for example `8%`
<br><br>

*  `ul li` 
    - make display `inline-block`
<br><br>

* `ul li a`
    - make it also `inline-block`
    - make space between each link using padding, for example: `12px 25px`
    - change the font color to `white` for example
    - remove the underline in each link using `text-decoration:none;`
    - make the font bold using `font-weight:bold;`
    - use `transition:0.3s;` , this a cool trick will show off when we make hover in the next styling
<br><br>

* `ul li a:hover`
    - when you hover, change the `background-color:#1abc9c;` for example
    - make it go bigger using `transform:scale(1.1);` for example
        - notice, here the previous  `transition:0.3s;` will appear it's effect

---

## 4. Image Styling

Style the profile image.

Requirements:

* Make the image **circular**.
* Add a **border**.
* Center the image.

Properties to use:

* `margin`
    - to make it in the center, we will use again `auto;`. the 20px is to add more space from the up and down  
* `border-radius`
    - to make it circular, make it `50%;`
* `border`
    - for example `4px solid #1abc9c;`

---

## 5. About Section

Improve the readability of the paragraph.

Requirements:

* Increase line spacing.
* Limit text width.
* Justify the text.

Properties to use:
* `h2 + img + p`
    - we want to specify the styling for this particular p tag, not the rest tags
    * `line-height`
        - make it `1.8` for example
    * `max-width`
        - make it `600px` for example
    * `text-align`
        - make it `justify`
    * `margin`
        - to make it in the center of the page, use `auto`

---

## 6. Contact Form Styling

Style the form fields.<br>
Do this without illustration.
Requirements:

* Inputs should have padding.
* Add border and rounded corners.
* Style the submit button differently.
* Add hover effect to the button.

Properties to use:

* `padding`
* `border`
* `border-radius`
* `background`
* `cursor`
* `:hover`

