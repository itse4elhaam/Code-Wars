def xo(s):

    oCount = s.count('o') + s.count('O') 
    xCount = s.count('x') + s.count('X') 
    if xCount == oCount:
        return True
    else:
        return False