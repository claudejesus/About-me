var screen = document.getElementById("displayBox");

function handleSeven(){
  screen.value += document.getElementById("seven").value;
console.log(screen.value);
}

function handleEight(){
  screen.value += "8";
}

function handleNine(){
  screen.value += "9";
}

function handleDivision(){
  screen.value += "/";
}

function handleFour(){
  screen.value += "4";
}

function handleFive(){
  screen.value += "5";
}

function handleSix(){
  screen.value += "6";
}

function handleMultiplication(){
  screen.value += "*";
}

function handleOne(){
  screen.value += "1";
}

function handleTwo(){
  screen.value += "2";
}

function handleThree(){
  screen.value += "3";
}

const handleAddition = () => {
  screen.value += "+";
}

function handleZero(){
  screen.value += "0";
}

function handleDot(){
  screen.value += ".";
}

function handleMinus(){
  screen.value += "-";
}

function handleClear(){
  screen.value = ""
}

function handleEqual(){
  const result = eval(screen.value)
  screen.value = result;
}
