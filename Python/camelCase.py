def solution(str):
    capIndex = [0]
    words = []
    
    # Find the index of each capital letter
    for i in range(len(str)):
        if str[i].isupper():
            capIndex.append(i) 

    capWordCount = len(capIndex)

    # Slice the string to get each word
    for i in range(capWordCount):
        if  i == capWordCount - 1: #does this for the last word
            word  = str[capIndex[i] : len(str)]
        if i + 1 <= capWordCount - 1: #for all of the words except the last
            word  = str[capIndex[i] : capIndex[i + 1]]

        words.append(word)

    # Join the words together with spaces
    newStr = words[0]
    for w in words[1:]:
        newStr = newStr + " " + w

    return newStr
    



print (solution("imOkNotOk"))