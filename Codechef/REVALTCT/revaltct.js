// your code goes here
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = -1;
let inputs = [];
let currentLine = 0;

rl.on('line', (line) => {
    if (testCases === -1) {
        testCases = parseInt(line); // First input is the number of test cases
    } else {
        inputs.push(line);
        if (inputs.length === 2 * testCases) {
            rl.close();
        }
    }
});

rl.on('close', () => {
    function isAlternating(S) {
        for (let i = 1; i < S.length; i++) {
            if (S[i] === S[i - 1]) {
                return false;
            }
        }
        return true;
    }

    function canBecomeAlternating(S) {
        const N = S.length;
        for (let L = 0; L < N; L++) {
            for (let R = L; R < N; R++) {
                let substring = S.slice(L, R + 1).split('').reverse().join('');
                let modified = S.slice(0, L) + substring + S.slice(R + 1);
                if (isAlternating(modified)) {
                    return true;
                }
            }
        }
        return false;
    }

    function countAlmostAlternatingSubstrings(S) {
        const N = S.length;
        let count = 0;

        // Generate all substrings and check if they can become alternating
        for (let i = 0; i < N; i++) {
            for (let j = i + 1; j <= N; j++) {
                let substring = S.slice(i, j);
                if (isAlternating(substring) || canBecomeAlternating(substring)) {
                    count++;
                }
            }
        }
        return count;
    }

    let output = [];
    for (let i = 0; i < testCases; i++) {
        const n = parseInt(inputs[2 * i]);
        const s = inputs[2 * i + 1];
        output.push(countAlmostAlternatingSubstrings(s));
    }

    console.log(output.join("\n"));
});
