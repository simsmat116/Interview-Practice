
def oneAway(str1, str2):
    characters = {}
    for char in str1:
        if char not in characters:
            characters[char] = 1

    similarCount = 0
    for char in str2:
        if char in characters:
            similarCount += 1

    if max(len(str1), len(str2)) - similarCount == 1:
        return True
    return False

def oneAway2(str1, str2):
    index1, index2 = 0, 0
    len1, len2 = len(str1), len(str2)

    if abs(len1 - len2) > 1:
        return False

    diff_count = 0
    while index1 < len1 and index2 < len2:
        if str1[index1] == str2[index2]:
            index1 += 1
            index2 += 1
        else:
            if diff_count == 1:
                return False
            if len1 > len2:
                index1 += 1
            elif len2 > len1:
                index2 += 1
            else:
                index1 += 1
                index2 += 1

            diff_count += 1

    if index1 < len1 or index2 < len2:
        diff_count += 1

    return diff_count == 1


assert(oneAway2("pale", "ple") == True)
assert(oneAway2("a", "") == True)
assert(oneAway2("b", "a") == True)
assert(oneAway2("", "") == False)
assert(oneAway2("pale", "back") == False)
assert(oneAway2("ple", "pale") == True)
