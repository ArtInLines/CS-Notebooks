class Stack:
	def __init__(self):
		self.mElements = []
	
	def push(self, element):
		self.mElements.append(element)
		return self
	
	def pop(self):
		if self.isEmpty():
			return None
		self.mElements.pop(-1)
		return self
	
	def top(self):
		if self.isEmpty():
			return None
		return self.mElements[-1]
	
	def isEmpty(self):
		return self.mElements == []
	
	def copy(self):
		return Stack.createStack(self.mElements)
	
	def __str__(self):
		C = self.copy()
		result = C._convert()
		return result

	def _convert(self):
		if self.isEmpty():
			return '|'
		t = self.top()
		self.pop()
		return self._convert() + ' ' + str(t) + ' |'
	
	@staticmethod
	def createStack(elements):
		s = Stack()
		for e in elements:
			s.push(e)
		return s