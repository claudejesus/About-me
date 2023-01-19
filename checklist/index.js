const form = document.getElementById('todo-form');
const todo = document.getElementById('todo-input');
const todoList = document.getElementById('todo-list');
const clearDone = document.querySelector('.clear-done');
const clearAll = document.querySelector('.clear-all');

function currentData(){
    return JSON.parse(localStorage.getItem('todos') || '[]');
}

function getId(){
    return currentData().length + 1;
}

function clean(){
    todo.value = '';
}

function remove(id){
    const data = currentData();
    let updated;
    let index = 1;
    updated = data.filter(todo => todo[0] != id);
    for(let i=0; i<updated.length; i++){
        updated[i][0] = index;
        index++;
    }

    localStorage.setItem('todos', JSON.stringify(updated));
    display();
}

function done(id){
    const data = currentData();
    if(data[id-1][2] == false){
        data[id-1][2] = true;
    }else {
        data[id-1][2] = false;
    }
    localStorage.setItem('todos', JSON.stringify(data));
    display();
}

function updateText(id, value){
    const data = currentData();

    data[id-1][1] = value;

    localStorage.setItem('todos', JSON.stringify(data));
    display();
}

form.addEventListener('submit', (e)=>{
    e.preventDefault();
    if(todo.value != ''){
        const newTodo = [getId(), todo.value, false];
        const updateTodo = [...currentData(), newTodo]

        localStorage.setItem('todos', JSON.stringify(updateTodo));
        clean();
        display();
    }
});

function display(){
    const data = currentData();
    let codes = '';

    codes = data.map((todo)=>{
        return `
        <li>
        <img src=${todo[2]== true? "images/true.png" : "images/false.png"} onclick="done(${todo[0]})">
        <input type="text" class=${todo[2]== true? "done": "notdone"} value=${todo[1]} onchange="updateText(${todo[0]}, value)">
        <img src="images/del.png" onclick="remove(${todo[0]})">
        </li>`
    }).join('');

    todoList.innerHTML = codes;
}

clearDone.addEventListener('click', ()=>{
    let data = currentData();
    let updated = data.filter((todo)=>todo[2] == false);
    localStorage.setItem('todos', JSON.stringify(updated));
    display();
})

clearAll.addEventListener('click', ()=>{

    localStorage.removeItem('todos');
    display();
})

display();
