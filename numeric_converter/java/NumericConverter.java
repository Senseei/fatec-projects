public class NumericConverter {

    public static final int MAX_SUPPORTED_BASE = 36;
    public static final int OCTAL_BASE = 8;

    // This ensure this will not be instatiated
    private NumericConverter() {}

    // Numeric Converter, be sure to insert the right numeric base to precise conversion!

    public static void main(String... args) {
        int binary = 101;
        String hexadecimal = "57";

        System.out.println("Decimal to binary: " + Decimal.toBinary(75));

        System.out.println("Binary to decimal: " + toDecimal(binary, Binary.BASE));
        System.out.println("Binary to hexadecimal: " + Binary.toHexadecimal("100101"));

        System.out.println("Hexadecimal to decimal: " + toDecimal(hexadecimal, Hexadecimal.BASE));
        System.out.println("Hexadecimal to binary: " + Hexadecimal.toBinary(hexadecimal));
    }

    /*
     *   Handles conversion with a long value as paramater
     *   But only supports until decimal base
     *   If the base is higher than 10, the result will not be right
     */
    public static long toDecimal(long numToConvert, int base) {
        return toDecimal(Long.toString(numToConvert), base);
    }

    // The same applies to this, but with an int value as paramater
    public static int toDecimal(int numToConvert, int base) {
        return (int) toDecimal(Integer.toString(numToConvert), base);
    }

    
    // Handles every single numeric system with letters and numbers
    public static long toDecimal(String numToConvert, int base) {
        validateBase(base);

        if (numToConvert == null)
            throw new IllegalArgumentException("num argument cannot be null");

        String num = numToConvert.toUpperCase();
        int sum = 0;
        
        for (int i = 0, length = num.length(); i < length; i++) {
            int position = length - i - 1;
            int digit = num.charAt(position);

            if (Character.isAlphabetic(digit)) {
                sum += (10 + digit - 'A') * Math.pow(base, i);
            }
            else if (Character.isDigit(digit)) {
                digit = Integer.parseInt(String.valueOf(num.charAt(position)));
                sum += digit * Math.pow(base, i);
            }
        }
        return sum;
    }

    public static void validateBase(int base) {
        if (base < 2 || base > 36)
            throw new IllegalArgumentException("Only bases between 2 and 36 are supported");
    }
}
