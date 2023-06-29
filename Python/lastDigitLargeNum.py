# So the idea is that you have to find the last digit of a large exponent which if calculated normally would be impossible
# there is a formula for it, we take the last digit of the base(n1) and save it as b
# then we calculate the exponent(n2)'s mod 4  and save it as m, if this m is 0 then we assign it 4


def last_digit(n1, n2):

    if n1 == 0 and n2 == 0:
        return 1

    base = n1
    mod = n2 % 4

    if n1 > 99:
        base = int(str(n1)[-1])

    if n2 < 10:
        mod = n2
    elif mod == 0:
        mod = 4

    ans = base ** mod
    return int(str(ans)[-1]) 


print(last_digit(3715290469715693021198967285016729344580685479654510946723,68819615221552997273737174557165657483427362207517952651))