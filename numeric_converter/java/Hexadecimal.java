public class Hexadecimal {
    
    public static final int BASE = 16;
    public static final int BITS = 4;

    private Hexadecimal() {}

    public static String toBinary(String hexadecimal) {

        if (hexadecimal == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        String binary = "";

        for (int i = 0, length = hexadecimal.length(); i < length; i++) {
            int digit = hexadecimal.charAt(length - i - 1);
            if (Character.isAlphabetic(digit) && digit <= 'F') {
                int decimal = (10 + digit - 'A');
                binary = Decimal.toBinary(decimal).concat(binary);
                binary = addZeros(binary);
            }
            else if (Character.isDigit(digit))
                binary = Decimal.toBinary(Character.toString(digit)).concat(binary);
                binary = addZeros(binary);
        }

        return binary;
    }

    public static String addZeros(String binary) {

        int extraZeros = binary.length() % 4 > 0 ? 4 - binary.length() % 4 : 0;
        String zeros = "";
        for (int i = 0; i < extraZeros; i++)
            zeros += "0";

        return zeros.concat(binary);
    }
}
