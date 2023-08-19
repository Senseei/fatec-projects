def main():
    print(convert(101, 2))

def convert(numberToConvert, base):
    num = str.upper(str(numberToConvert))
    sum = 0
    
    for i in range(len(num)):
        
        position = len(num) - i - 1
        if num[i].isalpha():
            charToDecimal = 10 + ord(num[i]) - ord('A')
            sum += charToDecimal * power(base, position)
        else:
            sum += int(num[i]) * power(base, position)
    return sum

def power(base, exponent):
    return base ** exponent

main()