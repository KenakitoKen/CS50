while True:
    try:
        intHeight = int(input("Enter a number between 1 and 8: "))
        if 1 <= intHeight <= 8:
            break
    except ValueError:
        print("Invalid input, try again.")
for lines in range(1, intHeight + 1):
    for spaces in range(1, (intHeight + 1) - lines):
        print(f" ", end="")
    for hashes in range(1, lines + 1):
        print("#", end="")
    print("")
