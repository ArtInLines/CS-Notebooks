import Stack from './Stack.js';

let S = new Stack();

console.assert(S.top() === null, 'Top of empty stack should be null');
console.assert(S.isEmpty(), 'Empty stack should be empty');
console.assert(S.pop() === null, 'Popping empty stack should return null');
console.assert(S.copy().top() === S.push('foo').pop().top(), 'Adding and removing element should have no effect');

let L = [];
for (let i = 0; i < 100; i++) {
	let x = Math.floor(Math.random() * 100_000);
	S.push(x);
	console.assert(S.top() === x, 'Top should be x: ' + x);
	console.assert(!S.isEmpty(), 'Stack should not be empty');
	L.push(x);
}

// console.log(S.toString());
// console.log(L);

for (let i = L.length - 1; i >= 0; i--) {
	console.assert(L[i] === S.top(), 'L[i] == ' + L[i] + ' and S.top() == ' + S.top());
	S.pop();
}

console.log('Test successful');
