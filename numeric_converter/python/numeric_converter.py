class NumericConverter:

    @classmethod
    def toDecimal(cls, numberToConvert, base):
        num = str.upper(str(numberToConvert))
        sum = 0
        
        for i in range(len(num)):
            
            position = len(num) - i - 1
            if num[i].isalpha():
                charToDecimal = 10 + ord(num[i]) - ord('A')
                sum += charToDecimal * cls.power(base, position)
            else:
                sum += int(num[i]) * cls.power(base, position)
        return sum

    def power(base, exponent):
        return base ** exponent
    
    
class Binary:
    
    BASE = 2
    
    @classmethod
    def toHexadecimal(cls, binary):
        return cls.convert(cls, binary, Hexadecimal.BITS)

    @classmethod
    def toOctal(cls, binary):
        return cls.convert(cls, binary, Octal.BITS)
    
    def convert(cls, binary, size):
        
        result = ""
        
        binary = cls.addZerosToLeft(str(binary), size)
        
        for i in range(0, len(binary), size):
            decimal = NumericConverter.toDecimal(binary[i:i+size], cls.BASE)
            if decimal >= 10:
                result += chr(decimal - 10 + ord('A'))
            else:
                result += str(decimal)
            
        return result
    
    @classmethod
    def toDecimal(cls, binary):
        return NumericConverter.toDecimal(binary, cls.BASE) if binary else None
        
    
    @classmethod
    def addZerosToLeft(cls, binary, size):
        if size <= 0:
            raise ValueError("Size cannot be less or equal to zero")
        
        extraZeros = 0 if len(binary) % size == 0 else size - len(binary) % size
        zeros = ""
        for i in range(extraZeros):
            zeros += "0"
            
        return zeros + binary
    
    
class Decimal:
    
    BASE = 10
    
    @classmethod
    def toBinary(cls, decimal):
        decimal = int(decimal)
        
        binary = ""
        
        while decimal != 0:
            binary = str(decimal % 2) + binary
            decimal = int(decimal / 2)
        
        return binary
    
    @classmethod
    def toOctal(cls, decimal):
        if decimal:
            binary = cls.toBinary(decimal)
            return Binary.toOctal(binary)
    
    @classmethod
    def toHexadecimal(cls, decimal):
        if decimal:
            binary = cls.toBinary(decimal)
            return Binary.toHexadecimal(binary)
        
        
class Hexadecimal:
    
    BASE = 16
    BITS = 4
    
    @classmethod
    def toBinary(cls, hexadecimal):
        if hexadecimal:
            binary = ""
            
            for c in hexadecimal:
                if c.isalpha():
                    decimal = int(10 + c - 'A')
                    result = Binary.addZerosToLeft(Decimal.toBinary(int(decimal)), cls.BITS)
                    binary += result
                elif c.isdigit():
                    result = Binary.addZerosToLeft(Decimal.toBinary(int(c)), cls.BITS)
                    binary += result
            
            return binary
    
    @classmethod
    def toOctal(cls, hexadecimal):
        if hexadecimal:
            binary = cls.toBinary(hexadecimal)
            return Binary.toOctal(binary)
        
    @classmethod
    def toDecimal(cls, hexadecimal):
        return NumericConverter.toDecimal(hexadecimal, cls.BASE) if hexadecimal else None


class Octal:
    
    BASE = 8
    BITS = 3
    
    @classmethod
    def toBinary(cls, octal):
        if octal:
            binary = ""
            
            for c in str(octal):
                if c.isdigit():
                    result = Binary.addZerosToLeft(Decimal.toBinary(int(c)), cls.BITS)
                    binary += result

            return binary
    
    @classmethod
    def toDecimal(cls, octal):
        return NumericConverter.toDecimal(octal, cls.BASE) if octal else None
    
    @classmethod
    def toHexadecimal(cls, octal):
        if octal:
            binary = cls.toBinary(octal)
            return Binary.toHexadecimal(binary)