function reverseAndCheck(n) {
	// Convert the number to a string
	let str = n.toString();
	// Reverse the string
	let reversedStr = str.split('').reverse().join('');

	// Convert the reversed string back to a number
	let reversedNum = parseInt(reversedStr);

	// Check if the reversed number is bigger than the original number
	if (reversedNum > n) {
		return reversedNum;
	} else {
		return -1;
	}

}

function allDigitsSame(n) {
	// Convert the number to a string
	let str = n.toString();

	// Get the first digit
	let firstDigit = str[0];

	// Check if all digits are the same as the first digit
	for (let i = 1; i < str.length; i++) {
		if (str[i] !== firstDigit) {
			return false;
		}
	}

	return true;
}

function nextBigDigit(n, srt = 0) {
	// Convert the number to an array of digits
	let arr = Array.from(String(n), Number);
	// Initialize variables for the first and next highest digits
	let first = arr[srt];
	let next = Infinity;

	// Loop through the array of digits starting from indexK 1
	for (i = srt + 1; i < arr.length; i++) {
		// If we find a digit greater than the first digit and less than the current value of next, update next
		if (arr[i] > first && arr[i] < next) {
			next = arr[i];
		}
	}

	// If we found a next highest digit, return it. Otherwise, return null.
	if (next !== Infinity) {
	    const cutArray = arr.slice(srt);
		return [next, cutArray.indexOf(next) + srt];
	} else {
		return null;
	}
}

function nextBigger(n) {

	// gives us an array of numbers
	n = n.toString().split("").map(str => parseInt(str));

	//checks if array is shorter than 3 if yes then we can do stuff quickly
	if (n.length == 1 || allDigitsSame(n)) {
		return -1
	}
	else if (n.length == 2) {
		return reverseAndCheck(n.join(""))
	}

	//Index K is the index of the first num to be swapped
	//Index X is the index of the second num to be swapped
	let count = n.length - 1;
	let notFound = true;
	while (count > -1) {

		if (n[count] > n[count - 1]) {
			//this is where the relevant number is found
			var indexK = count - 1
			notFound = false;
			if (indexK == n.length - 2) {
				[n[indexK], n[indexK + 1]] = [n[indexK + 1], n[indexK]];
				return parseInt(n.join(""))
			}
			break
		}
		count--;
	}

	console.log(`Notfound: ${notFound}`)
	console.log(`indexK: ${indexK}`)
	console.log(n)
	//checking if no adjacent pairs found, so that I can return -1
	if (notFound || nextBigDigit(n.join(""), indexK) == null) {
		return -1
	}

	// checking if there are atleast two variables to sort
	// -1 for the indexK and then further -1 for the second last indexK check.
	if (indexK != n.length - 2) {
		// now getting the next bigger number than the num_tobe_swappped
		let [, indexX] = nextBigDigit(n.join(""), indexK)
		console.log(`n: ${n}`)
		console.log(`IndexX: ${indexX}`)
		console.log(`IndexK: ${indexK}`)
		// swapping them
		if (typeof indexK !== 'undefined') {
			[n[indexX], n[indexK]] = [n[indexK], n[indexX]];
		}

		// sorting the remaining numbers after the SWAP
		let startIndex = indexK + 1;
		let sortedArr = n.slice(startIndex).sort();
		n.splice(startIndex, n.length - startIndex, ...sortedArr);
	}

	console.log("TESTING LOGS OVER !!")
	return (parseInt(n.join("")))
}

console.log(nextBigger(264887448))

//412 PM, 3/27/2023:
// This is the toughest Kata I did now, and I just love the feeling.