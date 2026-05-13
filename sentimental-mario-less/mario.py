def main():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                break
        except (ValueError, TypeError):
            pass

    for i in range(1, height + 1):
        num_of_spaces = int(height - i)
        spaces = " " * num_of_spaces
        num_of_hashes = int(i)
        hashes = "#" * num_of_hashes
        print(f"{spaces}{hashes}")


main()
