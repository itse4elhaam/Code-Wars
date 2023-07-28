// uses mod operator to extract out the decimal bit, if more than 0.5 then we can carry on with rounding up, else we round down

function Round(num) {
	const decimalPart = num % 1;

	if (decimalPart >= 0.5) {
		return num - decimalPart + 1;
	}

	return num - decimalPart;
}
function RoundUp(num) {
	2;
	const hasDecimalPart = num % 1 !== 0;

	return hasDecimalPart ? num - (num % 1) + 1 : num;
}
function RoundDown(num) {
	return number - (number % 1);
}
