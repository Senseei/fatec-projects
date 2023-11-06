class NumericConverter:
    
    def __init__(self):
        pass
    
    def to_decimal(number_to_convert, base):
        num = str.upper(str(number_to_convert))
        sum = 0
        
        for i in range(len(num)):
            
            position = len(num) - i - 1
            if num[i].isalpha():
                char_to_decimal = 10 + ord(num[i]) - ord('A')
                sum += char_to_decimal * power(base, position)
            else:
                sum += int(num[i]) * power(base, position)
        return sum
    
    
class Binary:
    BASE = 2

    def __init__(self):
        pass

    @staticmethod
    def to_octal(binary):

        octal = ""
        binary = Binary.pad_with_zeros(binary, Octal.BITS)

        for i in range(0, len(binary), Octal.BITS):
            decimal = Binary.to_decimal(binary[i:i + Octal.BITS])
            octal += str(decimal)

        return octal

    @staticmethod
    def to_decimal(binary):
        return NumericConverter.to_decimal(binary, Binary.BASE)

    @staticmethod
    def to_hexadecimal(binary):

        hexadecimal = ""
        binary = Binary.pad_with_zeros(binary, Hexadecimal.BITS)

        for i in range(0, len(binary), Hexadecimal.BITS):
            decimal = Binary.to_decimal(binary[i:i + Hexadecimal.BITS])
            if decimal >= 10:
                hexchar = chr(ord('A') + decimal - 10)
                hexadecimal += hexchar
            else:
                hexadecimal += str(decimal)

        return hexadecimal

    @staticmethod
    def pad_with_zeros(binary, size):
        binary = str(binary)
        padding = size - len(binary) % size if len(binary) % size > 0 else 0

        for _ in range(padding):
            binary = "0" + binary
        return binary
    
    
class Octal:
    
    BITS = 3
    BASE = 8

    def __init__(self):
        pass

    @classmethod
    def to_binary(cls, octal):

        octal = str(octal)
        binary = ""

        length = len(octal)
        for i in range(length):
            decimal = cls.to_decimal(octal[i])
            binary += Binary.pad_with_zeros(Decimal.to_binary(decimal), cls.BITS)

        return binary
    
    @classmethod
    def to_decimal(cls, octal):
        return NumericConverter.to_decimal(octal, cls.BASE)

    @classmethod
    def to_hexadecimal(cls, octal):
        
        octal = str(octal)

        binary = cls.to_binary(octal)
        return Binary.to_hexadecimal(binary)
    
    
class Decimal:
    
    BASE = 10

    def __init__(self):
        pass

    @staticmethod
    def to_binary(decimal):
        decimal = int(decimal)

        binary = ""

        while decimal > 0:
            binary = str(decimal % 2) + binary
            decimal = int(decimal / 2)

        if len(binary) == 0:
            binary += "0"

        return binary

    @classmethod
    def to_octal(cls, decimal):
        binary = cls.to_binary(decimal)
        return Binary.to_octal(binary)

    @classmethod
    def to_hexadecimal(cls, decimal):
        binary = cls.to_binary(decimal)
        return Binary.to_hexadecimal(binary)
    
    
class Hexadecimal:
    
    BITS = 4
    BASE = 16

    def __init__(self):
        pass

    @classmethod
    def to_binary(cls, hexadecimal):
        hexadecimal = str(hexadecimal)

        binary = ""

        length = len(hexadecimal)
        for i in range(length):
            decimal = cls.to_decimal(hexadecimal[i])
            binary += Binary.pad_with_zeros(Decimal.to_binary(decimal), cls.BITS)
            
        return binary

    @classmethod
    def to_octal(cls, hexadecimal):

        binary = cls.to_binary(hexadecimal)
        return Binary.to_octal(binary)

    @classmethod
    def to_decimal(cls, hexadecimal):
        return NumericConverter.to_decimal(hexadecimal, cls.BASE)



def main():
    binary = "1010"
    decimal = 16
    octal = "10"
    hexadecimal = "10"

    print("\nBinary -> " + binary + "...")
    print("To octal: " + str(Binary.to_octal(binary)))
    print("To decimal: " + str(Binary.to_decimal(binary)))
    print("To hexadecimal: " + str(Binary.to_hexadecimal(binary)))
    print()

    print("Octal -> " + octal + "...")
    print("To binary: " + str(Octal.to_binary(octal)))
    print("To Decimal: " + str(Octal.to_decimal(octal)))
    print("To hexadecimal: " + str(Octal.to_hexadecimal(octal)))
    print()

    print("Decimal -> " + str(decimal) + "...")
    print("To binary: " + str(Decimal.to_binary(decimal)))
    print("To Octal: " + str(Decimal.to_octal(decimal)))
    print("To Hexadecimal: " + str(Decimal.to_hexadecimal(decimal)))
    print()

    print("Hexadecimal -> " + hexadecimal + "...")
    print("To binary: " + str(Hexadecimal.to_binary(hexadecimal)))
    print("To octal: " + str(Hexadecimal.to_octal(hexadecimal)))
    print("To decimal: " + str(Hexadecimal.to_decimal(hexadecimal)))
    print()

def power(base, exponent):
    return base ** exponent

if __name__ == "__main__":
    main()