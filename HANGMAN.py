import random
import time

time.sleep(2)
a = open("country.txt")
m = a.read()
coun = m.split()
tries = 5
print("""
         HANGMAN
The word is the name of a country.
""")

play = True
while play == True:
    b = random.choice(coun)
    b = b.upper()
    tries = 5
    print("\nTries: ",tries)
    print("_ "*len(b))
    f=[]
    for i in range(len(b)):
        f.append("_")
    while tries != 0:
        d = input("Enter a letter: ")
        y = False
        if d.islower() == True:
            d = d.upper()
        for j in range(len(b)):
            if b[j]==d:
                f[j] = d
                y = True
        a = ""
        for k in range(len(f)):
            a = a + f[k] + " "
        print(a)
        if y == False:
            tries = tries - 1
        print("Tries remaining: ", tries)
        if "_" not in f:
            print("You won the game.")
            break
    else:
        print("You Lose!")
        print(b)
    again = input("Want to play again(y for yes and other for no): ")
    if again == "y":
        play = True
    else:
        play = False
        

time.sleep(5)

    
    
