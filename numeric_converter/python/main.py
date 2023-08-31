from numeric_converter import *

def main():
    
    decimal = 75
    binary = 101101
    hexadecimal = "57"
    octal = 45

    print("\nDecimal number: " + str(decimal))
    print("Decimal to binary: " + str(Decimal.toBinary(decimal)))
    print("Decimal to octal: " + str(Decimal.toOctal(decimal)))
    print("Decimal to hexadecimal: " + str(Decimal.toHexadecimal(decimal)))

    print("\nBinary number: " + str(binary))
    print("Binary to decimal: " + str(Binary.toDecimal(binary)))
    print("Binary to hexadecimal: " + str(Binary.toHexadecimal(binary)))
    print("Binary to octal: " + str(Binary.toOctal(binary)))

    print("\nHexadecimal number: " + str(str(hexadecimal)))
    print("Hexadecimal to decimal: " + str(Hexadecimal.toDecimal(hexadecimal)))
    print("Hexadecimal to binary: " + str(Hexadecimal.toBinary(hexadecimal)))
    print("Hexadecimal to octal: " + str(Hexadecimal.toOctal(hexadecimal)))

    print("\nOctal number: " + str(str(octal)))
    print("Octal to decimal: " + str(Octal.toDecimal(octal)))
    print("Octal to binary:" + str(Octal.toBinary(octal)))
    print("Octal to hexadecimal: " + str(Octal.toHexadecimal(octal)))
    print()

if __name__ == "__main__":
    main()