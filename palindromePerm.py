# Some basic understanding of palindromes - if even length -> cannot have odd count for characters
# If odd length -> can only have one character of odd count
# If there is only one of odd count, then the string cannot be of even length
def palindromePerm(str):
    charCounts = getCounts(str.lower().replace(" ", ""))

    foundOdd = False
    for count in charCounts.values():
        if count % 2 == 1:
            if foundOdd:
                return False
            foundOdd = True

    return True

def getCounts(str):
    charCounts = {}
    for char in str:
        if char == " ":
            continue

        if char not in charCounts:
            charCounts[char] = 1
        else:
            charCounts[char] += 1
    return charCounts

assert(palindromePerm("Tact Coa") == True)
assert(palindromePerm(" ") == True)
assert(palindromePerm("") == True)
assert(palindromePerm("abccba") == True)
assert(palindromePerm("What were you thinking") == False)
assert(palindromePerm("talkaklat") == True)
