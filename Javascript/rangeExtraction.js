const MINIMUM_SEQUENCE_RANGE = 3;
function solution(list) {
  let currentRange = [];
  const sequence = [];
  for (let i = 0; i < list.length; i++) {
    const prev = list[i - 1];
    const curr = list[i];
    const next = list[i + 1];

    // console.table({ prev: prev, curr: curr, next: next });

    const isNextInSequence = next === curr + 1;

    const isPrevInSequence = prev === curr - 1;

    const isLastDigitInSequence = !isNextInSequence && isPrevInSequence;
    // console.table({
    //   isNextInSequence: isNextInSequence,
    //   isPrevInSequence: isPrevInSequence,
    //   isLastDigitInSequence: isLastDigitInSequence,
    // });

    if (isNextInSequence || isLastDigitInSequence) {
      currentRange.push(curr);
    }

    if (!isNextInSequence && !isLastDigitInSequence) {
      sequence.push(curr);
      continue;
    }

    if (isLastDigitInSequence) {
      sequence.push(getStrRange(currentRange));
      currentRange = [];
    }
  }

  return sequence.join(",");
}

function getStrRange(currentRange) {
  if (currentRange.length < MINIMUM_SEQUENCE_RANGE) {
    return currentRange.join(",");
  }
  return `${currentRange[0]}-${currentRange.pop()}`;
}

const result = solution([
  -6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20,
]);

const expected = "-6,-3-1,3-5,7-11,14,15,17-20";

// const result = solution([-6, -3, -2, -1, 0, 1]);
//
// const expected = "-6,-3-1";

if (result === expected) {
  console.log("PASS");
} else {
  console.log("expected", expected);
  console.log("result", result);
}
