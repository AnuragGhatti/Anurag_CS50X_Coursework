import string


def main():
    letters = 0
    sentences = 0
    words = 1

    text = input("Text: ")
    n = len(text)

    for i in range(n):
        if text[i].isalpha():
            letters += 1
        elif text[i] == '.':
            sentences += 1
        elif text[i] == '!':
            sentences += 1
        elif text[i] == '?':
            sentences += 1
        elif text[i] == ' ':
            words += 1

    L = (float(letters) / words) * 100
    S = (float(sentences) / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    grade_level = round(index)

    if grade_level < 1:
        print("Before Grade 1")
    elif (grade_level >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {grade_level}")


main()
