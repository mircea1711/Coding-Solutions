suma = 0
a, b, c= map(int, input().split())
d, e, f= map(int, input().split())
if a < d : suma = int(suma) + int(d) - int(a)
if b < e : suma = int(suma) + int(e) - int(b)
if c < f : suma = int(suma) + int(f) - int(c)
print(str(suma))