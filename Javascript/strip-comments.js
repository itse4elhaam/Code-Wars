function solution(text, markers) {
  if (markers.length === 0) return text.trimEnd();
  let finalText = "";
  let removeNextWord = false;
  const SPACE = " ";
  const ESCAPE_CHAR = "\\";
  const containsEscapeChar = text.includes(ESCAPE_CHAR);
  console.log("containsEscapeChar", containsEscapeChar)
  const isSingleMarker = markers.length === 1;
  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    console.log("char", char);
    const nextChar = text[i + 1];
    if (markers.includes(char)) {
      removeNextWord = true;
      continue;
    }

    const clearTillEnd =
      !containsEscapeChar && isSingleMarker && markers.includes(char);
      console.log("char", char)
      console.log("markers", markers)
    console.table({
      notContainsEscapeChar: !containsEscapeChar,
      isSingleMarker: isSingleMarker,
      markers: markers.includes(char),
    });
    console.log("clearTillEnd", clearTillEnd);
    if (clearTillEnd) {
      console.log("INSIDE the clearTillEnd block")
      return finalText
    }

    if (removeNextWord) {
      const isNextWordSpace = nextChar === SPACE;
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

  // ["aa bb cc", ["#"], "aa bb cc"],
  // ["aa bb # cc", ["#"], "aa bb"],
  ["aa# bb cc", ["#"], "aa"],
  ["aa #bb cc", ["#"], "aa"],
  ["aa # bb # cc", ["#"], "aa"],
  ["#aa bb cc", ["#"], ""],

  ["#aa bb\ncc dd", ["#"], "\ncc dd"],
  ["aa # bb\ncc dd", ["#"], "aa\ncc dd"],
  ["aa bb\n#cc dd", ["#"], "aa bb\n"],
  ["aa bb\ncc # dd", ["#"], "aa bb\ncc"],
  ["aa bb\ncc dd#", ["#"], "aa bb\ncc dd"],

  ["aa bb\ncc dd", ["#", "!"], "aa bb\ncc dd"],
  ["aa # bb\ncc dd", ["#", "!"], "aa\ncc dd"],
  ["aa bb\ncc ! dd", ["#", "!"], "aa bb\ncc"],
  ["#aa bb\n!cc dd", ["#", "!"], "\n"],
  ["aa ! bb\ncc # dd", ["#", "!"], "aa\ncc"],
  ["aa bb#\ncc dd!", ["#", "!"], "aa bb\ncc dd"],

  ["aa + bb\ncc - dd\nee * ff", ["+", "-", "*"], "aa\ncc\nee"],
  ["aa / bb\ncc ^ dd\nee $ ff", ["/", "^", "$"], "aa\ncc\nee"],
];

tests.forEach(([text, markers, expected], i) =>
  runTest(text, markers, expected, i + 1)
);
