n = input()
for i in range(int(n)):
    a = input()
    suma = 0
    for x in a:
        if x == '1':
            suma = int(suma) + 2
        elif x == '2':
            suma = int(suma) + 5
        elif x == '3':
            suma = int(suma) + 5
        elif x == '4':
            suma = int(suma) + 4
        elif x == '5':
            suma = int(suma) + 5
        elif x == '6':
            suma = int(suma) + 6
        elif x == '7':
            suma = int(suma) + 3
        elif x == '8':
            suma = int(suma) + 7
        else:
            suma = int(suma) + 6
    print(str(suma) + " leds")

