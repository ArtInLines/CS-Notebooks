export default class Stack {
	#elements;
	constructor(...elements) {
		this.#elements = elements;
	}

	push(el) {
		this.#elements.push(el);
		return this;
	}

	pop() {
		if (this.isEmpty()) return undefined;
		this.#elements.pop();
		return this;
	}

	top() {
		if (this.isEmpty()) return undefined;
		return this.#elements[this.#elements.length - 1];
	}

	isEmpty() {
		return this.#elements.length === 0;
	}

	copy() {
		return new Stack(...this.#elements);
	}

	toString() {
		if (this.isEmpty()) return '|';
		return '| ' + this.#elements.join(' | ') + ' |';
	}
}
