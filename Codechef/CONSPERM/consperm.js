const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = 0;
let currentTestCase = 0;
let inputs = [];

// Read all input data
rl.on('line', (input) => {
    inputs.push(input.trim());
    currentTestCase++;

    if (currentTestCase === 1) {
        testCases = parseInt(input); 
    }

    if (currentTestCase === testCases * 2 + 1) {
        rl.close();  
    }
});

rl.on('close', () => {
    let idx = 1;

    for (let t = 0; t < testCases; t++) {
        let n = parseInt(inputs[idx++]);

        if (n % 2 === 0) {
            console.log("-1");
            continue;
        }

        let odd = [];
        let even = [];

        for (let j = 1; j <= n; j++) {
            if (j % 2 === 0) {
                even.push(j);
            } else {
                odd.push(j);
            }
        }
        even.sort((a, b) => b - a);
        let result = [];
        
        let oi = 0; 
        let ei = 0; 

        for (let j = 0; j < n; j++) {
            if (j % 2 === 0) {
                result.push(odd[oi++]);
            } else {
                result.push(even[ei++]);
            }
        }

        console.log(result.join(" "));
    }
});