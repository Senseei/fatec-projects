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

        String sum = "";

        if (b1.length() >= b2.length())
            b2 = matchSizes(b2, b1);
        else
            b1 = matchSizes(b1, b2);


        int length = b1.length() >= b2.length() ? b1.length() : b2.length();
        int aux = 0;
        for (int i = length - 1; i >= 0; i--) {
            char char1 = b1.charAt(i), char2 = b2.charAt(i);

            int n1 = Character.getNumericValue(char1), n2 = Character.getNumericValue(char2);
            int expression = aux + n1 + n2;
            if (expression == 0) {
                sum = "0".concat(sum);
                aux = 0;
            }
            else if (expression == 1) {
                sum = "1".concat(sum);
                aux = 0;
            }
            else if (expression == 2) {
                sum = "0".concat(sum);
                aux = 1;
            }
            else if (expression == 3) {
                sum = "1".concat(sum);
                aux = 1;
            }
        }

        if (aux > 0)
            sum = "1".concat(sum);

        return sum;
    }

    public static String matchSizes(String shorter, String longer) {
        while (shorter.length() != longer.length()) {
            shorter = "0".concat(shorter);
        }
        return shorter;
    }
}
