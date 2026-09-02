from cs50 import get_float

while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break
cents = round(dollars * 100)

quarters = cents // 25
remainder = cents % 25

dimes = remainder // 10
remainder = remainder % 10

nickels = remainder // 5
remainder = remainder % 5

pennies = remainder

total = quarters + dimes + nickels + pennies
print(total)
