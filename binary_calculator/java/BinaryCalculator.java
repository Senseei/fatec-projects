package fatec.binary_calculator.java;

public class BinaryCalculator {

    private BinaryCalculator() {}

    public static void main(String... args) {
        System.out.println(sum("0101", "0010"));
        System.out.println(sum("0111", "0101"));
        System.out.println(sum("1100", "1010"));
    }

    public static String sum(int b1, int b2) {
        return sum(Integer.toString(b1), Integer.toString(b2));
    }

    public static String sum(long b1, long b2) {
        return sum(Long.toString(b1), Long.toString(b2));
    }
    
    public static String sum(String b1, String b2) {

        if (b1 == null || b2 == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        int maxLength = Math.max(b1.length(), b2.length());

        StringBuilder sum = new StringBuilder(maxLength + 1);

        b1 = padWithZeros(b1, maxLength);
        b2 = padWithZeros(b2, maxLength);

        int length = b1.length() >= b2.length() ? b1.length() : b2.length();
        int carry = 0;
        for (int i = length - 1; i >= 0; i--) {
            char char1 = b1.charAt(i), char2 = b2.charAt(i);

            int n1 = Character.getNumericValue(char1), n2 = Character.getNumericValue(char2);
            int expression = carry + n1 + n2;

            carry = expression / 2;
            sum.insert(0, expression % 2);
        }

        if (carry > 0)
            sum.insert(0, carry);

        return sum.toString();
    }

    private static String padWithZeros(String str, int length) {
        int padding = length - str.length();
        if (padding > 0) {
            StringBuilder paddedStr = new StringBuilder(length);
            for (int i = 0; i < padding; i++) {
                paddedStr.append('0');
            }
            paddedStr.append(str);
            return paddedStr.toString();
        }
        return str;
    }
}
