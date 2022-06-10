from Queue import Queue
import random as rnd

Q = Queue()

assert Q.peek() == None
assert Q.isEmpty()
assert len(Q) == 0
assert not Queue().enqueue('foo').isEmpty()
assert Queue().enqueue('foo').dequeue().isEmpty()
assert Q.dequeue() == None
assert Q.enqueue('foo').peek() == 'foo'
assert Q.copy().peek() == Q.enqueue('bar').dequeue().peek()

L = []
for i in range(100):
	x = rnd.randint(0, 100_000)
	Qc = Q.copy()
	Q.enqueue(x)
	assert not Q.isEmpty()
	assert len(Qc) + 1 == len(Q)
	assert Q.peek() == x
	if len(Qc) > 0:
		assert Qc.peek() == Q.peek()
		assert Qc.enqueue().dequeue().peek() == Qc.dequeue().enqueue().peek()
	L.append(x)

print(Q)
print(L)

for i in range(len(L)-1, -1, -1):
	assert L[i] == Q.peek()
	Qc = Q.copy()
	Q.dequeue(x)
	assert len(Qc) - 1 == len(Q)