public class Decimal {

    public static final int BASE = 10;

    private Decimal() {}

    public static String toBinary(long num) {
        return convert(num);
    }

    public static String toBinary(String num) {
        if (num == null)
            throw new IllegalArgumentException("Method's argument cannot be null");

        return convert(Long.parseLong(num));
    }

    public static String convert(long num) {
        String binary = "";

        while (num != 0) {
            int digit = (int) (num % 2);
            binary = Integer.toString(digit).concat(binary);
            num /= 2;
        }

        return binary;
    }
}
