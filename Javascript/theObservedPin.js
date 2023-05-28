// ┌───┬───┬───┐
// │ 1 │ 2 │ 3 │
// ├───┼───┼───┤
// │ 4 │ 5 │ 6 │
// ├───┼───┼───┤
// │ 7 │ 8 │ 9 │
// └───┼───┼───┘
//     │ 0 │
//     └───┘

// I will getAdjNums for each digit of the observed pin, then I will start a loop acc to the array I get from the function
// each time it will replace that digit with each of the digits and return it

function repAtIndex(num, i, reps) {
    const results = [];

    for (const r of reps) {
        let digit = num[i]
        const n = num.replace(digit, r);
        results.push(n);
    }

    return results;
}

function getAdjNums(n) {
    const adjacentKeys = {
        '0': ['8'],
        '1': ['2', '4'],
        '2': ['1', '3', '5'],
        '3': ['2', '6'],
        '4': ['1', '5', '7'],
        '5': ['2', '4', '6', '8'],
        '6': ['3', '5', '9'],
        '7': ['4', '8'],
        '8': ['0', '5', '7', '9'],
        '9': ['6', '8']
    };

    return adjacentKeys[n] || [];
}

function getPINs(observed) {


    let combos = [];
    

    for (let digit of observed){
        let adjKeys = getAdjNums(digit);
        console.log("keys for " + digit + " are: " + adjKeys);
        
        for(let key of adjKeys){
            let otherPerms = repAtIndex(observed, 1 ,adjKeys);
            combos.push(observed, ...otherPerms);
            observed = observed.replace(digit, key);
        }

    }


    combos = Array.from(new Set(combos)).sort((a, b) => a - b);
    return combos;
}


let combos = getPINs('11'); // ["11", "22", "44", "12", "21", "14", "41", "24", "42"]
console.log(combos);