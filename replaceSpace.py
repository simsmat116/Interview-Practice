
def replaceSpace(str):
    return str.replace(" ", "%20")

assert(replaceSpace("") == "")
assert(replaceSpace(" ") == "%20")
assert(replaceSpace("Mr. Smith") == "Mr.%20Smith")
assert(replaceSpace(" Hello There ") == "%20Hello%20There%20")
assert(replaceSpace("Hello  There") == "Hello%20%20There")
