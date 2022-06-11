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
assert Q.copy().peek() == Q.copy().enqueue('bar').peek()

L = Q.toList()
for i in range(100):
	x = rnd.randint(0, 100_000)
	Qc = Q.copy()
	Q.enqueue(x)
	assert not Q.isEmpty()
	assert len(Qc) + 1 == len(Q)
	assert Q.peek() == 'foo'
	if len(Qc) > 0:
		assert Qc.peek() == Q.peek()
		assert Qc.copy().enqueue(x).dequeue().peek() == Qc.dequeue().enqueue(x).peek()
	L.append(x)

# print(Q)
# print(L)

for i in range(len(L)):
	assert L[i] == Q.peek()
	Qc = Q.copy()
	Q.dequeue()
	assert len(Qc) - 1 == len(Q)

print('Test successful')