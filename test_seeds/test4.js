// Array methods
let fruits = ["apple", "banana", "orange"];
fruits.push("grape");
print("Fruits:", fruits.join(", "));

// Map and filter
let numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let doubled = numbers.map(x => x * 2);
let evens = numbers.filter(x => x % 2 === 0);

print("Doubled numbers:", doubled);
print("Even numbers:", evens);

// Try-catch error handling
try {
    let result = 10 / 0;
    print("Result:", result);
} catch (error) {
    print("Error caught:", error.message);
}
