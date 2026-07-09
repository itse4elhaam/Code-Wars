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
    let abort = false;
    for (const char of str) {
      console.log("char", char);
      const charInAscii = char.charCodeAt(0);
      if (!this.isAlpha(charInAscii)) {
        abort = true;
        console.log("broke the loop");
        break;
      }

      const encodedChar = this.encodeChar(charInAscii, shift, encode);
      console.log("encodedChar", encodedChar);
      encoded += encodedChar;
    }

    return abort ? str.toUpperCase() : encoded.toUpperCase();
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

  this.encodeChar = function (ascii, shift, encode) {
    const asciShift = encode ? ascii + shift : ascii - shift;
    console.log("asciShift", asciShift);

    const isLowerOrUpper = this.isLowerOrUpper(ascii);
    console.log("isLowerOrUpper", isLowerOrUpper);

    console.log("asciShift", asciShift);
    const isUpperOutOfBound =
      asciShift > UPPERCASE_LOWER_BOUND || asciShift < LOWERCASE_UPPER_BOUND;
    if (isLowerOrUpper === "upper" && isUpperOutOfBound) {
      const loopedBackCharAscii = this.getLoopedBackCharAscii(
        asciShift,
        isLowerOrUpper
      );
      const encodedChar = String.fromCharCode(loopedBackCharAscii);
      return encodedChar;
    }

    const isLowerOutOfBound =
      asciShift > LOWERCASE_UPPER_BOUND || asciShift < LOWERCASE_UPPER_BOUND;
    if (isLowerOrUpper === "lower" && isLowerOutOfBound) {
      const loopedBackCharAscii = this.getLoopedBackCharAscii(
        asciShift,
        isLowerOrUpper
      );
      const encodedChar = String.fromCharCode(loopedBackCharAscii);
      return encodedChar;
    }

    const encodedChar = String.fromCharCode(asciShift);
    return encodedChar;
  };

  this.getLoopedBackCharAscii = function (asciShift, lowerOrUpper) {
    let newShift = 0;
    if (lowerOrUpper === "upper") {
      if (asciShift > UPPERCASE_UPPER_BOUND) {
        newShift = asciShift - UPPERCASE_UPPER_BOUND;

        const loopedBackCharAscii = newShift + UPPERCASE_UPPER_BOUND - 1;

        return loopedBackCharAscii;
      }

      if (asciShift < UPPERCASE_LOWER_BOUND) {
        console.log("inside the correct block atleast")
        newShift = asciShift + UPPERCASE_LOWER_BOUND;
        console.log("newShift", newShift)

        const loopedBackCharAscii = newShift + UPPERCASE_LOWER_BOUND - 1;

        return loopedBackCharAscii;
      }
    }

    if (lowerOrUpper === "lower") {
      if (asciShift > LOWERCASE_UPPER_BOUND) {
        newShift = asciShift - LOWERCASE_UPPER_BOUND;

        const loopedBackCharAscii = newShift + LOWERCASE_UPPER_BOUND - 1;

        return loopedBackCharAscii;
      }

      if (asciShift < LOWERCASE_LOWER_BOUND) {
        newShift = asciShift + LOWERCASE_LOWER_BOUND;

        const loopedBackCharAscii = newShift + LOWERCASE_LOWER_BOUND - 1;

        return loopedBackCharAscii;
      }
    }
  };
};

// const result1Obj = new CaesarCipher(5);
// const result1 = result1Obj.encode("Codewars");
// const expected1 = "HTIJBFWX";
//
// if (result1 !== expected1) {
//   console.error("expected " + expected1 + " but got " + result1);
// } else {
//   console.log("passed test 1");
// }

// const result2bj = new CaesarCipher(5);
// const result2 = result2bj.decode("HTIJBFWX");
// const expected2 = "CODEWARS";
//
// if (result2 !== expected2) {
//   console.error("expected " + expected2 + " but got " + result2);
// } else {
//   console.log("passed test 1");
// }

const result2bj = new CaesarCipher(5);
const result2 = result2bj.decode("B");
const expected2 = "W";

if (result2 !== expected2) {
  console.error("expected " + expected2 + " but got " + result2);
} else {
  console.log("passed test 1");
}
