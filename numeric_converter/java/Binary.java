public class Binary {
    
    public static final int BASE = 2;

    private Binary() {}

    public static String toHexadecimal(String binary) {
        if (binary == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        return convert(binary, Hexadecimal.BITS);
    }

    public static String toOctal(String binary) {
        if (binary == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        return convert(binary, 3);
    }

    private static String convert(String binary, int size) {
        String hexadecimal = "";
        
        int extraZeros = binary.length() % size > 0 ? size - binary.length() % size : 0;
        String zeros = "";
        for (int i = 0; i < extraZeros; i++)
            zeros += "0";
        binary = zeros.concat(binary);

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
}
