public class Binary {
    
    // Binary numerical base
    public static final int BASE = 2;

    private Binary() {}

    // Converts binary to hexadecimal
    public static String toHexadecimal(long binary) {
        return convert(Long.toString(binary), Hexadecimal.BITS);
    }

    public static String toHexadecimal(String binary) {
        if (binary == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        return convert(binary, Hexadecimal.BITS);
    }

    // Converts binary to octal
    public static long toOctal(long binary) {
        return toOctal(Long.toString(binary));
    }

    public static long toOctal(String binary) {
        if (binary == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        return Long.parseLong(convert(binary, Octal.BITS));
    }

    // Converts binary to another numerical system based on the numerical system size
    private static String convert(String binary, int size) {
        String hexadecimal = "";
        
        binary = addZerosToLeft(binary, size);

        for (int i = 0, length = binary.length(); i < length; i += size) {
            int decimal = (int) NumericConverter.toDecimal(Long.parseLong(binary.substring(i, i + size)), BASE);
            char hexChar;
            if (decimal >= 10)
                hexChar = (char) (decimal - 10 + 'A');
            else
                hexChar = (char) (decimal + '0');

            hexadecimal += hexChar;
        }

        return hexadecimal;
    }

    // Converts binary to decimal
    public static long toDecimal(long num) {
        return NumericConverter.toDecimal(num, BASE);
    }

    public static long toDecimal(String num) {
        if (num == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");
        return NumericConverter.toDecimal(num, BASE);
    }

    // Method to add remaining zeros to the left of the binary number based on the numerical system size
    public static String addZerosToLeft(String binary, int size) {
        if (size <= 0)
            throw new IllegalArgumentException("size cannot be less than 1");
        if (binary == null)
            throw new IllegalArgumentException("binary number cannot be null");

        int extraZeros = binary.length() % size > 0 ? size - binary.length() % size : 0;
        String zeros = "";
        for (int i = 0; i < extraZeros; i++)
            zeros += "0";
        return zeros.concat(binary);
    }
}
