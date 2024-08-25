// p = a^2 + b^2 + c^2 + d^2
// we know p always
// I will take the number and pick its underroot. after rounding it down, I will take its sq
// after the square I will check how much difference is left and will do the same thing with it recursively.
// will stop as soon as I get the sum right and will add 0 for the remainging stuff
// 3 => 1^2 + 1^2 + 1^2
// 31 => 5^2 + 2^2 + 1^2 + 1^2


function fourSquares(n) {
  n = Number(n)
  const fourSqs = [];
  let sum = 0;
  let temp = n;

  while (sum != n) {
    const numToSq = Math.floor(Math.sqrt(temp));
    const sqNumToSq = Math.pow(numToSq, 2);
    sum += sqNumToSq;
    temp -= sqNumToSq;
    fourSqs.push(BigInt(sqNumToSq.toString()));
  }
  return fourSqs;
}

console.log(fourSquares(0n))
