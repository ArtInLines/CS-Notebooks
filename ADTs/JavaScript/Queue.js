export default class Queue {
	#elements;
	constructor(...elements) {
		this.#elements = elements;
	}

	get length() {
		return this.#elements.length;
	}

	isEmpty() {
		return this.#elements.length == 0;
	}

	enqueue(el) {
		this.#elements.push(el);
		return this;
	}

	dequeue() {
		if (this.isEmpty()) return null;
		this.#elements.shift();
		return this;
	}

	peek() {
		if (this.isEmpty()) return null;
		return this.#elements[0];
	}

	toString() {
		if (this.isEmpty()) return '|';
		return '[ ' + this.#elements.join(' | ') + ' ]';
	}

	toList() {
		return [...this.#elements];
	}

	copy() {
		return new Queue(...this.#elements);
	}
}
