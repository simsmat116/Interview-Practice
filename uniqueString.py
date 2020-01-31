
def unique_string(str):
    unique_char = {}

    for letter in str:
        if letter in unique_char:
            return False
        unique_char[letter] = True

    return True

def unique_string2(str):
    if not str:
        return True

    str = sorted(str)

    for index in range(0, len(str) - 1):
        if str[index] == str[index + 1]:
            return False

    return True


assert(unique_string2("aaa") == False)
assert(unique_string2("") == True)
assert(unique_string2("abc") == True)
assert(unique_string2("bc22") == False)
