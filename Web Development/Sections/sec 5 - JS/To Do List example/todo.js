document.addEventListener("DOMContentLoaded", function() {
    const taskInput = document.getElementById("taskInput");
    const addTaskBtn = document.getElementById("addTaskBtn");
    const taskList = document.getElementById("taskList");

    // إضافة تاسك جديد
    addTaskBtn.addEventListener("click", function() {

        // if empty
        const taskText = taskInput.value.trim(); // trim() بتشيل أي مسافات زياده قبل بداية ونهاية التكست المكتوب

        if (taskText === "") {
            alert("Please enter a task!");
            return;
        }

        // add new task
        const li = document.createElement("li");
        li.innerHTML = `
            <span class="task">${taskText}</span>
            <button class="delete-btn">X</button>
        `;

        // حذف المهمة عند الضغط على زر X
        li.querySelector(".delete-btn").addEventListener("click", function() {
            li.remove();
        });

        // بعد ماخلصنا هنفوله يضيفها جوا ال ul 
        taskList.appendChild(li);

        // نفرغ الانبوت بعد مانعمله اضافع
        taskInput.value = ""; 
    });
    
    // change color 
    HelloWorldBtn.addEventListener("click",function(){
        document.getElementById("HelloWorld").setAttribute("class", "newClass");
    })
});

