import Queue from './Queue.js';

let Q = new Queue();

console.assert(Q.peek() === null, 'Peeking empty Queue should be null');
console.assert(Q.isEmpty(), 'Empty Queue should be empty');
console.assert(Q.length === 0, 'Empty Queue should have length of 0');
console.assert(!new Queue().enqueue('foo').isEmpty(), "Queue shouldn't be empty after adding element");
console.assert(new Queue().enqueue('foo').dequeue().isEmpty(), 'Enqueue then Dequeue should make new Queue empty again');
console.assert(Q.dequeue() === null, 'Dequeuing empty Queue should be null');
console.assert(Q.enqueue('foo').peek() === 'foo', 'Peeking at Q should be "foo"');
console.assert(Q.copy().peek() === Q.enqueue('bar').peek(), 'Error');

let L = Q.toList();
for (let i = 0; i < 10; i++) {
	let x = Math.floor(Math.random() * 100_000);
	let Qc = Q.copy();
	Q.enqueue(x);
	console.assert(!Q.isEmpty(), "Q shouldn't be empty");
	console.assert(Qc.length + 1 === Q.length, "Q.length didn't increase correctly");
	console.assert(Q.peek() === 'foo', "Peeking doesn't work");
	if (Qc.length) {
		console.assert(Qc.peek() === Q.peek(), 'Qc and Q should have the same first element');
		console.assert(Qc.copy().enqueue(x).dequeue().peek() === Qc.dequeue().enqueue(x).peek(), "Order of enqueuing and dequeuing shouldn't matter");
	}
	L.push(x);
}

// console.log(Q.toString());
// console.log(L);

for (let i = 0; i >= L.length; i++) {
	console.assert(L[i] === Q.peek(), 'L[i] should be equal to Q.peek(): ' + L[i] + ' and ' + Q.peek());
	let Qc = Q.copy();
	Q.dequeue();
	console.assert(Qc.length === Q.length + 1, 'Qc.length should be equal to Q.length + 1');
}

console.log('Test successful');
