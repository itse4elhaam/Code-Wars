var CaesarCipher = function (shift) {
  const UPPERCASE_LOWER_BOUND = 65; // A
  const UPPERCASE_UPPER_BOUND = 90; // Z

  const LOWERCASE_LOWER_BOUND = 97; // a
  const LOWERCASE_UPPER_BOUND = 122; // z

  this.encode = function (str) {
    return this.core(str, true);
  };

  this.decode = function (str) {
    return this.core(str, false);
  };

  this.core = function (str, encode) {
    let encoded = "";
    for (const char of str) {
      const charInAscii = char.charCodeAt(0);
      if (!this.isAlpha(charInAscii)) {
        encoded += char;
        continue;
      }

      const encodedChar = this.encodeChar(charInAscii, shift, encode);
      encoded += encodedChar;
    }

    return encoded.toUpperCase();
  };

  this.encodeChar = function (ascii, shift, encode) {
    const asciShift = encode ? ascii + shift : ascii - shift;

    const wrappedShift = this.handleWrappedShifts(ascii, asciShift);

    if (wrappedShift) {
      return wrappedShift;
    }

    const encodedChar = String.fromCharCode(asciShift);
    return encodedChar;
  };

  this.handleWrappedShifts = function (ascii, asciShift) {
    const isLowerOrUpper = this.isLowerOrUpper(ascii);

    const isConversionValidAlpha =
      isLowerOrUpper === "upper"
        ? asciShift >= UPPERCASE_LOWER_BOUND &&
          asciShift <= UPPERCASE_UPPER_BOUND
        : asciShift >= LOWERCASE_LOWER_BOUND &&
          asciShift <= LOWERCASE_UPPER_BOUND;
    if (isConversionValidAlpha) return;

    const loopedBackCharAscii = this.getLoopedBackCharAscii(
      asciShift,
      isLowerOrUpper
    );
    const encodedChar = String.fromCharCode(loopedBackCharAscii);
    return encodedChar;
  };

  // TODO: refactor this
  this.getLoopedBackCharAscii = function (asciShift, lowerOrUpper) {
    let loopedBackShift = 0;
    if (lowerOrUpper === "upper") {
      if (asciShift > UPPERCASE_UPPER_BOUND) {
        loopedBackShift = asciShift - UPPERCASE_UPPER_BOUND;

        const loopedBackCharAscii = loopedBackShift + UPPERCASE_LOWER_BOUND - 1;

        return loopedBackCharAscii;
      }

      if (asciShift < UPPERCASE_LOWER_BOUND) {
        loopedBackShift = UPPERCASE_LOWER_BOUND - asciShift;

        const loopedBackCharAscii = UPPERCASE_UPPER_BOUND - loopedBackShift + 1;

        return loopedBackCharAscii;
      }
    }

    if (lowerOrUpper === "lower") {
      if (asciShift > LOWERCASE_UPPER_BOUND) {
        loopedBackShift = asciShift - LOWERCASE_UPPER_BOUND;

        const loopedBackCharAscii = loopedBackShift + LOWERCASE_LOWER_BOUND - 1;

        return loopedBackCharAscii;
      }

      if (asciShift < LOWERCASE_LOWER_BOUND) {
        loopedBackShift = LOWERCASE_LOWER_BOUND - asciShift;

        const loopedBackCharAscii = LOWERCASE_UPPER_BOUND - loopedBackShift + 1;

        return loopedBackCharAscii;
      }
    }

    return asciShift;
  };

  this.isAlpha = function (char) {
    const isAlphabetic =
      (char >= 65 && char <= 90) || (char >= 97 && char <= 122);
    return isAlphabetic;
  };

  this.isLowerOrUpper = function (char) {
    const isLower = char >= 97 && char <= 122;
    const isUpper = char >= 65 && char <= 90;
    if (isLower) {
      return "lower";
    }

    if (isUpper) {
      return "upper";
    }
  };
};

const result1Obj = new CaesarCipher(5);
const result1 = result1Obj.encode("Codewars");
const expected1 = "HTIJBFWX";

if (result1 !== expected1) {
  console.error("expected " + expected1 + " but got " + result1);
} else {
  console.log("passed test 1");
}

const result2bj = new CaesarCipher(5);
const result2 = result2bj.decode("HTIJBFWX");
const expected2 = "CODEWARS";

if (result2 !== expected2) {
  console.error("expected " + expected2 + " but got " + result2);
} else {
  console.log("passed test 2");
}

// const result1Obj = new CaesarCipher(5);
// const result1 = result1Obj.encode("w");
// const expected1 = "B";
//
// if (result1 !== expected1) {
//   console.error("expected " + expected1 + " but got " + result1);
// } else {
//   console.log("passed test 1");
// }
//
// const result2bj = new CaesarCipher(5);
// const result2 = result2bj.decode("B");
// const expected2 = "W";
//
// if (result2 !== expected2) {
//   console.error("expected " + expected2 + " but got " + result2);
// } else {
//   console.log("passed test 1");
// }
