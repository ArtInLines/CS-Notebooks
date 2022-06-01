class Queue:
	def __init__(self):
		self._elements = []
	
	def __sizeof__(self):
		return len(self._elements)
	
	def isEmpty(self):
		return self._elements == []
	
	def enqueue(self, el):
		self._elements.append(el)
		return self
	
	def dequeue(self):
		if self.isEmpty():
			return None
		self._elements.pop(0)
		return self
	
	def peek(self):
		if self.isEmpty():
			return None
		return self._elements[0]
	
	def __str__(self):
		return self._elements.__str__
	
	def copy(self):
		return Queue.create(self._elements)
	
	@staticmethod
	def create(elements):
		C = Queue()
		C._elements = elements
		return C