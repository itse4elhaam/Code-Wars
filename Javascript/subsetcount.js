// Why does this function work?

// For each element in an array we have two options, either to include it in a subarray or exclude it 
// that's why we raise 2 to the number of element
// it gives us of the choices where each number in the array is either excluded in an subarray or not



function estSubsets(arr) {
	const set = new Set(arr);
	return 2 ** set.size - 1;
}

// * TESTS:

let arr = [1, 2, 3, 4];
let expected = 15;
let actual = estSubsets(arr);
console.log("Test 1:");
if (expected === actual) {
	console.log("PASS");
} else {
	console.log("FAIL");
}

arr = ["a", "b", "c", "d", "d"];
expected = 15;
actual = estSubsets(arr);
console.log("Test 2:");
if (expected === actual) {
	console.log("PASS");
} else {
	console.log("FAIL");
}

arr = [2, 3, 4, 5, 5, 6, 6, 7, 8, 8];
expected = 127;
actual = estSubsets(arr);
console.log("Test 3:");
if (expected === actual) {
	console.log("PASS");
} else {
	console.log("FAIL");
}
