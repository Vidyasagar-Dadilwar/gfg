function countSameElementSubarrays() {
    const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');
    let index = 0;
    const T = parseInt(input[index++]);
    const results = [];

    for (let t = 0; t < T; t++) {
        const N = parseInt(input[index++]);
        const vec = input[index++].split(' ').map(Number);

        let ans = 0;
        let len = 1;

        for (let i = 1; i <= N; i++) {
            if (i < N && vec[i] === vec[i - 1]) {
                len++;
            } else {
                ans += (len * (len + 1)) / 2;
                len = 1;
            }
        }

        results.push(ans);
    }

    console.log(results.join('\n'));
}

countSameElementSubarrays();
