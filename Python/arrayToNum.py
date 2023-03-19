def create_phone_number(n):
    f = "".join(map(str, n[0:3]) )
    s = "".join(map(str, n[3:6]) )
    t = "".join(map(str, n[6:10]) )
    return "("+f+") "+ s +"-"+t

print(create_phone_number([1, 2, 3, 4, 5, 6, 7, 8, 9, 0]))
