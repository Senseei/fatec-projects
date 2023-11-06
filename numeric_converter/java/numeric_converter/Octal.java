public class Octal {

    public static final int BITS = 3;
    public static final int BASE = 8;

    private Octal() {
    }

    public static String toBinary(long octal) {
        return toBinary(Long.toString(octal));
    }

    public static String toBinary(String octal) {

        if (octal == null)
            throw new IllegalArgumentException("Octal number cannot be null");

        String binary = "";

        for (int i = 0, length = octal.length(); i < length; i++) {
            byte decimal = (byte) toDecimal(Character.toString(octal.charAt(i)));
            binary += Binary.padWithZeros(Decimal.toBinary(decimal), BITS);
        }

        return binary;
    }

    public static long toDecimal(String octal) {
        return NumericConverter.toDecimal(octal, BASE);
    }

    public static String toHexadecimal(long octal) {
        return toHexadecimal(Long.toString(octal));
    }

    public static String toHexadecimal(String octal) {

        if (octal == null)
            throw new IllegalArgumentException("Octal number cannot be null");

        String binary = toBinary(octal);
        return Binary.toHexadecimal(binary);
    }
}
