function main() {
    const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
    let t = parseInt(input[0], 10);
    let output = [];

    for (let i = 1; i <= t; i++) {
        let n = parseInt(input[i * 2 - 1], 10);
        let a = input[i * 2].split(' ').map(Number);
        let ans = [];
        let foundSorted = false;

        while (true) {
            let b = [...a].sort((x, y) => x - y);
            if (JSON.stringify(a) === JSON.stringify(b)) {
                foundSorted = true;
                break;
            }
            if (a.length <= 2) {
                break;
            }

            ans.push([1, 3]);
            let cur = a.slice(0, 3);
            let curSorted = [...cur].sort((x, y) => x - y);
            let median = curSorted[1];
            let pos = cur.indexOf(median);
            a = a.filter((_, index) => index !== pos);
        }

        if (!foundSorted) {
            output.push(-1);
        } else {
            output.push(ans.length);
            ans.forEach(it => output.push(`${it[0]} ${it[1]}`));
        }
    }

    console.log(output.join('\n'));
}

main();
