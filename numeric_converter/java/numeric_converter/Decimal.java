package fatec.java.numeric_converter;

public class Decimal {
    
    public static final int BASE = 10;

    private Decimal() {}

    public static String toBinary(long decimal) {

        StringBuilder binary = new StringBuilder("");

        while (decimal > 0) {
            binary.insert(0, decimal % 2);
            decimal /= 2;
        }
        if (binary.length() == 0)
            binary.insert(0, "0");

        return binary.toString();
    }

    public static String toOctal(long decimal) {
        String binary = toBinary(decimal);
        return Binary.toOctal(binary);
    }

    public static String toHexadecimal(long decimal) {
        String binary = toBinary(decimal);
        return Binary.toHexadecimal(binary);
    }
}
