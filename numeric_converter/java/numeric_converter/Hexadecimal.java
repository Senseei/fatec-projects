public class Hexadecimal {

    public static final int BITS = 4;
    public static final int BASE = 16;

    private Hexadecimal() {
    }

    public static String toBinary(String hexadecimal) {

        if (hexadecimal == null)
            throw new IllegalArgumentException("Hexadecimal number cannot be null");

        String binary = "";

        for (int i = 0, length = hexadecimal.length(); i < length; i++) {
            byte decimal = (byte) toDecimal(Character.toString(hexadecimal.charAt(i)));
            binary += Binary.padWithZeros(Decimal.toBinary(decimal), BITS);
        }

        return binary;
    }

    public static String toOctal(String hexadecimal) {
        if (hexadecimal == null)
            throw new IllegalArgumentException("Hexadecimal number cannot be null");

        String binary = toBinary(hexadecimal);
        return Binary.toOctal(binary);
    }

    public static long toDecimal(String hexadecimal) {
        return NumericConverter.toDecimal(hexadecimal, BASE);
    }
}
