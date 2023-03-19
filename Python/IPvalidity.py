def is_valid_IP(strng):
    if strng.count(".") == 3:
        x = strng.split(".")
        flag = True
        for i in x:
            length = len(i)
            if i.isalpha() or i.find(" ") > -1:
                flag = False
                break
            else:
                if i.startswith("0"):
                    if length > 1:
                        flag = False
                        break
                else:
                    inInt = int(i)
                    if inInt < 0 or inInt > 255:
                        flag = False  
        return flag
    else:
        return False

print(is_valid_IP('12.255.56.1'))