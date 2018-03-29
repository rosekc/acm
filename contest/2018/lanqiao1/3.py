cnt = 0
def check(i):
    s = str(i)
    ok = True
    f = True
    for j in range(1, len(s)):
        if s[j - 1] > s[j]:
            if not f:
                ok = False
                break
        elif s[j - 1] < s[j]:
            if f and j != 1:
                f = False
            elif j == 1:
                ok = False
                break
        else:
            ok = False
            break
    return ok and not f
cnt = 0
for i in range(1, 100000):
    if check(i): 
        cnt += 1
        print(i)
print(cnt)
        