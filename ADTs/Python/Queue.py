class Queue:
	def __init__(self):
		self.mElements = []
	
	def __sizeof__(self):
		return len(self.mElements)
	
	def isEmpty(self):
		return self.mElements == []
	
	def enqueue(self, el):
		self.mElements.append(el)
		return self
	
	def dequeue(self):
		if self.isEmpty():
			return None
		self.mElements.pop(0)
		return self
	
	def peek(self):
		if self.isEmpty():
			return None
		return self.mElements[0]
	
	def __str__(self):
		return self.mElements.__str__
	
	def copy(self):
		return Queue.create(self.mElements)
	
	@staticmethod
	def create(elements):
		C = Queue()
		C.mElements = elements
		return C