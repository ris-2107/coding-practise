def phoneNumberMnemonics(phoneNumber):
    currentMnemonic = ['0']*len(phoneNumber)
    mnemonicsFound = []

    phoneNumberMnemonicsHelper2(
        0, phoneNumber, currentMnemonic, mnemonicsFound)
    return mnemonicsFound


def phoneNumberMnemonicsHelper2(idx, phoneNumber, currentMnemonic, mnemonicFound):
    if(idx == len(phoneNumber)):
        mnemonicFound.append(''.join(currentMnemonic))
    else:
        digit = phoneNumber[idx]
        letters = DIGIT_LETTER[digit]
        for letter in letters:
            currentMnemonic[idx] = letter
            phoneNumberMnemonicsHelper2(
                idx+1, phoneNumber, currentMnemonic, mnemonicFound)

    return mnemonicFound


DIGIT_LETTER = {
    "0": ["0"],
    "1": ["1"],
    "2": ["a", "b", "c"],
    "3": ["d", "e", "f"],
    "4":  ["g", "h", "i"],
    "5": ["j", "k", "l"],
    "6": ["m", "n", "o"],
    "7": ["p", "q", "r", "s"],
    "8": ["t", "u", "v", "w"],
}

phone = "1230"
print(phoneNumberMnemonics(phone))
