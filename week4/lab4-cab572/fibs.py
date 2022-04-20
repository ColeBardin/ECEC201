"""
fibs.py 
  Example showing how to compute the Fibonacci sequence in Python

Run with:
$ python fibs.py
"""

a, b = 0, 1
fibs = [a]

# Compute the next 99 numbers in the Fibonacci
# sequence and store them in order in the list `fibs`
for _ in range(99):
  a, b = b, a + b
  fibs.append(a)

# Simply display the contents of the list `fibs`
for i, f in enumerate(fibs):
  print('fibs[%d]: %d' % (i, f))