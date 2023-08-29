public class NumericConverter {

    public static final int MAX_SUPPORTED_BASE = 36;

    // This ensure this will not be instatiated
    private NumericConverter() {}

    // Numeric Converter, be sure to insert the right numeric base to precise conversion!

    public static void main(String... args) {
        int decimal = 75;
        int binary = 101101;
        String hexadecimal = "57";
        int octal = 45;

        System.out.println("\nDecimal number: " + decimal);
        System.out.println("Decimal to binary: " + Decimal.toBinary(decimal));
        System.out.println("Decimal to octal: " + Decimal.toOctal(decimal));
        System.out.println("Decimal to hexadecimal: " + Decimal.toHexadecimal(decimal));

        System.out.println("\nBinary number: " + binary);
        System.out.println("Binary to decimal: " + Binary.toDecimal(binary));
        System.out.println("Binary to hexadecimal: " + Binary.toHexadecimal(binary));
        System.out.println("Binary to octal: " + Binary.toOctal(binary));

        System.out.println("\nHexadecimal number: " + hexadecimal);
        System.out.println("Hexadecimal to decimal: " + Hexadecimal.toDecimal(hexadecimal));
        System.out.println("Hexadecimal to binary: " + Hexadecimal.toBinary(hexadecimal));
        System.out.println("Hexadecimal to octal: " + Hexadecimal.toOctal(hexadecimal));

        System.out.println("\nOctal number: " + octal);
        System.out.println("Octal to decimal: " + Octal.toDecimal(octal));
        System.out.println("Octal to binary:" + Octal.toBinary(octal));
        System.out.println("Octal to hexadecimal: " + Octal.toHexadecimal(octal));
        System.out.println();
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
