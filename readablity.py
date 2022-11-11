# Ask user for  text
text = input("Text: ")
# Variables used in code
letters = 0
words = 1
sentences = 0

for i in text:
    # Checks to see if its uppercase or lowercase letters in ascii
    if i.isalpha():
        letters += 1
    elif i.isspace():
        words += 1
    elif i == "." or i == "?" or i == "!":
        sentences += 1

# Calculate Coleman-liau Index (is to know what grade level people read)
index = 0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8

# Prints grade level of reading
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")
