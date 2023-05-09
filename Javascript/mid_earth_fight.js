function getWorth(val, index, good) {
    // gives the values according to the good/bad
    const worth = good ? [1, 2, 3, 3, 4, 10] : [1, 2, 2, 2, 3, 5, 10];
    return val * worth[index];
}

function goodVsEvil(good, evil) {

    [good, evil] = [good.split(" "), evil.split(" ")];
    let goodWorth = 0, evilWorth = 0;

    // running it till the bigger array(evil)
    for (let i = 0; i < 7; i++) {
        if (i !== 6){
            goodWorth += getWorth(good[i], i, true);
        }

        evilWorth += getWorth(evil[i], i, false);
    }

    return goodWorth === evilWorth ? "Battle Result: No victor on this battle field" :
                        goodWorth > evilWorth ? "Battle Result: Good triumphs over Evil" :
                        "Battle Result: Evil eradicates all trace of Good";

}


console.log(goodVsEvil('0 0 0 0 0 10', '0 1 1 1 1 0 0'))