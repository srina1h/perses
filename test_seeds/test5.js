// Class definition
class Calculator {
    constructor() {
        this.history = [];
    }
    
    add(a, b) {
        let result = a + b;
        this.history.push(`${a} + ${b} = ${result}`);
        return result;
    }
    
    subtract(a, b) {
        let result = a - b;
        this.history.push(`${a} - ${b} = ${result}`);
        return result;
    }
    
    getHistory() {
        return this.history;
    }
}

// Using the class
let calc = new Calculator();
print("Addition result:", calc.add(15, 7));
print("Subtraction result:", calc.subtract(20, 8));
print("History:", calc.getHistory());

// Date operations
let now = new Date();
print("Current date:", now.toDateString());
print("Current time:", now.toTimeString());
