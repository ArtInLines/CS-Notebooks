class Stack:
	def __init__(self):
		self._elements = []
	
	def push(self, element):
		self._elements.append(element)
		return self
	
	def pop(self):
		if self.isEmpty():
			return None
		self._elements.pop(-1)
		return self
	
	def top(self):
		if self.isEmpty():
			return None
		return self._elements[-1]
	
	def isEmpty(self):
		return self._elements == []
	
	def __sizeof__(self):
		return len(self._elements)
	
	def copy(self):
		return Stack.createStack(self._elements)
	
	def __repr__(self):
		C = self.copy()
		result = C._convert()
		return result

	def _convert(self):
		if self.isEmpty():
			return '|'
		t = self.top()
		self.pop()
		return self._convert() + ' ' + str(t) + ' |'
	
	def __iter__(self):
		return self.copy()
	
	def __next__(self):
		if self.isEmpty():
			raise StopIteration
		x = self.top()
		self.pop()
		return x
	
	@staticmethod
	def createStack(elements):
		s = Stack()
		for e in elements:
			s.push(e)
		return s