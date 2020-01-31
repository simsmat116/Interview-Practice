
def permutation(str):
    return perm_helper(str, "", [])

def perm_helper(str, prefix, perms):
    if(len(str) == 0):
        perms.append(prefix)
    else:
        for i in range(0, len(str)):
            remaining = str[0:i] + str[i+1:]
            char_at_index = str[i]
            perm_helper(remaining, prefix + char_at_index, perms)
    return perms

def check_perm(str1, str2):
    perm1 = permutation(str1)

    for perm in perm1:
        if perm == str2:
            return True
    return False

def check_perm2(str1, str2):
    if len(str1) != len(str2):
        return False

    str1 = sorted(str1)
    str2 = sorted(str2)

    if str1 == str2:
        return True
    return False

assert(check_perm2("abc", "cba") == True)
assert(check_perm2("aas", "sas") == False)
