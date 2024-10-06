function main() {
    let a = 1;
    function f() {
        console.log(a)
    }
    a = 2;
    f();
}

main();