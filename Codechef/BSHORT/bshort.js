// your code goes here
function main() {
    const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n'); 
    const T = parseInt(input[0], 10); 
    const results = [];

    for (let i = 1; i <= T; i++) {
        const N = parseInt(input[i * 2 - 1], 10); 
        const S = input[i * 2]; 
        let count_1 = 0, count_0 = 0;

        for (const c of S) {
            if (c === '1') {
                count_1++;
            } else {
                count_0++;
            }
        }

        let result;
        if (count_1 === 0) {
            result = 0;
        } else if (count_1 % 2 === 0) {
            result = count_0;
        } else {
            result = 1;
        }

        results.push(result);
    }

    console.log(results.join('\n'));
}

main();
