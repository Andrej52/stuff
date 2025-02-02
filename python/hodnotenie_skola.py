import os

#SKRIPT NA HODNOTENIE PROJEKTU
# SOS TURA
# copyright Andrej Mrázik

script_dir = os.path.dirname(__file__)

def makeComment():
    print("Enter your comment (type 'END' on a new line to finish):")
    commentHolder = ""
    while True:
       
        line = input()
        if line.upper() == "Ň":
            break
    
        commentHolder += line + "\n"
    return commentHolder

def checkZrazka(zrazka, maxPoints):
    while zrazka < 0 or zrazka > maxPoints:
        print(f"Zrazka must be between 0 and {maxPoints}.")
        zrazka = float(input("Zrazka: "))
    return zrazka       

while True:
    os.system('cls' if os.name == 'nt' else 'clear')
    
    filename = input("Nazov ziaka (or type 'exit' to quit): ")
    if filename.lower() == 'exit':
        break

    filename += "-hod.txt"
    filepath = os.path.join(script_dir, filename)
    try:
        with open(filepath, 'w') as file:
            print(f"File '{filename}' has been created or opened successfully.")
            
            # Predmety hodnotenia
            var1 = "DIZAJN"
            var2 = "Registracia Login "
            var3 = "PHP funkcnost"
            var4 = "Databaza"
            var5 = "Celkovo"

            # Max points
            dizajnPoints = 5
            registraciaPoints = 5
            phpPoints = 3
            dbPoints = 5
            maxTotalPoints = dizajnPoints + registraciaPoints + phpPoints + dbPoints

             # zrazky
            dizajnZrazka = 0
            registraciaZrazka = 0
            phpZrazka = 0
            dbZrazka = 0

            # Comments for each category
            print("Comment for DIZAJN: ")
            dizajnComment = makeComment()
            dizajnZrazka = checkZrazka(float(input("Zrazka for DIZAJN: ")), dizajnPoints)

            print("Comment for Registracia Login: ")
            registraciaComment = makeComment()
            registraciaZrazka = checkZrazka(float(input("Zrazka for Registracia Login: ")), registraciaPoints)

            print("Comment for PHP funkcnost: ")
            phpComment = makeComment()
            phpZrazka = checkZrazka(float(input("Zrazka for PHP funkcnost: ")), phpPoints)

            print("Comment for Databaza: ")
            dbComment = makeComment()
            dbZrazka = checkZrazka(float(input("Zrazka for Databaza: ")), dbPoints)

            # out to file
            htmlCssPoints = dizajnPoints - dizajnZrazka
            phpTotalPTS = phpPoints + registraciaPoints - phpZrazka - registraciaZrazka
            dbTotalPTS = dbPoints - dbZrazka
            totalPoints = htmlCssPoints + phpTotalPTS + dbTotalPTS

            file.write(f"{var1} (max {dizajnPoints}B):\n")
            file.write(f"{htmlCssPoints}B\n")
            file.write(f"- {dizajnComment}\n\n")

            file.write(f"{var2} (max {registraciaPoints}B)\n")
            file.write(f"{registraciaPoints - registraciaZrazka}B\n")
            file.write(f"- {registraciaComment}\n\n")

            file.write(f"{var3} (max {phpPoints}B)\n")
            file.write(f"{phpPoints - phpZrazka}B\n")
            file.write(f"- {phpComment}\n\n")

            file.write(f"{var4} (max {dbPoints}B)\n")
            file.write(f"{dbPoints - dbZrazka}B\n")
            file.write(f"- {dbComment}\n\n")

            file.write(f"CELKOVO:\n{totalPoints}/{maxTotalPoints} = {totalPoints / maxTotalPoints*100:.2f}%\n\n")

            file.write(f"Čiastkovo:\n")
            file.write(f"HTML CSS\n{htmlCssPoints}/{dizajnPoints} = {htmlCssPoints/dizajnPoints*100:.2f}%\n")
            file.write(f"PHP:\n{phpTotalPTS}/{phpPoints + registraciaPoints} = {phpTotalPTS/(phpPoints + registraciaPoints)*100:.2f}%\n")
            file.write(f"DATABAZA:\n{dbTotalPTS}/{dbPoints} = {dbTotalPTS/dbPoints*100:.2f}%\n")

    except FileNotFoundError:
        print(f"File '{filename}' not found.")
    except IOError as e:
        print(f"Error occurred while accessing the file '{filename}': {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")