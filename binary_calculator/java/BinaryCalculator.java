public class BinaryCalculator {

    private BinaryCalculator() {
    }

    public static void main(String... args) {
        System.out.println("0101 + 0010 = " + sum("0101", "0010"));
        System.out.println("0111 + 0101 = " + sum("0111", "0101"));
        System.out.println("1100 + 1010 = " + sum("1100", "1010"));
        System.out.println();

        System.out.println("0100 - 1101 = " + sub("100", "1101"));
        System.out.println("1101 - 0100 = " + sub("1101", "100"));
        System.out.println("01001 - 00101 = " + sub("01001", "101"));
        System.out.println();
    }

    public static String sub(String b1, String b2) {

        if (b1 == null || b2 == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        int maxLength = Math.max(b1.length(), b2.length());

        b1 = padWithZeros(b1, maxLength);
        b2 = padWithZeros(b2, maxLength);

        b2 = complement(b2);

        String result = sum(b1, b2);

        return result.length() > maxLength ? result.substring(1) : result;
    }

    private static String complement(String binary) {
        StringBuilder result = new StringBuilder(binary.length());

        for (int i = 0, length = binary.length(); i < length; i++) {
            int digit = Character.getNumericValue(binary.charAt(i));
            int inverse = digit == 0 ? 1 : 0;
            result.append(inverse);
        }
        return sum(result.toString(), "1");
    }

    public static String sum(String b1, String b2) {

        if (b1 == null || b2 == null)
            throw new IllegalArgumentException("Method's parameter cannot be null");

        int maxLength = Math.max(b1.length(), b2.length());

        StringBuilder sum = new StringBuilder(maxLength + 1);

        b1 = padWithZeros(b1, maxLength);
        b2 = padWithZeros(b2, maxLength);

        int carry = 0;
        for (int i = maxLength - 1; i >= 0; i--) {
            char char1 = b1.charAt(i), char2 = b2.charAt(i);
            int n1 = Character.getNumericValue(char1), n2 = Character.getNumericValue(char2);

            int expression = carry + n1 + n2;

            carry = expression / 2;
            sum.insert(0, expression % 2);
        }

        if (carry > 0)
            sum.insert(0, carry);

        return padWithZeros(sum.toString(), maxLength);
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
