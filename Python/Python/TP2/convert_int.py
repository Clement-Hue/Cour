def conv_int(str):
    conv= 0
    for l in str:
        if ord(l)< 48 or ord(l)>57:
             return False 
        conv = conv*10 + (ord(l)- ord('0'))
    return conv, True


