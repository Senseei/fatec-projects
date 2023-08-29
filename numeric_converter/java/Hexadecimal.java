public class Hexadecimal {
    
    // Hexadecimal numerical base
    public static final int BASE = 16;
    // Hexadecimal size in bits
    public static final int BITS = 4;

    private Hexadecimal() {}

    // Converts an hexadecimal to binary
    public static String toBinary(String hexadecimal) {

        if (hexadecimal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        String binary = "";

        for (int i = 0, length = hexadecimal.length(); i < length; i++) {
            int digit = hexadecimal.charAt(length - i - 1);
            if (Character.isAlphabetic(digit) && digit <= 'F') {
                int decimal = (10 + digit - 'A');
                binary = Decimal.toBinary(decimal).concat(binary);
                binary = Binary.addZerosToLeft(binary, BITS);
            }
            else if (Character.isDigit(digit))
                binary = Decimal.toBinary(Character.toString(digit)).concat(binary);
                binary = Binary.addZerosToLeft(binary, BITS);
        }

        return binary;
    }

    // Converts an hexadecimal to an octal
    public static long toOctal(String hexadecimal) {
        if (hexadecimal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        String binary = toBinary(hexadecimal);
        return Binary.toOctal(binary);
    }

    // Converts an hexadecimal to decimal
    public static long toDecimal(String hexadecimal) {
        if (hexadecimal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        String binary = toBinary(hexadecimal);
        return Binary.toDecimal(binary);
    }
}
