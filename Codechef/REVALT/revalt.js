// your code goes here
function isAlternating(s) {
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) {
            return false;
        }
    }
    return true;
}

function canBecomeAlternating(s) {
    let n = s.length;
    if (isAlternating(s)) {
        return true;
    }

    // Try reversing every possible substring and check if it becomes alternating
    for (let L = 0; L < n; L++) {
        for (let R = L; R < n; R++) {
            // Reverse substring from L to R
            let modified = s.split(''); // Convert string to array for easier manipulation
            let reversedPart = modified.slice(L, R + 1).reverse();
            modified.splice(L, R - L + 1, ...reversedPart); // Replace the part with reversed part
            
            if (isAlternating(modified.join(''))) {
                return true;
            }
        }
    }
    return false;
}

// Input and processing logic
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = -1;
let inputs = [];

rl.on('line', (line) => {
    if (testCases === -1) {
        testCases = parseInt(line, 10);
    } else {
        inputs.push(line);
        if (inputs.length === testCases * 2) {
            rl.close();
        }
    }
});

rl.on('close', () => {
    for (let i = 0; i < testCases; i++) {
        const n = parseInt(inputs[2 * i], 10);
        const s = inputs[2 * i + 1];

        if (canBecomeAlternating(s)) {
            console.log("Yes");
        } else {
            console.log("No");
        }
    }
});
