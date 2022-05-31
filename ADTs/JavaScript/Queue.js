export default class Queue {
	#elements;
	constructor(...elements) {
		this.#elements = elements;
	}

	length() {
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
		this.#elements.shift(el);
		return this;
	}

	peek() {
		return this.#elements[0];
	}

	toString() {
		if (this.isEmpty()) return '|';
		return '[ ' + this.#elements.join(' | ') + ' ]';
	}

	copy() {
		return new Queue(...this.#elements);
	}
}
