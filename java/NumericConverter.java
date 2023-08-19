public class NumericConverter {

    // Numeric Converter, be sure to insert the right numeric base to precise conversion!

    public static void main(String... args) {
        int num = 101;
        String hexadecimal = "AF";
        System.out.println(convert(num, 2));
        System.out.println(convert(hexadecimal, 16));
    }

    /*
     *   Handles conversion with a long value as paramater
     *   But only supports until decimal base
     *   If the base is higher than 10, the result will not be right
     */
    public static long convert(long numToConvert, int base) {
        String num = Long.toString(numToConvert);
        long sum = 0;
        
        for (int i = num.length() - 1; i >= 0; i--) {
            int digit = Integer.parseInt(String.valueOf(num.charAt(i)));
            sum += digit * Math.pow(base, num.length() - i - 1);
        }
        return sum;
    }

    // The same applies to this, but with an int value as paramater
    public static int convert(int numToConvert, int base) {
        String num = Long.toString(numToConvert);
        int sum = 0;
        
        for (int i = num.length() - 1; i >= 0; i--) {
            int digit = Integer.parseInt(String.valueOf(num.charAt(i)));
            sum += digit * Math.pow(base, num.length() - i - 1);
        }
        return sum;
    }

    /*
     * Handles conversion with a String number parameter, also supports
     * alphanumeric values, hexadecimal, for example.
     * Supports until base 36, if base is higher than 36 it will not work as expected
     */
    public static long convert(String numToConvert, int base) {
        if (numToConvert == null)
            throw new IllegalArgumentException("num argument cannot be null");

        String num = numToConvert.toUpperCase();
        int sum = 0;
        
        for (int i = 0, length = num.length(); i < length; i++) {
            int digit = num.charAt(length - i - 1);
            if (Character.isAlphabetic(digit)) {
                sum += (10 + digit - 'A') * Math.pow(base, i);
            }
            else if (Character.isDigit(digit)) {
                digit = Integer.parseInt(String.valueOf(num.charAt(i)));
                sum += digit * Math.pow(base, i);
            }
        }
        return sum;
    }
}
