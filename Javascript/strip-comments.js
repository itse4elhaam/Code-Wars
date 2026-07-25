function solution(text, markers) {
  if (markers.length === 0) return text.trimEnd();
  let finalText = "";
  let removeNextWord = false;
  const SPACE = " ";
  const ESCAPE_CHAR = "\\";
  const containsEscapeChar = text.includes(ESCAPE_CHAR);
  console.log("ESCAPE_CHAR", ESCAPE_CHAR)
  console.log("text", text)
  console.log("containsEscapeChar", containsEscapeChar)
  const isSingleMarker = markers.length === 1;
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    const nextChar = text[i + 1];

    const clearTillEnd =
      !containsEscapeChar && isSingleMarker && markers.includes(char);
    if (clearTillEnd) {
      break;
    }

    if (markers.includes(char)) {
      removeNextWord = true;
      continue;
    }


    console.log("char", char)
    console.log("removeNextWord", removeNextWord)
    if (removeNextWord) {
      const isNextWordSpace = !containsEscapeChar && nextChar === SPACE;
      const isNextWordEscapeChar = nextChar === ESCAPE_CHAR;
      if (isNextWordSpace || isNextWordEscapeChar) {
        removeNextWord = false;
      }
      continue;
    }

    finalText += char;
  }

  return finalText.trimEnd();
}

// --- IF-CONDITION TESTS ---

function runTest(text, markers, expected, n) {
  let actual = solution(text, markers);
  if (actual !== expected) {
    console.log(
      `FAIL #${n}: text=${JSON.stringify(text)}, markers=${JSON.stringify(markers)}`
    );
    console.log(`  expected: ${JSON.stringify(expected)}`);
    console.log(`  actual:   ${JSON.stringify(actual)}`);
    process.exit(0);
  } else {
    console.log(`PASS #${n}`);
  }
}

const tests = [
  // ['aa bb cc', [], 'aa bb cc'],
  // ['aa bb cc  ', [], 'aa bb cc'],
  // ['  aa bb cc', [], '  aa bb cc'],
  // ["  aa # bb # cc  ", [], "  aa # bb # cc"],
  //
  // ["aa bb cc", ["#"], "aa bb cc"],
  // ["aa bb # cc", ["#"], "aa bb"],
  // ["aa# bb cc", ["#"], "aa"],
  // ["aa #bb cc", ["#"], "aa"],
  // ["aa # bb # cc", ["#"], "aa"],
  // ["#aa bb cc", ["#"], ""],

  [String.raw`#aa bb\ncc dd`, ["#"], String.raw`\ncc dd`],
  [String.raw`aa # bb\ncc dd`, ["#"], String.raw`aa\ncc dd`],
  [String.raw`aa bb\n#cc dd`, ["#"], String.raw`aa bb\n`],
  [String.raw`aa bb\ncc # dd`, ["#"], String.raw`aa bb\ncc`],
  [String.raw`aa bb\ncc dd#`, ["#"], String.raw`aa bb\ncc dd`],

  [String.raw`aa bb\ncc dd`, ["#", "!"], String.raw`aa bb\ncc dd`],
  [String.raw`aa # bb\ncc dd`, ["#", "!"], String.raw`aa\ncc dd`],
  [String.raw`aa bb\ncc ! dd`, ["#", "!"], String.raw`aa bb\ncc`],
  [String.raw`#aa bb\n!cc dd`, ["#", "!"], String.raw`\n`],
  [String.raw`aa ! bb\ncc # dd`, ["#", "!"], String.raw`aa\ncc`],
  [String.raw`aa bb#\ncc dd!`, ["#", "!"], String.raw`aa bb\ncc dd`],

  [String.raw`aa + bb\ncc - dd\nee * ff`, ["+", "-", "*"], String.raw`aa\ncc\nee`],
  [String.raw`aa / bb\ncc ^ dd\nee $ ff`, ["/", "^", "$"], String.raw`aa\ncc\nee`],
];

tests.forEach(([text, markers, expected], i) =>
  runTest(text, markers, expected, i + 1)
);
