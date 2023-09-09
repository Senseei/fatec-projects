package fatec.java.numeric_converter;

public class Binary {
    
    public static final int BASE = 2;

    private Binary() {}

    public static String toOctal(String binary) {

        if (binary == null)
            throw new IllegalArgumentException("Binary number cannot be null");
        
        String octal = "";

        binary = padWithZeros(binary, Octal.BITS);

        for (int i = 0, length = binary.length(); i < length; i += Octal.BITS) {
            byte decimal = (byte) toDecimal(binary.substring(i, i + Octal.BITS));
            octal += Byte.toString(decimal);
        }

        return octal;
    }

    public static long toDecimal(String binary) {
        return NumericConverter.toDecimal(binary, BASE);
    }

    public static String toHexadecimal(String binary) {

        if (binary == null)
            throw new IllegalArgumentException("Binary number cannot be null");
        
        String hexadecimal = "";

        binary = padWithZeros(binary, Hexadecimal.BITS);

        for (int i = 0, length = binary.length(); i < length; i += Hexadecimal.BITS) {
            byte decimal = (byte) toDecimal(binary.substring(i, i + Hexadecimal.BITS));
            if (decimal >= 10) {
                char hexchar = (char) ('A' + decimal - 10);
                hexadecimal += hexchar;
            }
            else hexadecimal += decimal;
        }

        return hexadecimal;
    }

    public static String padWithZeros(String binary, int size) {
        int padding = binary.length() % size > 0 ? size - binary.length() % size : 0;

        for (int i = 0; i < padding; i++)
            binary = "0".concat(binary);
        return binary;
    }
}
