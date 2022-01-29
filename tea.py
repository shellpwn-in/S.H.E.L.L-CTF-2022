# shellctf{T0_1nfiNi7y_4nD_B3y0nd}
pwd = ""

def boilWater():
    global pwd
    pwd = input("Enter the password: ")
    return len(pwd)

def addSugar():
    global pwd
    odd = ""
    even = "";
    for i in range(len(pwd)):
        if i % 2 == 0:
            even += pwd[i]
        else:
            odd += pwd[i]
    pwd = odd + even

def addTea():
    global pwd
    string = ""
    for i in range(0, len(pwd) // 2):
            string += chr(ord(pwd[i]) - 3 * (i // 2))
    for i in range(len(pwd) // 2, len(pwd)):
            string += chr(ord(pwd[i]) + (i // 6))

    pwd = string

def addMilk():
    global pwd
    i = 0

    a, b, c = "", "", ""
    while pwd[i] != '5':
        a += pwd[i]
        i += 1

    while pwd[i] != 'R':
        b += pwd[i]
        i += 1

    while i < len(pwd):
        c += pwd[i]
        i += 1
    pwd = c + a + b

def strainAndServe():
    if "R;crc75ihl`cNYe`]m%50gYhugow~34i" == pwd:
        print("yep, that's right")
    else:
        print("nope, that's not it")
        
length = boilWater()
if length == 32:
    addSugar()
    addTea()
    addMilk()
    strainAndServe()
else:
    print("wrong length")
