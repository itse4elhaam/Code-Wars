def disemvowel(string_):
    Vowels = ['A','E','I','O','U','a','e','i','o','u']
    for Vowel in Vowels:
        string_ = string_.replace(Vowel, "")
    return (string_)
    
print(disemvowel('aeisdsdgd'))