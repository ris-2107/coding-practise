DIGIT_LETTER = {
    "0": ["0"],
    "1": ["1"],
    "2": ["a", "b", "c"],
    "3": ["d", "e", "f"],
    "4":  ["g", "h", "i"],
    "5": ["j", "k", "l"],
    "6": ["m", "n", "o"],
    "7": ["p", "q", "r", "s"],
    "8": ["t", "u", "v"],
    "9": ["w", "x", "y", "z"],
}


def getPhoneNumber(phoneNumber):
    currentMnemonic = ['0']*len(phoneNumber)
    mnemonicFound = []
    mnemonicsFound = getMnemonicsHelper(
        0, phoneNumber, currentMnemonic, mnemonicFound)

    return mnemonicFound


def getMnemonicsHelper(idx, phoneNumber, currentMnemonic, mnemonicFound):
    if(idx == len(phoneNumber)):
        mnemonicFound.append(''.join(currentMnemonic))
    else:
        digit = phoneNumber[idx]
        letters = DIGIT_LETTER[digit]
        for letter in letters:
            currentMnemonic[idx] = letter
            getMnemonicsHelper(idx+1, phoneNumber,
                               currentMnemonic, mnemonicFound)

    return mnemonicFound


phoneNum = "120979797979797898"
# print(getPhoneNumber(phoneNum))


def findPowerSet():
    array = {1, 2, 3}
    subsets = [[]]

    for ele in array:
        for i in range(len(subsets)):
            currentsubset = subsets[i]
            subsets.append(currentsubset + [ele])

    return subsets
