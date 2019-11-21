text = input("Text: ")

wordcount = 1
lettercount = 0
sentencecount = 0

for letter in text:
    if letter == " ":
        wordcount += 1
    elif letter == "." or letter == "?" or letter == "!":
        sentencecount += 1
    elif letter.isalnum():
        lettercount += 1

lettersper = (lettercount / wordcount) * 100
sentencesper = (sentencecount / wordcount) * 100


index = round((0.0588 * lettersper) - (0.296 * sentencesper) - 15.8)

if index < 1 or sentencecount == 0:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")