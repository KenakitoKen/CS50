from cs50 import get_string
from cs50 import get_float

text = get_string("Enter sentence: ")
print(text)

charCounter = 0.0
spaceCounter = 0.0
sentenceCounter = 0.0
wordCounter = 0.0

g = 0.0
s = 0.0
index = 0.0


for char in text:
    if char.isalpha():
        charCounter += 1.0
    if char.isspace():
        spaceCounter += 1.0
    if char in {'.', '!', '?'}:
        sentenceCounter += 1.0

wordCounter = spaceCounter + 1.0
# cast integers to floats

#calculate number of letters per 100 words in text
l = (charCounter / wordCounter) * 100.0
s = (sentenceCounter / wordCounter) * 100.0
index = (0.0588 * l) - (0.296 * s) - 15.8

index = round(index)

if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", index)

#If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level),
#your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1,
#your program should output “Before Grade 1”.
