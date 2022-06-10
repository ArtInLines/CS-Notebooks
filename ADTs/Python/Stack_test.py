from Stack import Stack
import random as rnd

S = Stack()

assert S.top() == None
assert S.isEmpty()
assert S.pop() == None
assert S.copy().top() == S.push('bar').pop().top()

L = []
for i in range(100):
	x = rnd.randint(0, 100_000)
	S.push(x)
	assert S.top() == x
	assert not S.isEmpty()
	L.append(x)

print(S)
print(L)

for i in range(len(L)-1, -1, -1):
	assert L[i] == S.top()
	S.pop()