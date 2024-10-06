let a = [1]
function f(a) {
    a = [2, 3]
}

console.log(a)
f(a)
console.log(a)