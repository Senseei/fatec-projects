public class Decimal {

    // Decimal decimalerical base
    public static final int BASE = 10;

    private Decimal() {}

    // Converts decimal to binary
    public static String toBinary(long decimal) {
        return convert(decimal);
    }

    public static String toBinary(String decimal) {
        if (decimal == null)
            throw new IllegalArgumentException("Method's argument cannot be null");

        return convert(Long.parseLong(decimal));
    }

    public static String convert(long decimal) {
        String binary = "";

        while (decimal != 0) {
            int digit = (int) (decimal % 2);
            binary = Integer.toString(digit).concat(binary);
            decimal /= 2;
        }

        return binary;
    }

    // Converts decimal to octal
    public static long toOctal(String decimal) {
        return toOctal(Long.parseLong(decimal));
    }

    public static long toOctal(long decimal) {
        String binary = toBinary(decimal);
        return Binary.toOctal(binary);
    }

    // Converts decimal to hexadecimal
    public static String toHexadecimal(String decimal) {
        return toHexadecimal(Long.parseLong(decimal));
    }

    public static String toHexadecimal(long decimal) {
        String binary = toBinary(decimal);
        return Binary.toHexadecimal(binary);
    }
}
