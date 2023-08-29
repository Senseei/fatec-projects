public class Octal {
    
    // Octal numerical base
    public static final int BASE = 8;
    // Octal size in bits
    public static final int BITS = 3;

    private Octal() {}

    // Converts an Octal to binary
    public static String toBinary(long octal) {
        return toBinary(Long.toString(octal));
    }

    public static String toBinary(String octal) {
        if (octal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");
        
        String binary = "";

        for (int i = 0, length = octal.length(); i < length; i ++) {
            int digit = octal.charAt(length - i - 1);
            if (Character.isDigit(digit) && digit < '8') {
                binary = Decimal.toBinary(Character.toString(digit)).concat(binary);
                binary = Binary.addZerosToLeft(binary, BITS);
            }
        }

        return binary;
    }

    // Converts an Octal to decimal
    public static long toDecimal(long octal) {
        return toDecimal(Long.toString(octal));
    }

    public static long toDecimal(String octal) {
        if (octal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        return NumericConverter.toDecimal(octal, BASE);
    }

    // Converts an Octal to hexadecimal
    public static String toHexadecimal(long octal) {
        return toHexadecimal(Long.toString(octal));
    }

    public static String toHexadecimal(String octal) {
        if (octal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");
        String binary = toBinary(octal);
        return Binary.toHexadecimal(binary);
    }
}
