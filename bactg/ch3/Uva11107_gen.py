from cyaron import *

test = IO("in.txt")
t = randint(1, 10)
n = randint(1, 100)
for p in xrange(0, t):
    test.input_writeln(n)
    for i in range(n):
        test.input_writeln(String.random(randint(1, 1000)))
test.input_writeln(0)
