def generate_hashtag(s):
    #your code here
    if s == "":
        return False
    else:
        Caps = s.title()
        FinalOut = ('#' + Caps.replace(" ", ""))
        if len(FinalOut) > 140:
            return False
        else:
            return FinalOut
            
generate_hashtag("u can die")