class Queue:
	def __init__(self):
		self._elements = []
	
	def __len__(self):
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
	
	def __repr__(self):
		return self._elements.__repr__()
		
	def __str__(self):
		return self._elements.__str__()
	
	def __add__(self, __o):
		c = self.copy()
		if isinstance(__o, Queue):
			o = __o.copy()
			while not o.isEmpty():
				c.enqueue(o.peek())
				o.dequeue()
		elif isinstance(__o, list):
			for x in __o:
				c.enqueue(x)
		else:
			c.enqueue(__o)
		return c
	
	def __iadd__(self, __o):
		if isinstance(__o, Queue):
			o = __o.copy()
			while not o.isEmpty():
				self.enqueue(o.peek())
				o.dequeue()
		elif isinstance(__o, list):
			for x in __o:
				self.enqueue(x)
		else:
			self.enqueue(__o)
		return self
	
	def __iter__(self):
		return self.copy()
	
	def __next__(self):
		if self.isEmpty():
			raise StopIteration
		x = self.peek()
		self.dequeue()
		return x
	
	def toList(self):
		return self._elements.copy()
	
	def copy(self):
		return Queue.create(self._elements)
	
	@staticmethod
	def create(elements):
		C = Queue()
		C._elements = elements.copy()
		return C