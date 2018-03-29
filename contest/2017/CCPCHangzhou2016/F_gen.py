import random

print 1
len = random.randint(5, 20)
l = []
for i in xrange(0, len):
    l.append(str(random.randint(1, 9)))
s = ''.join(l)
print s