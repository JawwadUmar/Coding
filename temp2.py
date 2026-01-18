str = input()
previousPin = "1234"

for i in range(len(str)):
    if str[i].isdigit() == False:
        print("Not Valid")
        exit()


if(len(str) != 4):
    print("Not Valid")
    exit()

num = int(str)
##num = stringToInteger(str)

if(num<1000):
     print("Not Valid")
     exit()


previousPin = str
print("Valid")
print("Your new pin is ", previousPin)