def main():
    card_number = int(input("Number: "))

    luhn_sum = 0
    digits = 0
    count = 0
    first_two_digits = 0
    first_digit = 0

    while (card_number > 0):
        digits = card_number % 10

        if count % 2 == 0:
            luhn_sum = luhn_sum + digits
        elif count % 2 != 0:
            odd_product = digits * 2
            luhn_sum += (odd_product // 10) + (odd_product % 10)

        if 10 <= card_number < 100:
            first_two_digits = card_number
        if 0 < card_number < 10:
            first_digit = card_number

        card_number //= 10
        count += 1

    if luhn_sum % 10 != 0:
        print("INVALID")
        return 0

    if count == 15 and (first_two_digits == 34 or first_two_digits == 37):
        print("AMEX")
        return 0
    elif count == 16 and (first_two_digits == 51 or first_two_digits == 52
                          or first_two_digits == 53 or first_two_digits == 54
                          or first_two_digits == 55):
        print("MASTERCARD")
        return 0
    if ((count == 13 or count == 16) and first_digit == 4):
        print("VISA")
        return 0
    else:
        print("INVALID")
        return 0


main()
