# Get credit card input
while True:
    credit_card = int(input("Type Your Credit Card Number Here: "))
    if credit_card > 0:
        break
# Luhn's Algorithm: for checking if credit cards are valid or invalid


def luhn_check_sum(credit_card):
    def digits_of(n):
        # Iterates through all the digits
        return [int(d) for d in str(n)]
    digits = digits_of(credit_card)
    # Starts at the last digit and goes back by 2
    odd_digits = digits[-1::-2]
    # Starts at the second to last digit and goes back by 2
    even_digits = digits[-2::-2]
    # Add check sum  together
    check_sum = 0
    check_sum += sum(odd_digits)
    # Add reminding even_digits together
    for d in even_digits:
        check_sum += sum(digits_of(d * 2))
    return check_sum % 10

# Different Cards Visa, AMex , Mastercard


length = 0
visa = credit_card
amex = credit_card
mastercard = credit_card

length = len(str(credit_card))
# Identify Visa Card
while visa >= 10:
    visa = int(visa/10)
# Identify Amex Card
while amex >= 10**13:
    amex = int(amex/10**13)
# Identify Master Card
while mastercard >= 10**14:
    mastercard = int(mastercard/10**14)

if luhn_check_sum(credit_card) == 0:
    if visa == 4 and (length == 13 or length == 16):
        print("VISA")
    elif length == 15 and (amex == 34 or amex == 37):
        print("AMEX")
    elif length == 16 and (51 <= mastercard <= 55):
        print("MASTERCARD")
# Mark invalid cards as invalid
    else:
        print("INVALID")
else:
    print("INVALID")
